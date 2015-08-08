Serveur FTP en Java
Antonin Carette et Alexandre Verkyndt.
17/02/15


# Introduction

Dans le cadre de l'enseignement de Construction d'Application Réparties (CAR), le premier TP à réaliser est un serveur FTP.
Ce projet consiste à implémenter en Java les fonctionnalités d'un serveur FTP multiplatforme.
L'implémentation de celui-ci suis la norme RFC 959 qui est le standard du sujet.
La version java avec laquelle a été développée la solution est la version 1.7 .
Les commandes, liées au serveur FTP, qui ont été implémentées sont: USER, PASS, SYST, PORT, LIST, STOR, RETR, PWD, CPUD, CWD, QUIT.

# Architecture

L'application est structurée de la façon suivante : 
- deux packages principaux : celui du FTPServer et un package utilitaire.
- le package serveur est subdivisé en deux sous-packages : Server et User.

Le sous-package Server rassemble les classes qui sont fortement liées au serveur. Ces classes font partie du coeur même du serveur.
Le sous-package User contient un format objet des données de l'utilisateur connecté ce qui permet aux requêtes de se souvenir d'avec qui elles communiquent.
Le package utilitaire livre une solution de récupération des données stocké dans un fichier csv qui contient les données des utilisateurs qui seront reconnus par le serveur.
Une classe main est placé en dehors des packages. Celle-ci sert au lancement d'un nouveau serveur.

Une fois le FTPServer lancé, celui-ci se met en attente de socket entrante. Une fois qu'une socket entre, un nouveau Thread est créé. Ce thread va se charger de gérer les 
différentes requêtes de l'utilisateur qui désire se connecter. C'est la classe FTPRequest qui sera lancée dessus.
FTPRequest gère les différentes fonctionnalités que propose le serveur au client. Une méthode maîtresse se charge d'appeler les fonctionnalités selon le besoin et gère avec des blocs try/catch les erreurs qui pourraient être remontées par les fonctionnalités.

Le FTP dispose d'un système assez précis en ce qui concerne les messages de notification vers l'utilisateur. Pour gérer ce système et permettre une plus grande liberté dans les notifications, une classe dédiée et une énumération ont été crées. CodeMessage est l'énumération qui référence les codes des messages qui sont gérés par le FTPServer. FTPMessage, quant à elle gère les messages associés ainsi que les informations que le systeme pourrait envoyer en plus, pour aider l'utilisateur.


En dehors du dossier src du projet se trouve le dossier test. Celui-ci partage les mêmes packages que le dossier src afin que les classes de tests se retourvent de façon cohérente avec les classes qui sont testées.

# Code Samples

Classe FTPRequest, Méthode gérant la commande STOR, ici il est intéressant de voir que pour l'envoie de données la méthode se sert un tampon de la taille du buffer de la socket pour éviter les débordements de buffer lors de l'envoie des données.

```java
/**
  * Method which allows to process the STOR command
  * @param file_name The file name of the file to store
  * @throws IOException An exception raises if the file can't be found
  */
  public void processStor(String file_name) throws IOException {
		
    File file_to_send = new File(this.current_path + file_name);
	
    /*
    * Send the file to the user
    */
    InputStream is = this.socket_data.getInputStream();
	
    /*
     * Data transfer : OK
     */
     sendMessageCom(CodeMessage.CODE_125, "");

     FileOutputStream fos = new FileOutputStream(file_to_send);
     byte[] buffer_socket = new byte[this.socket_data.getReceiveBufferSize()];
     int bytes_read = 0;

     /*
      * Store all bytes
      */
     while ((bytes_read = is.read(buffer_socket)) != -1)
       fos.write(buffer_socket, 0, bytes_read);

	/*
	 * Close all
	 */
	fos.flush();
	
	fos.close();
	
	sendMessageCom(CodeMessage.CODE_226, "");
	
	is.close();
}
```


Classe FTPRequest : La méthode maîtresse qui gère les requêtes et appelle les fonctions associées aux commandes. De plus elle gère les exceptions qui sont remontées. 

```java
/**
  * Method which allows to make general treatments for the input request
  */
  public void processRequest(String request_head, String request_msg) {
    System.out.println(request_head +   "    " +  request_msg);

    /*
     * Switch which contains all commands to process individually
    */
    switch(request_head) {
                      ...
    case "LIST":
        try {
            this.processList();
        } catch (Exception e) {
             sendMessageCom(CodeMessage.CODE_500, "Error with the data socket.");
        }
        return;

    case "PORT":
        try{
            this.processPort(request_msg);
        } catch (IOException e) {
            sendMessageCom(CodeMessage.CODE_500,"Illegal port command. No connection for data...");
        }
        return; 
                     ...
    case "RETR":
        try {
           this.processRetr(request_msg);
        } catch (IOException e) {
           sendMessageCom(CodeMessage.CODE_500, "Error with files.");
        }
        return;
                     ...
    }
```

Classe FTPRequest : Voici la méthode qui est utilisée pour chaque communication avec l'utilisateur via les messages FTP.

```java
/**
  * Method which allows to send a com' message
  * @param code The message code to send
  * @param message The complementary information to send
  */
  public void sendMessageCom(CodeMessage code, String message) {
     try {
       //if there is complementary informations 
        if(message.length() < 1)
           this.dos.writeBytes(new FTPMessage(code).getMessage());
        else 
           this.dos.writeBytes(new FTPMessage(code, message).getMessage());
    } 
    catch (IOException e) {
           System.err.println("The message " + code.toString() + " : " + message + " failed to be send.");
    }
   }
```


Classe FTPRequest : Ici la méthode qui permet de rejoindre le répertoire parent. 

```java
/**
  * Method which allows to move to the parent path
  */
  public void processCdup() {
     //if not root
     if (this.current_path != FTPRequest.repository_root_PATH) {
       //split the path by '/'
       String[] path_splitted = this.current_path.split("/");
       //initialiaze new path
       this.current_path = "";
       //append all the cells of the String tab except the last one
       for (int i = 0; i < (path_splitted.length - 1); i++)
           this.current_path += path_splitted[i] + "/";
       sendMessageCom(CodeMessage.CODE_200, "Directory changed to " + this.current_path);
    }
    else
       sendMessageCom(CodeMessage.CODE_500, "No changement to parent directory.");
  }
```

Classe FTPRequest.java : La méthode qui gère la commande Liste et qui génère dans un format intuitif la liste des fichiers (f) et répertoires (d)

```java
 /**
  * Method which allows to process the LIST command
  * @throws IOException Exception raises if the actual path file can't be found
  */
  public void processList() throws Exception {
    File actual_file = new File(this.current_path);
    String message_to_return = "List of files into "+this.current_path+" :\r\n";
    /*
     * For all files, if the studied file is a file -> f + getName; else d + getName
     */
    for (File fileEntry: actual_file.listFiles()) {
        if (fileEntry.isFile())
           message_to_return += "f: "+fileEntry.getName()+"\r\n";
        if (fileEntry.isDirectory())
           message_to_return += "d: "+fileEntry.getName()+"\r\n";
    }

    /*
     * Send the list via the socket_data
     */
    OutputStream os = this.socket_data.getOutputStream();
    DataOutputStream dos = new DataOutputStream(os);

    sendMessageCom(CodeMessage.CODE_125, "");
    dos.writeBytes(message_to_return);
    dos.flush();
    sendMessageCom(CodeMessage.CODE_226,"List successfully send.");
    socket_data.close();
  }
```
