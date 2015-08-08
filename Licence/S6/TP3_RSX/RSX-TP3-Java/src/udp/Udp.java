package udp;
import java.lang.*;
import java.net.*;

public class Udp {

    public static void main(String[] argv) {

	try {

	    /*Numéro de port: 53*/
	    int port = 53;
	    /*Création de l'inetAddress*/
	    InetAddress adresseDest = InetAddress.getByName("193.49.225.15");
	    /*Message à envoyer*/
	    byte[] message = {(byte)0x08,(byte)0xbb,(byte)0x01,(byte)0x00,(byte)0x00,(byte)0x01,(byte)0x00,(byte)0x00,(byte)0x00,(byte)0x00,(byte)0x00,(byte)0x00,(byte)0x03,(byte)0x77,(byte)0x77,(byte)0x77,(byte)0x04,(byte)0x6c,(byte)0x69,(byte)0x66,(byte)0x6c,(byte)0x02,(byte)0x66,(byte)0x72,(byte)0x00,(byte)0x00,(byte)0x01,(byte)0x00,(byte)0x01};
	    /*Buffer reçu*/
	    byte[] bufferRecu = new byte[1500];
	    /*Création du DatagramPacket pour envoyer*/
	    DatagramPacket envoie = new DatagramPacket(message, 29, adresseDest, port);
	    /*Création du DatagramPacket receveur*/
	    DatagramPacket recoit = new DatagramPacket(bufferRecu, 1500);
	    /*Créaton du DatagramSocket -> Envoie et reçoit sur la ligne*/
	    DatagramSocket esclave = new DatagramSocket(1500);

	    /*Envoie et reçoitx*/
	    esclave.send(envoie);
	    esclave.receive(recoit);

	    /*Affichage en Hexadécimal*/
	    for (int i=0; i<recoit.getLength(); i++) {
		System.out.print(","+Integer.toHexString(recoit.getData()[i] & 0xff));
		if (((i+1) % 16) == 0) System.out.println("");
	    }

	}
	catch (Exception e) {
	    
	    System.out.println(e.getMessage());
	
	}

    }

}
