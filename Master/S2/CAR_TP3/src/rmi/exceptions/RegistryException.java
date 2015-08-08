package rmi.exceptions;

/**
 * Exception handled when the registry location is not available
 */
public class RegistryException extends Exception {

	@Override
	public String getMessage() {
		return "ERROR : can not locate the registry.";
	}
	
}
