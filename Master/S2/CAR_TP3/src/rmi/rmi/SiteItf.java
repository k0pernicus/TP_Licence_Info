package rmi.rmi;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

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
	
	/**
	 * Method to return the bool attribute 'isRoot' of the node
	 * @return the isRoot
	 * @throws RemoteException
	 */
	public boolean isRoot() throws RemoteException;
	
	/**
	 * Method to set the bool attribute 'isRoot' of the node
	 * @param isRoot the isRoot to set
	 * @throws RemoteException
	 */
	public void setRoot(boolean isRoot) throws RemoteException;
	
	/**
	 * Method to return the father of the node
	 * @return the father
	 * @throws RemoteException
	 */
	public SiteItf getFather() throws RemoteException;
	
	/**
	 * Method to set the father of the node
	 * @param father the father to set
	 * @throws RemoteException
	 */
	public void setFather(SiteItf father) throws RemoteException;
	
	/**
	 * Method to return sons of the node
	 * @return the sons
	 * @throws RemoteException
	 */
	public ArrayList<SiteItf> getSons() throws RemoteException;
	
	/**
	 * Method to add a single son
	 * @param son A son to add to a father node
	 * @throws RemoteException
	 */
	public void addSon(SiteItf son) throws RemoteException;
	
	/**
	 * Method to set sons of the node
	 * Comment : Sons know the father
	 * @param sons the sons to set
	 * @throws RemoteException
	 */
	public void setSons(ArrayList<SiteItf> sons) throws RemoteException;
	
	/**
	 * Method to return the data of the node
	 * @return The byte array
	 * @throws RemoteException
	 */
	public byte[] getData() throws RemoteException;
	
	/**
	 * Method to set the byte array contains by the node
	 * @param data The data to set
	 * @throws RemoteException
	 */
	public void setData(byte[] data) throws RemoteException;
	
	/**
	 * Method to set the boolean 'allready_received' value
	 * @param bool The boolean to change
	 * @throws RemoteException
	 */
	public void setVisited(boolean bool) throws RemoteException;
	
	/**
	 * Method to reset all flags 'allready_visited'
	 * Use setVisited and send 'false' as parameter
	 * @throws RemoteException
	 */
	public void cleanVisited() throws RemoteException;
	
	/**
	 * Method to send data (a byte array) to sons of node.
	 * When the node receive the data, he will send it to each son.
	 * Also, he will prevent us the good reception of data.
	 * @param data The data to send - a byte array
	 * @throws RemoteException
	 */
    public void sendDataToSon(byte[] data) throws RemoteException;
}
