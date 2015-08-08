package rest.services;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import org.apache.commons.net.ftp.FTPClient;
import org.apache.commons.net.ftp.FTPFile;
import org.apache.commons.net.ftp.FTPReply;

import rest.exceptions.CreateDirException;
import rest.exceptions.CreateFileException;
import rest.exceptions.DirNotFoundException;
import rest.exceptions.FileNotFoundException;

/**
 * Class to implement a FTP Client
 */
public class FTPServices {

    /**
     * Hostname of the client
     */
    static final String hostname = "127.0.0.1";

    /**
     * Port to login
     */
    static final int port = 1025;

    /**
     * FTP client - usage of commons-net
     */
    private FTPClient ftpClient;

    /**
     * Attribute to know if the user (recognized by the attribute user) is login
     */
    private boolean login = false;

    /**
     * Constructor of the FTPServices object
     */
    public FTPServices() {
        this.ftpClient = new FTPClient();
        System.out.println("New FTPClient OK!");
        try {
            System.out.println("Connection...");
            this.ftpClient.connect(FTPServices.hostname, FTPServices.port);
            System.out.println("Connection OK!");
            int reply = this.ftpClient.getReplyCode();
            if (FTPReply.isPositiveCompletion(reply)) {
                this.ftpClient.enterLocalActiveMode();
                System.out.println("FTP client : connected! Hostname : "+FTPServices.hostname+", Port : "+FTPServices.port);
            }
            else {
                System.out.println("ERROR : Failed to connect to "+FTPServices.hostname);
            }
        } catch (IOException e) {
            System.out.println("ERROR : Failed to instantiate FTP client!");
            return;
        }
    }

    /**
     * Method to close the FTP client
     */
    public void quit() {
        if (this.ftpClient.isConnected()) {
            try {
                this.ftpClient.disconnect();
            } catch (IOException e) {
                System.out.println("ERROR : Failed to disconnect!");
            }
        }
    }

    /**
     * Method to login the user - if the login is ok, we save the username
     * @param username The username
     * @param passwd The password
     */
    public boolean login(String username, String passwd) {
        try {
            if (this.ftpClient.login(username, passwd)) {
                this.login = true;
                System.out.println("LOGIN : OK!");
                return true;
            }
            else {
                System.out.println("LOGIN : Bad username/passwd");
                return false;
            }
        } catch (IOException e) {
            System.out.println("ERROR : Failed to login!");
            return false;
        }
    }

    /**
     * Method to know if the FTP client is connected or not
     * @return A boolean - True if the client is connected, else False
     */
    public boolean isConnected() {
        return this.ftpClient.isConnected();
    }

    /**
     * Method to know if the user is actually login
     * @return A boolean - True if the user is login, else False
     */
    public boolean isLogin() {
        return this.login;
    }

    /**
     * Method to list files and directories in the specific directory gave in parameter
     * @param directoryName The pathname of the specific directory to list
     * @return A list of strings which represents the name of files and directories
     */
    public FTPFile[] list(final String directoryName) {
        FTPFile[] ftpFiles = null;
        try {
            if (directoryName == "../") {

            }
            ftpFiles = this.ftpClient.listFiles(directoryName);
        } catch (IOException e) {
            System.out.println("ERROR : Not possible to list files and directories!");
        }
        return ftpFiles;
    }

    /**
     * Method to delete a specific file, given by his name
     * @param filename The file to delete (his pathname)
     * @throws FileNotFoundException Exception if the filename is not found in the FTP server
     */
    public void deleteFile(final String pathfile) {
        try {
            this.ftpClient.deleteFile(pathfile);	
        } catch (IOException e) {
            throw new FileNotFoundException(pathfile);
        }
    }

    /**
     * Method to delete a specific directory, given by his name
     * @param dirName The directory to delete (his pathname)
     */
    public void deleteDir(final String dirpath) {
        try {
            this.ftpClient.removeDirectory(dirpath);
        } catch (IOException e) {
            throw new DirNotFoundException(dirpath);
        }
    }

    /**
     * Method to create a file, given by his name
     * @param pathfile The file to create (his pathname)
     * @param local The input stream of the created file
     */
    public void createFile(final String pathfile, final InputStream local) {
        try {
            this.ftpClient.storeFile(pathfile, local);
        } catch (IOException e) {
            throw new CreateFileException(pathfile);
        }
    }

    /**
     * Method to create a directory, given by his name
     * @param dirpath The directory to create (his pathname)
     */
    public void createDir(final String dirpath) {
        try {
            this.ftpClient.makeDirectory(dirpath);
        } catch (IOException e) {
            throw new CreateDirException(dirpath);
        }
    }

    /**
     * Method to add a file, given by his name 
     * @param pathfile The file to store (his pathname)
     * @param local The input stream of the created file
     * @throws CreateFileException Exception if the file canno't be created
     */
    public void putFile(final String pathfile, final String newname) {
        String tmp = pathfile.substring(0, pathfile.lastIndexOf('/')) + "/"+newname + pathfile.substring(pathfile.lastIndexOf('.'));
        try {
           this.ftpClient.rename(pathfile, tmp);
            System.out.println(tmp);
        } catch (IOException e) {
            throw new CreateFileException(pathfile);
        }
    }

    /**
     * Get a file from the FTP server
     * @param filename The file to be get
     * @return A stream of the file
     */
    public InputStream getFile(String filename) {
        try {
            return this.ftpClient.retrieveFileStream(filename);
        } catch (IOException e) {
            return null;
        }
    }
    
}