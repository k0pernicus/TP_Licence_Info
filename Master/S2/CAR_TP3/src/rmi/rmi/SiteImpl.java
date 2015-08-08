package rmi.rmi;

import java.rmi.RemoteException;
import java.rmi.server.RMIClientSocketFactory;
import java.rmi.server.RMIServerSocketFactory;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

/**
 * Implementation of the data transfer mecanism between nodes
 * Each nodes will be implemented in differents virtual machines
 */
public class SiteImpl extends UnicastRemoteObject implements SiteItf {

    /*
     * Attributes
     */
	
	/**
	 * Integer to represent the node object
	 */
	private int id;
	
    /**
     * Attribute to know if the node is root
     * Comment : 'false' is the default setting
     * Comment : The root node doesn't have a father
     */
    private boolean isRoot = false;
    
    /**
     * Attribute to know if the message has been allready transmited
     */
    private boolean allready_received = false;
    
    /** 
     * The father's node
     */
    private SiteItf father;
    
    /**
     * The sons nodes
     */
    private ArrayList<SiteItf> sons;

    /**
     * The data that will store inside the node
     */
    private byte[] data;
    
    /**
     * Default constructor
     * @throws RemoteException
     */
    public SiteImpl() throws RemoteException {
        super();
        this.sons = new ArrayList<SiteItf>();
        System.out.println("Node built!");
    }

    /**
     * Initialize the RMI object with it's ID, it's sons (if the node is not a leaf) and it's father (if the node is not the root)
     * @param id An integer to represent the node
     * @param sons Sons of the node (null if the node is a leaf)
     * @param father Father of the node (null if the node is a root)
     */
    public void init(int id, ArrayList<SiteItf> sons, SiteItf father){
        this.id = id;
        if (sons != null)
        	this.sons = sons;
        if (father != null)
        	this.father = father;
        else
        	this.isRoot = true;
    }

    /**
     * Method to personalize communications, with the specification of the port only
     * @param port Port to communicate
     * @throws RemoteException
     */
    public SiteImpl(int port) throws RemoteException {
        super(port);
    }
    
    /**
     * Method to personalize communications, with the specification of the port & sockets used
     * @param port Port to communicate
     * @param csf Client socket
     * @param ssf Server socket
     * @throws RemoteException
     */
    protected SiteImpl(int port, RMIClientSocketFactory csf,
            RMIServerSocketFactory ssf) throws RemoteException {
        super(port, csf, ssf);
    }

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

	@Override
	public int getId() throws RemoteException {
		return id;
	}

	@Override
	public void setId(int id) throws RemoteException {
		this.id = id;
	}

	@Override
	public boolean isRoot() throws RemoteException {
		return isRoot;
	}

	@Override
	public void setRoot(boolean isRoot) throws RemoteException {
		this.isRoot = isRoot;
	}

	@Override
	public SiteItf getFather() throws RemoteException {
		return this.father;
	}

	@Override
	public void setFather(SiteItf father) throws RemoteException {
		this.father = father;
	}

	@Override
	public ArrayList<SiteItf> getSons() throws RemoteException {
		return this.sons;
	}
	
	@Override
	public void addSon(SiteItf son) throws RemoteException {
		this.sons.add(son);
		son.setFather(this);
	}

	@Override
	public void setSons(ArrayList<SiteItf> sons) throws RemoteException {
		if (sons == null)
			this.sons.clear();
		for (SiteItf son : this.sons)
			son.setFather(this);
	}

	@Override
	public byte[] getData() throws RemoteException {
		return data;
	}

	@Override
	public void setData(byte[] data) throws RemoteException {
		this.data = data;
	}

	@Override
	public void cleanVisited() throws RemoteException {
		for (SiteItf son : this.sons) {
			son.cleanVisited();
		}
		this.setVisited(false);
	}

	@Override
	public void setVisited(boolean bool) throws RemoteException {
		this.allready_received = bool;
	}

}
