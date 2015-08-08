package rest.exceptions;

import javax.ws.rs.WebApplicationException;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.Status;

/**
 * Exception throws when the directory is not found
 */
public class DirNotFoundException extends WebApplicationException {
	
	/**
	 * Constructor
	 * @param dirName The directory name
	 */
	public DirNotFoundException( final String dirName ) {
		super(
			Response
				.status( Status.NOT_FOUND )
				.entity( "File not found: " + dirName )
				.build()
		);
	}
	
}
