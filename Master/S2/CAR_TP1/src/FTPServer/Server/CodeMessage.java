package FTPServer.Server;

/**
 * Enumeration which permits to list FTP message codes
 */
public enum CodeMessage {
	/**
	 * CODE_125 : "Data connection already open; transfer starting."
	 */
    CODE_125, 
    /**
     * CODE_200 : "Action successfully completed."
     */
    CODE_200, 
    /**
     * CODE_215 : Open message - no default message.
     */
    CODE_215,
    /**
     * CODE_220 : "Service ready."
     */
    CODE_220,
    /**
     * CODE_221 : "Service ready."
     */
    CODE_221,
    /**
     * CODE_225 : "Service closing control connection."
     */ 
    CODE_225,
    /**
     * CODE_226 : "Data connection open; no transfer in progress."
     */
    CODE_226,
    /**
     * CODE_257 : "PATHNAME created."
     */
    CODE_257,
    /**
     * CODE_331 : "User name okay, need password."
     */
    CODE_331, 
    /**
     * CODE 500 : "The command was not accepted and the requested action did not take place."
     */
    CODE_500, 
    /**
     * CODE_502 : "Command not implemented."
     */
    CODE_502, 
    /**
     * CODE_503 : "Bad sequence of commands."
     */
    CODE_503,
    /**
     * CODE_530 : "Not logged in."
     */
    CODE_530,
    /**
     * CODE_550 : "File unavailable."
     */
    CODE_550
}
