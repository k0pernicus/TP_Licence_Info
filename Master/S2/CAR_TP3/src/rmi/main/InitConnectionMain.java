package rmi.main;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import rmi.exceptions.RegistryException;
import rmi.rmi.SiteItf;

/**
 * Program to add a relation between two nodes
 */
public class InitConnectionMain {

	/**
	 * RMI main of the program
	 * @param argv Nodes to add the relation - the first node is the father ID, the second is the son ID
	 * @throws NotBoundException Exception handled when the node done in argv is not found
	 */
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

}
