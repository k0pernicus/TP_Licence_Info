package rmi.main;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import rmi.exceptions.RegistryException;
import rmi.rmi.SiteImpl;
import rmi.rmi.SiteItf;

/**
 * Program to send a byte array (default or text message) to a specific node
 */
public class SendMessage {

	/**
	 * Main of the program
	 * @param argv The ID of the node to send first the message, and a text message (by default "HelloWorld")
	 * @throws NotBoundException 
	 */
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
}
