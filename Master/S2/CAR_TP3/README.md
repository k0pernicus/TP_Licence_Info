CAR_TP3
=======
-------

# Auteurs

Carette Antonin / Verkyndt Alexandre

# Sommaire

* [Sources](#sources)
* [Code samples](#code_samples)
  * [Scripts](#scripts)
  * [Code](#code)
* [Utilisation](#utilisation)
* [Remarques](#remarques)

###<a name="sources"></a>Sources

*	**README.md** : fichier README du projet
* **Scenarii.md** : fichier permettant de visualiser les tests effectués sur le projet
* **doc/** : la documentation du projet
*	**src/rmi/** : sources du projet
*	**src/test/** : sources des tests du projet
* **scripts/** : scripts Bash permettant l'utilisation du projet

###<a name="code_samples"></a>Code Samples

####<a name="scripts"></a>Scripts

##### init_rmiregistry.sh

Il faudra tout d'abord utiliser le compilateur Java pour RMI, permettant d'initialiser les *stubs* ```rmic rmi.rmi.SiteImpl```.  
Ensuite, on initialise le *rmiregistry* par la commande ```rmiregistry```.

##### init_simple_graph.sh / init_simple_tree.sh

Initialisation du graph d'exemple, ainsi que de l'arbre.

##### rm_all_objects.sh

On cherchera tous les objets RMI à détruire, et on tuera chaque processus de ces objets : ```kill `ps -ef | grep "java rmi.main" | awk '{print $2}'` > /dev/null 2>&1```.  
De même pour *rmiregistry* : ```kill `ps -ef | grep usr/bin/rmiregistry | awk '{print $2}'` > /dev/null 2>&1```.

####<a name="code"></a>Code

##### SiteItf.java

Il s'agit de l'interface structurant l'implémentation de chaque noeud.  
Cette interface contiendra donc tous les *getters*/*setters* requis, ainsi qu'une méthode récursive *sendDataToSon* permettant d'envoyer à chaque fils d'un noeud le message précédemment reçu.  
Cette interface étendra l'interface *Remote*, permettant d'intéragir avec les objets RMI. Aussi, chaque méthode pourra retourner une exception *RemoteException*.

```
/**
 * Interface to build the data transfer mecanism between nodes
 */
public interface SiteItf extends Remote {

	/**
	 * Method to return the id of the node
	 * @return the id
	 * @throws RemoteException
	 */
	public int getId() throws RemoteException;

	/**
	 * Method to set the id of the node
	 * @param id the id to set
	 * @throws RemoteException
	 */
	public void setId(int id) throws RemoteException;

  ...

  /**
	 * Method to send data (a byte array) to sons of node.
	 * When the node receive the data, he will send it to each son.
	 * Also, he will prevent us the good reception of data.
	 * @param data The data to send - a byte array
	 * @throws RemoteException
	 */
    public void sendDataToSon(byte[] data) throws RemoteException;
}
```

##### SiteImpl.java

Cette classe implémentera l'interface *SiteItf.java*.  
Elle implémente donc toutes les méthodes définies dans l'interface citée précédemment.  
Le plus intéressant est la méthode *sendDataToSon*, de par l'utilisation du *Synchronized* pour préserver seulement l'accès d'un noeud quant à la réception du message.  
Ainsi, on préserve l'accès au booléen *allready_received* par un noeud, ce qui permettra de ne pas faire accéder par deux noeuds parents le même attribut et donc envoyer deux fois le même message à leur fils communs.  
Quant à la gestion de la concurrence, on lancera un *thread* par chaque envoie de message sur un noeud.


```
@Override
public void sendDataToSon(final byte[] data) throws RemoteException {
  if (!this.allready_received) {
    synchronized (this) {
      System.out.println("Node "+this.id+" have received data...");
      this.data = data;
      this.allready_received = true;
    }
      //send data to sons
    for (final SiteItf son : this.sons)
      new Thread(new Runnable() {
      @Override
      public void run() {
        try {
          son.sendDataToSon(data);
        } catch (RemoteException e) {
          System.err.println(e.getMessage());
        }
      }
  }).start();
  }
}
```

##### SiteInitializer.java

Ce programme initialisera un objet *SiteItf* qui pourra être déterminé par le numéro (*id*) qu'on lui donnera en paramètre.  
Tout d'abord, on localisera l'objet *Registry*, afin de pouvoir implémenter ce noeud et ensuite l'inscrire dans ce registre.  
On le nommera avec la méthode *rebind*, et il sera donc stocké dans le registre RMI global afin d'être pris en compte dans la suite.  
Il est à noter que chaque nouvelle implémentation d'un objet *SiteItf* sera threadée. De plus, afin de ne pas supprimer l'objet créé de suite, on lui permettra de vivre dans une période infinie, grâce à *Thread.sleep(999999999)*. Aussi, une exception *RegistryException* sera retournée lors de la levée d'une *RemoteException*.

```
public static void main(String[] argv) throws RemoteException {
  try {
    Registry registry = LocateRegistry.getRegistry();

    SiteItf node_to_implement = new SiteImpl();
    node_to_implement.setId(Integer.parseInt(argv[0]));

    //Register the node
    registry.rebind(argv[0], node_to_implement);

    System.out.println("Node" + argv[0] + " successfully implemented!");

    //The node is now threadable
    new Thread(new Runnable() {
      @Override
      public void run() {
        try {
          Thread.currentThread();
          Thread.sleep(999999999);
        } catch (InterruptedException e) {
          e.printStackTrace();
        }
      }
    }).start();

  }
  catch (RemoteException e) {
    System.out.println(new RegistryException().getMessage());
    return;
  }
}
```

##### InitConnection.java

Ce programme permettra d'établir une connexion entre deux objets RMI déjà implémentés. Ces objets sont transmis en paramètres par leur ID respectif, et permettra donc de créer une arête entre ces deux objets, dans une représentation en graphe par exemple.  
L'on renverrai cette fois ci l'exception *NotBoundException* si les objets demandés dans le registre RMI ne sont pas trouvés.

```
public static void main(String[] argv) throws NotBoundException {

  try {
    Registry registry = LocateRegistry.getRegistry();

    SiteItf father = (SiteItf) registry.lookup(argv[0]);
    SiteItf son = (SiteItf) registry.lookup(argv[1]);

    //Set son and father (go see addSon method in SiteImpl class)
    father.addSon(son);

    System.out.println("Connection : node"+father.getId()+" and node"+son.getId()+" have been added.");
  }
  catch (RemoteException e) {
    System.out.println(new RegistryException().getMessage());
    return;
  }

}
```

##### SendMessage.java

Ce dernier programme permettra d'envoyer un message (par défaut : "HelloWorld") à un noeud spécifié en paramètre par son ID.  
Le message pourra être spécifié par l'utilisateur, en 2ème argument du programme.  
La méthode *cleanVisited()* invoquée sur l'objet *node_to_send_msg* permettra de remettre tous les drapeaux à *false* - permettant ainsi aux messages de se propager dans le graphe.

```
public static void main(String[] argv) throws NotBoundException {
  try{
    Registry registry = LocateRegistry.getRegistry();

    SiteItf node_to_send_msg = (SiteItf) registry.lookup(argv[0]);

    //Default message to send
    String message_to_send = "HelloWorld";

    //If the user have specify a message to send, we replace the "HelloWorld" by the specified message
    if (argv.length > 1)
      message_to_send = argv[1];

    //Clean all nodes
    node_to_send_msg.cleanVisited();

    node_to_send_msg.sendDataToSon(message_to_send.getBytes());

    System.out.println("Message sent to node" + node_to_send_msg.getId() + " successfully!");

  }
  catch (RemoteException e){
    System.out.println(new RegistryException().getMessage());
    return;
  }
}
```

###<a name="utilisation"></a>Utilisation

L'utilisation du projet se fait exclusivement par des **scripts Bash** (autre que l'utilisation aussi des classes Java) - il faudra ainsi se placer dans la racine du projet.

**Initialisation (optionnelle) :**
* Initialisation du registre rmi : ```./scripts/init_rmiregistry.sh``` OU lancer directement le script d'initialisation du graphe choisi (voir ci-dessous).

**Utilisation :**  
Pour chaque objet RMI créé, un terminal (xterm par défaut) s'ouvrira afin de pouvoir visualiser toutes les intéractions effectuées avec l'objet.
* Initialisation de l'arbre : ```./scripts/init_simple_tree.sh```
* Initialisation du graphe : ```./scripts/init_simple_graph.sh```  

**Une fois terminé :**
* Suppression de tous les objets RMI, ainsi que le registre : ```./scripts/rm_all_objects.sh```

###<a name="remarques"></a>Remarques

"Have fun!"
