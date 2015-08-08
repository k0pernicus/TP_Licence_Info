package rmi.main;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

import rmi.exceptions.RegistryException;
import rmi.rmi.SiteImpl;
import rmi.rmi.SiteItf;

/**
 * Program to initialize completely a node
 */
public class SiteInitializer {

	/**
	 * Main of the program
	 * @param argv The node ID we want to initialize
	 * @exception RemoteException
	 */
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
}
