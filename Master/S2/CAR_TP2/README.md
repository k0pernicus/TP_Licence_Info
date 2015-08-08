# CAR_TP2 - Passerelle REST

Auteurs
-------  
Antonin Carette / Alexandre Verkyndt

Remarques
---------
Ce projet utilise une librairie externe à celles données initialement : commons-net.  
Elle permet d'instancier facilement un client FTP.

Liste des fichiers
------------------
*	*README.md*		Fichier 'lisez-moi' du projet
*	*active_ftp_server.sh*	Script permettant de lancer le serveur FTP (voir **FTPServer/FTPServer.py**)
*	**src/**		Sources
*	**src/rest/**		Sources de la passerelle REST
*	**src/rest/config**		Sources de la configuration de la passerelle REST
*	**src/rest/exceptions**		Sources des exceptions du projet
*	**src/rest/main**		Source du main du projet
*	**src/rest/restResource**		Sources des ressources de la passerelle REST
*	**src/rest/rs**		Sources de l'API (non-utilisées)
*	**src/rest/services**		Sources des services de la passerelle REST
*	**src/test/**		Sources des exemples pour l'implémentation de la passerelle REST
*	**FTPServer/**		Sources du serveur FTP (en Python)

Code Samples
------------

*	RestStarter.java : Classe permettant de lancer la passerelle REST. On lancera la passerelle sur le serveur FTP, configuré pour fonctionner sur localhost/ au port 1025.
	```
	...

	public class RestStarter {
		
		public static void main( final String[] args ) throws Exception {
			Server server = new Server( 8080 );
			        
	 		// Register and map the dispatcher servlet
	 		final ServletHolder servletHolder = new ServletHolder( new CXFServlet() );
	 		final ServletContextHandler context = new ServletContextHandler(); 		
	 		context.setContextPath( "/" );
	 		context.addServlet( servletHolder, "/rest/*" ); 	
	 		context.addEventListener( new ContextLoaderListener() );
	 		
	 		context.setInitParameter( "contextClass", AnnotationConfigWebApplicationContext.class.getName() );
	 		context.setInitParameter( "contextConfigLocation", AppConfig.class.getName() );
	 		 		
	        server.setHandler( context );
	        server.start();
	        server.join();
		}
	}	
	```
*	FTPResource.java : Classe contenant toutes les ressources disponibles pour la passerelle et communiquer activement avec le serveur FTP. La communication pourra se faire par le navigateur web (Firefox, Chrome, etc...) ou alors par le terminal, via le programme cURL par exemple. Tout celà pourra se faire avec GET (accéder à des ressources, télécharger un fichier), POST (se logger, créer un fichier), PUT (mise-à-jour d'un fichier) ou DELETE (suppression d'un fichier/dossier).
	```
	@Path("/ftp/")
	public class FTPResource {
		
		...
		
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
		
		...
	
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
	
	...
	}
	```

*	FTPServices.java : Classe permettant d'accéder à tous les services internes de la passerelle REST, d'après les requêtes envoyées par l'utilisateur. Ces méthodes utilisera un client JAVA d'après la librairie JAVA *commons.net*. Ces ressources pourront renvoyer des exceptions s'il y a besoin (présents dans *rest/exceptions*).
	```
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
		
		...
		
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
		
		...
		
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
		
		...	
	}
	```

Utilisation
-----------
*	lancez le serveur FTP python ```chmod +x active_ftp_server.sh && ./active_ftp_server.sh``` 
*	lancez le programme **RestStarter** : ```java -jar tp02-carette-antonin-verkyndt-alexandre.jar```
*	connectez-vous avec votre navigateur favori (Mozilla Firefox powaaaa) sur ```http://localhost:8080/rest/api/ftp/```
*	utilisez-le, hackez-le, etc...

Utilisation des requêtes via le terminal
----------------------------------------
Dans votre terminal :
*	GET : ```curl http://localhost:8080/rest/api/ftp```
*	POST : ```curl --data "username=XXX&passwd=XXX" http://localhost:8080/rest/api/ftp/login```
*	DELETE : ```curl -X DELETE http://localhost/8080/rest/api/ftp/deleteFile/XXX```
*	PUT : ```curl -X -d "filepath=XXX" PUT http://localhost:8080/rest/api/ftp/putFile```