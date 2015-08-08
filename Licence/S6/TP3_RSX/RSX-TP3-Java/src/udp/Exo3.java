package udp;

import java.lang.*;
import java.util.*;
import java.net.*;

public class Exo3 {

    public static void main(String[] argv) {

	String decodage(byte[] tabBytes) {

	}
	
	try {

	    /*Num�ro de port: 53*/
	    int port = 53;
	    /*Cr�ation de l'inetAddress*/
	    InetAddress adresseDest = InetAddress.getByName("172.18.12.9");
	    /*Buffer re�u*/
	    byte[] bufferRecu = new byte[1500];
	    
	    /*Cr�ation d'un tableau d'octets contenant la requ�te DNS -> On l'initialise avec le header de la requ�te, fixe*/
	    byte[] requeteDNS = {
		(byte)0x08, (byte)0xbb, (byte)0x01, (byte)0x00, 
		(byte)0x00, (byte)0x01, (byte)0x00, (byte)0x00, 
		(byte)0x00, (byte)0x00, (byte)0x00, (byte)0x00, 
		(byte)0x03, (byte)0x77, (byte)0x77, (byte)0x77, 
		(byte)0x04, (byte)0x6c, (byte)0x69, (byte)0x66, 
		(byte)0x6c, (byte)0x02, (byte)0x66, (byte)0x72, 
		(byte)0x00, 
		(byte)0x00, (byte)0x01, (byte)0x00, (byte)0x01};

	    /*Cr�ation du DatagramPacket envoyeur*/
	    DatagramPacket envoyeur = new DatagramPacket(requeteDNS, requeteDNS.length, adresseDest, port);
	    /*Cr�ation du DatagramPacket receveur*/
	    DatagramPacket receveur = new DatagramPacket(bufferRecu, 1500);
	    /*Cr�ation du DatagramSocket pour envoyer/recevoir*/
	    DatagramSocket esclave = new DatagramSocket(1500);

	    esclave.send(envoyeur);
	    esclave.receive(receveur);

	    /*Affichage en Hexad�cimal*/
	    for (int i=0; i<receveur.getLength(); i++) {
		System.out.print(","+Integer.toHexString(receveur.getData()[i] & 0xff));
		if (((i+1) % 16) == 0) System.out.println("");
	    }
	    
	}
	catch (Exception e) {

	    System.out.println(e.getMessage());

	}

    }

}

/*
Lecture de la chaine

int lire_chaine(byte[] t, int offset_debut) {

int i = offset_debut;

while(t[i] > 0) {

   if (t[i] >= 192) { -> POINTEUR
      ...
      ...
      return i+2;
   }
   else {
      i+=(t[i] & 0xff)+1;
   }

}

return i+1;

}
*/