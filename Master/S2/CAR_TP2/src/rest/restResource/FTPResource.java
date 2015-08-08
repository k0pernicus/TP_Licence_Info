package rest.restResource;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

import javax.ws.rs.DELETE;
import javax.ws.rs.FormParam;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.Status;

import org.apache.commons.net.ftp.FTPFile;

import rest.services.FTPServices;

/**
 * REST link
 * accessible : http://localhost:8080/rest/api/ftp/
 */
@Path("/ftp/")
public class FTPResource {
	
	/*
	 * HTML format
	 */
	static String BEGIN_WEBPAGE = "<!DOCTYPE><head><title>Passerelle-REST</title></head><html>";
	static String END_WEBPAGE = "</html>";
	
	/*
	 * LOGIN
	 */
	static String LOGIN_FORM = "<form action=\"\" method=\"post\"><label for=\"username\">Login</label><input name=\"username\" type=\"text\" />" +
			"<br/><label for=\"passwd\">Password</label><input name=\"passwd\" type=\"password\" /><br/>" +
			"<input type=\"submit\" /></form>";
			
	/*
	 * List
	 */
	static String BEGIN_LIST = "<ul>";
	static String END_LIST = "</ul>";
	static String BEGIN_ENUM = "<li>";
	static String END_ENUM = "</li>";
	
	/*
	 * Title
	 */
	static String BEGIN_BIG_TITLE = "<h1>";
	static String END_BIG_TITLE = "</h1>";
	
	/*
	 * Format text
	 */
	static String NEW_LINE = "</br>";
	static String BEGIN_BIG_TEXT = "<b>";
	static String END_BIG_TEXT = "</b>";
	static String BEGIN_ITA_TEXT = "<i>";
	static String END_ITA_TEXT = "</i>";
	
	static FTPServices ftpServices = new FTPServices();

	/**
	 * Principle screen of the REST application
	 * @return The HTTP response
	 */
	@GET
	@Produces("text/html")
	public Response mainFtp() {
		System.out.println("PROCESS : main");
		String to_return = "";
		if (FTPResource.ftpServices.isConnected()) {
			if (FTPResource.ftpServices.isLogin()) {
				to_return += this.listSpecificDirectory("/");
			}
			else {
				to_return = FTPResource.BEGIN_WEBPAGE;
				to_return += FTPResource.BEGIN_BIG_TITLE + "Connection" + FTPResource.END_BIG_TITLE;
				to_return += FTPResource.LOGIN_FORM;
				to_return += FTPResource.END_WEBPAGE;
			}
		}
		else {
			System.out.println("No possible to connect to the FTP server...");
			to_return = FTPResource.BEGIN_WEBPAGE;
			to_return += FTPResource.BEGIN_BIG_TITLE + "No connection with FTP server!" + FTPResource.END_BIG_TITLE;
			to_return += FTPResource.END_WEBPAGE;
		}
		return Response.ok(to_return).build();
	}
	
	/**
	 * Method to login
	 * @param username The username
	 * @param passwd The password of the user
	 * @return The HTTP response
	 */
	@POST
	@Produces( {MediaType.TEXT_HTML} )
	public Response login(@FormParam("username") final String username,
			@FormParam("passwd") final String passwd) {
		System.out.println("Process: LOGIN");
		String to_return = ""; 
		if (FTPResource.ftpServices.isConnected()){
			if (FTPResource.ftpServices.login(username, passwd)) {
				to_return += this.listSpecificDirectory("/");
			}
			else{
				to_return += FTPResource.BEGIN_WEBPAGE;
				to_return += FTPResource.BEGIN_BIG_TITLE + "Sorry! You're not recognized!" + FTPResource.END_BIG_TITLE;
				to_return += FTPResource.END_WEBPAGE;
			}
		}
		else {
			System.out.println("No possible to connect to the FTP server...");
			to_return += FTPResource.BEGIN_WEBPAGE;
			to_return += FTPResource.BEGIN_BIG_TITLE + "No connection with FTP server!" + FTPResource.END_BIG_TITLE;
			to_return += FTPResource.END_WEBPAGE;
		}
		
		return Response.ok(to_return).build();
	}
	
	/**
	 * Method to list files and directories with a specific directory name
	 * @param directoryName The specific directory name to list files and directories
	 * @return The HTTP response
	 */
	@Produces( {MediaType.TEXT_HTML} )
	@Path("/{directoryName: .+}")
	@GET
	public String listSpecificDirectory(@PathParam( "directoryName" ) final String directoryName) {
		System.out.println("Process: LIST SPECIFIC DIRECTORY FOR " + directoryName);
		String to_return = FTPResource.BEGIN_WEBPAGE;
		to_return += FTPResource.BEGIN_BIG_TITLE + "List " + directoryName +FTPResource.END_BIG_TITLE;
		to_return += FTPResource.BEGIN_LIST;
		if (FTPResource.ftpServices.isLogin()) {
			FTPFile[] ftpFiles = FTPResource.ftpServices.list(directoryName);
			if (directoryName != "/") {
				to_return += FTPResource.BEGIN_ENUM + "<a href=\"../\">" + "../" + "</a>" + FTPResource.END_ENUM;
			}
			for (FTPFile ftpFile : ftpFiles) {
				String line = "";
				String fileName = ftpFile.getName();
				if (ftpFile.isDirectory())
					line += FTPResource.BEGIN_ENUM + "<a href=\"" + fileName + "/" + "\">" + fileName + "/</a>";
				else
					line += FTPResource.BEGIN_ENUM + fileName;
				line += " - size : "+ftpFile.getSize()+" bytes";
				line += FTPResource.END_ENUM;
				to_return += line;
			}
		}
		else {
			System.out.println("Please to login!");
			to_return += "Please to login before list directory...";
		}
		to_return += FTPResource.END_LIST;
		to_return += FTPResource.END_WEBPAGE;
		return to_return;
	}
	
