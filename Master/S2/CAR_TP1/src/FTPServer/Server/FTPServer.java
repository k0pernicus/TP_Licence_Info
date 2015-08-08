package FTPServer.Server;

/*
 * JAVA import
 */
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
/*
 * Class import
 */

/**
 * Class which allows to implement a multi-thread FTP server
 */
public class FTPServer extends Thread {

    /**
     * A list of FTP requests
     */
    public static ArrayList<FTPRequest> ftp_requests = new ArrayList<FTPRequest>();
    
    /**
     * The server socket
     */
    protected ServerSocket socket;


    public FTPServer(int port){
        try {
            this.socket = new ServerSocket(port);
       } catch (IOException e) {
            System.err.println("Problem with the server socket");
            throw new RuntimeException();
        }
    }

    /**
     * Method which allows to run the FTP Server (multi-threading)
     */
    public void run(){
        util.RootFileCSV csv_database = new util.RootFileCSV();

        try {


            while(true) {

                Socket socket_communication = socket.accept();
                FTPRequest request = new FTPRequest(socket_communication, csv_database);
                FTPServer.addFtpRequest(request);
                new Thread(request).start();


            }

        } 
        catch (IOException e) {
            System.err.println("ERROR: "+e.getMessage());
            throw new RuntimeException();
        }
    }

	/**
	 * Method which allows to return all the FTP requests
	 * @return ftp_requests attribute
	 */
	public static ArrayList<FTPRequest> getFtpRequests() {
		return FTPServer.ftp_requests;
	}

	/**
	 * Method which allows to set the FTP requests list
	 * @param new_ftp_requests the ftp_requests to set
	 */
	public static void setFtpRequests(ArrayList<FTPRequest> new_ftp_requests) {
		FTPServer.ftp_requests = new_ftp_requests;
	}
	
	/**
	 * Method to add a FTP request to the ftp_requests attribute
	 * @param ftp_request the FTP request to add in the list
	 */
	public static void addFtpRequest(FTPRequest ftp_request) {
		FTPServer.ftp_requests.add(ftp_request);
	}

}
