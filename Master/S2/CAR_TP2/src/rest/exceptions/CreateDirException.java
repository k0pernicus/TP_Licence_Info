package rest.exceptions;

import javax.ws.rs.WebApplicationException;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.Status;

/**
 * Exception throws when the directory creation is not available
 */
public class CreateDirException extends WebApplicationException {
	
	/**
	 * Constructor of the object
	 * @param dirname The directory name
	 */
	public CreateDirException( final String dirname ) {
		super(
			Response
				.status( Status.NOT_FOUND )
				.entity( "Can not create directory: " + dirname )
				.build()
		);
	}
	
}
