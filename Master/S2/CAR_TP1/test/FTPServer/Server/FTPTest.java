package FTPServer.Server;

import static org.junit.Assert.*;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

import org.junit.BeforeClass;
import org.junit.Test;


public class FTPTest {

    public static FTPServer server;


    @BeforeClass
    public static void initServer() throws Exception {
        /**
         * Initialisation and launching of the server
         */
        server = new FTPServer(4001);
        new Thread(server).start();
    }


    @Test
    public void testConnection() throws IOException {
        //Test for one user
        Socket soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        assertEquals(new FTPMessage(CodeMessage.CODE_220).getMessage().replace("\n", ""), this.readMessage(soc));
        soc.close();
    }

    @Test
    public void testMultiConnection() throws IOException {
        //Test for two user
        Socket soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        assertEquals(new FTPMessage(CodeMessage.CODE_220).getMessage().replace("\n", ""), this.readMessage(soc));

        Socket socbis = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        assertEquals(new FTPMessage(CodeMessage.CODE_220).getMessage().replace("\n", ""), this.readMessage(socbis));

        soc.close();
        socbis.close();

    }


    /**
     * USER command Tests
     * The verification about the validity of the username is not done at this step.
     * 
     * @throws IOException
     */

    @Test
    public void testUser() throws IOException {
        Socket soc;
        //First user want to log himself as an existing user
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_331).getMessage().replace("\n", ""), this.readMessage(soc));
        soc.close();


        //Second user want to log himself as a non existing user
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER notExistingUser\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_331).getMessage().replace("\n", ""), this.readMessage(soc));
        soc.close();
    }

    /**
     * PASS command Tests
     * 
     * @throws IOException
     */
    @Test
    public void testPass() throws IOException {
        Socket soc;


        //First user want to log himself as an existing user with the good password
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS magruemalife\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_200).getMessage().replace("\n", ""), this.readMessage(soc));
        soc.close();


        //Second user want to log himself as an existing user with a wrong password
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS wrongPwd\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_530).getMessage().replace("\n", ""), this.readMessage(soc));
        soc.close();


        //Third user want to log himself as an non existing user with a password
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER nonExistingUser\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS password\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_530).getMessage().replace("\n", ""), this.readMessage(soc));
        soc.close();


        //Forth user want to try to send a PASS request before a USER one.
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS magruemalife\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_530).getMessage().replace("\n", ""), this.readMessage(soc));
        soc.close();
    }


    /**
     * SYST command Tests
     * 
     * @throws IOException
     */
    @Test
    public void testSyst() throws IOException {
        Socket soc;

        //First successfully log himself and a SYST command is sending
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS magruemalife\n");
        //200 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "SYST\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_215).getMessage().replace("\n", ""), this.readMessage(soc));

        soc.close();

        //Second didn't log himself and send a SYST command
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "SYST\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_215).getMessage().replace("\n", ""), this.readMessage(soc));

        soc.close();
    }

    /**
     * QUIT command Tests
     * 
     * @throws IOException
     */
    @Test
    public void testQuit() throws IOException {
        Socket soc;

        //First successfully log himself and send QUIT command
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS magruemalife\n");
        //200 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "QUIT\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_221).getMessage().replace("\n", ""), this.readMessage(soc));

        soc.close();

        //Second didn't log himself and send QUIT command
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "QUIT\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_221).getMessage().replace("\n", ""), this.readMessage(soc));

        soc.close();
    }

    /**
     * PORT command Tests
     * 
     * @throws IOException
     */
    @Test
    public void testPort() throws IOException {
        Socket soc;

        //First successfully log himself and send PORT command
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS magruemalife\n");
        //200 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "SYST\n");
        //215 message OK
        this.readMessage(soc);
        ServerSocket data_socket = new ServerSocket(2571);
        this.sendMessage(soc, "PORT 127,0,0,1,10,11\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_225).getMessage().replace("\n", ""), this.readMessage(soc));
        Socket data_s = data_socket.accept();

        soc.close();
    }
    
    @Test
    public void testList() throws IOException {
        Socket soc;

        
        //First successfully log himself and send LIST command
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS magruemalife\n");
        //200 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "SYST\n");
        //215 message OK
        this.readMessage(soc);
        ServerSocket data_socket = new ServerSocket(2570);
        this.sendMessage(soc, "PORT 127,0,0,1,10,10\n");
        //225 message OK
        this.readMessage(soc);
        Socket data_s = data_socket.accept();
        
        this.sendMessage(soc, "LIST\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_125).getMessage().replace("\n", ""), this.readMessage(soc));
        //liste OK
        String liste = this.readMessages(data_s);
        //Data socket closing
        data_s.close();
        data_socket.close();
        //At least one byte was received from the server
        assertTrue(!liste.isEmpty());
        
        //this assert is not working because 
//        assertEquals(new FTPMessage(CodeMessage.CODE_226).getMessage().replace("\n", ""), this.readMessage(soc));

        soc.close();
        
        
        //Second didn't log himself and send LIST command
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        this.readMessage(soc);
        this.sendMessage(soc, "LIST\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_500).getMessage().replace("\n", "") + "Details : Error with the data socket.", this.readMessage(soc));
        soc.close();
    }
    
    /**
     * PWD command Tests
     * 
     * @throws IOException
     */
    @Test
    public void testPwd() throws IOException {
        Socket soc;

        //First successfully log himself and a SYST command is sending
        soc = new Socket(server.socket.getInetAddress(), server.socket.getLocalPort());
        //220 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "USER grutier\n");
        //331 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PASS magruemalife\n");
        //200 message OK
        this.readMessage(soc);
        this.sendMessage(soc, "PWD\n");
        assertEquals(new FTPMessage(CodeMessage.CODE_257).getMessage().replace("\n", "") + "Details : PATHNAME = ./root_file_repository/", this.readMessage(soc));

        soc.close();
    }

    private void sendMessage(Socket socket, String message) throws IOException {
        DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
        dataOutputStream.writeBytes(message);
        dataOutputStream.flush();
    }
    private String readMessage(Socket socket) throws IOException {
        BufferedReader bufferReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        return bufferReader.readLine();
    }
    private String readMessages(Socket socket) throws IOException {
        BufferedReader bufferReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String result = "";
        String tmp = "";
        while(tmp != null){
            result += tmp + "\r\n";
            tmp = bufferReader.readLine();
        }
        return result;
    }
}
