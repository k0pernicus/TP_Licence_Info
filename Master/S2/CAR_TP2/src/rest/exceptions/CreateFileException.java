package rest.exceptions;

import javax.ws.rs.WebApplicationException;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.Status;

/**
 * Exception throws when the file creation is not available
 */
public class CreateFileException extends WebApplicationException {
	
	/**
	 * Constructor of the object
	 * @param filename The file name
	 */
	public CreateFileException( final String filename ) {
		super(
			Response
				.status( Status.NOT_FOUND )
				.entity( "Canno't create file: " + filename )
				.build()
		);
	}
	
}