	/**
	 * Method to delete a specific file in the FTP server
	 * @param pathfile The path of the specific file
	 * @return The HTTP response
	 */
	@Path("/deleteFile/{pathfile: .*}")
	@DELETE
	public Response deleteFile( @PathParam( "pathfile" ) final String pathfile ) {
		System.out.println("Process: DELETE SPECIFIC FILE");
		if (FTPResource.ftpServices.isLogin()) {
			FTPResource.ftpServices.deleteFile(pathfile);
			return Response.ok().build();
		}
		else {
			System.out.println("Please to login before delete file...");
			return Response.status(Status.UNAUTHORIZED).entity(new String("Please to login before delete file!")).build();
		}
	}
	
	/**
	 * Method to delete a specific directory in the FTP server
	 * @param dirpath The path of the specific directory
	 * @return The HTTP response
	 */
	@Path("/deleteDir/{dirpath: .*}")
	@DELETE
	public Response deleteDir( @PathParam( "dirpath" ) final String dirpath ) {
		System.out.println("Process : DELETE SPECIFIC DIR");
		if (FTPResource.ftpServices.isLogin()) {
			FTPResource.ftpServices.deleteDir(dirpath);
			return Response.ok().build();
		}
		else {
			System.out.println("Please to login before delete directory...");
			return Response.status(Status.UNAUTHORIZED).entity(new String("Please to login before delete directory!")).build();
		}
	}

	/**
	 * Method to create a specific file in the FTP server
	 * @param filepath The path of the specific file to create
	 * @param filestream The stream of the file to send
	 * @return The HTTP response
	 */
	@Produces( { MediaType.APPLICATION_JSON  } )
	@Path("/createFile")
	@POST
	public Response createFile( @FormParam( "filepath" ) final String filepath, final InputStream filestream ) {
		System.out.println("Process : CREATE FILE");
		if (FTPResource.ftpServices.isLogin()) {
			FTPResource.ftpServices.createFile(filepath, filestream);
			return Response.ok().build();
		}
		else {
			System.out.println("Please to login before create file...");
			return Response.status(Status.UNAUTHORIZED).entity(new String("Please to login before create file!")).build();
		}
	}
	
	/**
	 * Method to create a specific directory in the FTP server
	 * @param dirpath The path of the specific directory to create
	 * @return The HTTP response
	 */
	@Produces( { MediaType.APPLICATION_JSON  } )
	@Path("/createDir")
	@POST
	public Response createDir( @FormParam( "dirpath" ) final String dirpath ) {
		System.out.println("Process : CREATE DIRECTORY");
		if (FTPResource.ftpServices.isLogin()) {
			FTPResource.ftpServices.createDir(dirpath);
			return Response.ok().build();
		}
		else {
			System.out.println("Please to login before create directory...");
			return Response.status(Status.UNAUTHORIZED).entity(new String("Please to login before create directory!")).build();
		}
	}
	
	/**
	 * Method which allows to rename a file
	 * @param filepath The file path to be rename
	 * @param newname The new name of the file
	 * @return The HTTP response
	 */
	@Produces( { MediaType.APPLICATION_JSON  } )
    @Path("/putFile/{pathfile: .*}")
    @PUT
    public Response putFile( @PathParam( "pathfile" ) final String filepath, @FormParam( "newname" ) final String newname) {
        System.out.println("Process : PUT FILE");
            if (FTPResource.ftpServices.isLogin()) {
                FTPResource.ftpServices.putFile(filepath, newname);
                return Response.ok().build();
            }
            else {
                System.out.println("Please to login before create file...");
                return Response.status(Status.UNAUTHORIZED).entity(new String("Please to login before create file!")).build();
            }
    }

    /**
     * Method which get a file from the FTP server
     * @param path The file path
     * @return The HTTP response
     */
    @Produces(MediaType.APPLICATION_OCTET_STREAM)
    @Path("/download/{path: .*}")
    @GET
    public Response getFile(@PathParam("path") String path) {
        if(!FTPResource.ftpServices.isConnected()) {
            return Response.status(Response.Status.FORBIDDEN).build();
        }
        InputStream is = FTPResource.ftpServices.getFile("/" + path);
        if(is == null) {
            return Response.status(Response.Status.NOT_FOUND).build();
        }
        return Response.ok(is).build();
    }
}