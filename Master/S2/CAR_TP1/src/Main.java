import FTPServer.Server.FTPServer;


public class Main {

    
    
    public static void main(String[] args) {

        FTPServer server = new FTPServer(4000);
        server.start();

    }

}
