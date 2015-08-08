package udp;

import java.lang.*;
import java.util.*;
import java.net.*;

public class Exo3 {

    /**Permet de lire l'IP dans un tableau d'octets a partir de l'inex fourni
     *@param t le tableau d'octets
     *@param offset l'indice auquel se trouve l'adresse ip
     *@return la chaine de caracteres correspondant a l'adresse ip
     */
    public String lireIp(byte[] t, int offset) {
	String s = "";
	for (int i =0; i<3; i++) {
	    s += t[offset+(i)] & 0xff;
	    s += ".";
	};
	s += t[offset+3] & 0xff;
	return s;
    }
	
	
    /**  Lecture d'une chaine a partir d'un byte donnee dans le tableau
     *Renvoie la chaine correspondante, a defaut l'adresse ip quand on indique "ip" en parametre
     *@param t le tableau d'octets ou lire la chaine
     *@param offset_debut l'indice a partir duquel lire la chaine
     *@param s l'option permet de choisr entre l'affichage en caracteres ou en nombre pour une adresse ip     
     *@return la chaine de caracteres 
    */
    public String lirechaine(byte[] t, int offset_debut, String s) {
	int i = offset_debut;
	if (s=="ip") { 
	    return (lireIp(t, offset_debut));
	}
	else 
	    {
		while((t[i] & 0xff) > 0) {
		    if ((t[i] & 0xff) >= 192) { /*-> POINTEUR : on affiche le message point\'e.*/
			/*System.out.println("Pointeur "+i);*/
			int index = (t[i+1] & 0xff);  /*l'index ou se deplacer est inscrit sur l octet suivant*/
			/*	System.out.println("index "+index);*/
			int nbOctetsALire =   t[index];
			for (int j=0; j<nbOctetsALire; j++) {
			    /*Conversion d'un hexadecimal en chaine de caractere */
			    int n = t[1+(index++)];
			    String stringChar =  ""+((char) n); 
			    /* ajout du caratere obtenu a la chaine */
			    s+= stringChar;
			};	
			s+=".";	
			/* on a atteint un zero, la zone qui nous interessait est termine, on renvoie l index ou se trouvera la prochaine section a decoder */ 
			i=index+1;
		    }
		    else {
			/*il n'y a pas de pointeur */
			int index =i; 
			int nbOctetsALire =   t[i];
			for (int j=0; j<nbOctetsALire; j++) {
			    /*Conversion d'un hexadecimal en chaine de caractere */
			    int n = t[index+j+1];	 
			    String stringChar =  ""+((char) n); 
			    /* ajout du caratere obtenu a la chaine */
			    s+= stringChar;
			}
			s+=".";
			i+=nbOctetsALire+1;
		    }
		}
	    }
	/* suppression du point ajouter en trop a la fin de la chaine */
	if (s.charAt(s.length()-1)==( '.')) {
	    s = s.substring(0, s.length()-1);
	}
	return s;
    }
    
    /** Convertit un nombre hexadecimal en entier 
     *@param b l'octet a convertir en entier
     *@return l'entier correspondant 
*/
    public int hexToInt(byte b) {
	return (b & 0xff);
    }

    /* renvoie la chaine correspondant a l'octet passe en parametre */
    public String unBit(byte b) {
	String s = Integer.toHexString(b & 0xff);
	int l = s.length();
	if (l==2) {return s;}
	else { return ("0"+s);
	}
    }

    /** renvoie la chaine correspondant a 2 octets
     *@param t le tableau d'octets d'ou afficher les octets
     *@param index, l'index ou se trouve le premier des deux octets a afficher
     @return s la chaine correspondant aux 2 octets voulus
    */
    public String deuxBits(byte[] t ,  int index) {
	String s = this.unBit(t[index++])+""+this.unBit(t[index++]);
	return s;
    }

