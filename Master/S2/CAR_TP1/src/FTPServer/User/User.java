package FTPServer.User;

/**
 * Class which permits to implement a FTP User
 */
public class User {

	/**
	 * Private string which define the name of the user
	 */
	private String username;
	
	/**
	 * Private string which represents the password of the user
	 */
	private String passwd;
	
	/**
	 * Constructor of the User object
	 * @param username The username to set
	 * @param passwd The password to set
	 */
	public User(String username, String passwd) {
		this.username = username;
		this.passwd = passwd;
	}
	
	/**
	 * Second constructor of the User object - without parameters
	 */
	public User() {
	}
	
	/**
	 * Method which allows to get the username attribute
	 * @return The username of the object
	 */
	public String getUsername() {
		return username;
	}

	/**
	 * Method which allows to set the username attribute
	 * @param username The username to set
	 */
	public void setUsername(String username) {
		this.username = username;
	}

	/**
	 * Method which allows to get the password attribute
	 * @return The password of the user
	 */
	public String getPasswd() {
		return passwd;
	}

	/**
	 * Method which allows to set the password attribute
	 * @param passwd The password to set
	 */
	public void setPasswd(String passwd) {
		this.passwd = passwd;
	}
	
	/**
	 * toString method
	 * @return The identity of the user
	 */
	public String toString() {
		return "User: "+this.username;
	}
	
	/**
	 * Equals method
	 * @param object An object to compare to this
	 * @return If the objects have the same attributes, returns True - else False
	 */
	public boolean equals(Object object) {
		if (object instanceof User && ((User) object).getUsername().equals(this.getUsername()) && this.getPasswd().equals(this.getPasswd()))
			return true;
		else
			return false;
	}
	
}
