package test;

import static org.junit.Assert.*;

import java.rmi.RemoteException;
import java.util.ArrayList;

import org.junit.Test;

import rmi.rmi.SiteImpl;
import rmi.rmi.SiteItf;

public class SiteImplTest {

	@Test
	public void testSiteImpl() throws RemoteException{
		SiteItf node0 = new SiteImpl();
		assertNotNull("The test must show that the SiteImpl object is not null.", node0);
	}

	@Test
	public void testInit() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		SiteImpl node1 = new SiteImpl();
		ArrayList<SiteItf> all_sons = new ArrayList<SiteItf>();
		all_sons.add(node1);
		node0.init(0, all_sons, null);
		node1.init(1, null, node0);
		assertEquals("The test must show that the node0 ID is equals to 0.", node0.getId(), 0);
		assertEquals("The test must show that the node1 ID is equals to 1.", node1.getId(), 1);
		assertTrue("The test must show that the son of node0 is equals to node1.", node0.getSons().contains(node1));
		assertEquals("The test must show that there is no son for node1.", node1.getSons().size(), 0);
		assertEquals("The test must show that the node0 is a father.", node0.getFather(), null);
		assertEquals("The test must show that the node1 is not a father.", node1.getFather(), node0);
	}

	@Test
	public void testSendDataToSon() throws RemoteException, InterruptedException{
		SiteImpl node0 = new SiteImpl();
		SiteImpl node1 = new SiteImpl();
		SiteImpl node2 = new SiteImpl();
		SiteImpl node3 = new SiteImpl();
		SiteImpl node4 = new SiteImpl();
		SiteImpl node5 = new SiteImpl();
		SiteImpl node6 = new SiteImpl();
		ArrayList<SiteItf> sons_of_node0 = new ArrayList<SiteItf>();
		ArrayList<SiteItf> sons_of_node1 = new ArrayList<SiteItf>();
		ArrayList<SiteItf> sons_of_node2 = new ArrayList<SiteItf>();
		ArrayList<SiteItf> sons_of_node5 = new ArrayList<SiteItf>();
		sons_of_node0.add(node1);
		sons_of_node0.add(node2);
		sons_of_node1.add(node3);
		sons_of_node1.add(node4);
		sons_of_node2.add(node5);
		sons_of_node5.add(node6);
		
		/*
		 * ====TEST ARCHITECTURE====
		 * 
		 * 			node0
		 * 		   /	 \
		 * 		  /		  \
		 * 		node1	 node2
		 * 	   /    \        \
		 *   node3  node4     node5
		 *   					|
		 *   				  node6
		 * 
		 */
		
		node0.init(0, sons_of_node0, null);
		node1.init(1, sons_of_node1, node0);
		node2.init(2, sons_of_node2, node0);
		node3.init(3, null, node1);
		node4.init(4, null, node1);
		node5.init(5, sons_of_node5, node2);
		node6.init(6, null, node5);
		
		/*
		 * assert NULL
		 */
		
		assertNull("The test must show that the node0 doesn't have any byte array when he has been initialized", node0.getData());
		assertNull("The test must show that the node1 doesn't have any byte array when he has been initialized", node1.getData());
		assertNull("The test must show that the node2 doesn't have any byte array when he has been initialized", node2.getData());
		assertNull("The test must show that the node3 doesn't have any byte array when he has been initialized", node3.getData());
		assertNull("The test must show that the node4 doesn't have any byte array when he has been initialized", node4.getData());
		assertNull("The test must show that the node5 doesn't have any byte array when he has been initialized", node5.getData());
		assertNull("The test must show that the node6 doesn't have any byte array when he has been initialized", node6.getData());
		
		byte[] byte_array = "0xCAFE".getBytes();
		
		node0.sendDataToSon(byte_array);
		
		Thread.sleep(2000L);
		
		/*
		 * assert NOT NULL
		 */

		assertNotNull("The test must show that the node0 has received the byte array sent by node0", node0.getData());
		assertNotNull("The test must show that the node1 has received the byte array sent by node0", node1.getData());
		assertNotNull("The test must show that the node2 has received the byte array sent by node0", node2.getData());
		assertNotNull("The test must show that the node3 has received the byte array sent by node0", node3.getData());
		assertNotNull("The test must show that the node4 has received the byte array sent by node0", node4.getData());
		assertNotNull("The test must show that the node5 has received the byte array sent by node0", node5.getData());
		assertNotNull("The test must show that the node6 has received the byte array sent by node0", node6.getData());
		assertEquals("The test must show that the node6 has received the byte array sent by node0", node6.getData(), byte_array);
		
	}

	@Test
	public void testGetId() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		node0.init(0, null, null);
		assertEquals("The test must show that the node0 ID is equals to 0.", node0.getId(), 0);
	}

	@Test
	public void testSetId() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		node0.init(0, null, null);
		node0.setId(1);
		assertEquals("The test must show that the node0 ID has changed to 1.", node0.getId(), 1);
	}

	@Test
	public void testIsRoot() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		node0.init(0, null, null);
		assertEquals("The test must show that the node0 is root.", node0.isRoot(), true);
	}

	@Test
	public void testSetRoot() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		node0.init(0, null, null);
		node0.setRoot(false);
		assertFalse("The test must show that the node0 is root.", node0.isRoot());
	}

	@Test
	public void testGetFather() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		SiteImpl node1 = new SiteImpl();
		ArrayList<SiteItf> all_sons = new ArrayList<SiteItf>();
		all_sons.add(node1);
		node0.init(0, all_sons, null);
		node1.init(1, null, node0);
		assertEquals("The test must show that there is no father for the node0.", node0.getFather(), null);
		assertEquals("The test must show that the father of the node1 is node0.", node1.getFather(), node0);
	}

	@Test
	public void testSetFather() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		SiteImpl node1 = new SiteImpl();
		SiteImpl node2 = new SiteImpl();
		ArrayList<SiteItf> sons_of_node0 = new ArrayList<SiteItf>();
		ArrayList<SiteItf> sons_of_node1 = new ArrayList<SiteItf>();
		sons_of_node0.add(node1);
		sons_of_node1.add(node2);
		node0.init(0, sons_of_node0, null);
		node1.init(1, sons_of_node1, node0);
		node2.init(2, null, node1);
		node2.setFather(node0);
		node1.setSons(null);
		assertEquals("The test must show that we can change the father of the node2.", node2.getFather(), node0);
	}

	@Test
	public void testGetSons() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		SiteImpl node1 = new SiteImpl();
		SiteImpl node2 = new SiteImpl();
		ArrayList<SiteItf> sons_of_node0 = new ArrayList<SiteItf>();
		ArrayList<SiteItf> sons_of_node1 = new ArrayList<SiteItf>();
		sons_of_node0.add(node1);
		sons_of_node1.add(node2);
		node0.init(0, sons_of_node0, null);
		node1.init(1, sons_of_node1, node0);
		node2.init(2, null, node1);
		assertEquals("The test must show that we have correct sons of the node0.", node0.getSons(), sons_of_node0);
		assertEquals("The test must show that we have correct sons of the node1.", node1.getSons(), sons_of_node1);
	}

	@Test
	public void testAddSon() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		SiteImpl node1 = new SiteImpl();
		SiteImpl node2 = new SiteImpl();
		node0.setId(0);
		node1.setId(1);
		node2.setId(2);
		node0.addSon(node1);
		node1.addSon(node2);
		assertEquals("The test must show that node1 is the son of node0", node0.getSons().get(0), node1);
		assertEquals("The test must show that node2 is the son of node1", node1.getSons().get(0), node2);
	}

	@Test
	public void testSetSons() throws RemoteException{
		SiteImpl node0 = new SiteImpl();
		ArrayList<SiteItf> sons_of_node0 = new ArrayList<SiteItf>();
		node0.setId(0);
		node0.setSons(sons_of_node0);
		assertEquals("The test must show that we can set sons of a node.", node0.getSons(), sons_of_node0);
	}

}
