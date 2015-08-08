package rest.exceptions;

import javax.ws.rs.WebApplicationException;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.Status;

/**
 * Exception throws when the file is not found
 */
public class FileNotFoundException extends WebApplicationException {
	
	/**
	 * Constructor
	 * @param filename The file name
	 */
	public FileNotFoundException( final String filename ) {
		super(
			Response
				.status( Status.NOT_FOUND )
				.entity( "File not found: " + filename )
				.build()
		);
	}
	
}