    /** Decode le message recu 
	@param le tableau d'octets contenus dans le paquet recu
    */
    public void decodeMessage(byte[]t) {
	int index = 0;
	/*Decodage de l'entete */ 
	System.out.println("Identifiant : "+ this.deuxBits(t, index));
	index+=2;
	System.out.println("Parametre : "+ this.deuxBits(t,index));
	index+=2;
	System.out.println("QDCOUNT : "+ this.deuxBits(t,index));
	index+=2;
	System.out.println("ANCOUNT : "+this.deuxBits(t,index));
	index+=2;
	System.out.println("NSCOUNT : "+ this.deuxBits(t,index));
	index+=2;
	System.out.println("ARCOUNT : "+ this.deuxBits(t,index));
	index+=2;
	/*Fin de l'entete*/
	/*adresse ou envoyer la requete*/
	String requete = lirechaine(t, index, "");
	System.out.println(requete);
	index+=requete.length()+2;/*on ajoute +1 pour le '00' signifiant la fin de l'adresse*/
	System.out.println("type :"+ this.deuxBits(t, index));
	index += 2;
	System.out.println("class :"+ this.deuxBits(t, index));
	index +=2;
	/*section reliant l'adresse a son adresse canonique*/
	System.out.println("Pointeur vers "+lirechaine(t, index,""));
	index +=2;
	System.out.println("TYPE : CNAME  :"+ this.deuxBits(t, index));
	index +=2;
	System.out.println("Class : Internet  :"+ this.deuxBits(t, index));
	index +=2;
	System.out.println("TTL : "+this.deuxBits(t,index++)+" "+this.deuxBits(t,++index));
	index +=2;
	System.out.println("Nombre d'octets suivants indiquant l'adresse canonique : "+this.deuxBits(t,index));
	int nbOctets = Integer.parseInt(this.deuxBits(t,index));
	index +=2;
	/*traitement des 8 octets suivant*/
	System.out.println(lirechaine(t,index,""));
	index+=nbOctets;
	/*section de lien entre le proxy et l'ip*/
	System.out.println(lirechaine(t,index,""));
	index +=2;
	System.out.println("type :"+ this.deuxBits(t, index));
	index += 2;
	System.out.println("class :"+ this.deuxBits(t, index));
	index +=2;
	System.out.println("TTL : "+this.deuxBits(t,index++)+" "+this.deuxBits(t,++index));
	index +=2;
	System.out.println("Nombre d'octets suivants indiquant l'adresse canonique IP : "+this.deuxBits(t,index));
	nbOctets = Integer.parseInt(this.deuxBits(t,index));
	index +=2;
	/*traitement des 8 octets suivant*/
	System.out.println(lirechaine(t,index,"ip"));
	index+=nbOctets;
	/*Autorite 1 */
	System.out.println("** Autorite 1 **");
	System.out.println("Autorite sur le domaine via pointeur :"+ lirechaine(t, index,""));
	index += 2;	
	System.out.println("type NS :"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("Class : Internet :"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("TTL : "+this.deuxBits(t,index++)+" "+this.deuxBits(t,++index));
	index +=2 ;
	nbOctets = ((t[index])& 0xff)*16 + (t[index+1] & 0xff);
	System.out.println("Nombre d'octets permettant de trouver le nom du Serveur faisant autorite sur le domaine : "+this.deuxBits(t,index)+" soit "+nbOctets+" octets");
	index +=2;
	System.out.println("Serveur faisant autorite sur le domaine : "+lirechaine(t,index,""));

	/* Autorite 2 */
	index+=nbOctets;
	
	System.out.println("\n** Autorite 2 **");
	System.out.println("Autorite sur le domaine via pointeur :"+ lirechaine(t, index,""));
	index += 2;	
	System.out.println("type NS :"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("Class : Internet :"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("TTL : "+this.deuxBits(t,index++)+" "+this.deuxBits(t,++index));
	index +=2;
	nbOctets = ((t[index])& 0xff)*16 + (t[index+1] & 0xff);
	System.out.println("Nombre d'octets permettant de trouver le nom du Serveur faisant autorite sur le domaine : "+this.deuxBits(t,index)+" soit "+nbOctets+" octets");
	index +=2;
	System.out.println("Serveur faisant autorite sur le domaine : "+lirechaine(t,index,""));
	index+=nbOctets;
	/*Description des serveurs de nom */
	/* Serveur de nom de l'autorite 1 */
	System.out.println("\n** Serveur de nom de l'autorite 1 **");
	System.out.println("Serveur de nom : "+lirechaine(t, index, ""));
	index +=2;
		System.out.println("type A (host adress):"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("Class : Internet :"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("TTL : "+this.deuxBits(t,index++)+" "+this.deuxBits(t,++index));
	index +=2 ;
	nbOctets = ((t[index])& 0xff)*16 + (t[index+1] & 0xff);
	System.out.println("Nombre d'octets permettant de trouver l'IP du Serveur de nom : "+this.deuxBits(t,index)+" soit "+nbOctets+" octets");
	index +=2;
	System.out.println("Ip du serveur de nom : "+lirechaine(t,index,"ip"));

	index+=nbOctets;
	/* Serveur de nom de l'autorite 2*/
	System.out.println("\n** Serveur de nom de l'autorite 2 **");
	System.out.println("Serveur de nom : "+lirechaine(t, index, ""));
	index +=2;
		System.out.println("type A (host adress):"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("Class : Internet :"+ this.deuxBits(t, index));
	index += 2;	
	System.out.println("TTL : "+this.deuxBits(t,index++)+" "+this.deuxBits(t,++index));
	index +=2 ;
	nbOctets = ((t[index])& 0xff)*16 + (t[index+1] & 0xff);
	System.out.println("Nombre d'octets permettant de trouver l'IP du Serveur de nom : "+this.deuxBits(t,index)+" soit "+nbOctets+" octets");
	index +=2;
	System.out.println("Ip du serveur de nom : "+lirechaine(t,index,"ip"));
    }



    public byte[] sendMessage(String s) {
	try {
	    /*Numero de port: 53*/
	    int port = 53;
	    /*Creation de l'inetAddress*/
	    InetAddress adresseDest = InetAddress.getByName("172.18.12.9")/*InetAddress.getByName(s).getHostAddress()*/;
	    System.out.println(adresseDest);
	    /*Buffer recu*/
	    byte[] bufferRecu = new byte[1500];	    
	    /*Creation d'un tableau d octets contenant la requete DNS -> On l'initialise avec le header de la requete, fixe*/
	    byte[] requeteDNS = /*{
		(byte)0x08, (byte)0xbb, (byte)0x01, (byte)0x00, 
		(byte)0x00, (byte)0x01, (byte)0x00, (byte)0x00, 
		(byte)0x00, (byte)0x00, (byte)0x00, (byte)0x00, 
		(byte)0x03, (byte)0x77, (byte)0x77, (byte)0x77, 
		(byte)0x04, (byte)0x6c, (byte)0x69, (byte)0x66, 
		(byte)0x6c, (byte)0x02, (byte)0x66, (byte)0x72, 
		(byte)0x00, 
		(byte)0x00, (byte)0x01, (byte)0x00, (byte)0x01};*/
		this.createRequete(s);


	    /*Creation du DatagramPacket envoyeur*/
	    DatagramPacket envoyeur = new DatagramPacket(requeteDNS, requeteDNS.length, adresseDest, port);
	    /*Creation du DatagramPacket receveur*/
	    DatagramPacket receveur = new DatagramPacket(bufferRecu, 1500);
	    /*Creation du DatagramSocket pour envoyer/recevoir*/
	    DatagramSocket esclave = new DatagramSocket(1500); 
	      System.out.println("Envoi");
	    esclave.send(envoyeur);
	    System.out.println("Reception");
	    esclave.receive(receveur);
	    
  /* Section d'affichages differents : a decommenter selon les besoins */
	    System.out.println("Affichage Message");
	    /*Affichage en Hexadecimal*/
	    byte[] btres = new byte[receveur.getLength()];
	     for (int i=0; i<receveur.getLength(); i++) {
		System.out.print(","+Integer.toHexString(receveur.getData()[i] & 0xff));
		if (((i+1) % 16) == 0) System.out.println("");
		btres[i] = (receveur.getData())[i];
		}
	     System.out.println();
	     return btres;
	    /*   System.out.println("Affichage nom de domaine : ");
	    System.out.println(this.lirechaine(receveur.getData(), 12, ""));
	    System.out.println("Affichage adresse proxy : ");
	    System.out.println(this.lirechaine(receveur.getData(), 41, ""));
	    System.out.println("Affichage adresse ip : ");
	    System.out.println(this.lirechaine(receveur.getData(), 61, "ip"));	    
	    System.out.println("Pointeur vers www.lifl.fr ; octet 29 : ");
	    System.out.println(this.lirechaine(receveur.getData(), 29, "")); */
	    /*  System.out.println("\nDecodage du message via la fonction decodeMessage\n");
		this.decodeMessage(receveur.getData()); */
	}
	catch (Exception e) {
	    System.out.println(e.getMessage());
	}
	return (new byte[0]);
    }

    /** Convertit l'adresse du site fournit en chaine de caractere en un tableau de byte
     *@param address l'adresse a convertir
     *@return le tableau de byte correspondant a l'adresse passe en parametre
     */
    public byte[] convertAddress(String address) {
	int cpt = 0;
	int lon = address.length();
	int indexString = lon-1;
	int indexTab = lon;
	String numIp ;
	byte[] res = new byte[lon+1];
	while (indexString>-1) {
	    if (address.charAt(indexString) != '.') {
		cpt++;
		res[indexTab] = (byte)address.charAt(indexString);
		indexString--;
		indexTab--;
	}
	    else {
		res[indexTab] = ((Integer)cpt).byteValue();
		cpt=0;
		indexString--;
		indexTab--;
	    }
	}
	res[indexTab] = ((Integer)cpt).byteValue();
	return res;
    }

    public byte[] createRequete(String address) {
	 byte[] requeteDNSDebut = {
	     (byte)0x08, (byte)0xbb, (byte)0x01, (byte)0x00, 
	     (byte)0x00, (byte)0x01, (byte)0x00, (byte)0x00, 
	     (byte)0x00, (byte)0x00, (byte)0x00, (byte)0x00
	 };
	 byte[] requeteDNSFin={
	     (byte)0x00, 
	     (byte)0x00, (byte)0x01, (byte)0x00, (byte)0x01
	 };
	 byte[] requeteDNSMilieu = this.convertAddress(address);
        
	 int longdebut = requeteDNSDebut.length;
	 int longmilieu = requeteDNSMilieu.length;
	 int longfin = requeteDNSFin.length;
	 byte[] requeteComplete = new byte[longdebut+longmilieu+longfin];
	 for (int i=0; i<longdebut; i++) {
	     requeteComplete[i] = requeteDNSDebut[i];
	 }
	 for (int j=0; j<longmilieu; j++) {
	     requeteComplete[longdebut+j] = requeteDNSMilieu[j];
	 }
	 for (int i=0; i<longfin; i++) {
	     requeteComplete[longdebut+longmilieu+i] = requeteDNSFin[i];
	 }
	 return requeteComplete;
    }

    /** Retourne l'index ou se trouve l'indication de l'adresse IP dans un tableau d'octets renvoye par une requete DNS
     *@param t le tableau d'octets du paquets DNS
     *@return l'indice du tableau ou se trouve l'IP 
     */
    public int findIP(byte[] t) {
	    int index = 0;
	    index+=12; /* on passe l'entete*/
	    index+=(t[index] & 0xff)+1;/*on passe l'adresse internet*/
	    index+=(t[index] & 0xff)+1;
	    index+=(t[index] & 0xff)+1+1/*0 a la fin*/;
	    index+=4;/*on passe type et class*/
	    /*le prochain octet est un pointeur, l'info suivante est 4 octets plus loin*/
	    index+=2;
	    /*suivent Type(2 octets), Class(2octets), TTL(4 octets)*/
	    index+=8;
	    /*le nombre suivant indique le nombre d'octets qui donnent le nom canonique : on les passe aussi*/
	    index+= ((t[index])& 0xff)*16 + (t[index+1] & 0xff)+2;
	    /*le prochain octet est un pointeur vers le nom canonique */
	    index+=2;
	    /*suivent Type(2 octets), Class(2octets), TTL(4 octets)*/
	    index+=8;	    
	    /*le nombre suivant indique le nombre d'octets qui donnent le nom canonique : on les passe aussi*/
	    index+=2 ;
	    /*l'index est maintenant sur le premier octet indiquant l'adresse IP*/
	    return index;
    }


    /** Affiche sur la sortie standard les octets du tableau d'octets passe en parametre
     *@param t le tableau d'octets a afficher
     */
    public void printByteT(byte[] t){
	int cpt= 0;
	for (byte b : t) {
	    String s = Integer.toHexString(b & 0xff);
	    int l = s.length();
	    if (cpt%8 !=0) {
		if (l==2) { System.out.print(s+","); }
		else { System.out.print("0"+s+","); }
	    }
	    else {
		System.out.println("");
		if (l==2) { System.out.print(s+","); }
		else { System.out.print("0"+s+",");}
	    }
	    cpt++;
	}
      } 
	
    /** Main de la class Exo3
     * Execute les fonctions suivantes
     * Convertit l'adresse fournit en parametre en tableau d'octets
     *et l'integre a la requete DNS
     * la requete est envoyee et le message recu en retour est decode et affiche
     * l'adresse ip de retour est affichee ensuite
     */
    public static void main(String[] argv) {
	Exo3 objet = new Exo3();
		try {
		    System.out.println(InetAddress.getByName("www.yahoo.fr").getHostAddress());
	}
	catch (Exception e) { System.out.println("bug addresse");}
	System.out.println("Decodage du message : Question 4\n");
       	byte[] t = objet.sendMessage(argv[0]);
	/*  objet.decodeMessage(t);*/
	System.out.println("\n\n\nTraitement");
	System.out.print("Requete envoyee apres conversion de l'adresse");
        objet.printByteT(objet.createRequete(argv[0]));
	System.out.print("\n\nMessage de retour :");
	objet.printByteT(t);
	System.out.println();
	System.out.println("\nAdresse IP :");
	System.out.println(objet.lirechaine(t,objet.findIP(t), "ip"));

	

    }
}

