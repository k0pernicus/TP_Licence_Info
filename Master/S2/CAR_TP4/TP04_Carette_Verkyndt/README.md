CAR_TP4
=======
-------

# Auteurs

Carette Antonin / Verkyndt Alexandre

# Remarque

La validation finale de la commande pose problème - le temps ne nous a pas permit de mettre à jour ce problème, avant l'heure du rendu.

# Sommaire

* [Sources](#sources)
* [Code samples](#code_samples)
  * [Web](#web_code_samples)
  * [Entities](#entities_code_samples)
  * [Servlets](#servlets_code_samples)
  * [Sessions](#sessions_code_samples)
* [Utilisation](#utilisation)
* [Remarques](#remarques)

###<a name="sources"></a>Sources

*	**README.md** : fichier README du projet
*	**dist/javadoc/** : la documentation du projet
*	**src/** : sources du projet, concernant 'entity', 'session' et 'servlet'
*	**web/** : sources .JSP du projet
*	**web/css/** : source .css du projet
*	**web/img/** : source image du projet

###<a name="code_samples"></a>Code samples

Quelques *code samples*...

####<a name="web_code_samples"></a>Web

##### index.html

Simple page HTML permettant à l'utilisateur de se logger.  
Il y a 3 possibilités:
* se logger en tant qu'anonyme et ne consulter que la liste de livres, auteurs, etc...
* se logger en tant que client et pouvoir consulter la liste de livres, auteurs, ... mais aussi d'ajouter des livres dans son panier pour le valider par la suite
* se logger en tant que *admin* et pouvoir faire la totalité des opérations, sur la base de données également.

Pour se logger en tant que *admin*, login: admin / password: n'importe-quoi...

```
<fieldset>
       <legend>Authentification</legend>
           <form method="post" action="VerifAuthServlet">    
               <table>
                   <tr>
                       <td>
                           Login:
                       </td>
                       <td>
                           <input type="text" name="login"/>
                       </td>
                   </tr>
                   <tr>
                       <td>
                           Password:
                       </td>
                       <td>
                           <input type="text" name="password" />
                       </td>
                   </tr>
                   <tr>
                       <td>
                       </td>
                       <td>
                           <input type=submit value="connect">
                       </td>
                   </tr>
               </table>
           </form>
           </br>
           <center>
           <a href="new_account.html">Create new account...</a>
           <br/>
           <a href="menu.html">Anonymous ? This way...</a>
           </center>
</fieldset>
```
##### new_account.html

Simple page HTML permettant à l'utilisateur de créer un compte utilisateur ou administrateur.

```
<fieldset>
            <legend>New account</legend>
            <form method="post" action="AddClient">
                <table>
                    <tr>
                        <td>
                            Your login:
                        </td>
                        <td>
                            <input type="text" name="login" />
                        </td>
                    </tr>
                    <tr>
                        <td>
                            Your password:
                        </td>
                        <td>
                            <input type="text" name="password" />
                        </td>
                    </tr>
                    <tr>
                        <td></td>
                        <td>
                            <input type=submit value="Create">
                        </td>
                    </tr>
                </table>
            </form>
</fieldset>
```

##### menu.html

Simple page HTML permettant de choisir entre plusieurs fonctionnalités:
* ajouter un livre à la base de données,
* obtenir la connaissance de tous les auteurs des livres contenus dans la base de données,
* obtenir la liste de tous les titres de livres contenus dans la base de données ET la possibilité d'en supprimer un de la base,
* obtenir la liste de tous les utilisateurs loggés,
* obtenir la liste de tous les livres contenus dans le panier.
Chaque fonctionnalité sera une **.jsp** à elle seule!

```
<body>
    <div id="menu_appplications">
        <fieldset>
        <legend>List of available applications</legend>
            <ul id="list_applications">
                <li><a href="form_book.jsp">Register an amazing book</a></li>
                <li><a href="Authors">List all of our amazing authors</a></li>
                <li><a href="BooksTitles">List all of our amazing books</a></li>
                <li><a href="ClientLogins">See all of our amazing users</a></li>
                <li><a href="ShowMyBasket">See your amazing basket</a></li>
                <li><a href="index.html">Back to authentification page</a></li>
            </ul>
        </fieldset>
    </div>
</body>
```

##### form_book.jsp

Simple page JSP contenant un formulaire pointant sur une servlet (*AddBook*), permettant d'ajouter un livre (dont l'ID sera son titre) dans la base de données.  
Aussi, un lien permettra de retourner dans la *homepage* afin de continuer d'utiliser l'application comme il le voudra.

```
<form method="post" action="AddBook">
    <p>Title: <input type="text" name="title" /></p>
    <p>Author: <input type="text" name="author" /></p>
    <p>Parution year: <input type="text" name="parution_year" /></p>
    <input type=submit value="Add to DB">
</form>
            
<br/>
        
<a href="menu.html">Return to the homepage...</a> 
```

##### print_book.jsp

Simple page JSP permettant d'afficher toutes les informations nécessaires d'un livre.

```
Book's title :
<%= request.getParameter("title") %>
</br>

<!--
Permettra de demander à la requête quel est le résultat de 'auteur'
-->
Book author :
<%= request.getParameter("author") %>
</br>

<!--
Permettra de demander à la requête quel est le résultat de 'annee_parution'
-->
Book's parution year :
<%= request.getParameter("parution_year") %>

<!--
Formulaire, pointant sur form_book.jsp
-->
<form method="post" action="form_book.jsp">
    <input type="hidden" name="title" value="<%= request.getParameter("title") %>" />
    <input type="hidden" name="author" value="<%= request.getParameter("author") %>"/>
    <input type="hidden" name="parution_year" value="<%= request.getParameter("parution_year") %>" />
    <input type=submit value="Return...">
</form>
```

##### remove_book.jsp

Simple page JSP permettant de supprimer un livre (via son titre) de la base de données.  
Elle pointera sur une servlet *RemoveOneBookServlet*.

```
<form method="post" action="RemoveOneBookServlet">
    <p>Title of the book (to remove): <input type="text" name="title" value="<%= request.getParameter("title") %>"    /></p>
    <input type=submit value="Remove this book">
</form>
```

####<a name="entities_code_samples"></a>Entities

Une entité encapsule les données d'une occurrence d'une ou plusieurs tables - ce sont donc de simples objets n'implémentant aucune interface particulière, ni n'hérite d'aucune classe mère spécifique. 

##### Book.java
 
Pour l'entité Book, elle contiendra ainsi : un titre, un auteur et une date de parution.

```
public class Book implements Serializable {
    
    private static final long serialVersionUID = 1L;
    
    /**
     * Title of the Book object
     * Id of the Book object
     */
    @Id
    private String title;
    
    /**
     * Author of the Book object
     */
    private String author;
    
    /**
     * The parution date of the Book object
     */
    private String parution_date;
    
    /**
     * Constructor of the Book object
     * @param title A string which represents the title of the Book object to construct
     * @param author A string which represents the author of the Book object to construct
     * @param parution_date A string which represents the parution date of the Book object to construct
     */
    public Book(String title, String author, String parution_date) {
        this.title = title;
        this.author = author;
        this.parution_date = parution_date;
    }
    
    ...
    ...
    
}
```

Aussi, cette entité contiendra une méthode hashCode, afin de pouvoir établir un code via une fonction de hachage dans la table, en fonction du titre du livre.

```
public int hashCode() {
    int hash = 0;
    hash += (this.title != null ? this.title.hashCode() : 0);
    return hash;
}
```

Dernière chose, deux requêtes ont été définies pour cette entité : une permettant de retourner tous les auteurs (*allauthors*), l'autre chaque titre de livres (*allbooks*).

```
@NamedQueries(value={ @NamedQuery(name="allauthors", query="select distinct b.author from Book b"), 
                      @NamedQuery(name="allbooks"  , query="select distinct b.title from Book b")})
```

##### ClientUser.java

L'entité ClientUser contiendra un champ login (ID) ainsi qu'un champ password.  

```
@Entity
public class ClientUser implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    private String login;
    private String password;
    
    public ClientUser() {
    }
    
    public ClientUser(String login, String password){
        this.login = login;
        this.password = password;
    }
    
    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    ...
    ...

}
```

Une méthode hashCode a aussi été implémentée, tout comme une requête permettant de récupérer les logins présents dans la base de données.

```
public int hashCode() {
        int hash = 0;
        hash += (login != null ? login.hashCode() : 0);
        return hash;
}
```

```
@NamedQuery(name="alllogins", query="select u.login from ClientUser u")
```

##### Command.java

Quant à cette dernière entité, elle servira pour les commandes de l'utilisateur.  
Elle contiendra ainsi un id (généré lors de la création de l'objet), ainsi qu'un nombre d'utilisateur (on le rappelle, ID de la base ClientUser) et une liste de livres contenue dans une chaîne de caractères.

```
@Entity
public class Command implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    
    private String user;
    
    private String book_list;

    
    public Command() {
    }
    
    /**
     * Constructor of the Book object
     * @param user A string which represents the name of the user who made this command
     * @param booklist list of books
     */
    public Command(String user, String booklist) {
        this.user = user;
        this.book_list = booklist;
    }
    
    ...
    ...
    
}
```

Une méthode hashCode a aussi été implémentée.

```
public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
}
```

####<a name="servlets_code_samples"></a>Servlets

Une servlet est en réalité une simple classe Java, qui a la particularité de permettre le traitement de requêtes et la personnalisation de réponses.

##### AddBook.java

*AddBook* est une servlet permettant d'ajouter un livre dans la base de données - elle transmettra donc le message jusqu'à la base.

Cette servlet contiendra la session BookFacade en attribut, et implémentera une méthode *processRequest*, permettant de transmettre une requête HTTP pour obtenir une réponse HTTP, affichée sur le navigateur pour l'utilisateur.

Ici, on affichera en réponse si le livre a pu être ajouté à la base de données ou non (pour diverses causes...).

```
public class AddBook extends HttpServlet {
    
    /**
     * BookFacade is the session EJB.
     */
    @EJB
    private BookFacade book_session;

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        String title = (String)request.getParameter("title"),
                   author =  (String)request.getParameter("author"),
                   parution_year = (String) request.getParameter("parution_year");
        String result;
        if("null".equals(title) || "null".equals(author) || "null".equals(parution_year))
            result = "Empty field has been detected.";
        else if(book_session.exists(title)){
            System.out.println("OK!");
            result = "This title exists.";
        }else {
            /*
            Creation of a new book, with 3 parameters : 'titre', 'auteur' and 'annee_parution'
            */
            book_session.create(new Book(title,author,parution_year));
            result = "The book has been added.";
        }
            
        try (PrintWriter out = response.getWriter()) {
            /*
            Basic webpage header and footer
            */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet AddBook</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println(result);
            out.println("<br/>");
            out.println("<a href=\"index.html\">Return to the homepage...</a>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### AddCommandServlet.java

*AddCommandServlet* est une servlet permettant d'ajouter un objet *Book* au panier de l'utilisateur.

```
public class AddCommandServlet extends HttpServlet {

    private static final String BASKET_BEAN_SESSION_KEY = "basket_key";

    @EJB
    private CommandFacade command_session;
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        String result = "";
        if(request.getSession() == null || request.getSession().getAttribute("login")==null || request.getSession().getAttribute(BASKET_BEAN_SESSION_KEY) == null){//error case
            result = "You need to be authentificate.";
            result += "<br/><a href=\"index.html\">Go to the authentification page...</a>";
            result += "<br/><a href=\"BooksTitles\">Return to the book list...</a>";
        }
        else {
  
            BasketITF b = (BasketITF)request.getSession().getAttribute(BASKET_BEAN_SESSION_KEY);
            String user = (String)request.getSession().getAttribute("login");
            
            if(b.getBasket_list().size() > 0){
        
                String basket_str = "";
        
                for (String s : b.getBasket_list())
                    basket_str += s+";";
        
                this.command_session.addCommand(user, basket_str);
            
                result = "The commande has been added.";
            }
            else {
                result = "The commande is empty.";
            }
        }
        
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet AddCommandServlet</title>");  
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");          
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println(result);
            out.println("</div>");
            out.println("</br>");
            out.println("</br>");
            out.println("<center><a href=\"menu.html\">Return to the homepage...</a></center>");
            out.println("</body>");
            out.println("</html>");
        }
    }

    ...
    ...
    
}
```

##### Authors.java

*Authors* est une servlet permettant d'obtenir des informations concernant le(s) auteur(s) d'un/de livre(s).

```
public class Authors extends HttpServlet {

    /**
     * BookFacade is the session EJB.
     */
    @EJB
    private BookFacade book_session;
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        /*
        Basic webpage
        */
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet Authors</title>");            
            out.println("</head>");
            out.println("<body>");
            /*
            Call to the getAllAuthors() method
            */
            out.println(book_session.getAllAuthors());
            out.println("<a href=\"index.html\">Return to the homepage...</a>");
            out.println("<br/>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
```

##### BooksTitles.java

*BooksTitles* est une servlet permettant d'obtenir des informations concernant le(s) titre(s) d'un/de livre(s).

```
public class BooksTitles extends HttpServlet {
    
    /**
     * BookFacade is the session EJB.
     */
    @EJB
    private BookFacade book_session;

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        /*
        Basic webpage
        */
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet BooksTitles</title>");            
            out.println("</head>");
            out.println("<body>");
            /*
            Call to the getAllBooks() method
            */
            out.println(book_session.getAllBooks());
            out.println("<a href=\"remove_book.jsp\">Remove a book</a>");
            out.println("<a href=\"index.html\">Return to the homepage...</a>");
            out.println("<br/>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
```

##### ClientLogins.java

*ClientLogins* est une servlet permettant de lister les utilisateurs de l'application en temps réel.

```
public class ClientLogins extends HttpServlet {

    @EJB
    private ClientFacade user_session;
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet UsersLogins</title>");     
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");        
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println("<fieldset>");
            out.println("<legend>List of users</legend>");
            out.println(user_session.getAllLogins());
            if(request.getSession().getAttribute("login").equals("admin")) //remove client = admin privilege
                 out.println("<a href=\"remove_client.jsp\">Remove a client</a>");
            out.println("</fieldset>");
            out.println("</div>");
            out.println("</br>");
            out.println("</br>");
            out.println("<center><a href=\"menu.html\">Return to the homepage...</center>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### InitServlet.java

*InitServlet* est une servlet permettant d'appeler la fonction initialisant la base de données (*init()* dans la *Bean Session*) avec quelques valeurs par défaut.

Elle ne peut être initialisée deux fois, d'où la présence du booléen d'initialisation.

```
public class InitServlet extends HttpServlet {

    /**
     * Boolean to return if the servlet is already initialized.
     */
    private boolean isInit = false;
    
    /**
     * BookFacade is the session EJB.
     */
    @EJB
    private BookFacade book_session;
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        /*
        Basic webpage
        */
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet InitServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            if(isInit)
                out.println("The initialization is already done.");
            else{
                book_session.init();
                isInit = true;
                out.println("The initialization has been done.");
            }
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### OperationsOnBasket.java

*OperationsOnBasket* est une servlet permettant de faire des opérations directement sur le panier de l'utilisateur - comme la suppression ou modification de la liste de livres enregistrée...

```
public class OperationsOnBasket extends HttpServlet {

    private static final String BASKET_BEAN_SESSION_KEY = "basket_key";
    
    @EJB
    private BookFacade em;
    
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        String result ="";
        if(request.getSession() == null || request.getSession().getAttribute("login")==null){//error case
            result = "You need to be authentificate.";
            result += "<br/><a href=\"index.html\">Go to the authentification page...</a>";
            result += "<br/><a href=\"BooksTitles\">Return to the book list...</a>";
        }
        else {
            
            BasketITF b;
            b = (BasketITF) request.getSession().getAttribute(BASKET_BEAN_SESSION_KEY);
            if ( b == null){ //basket doesn't exist

                try {
                    InitialContext ic = new InitialContext();
                    b = (BasketITF) ic.lookup("java:global/TP04_Carette_Verkyndt/Basket");
                
                    request.getSession().setAttribute(BASKET_BEAN_SESSION_KEY,b);
                
                } catch (NamingException ex) {
                    throw new ServletException(ex);
                }
                
            }
            String book = (String) request.getParameter("book");
            if(book != null){

                if(em.exists(book)){
                    b.addBook(book);
                    result = "The book has been added into the basket ";
                }
                else{
                    result = "The book doesn't exist into the database.";

                }
            }
            
            String remove_book = (String) request.getParameter("remove_book");
            if(remove_book != null){

                if(b.getBasket_list().contains(remove_book)){
                    b.removeBook(remove_book);
                    result = "The book has been removed from the basket ";
                }
                else{
                    result = "The book doesn't exist into the basket.";

                }
            }
            
            String complete = (String) request.getParameter("complete");
            
            if(complete != null)
                if(complete.equalsIgnoreCase("yes")){
                    response.sendRedirect("AddCommandServlet");
                }
        }
        
        
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Operations on the basket</title>");
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");        
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println("<fieldset>");
            out.println("<legend>Basket operations</legend>");
            out.println(result);
            out.println("<center><a href=\"ShowMyBasket\">Return to your basket...</a><center/>");
            out.println("</fieldset>");
            out.println("</div>");
            out.println("</br>");
            out.println("</br>");
            out.println("<center><a href=\"menu.html\">Return to the homepage...</center>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### RemoveAllBooksServlet.java

*RemoveAllBooksServlet* est une servlet permettant de supprimer toute la liste de livres enregistrée dans la base de données.

```
public class RemoveAllBooksServlet extends HttpServlet {

    @EJB
    private BookFacade book_session;
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        String result;
        if(request.getSession().getAttribute("login").equals("admin"))
            result = (book_session.removeOneBook(request.getParameter("title")))?"SUCCESS":"FAILED";
        else
            result = "You don't have the right to do such operation.";
        
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet RemoveAllBooksServlet</title>");
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");            
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println(result);
            out.println("</div>");
            out.println("</body>");
            out.println("<center><a href=\"BooksTitles\">Return to the list...</a></center>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### RemoveOneBookServlet.java

*RemoveOneBookServlet* est une servlet permettant de supprimer un livre (par son titre) de la base de données.

```
public class RemoveOneBookServlet extends HttpServlet {

    @EJB
    private BookFacade book_session;
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        String result = (book_session.removeOneBook(request.getParameter("title")))?"SUCCESS":"FAILED";
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet removeOnBookServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println(result);
            out.println("<a href=\"index.html\">Return to the homepage...</a>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### RemoveOneClientServlet.java

*RemoveOneClientServlet* est une servlet permettant de supprimer un utilisateur de la base de données.

```
public class RemoveOneClientServlet extends HttpServlet {

    @EJB
    private ClientFacade client_session;
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)   throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        ;
        
        String result;
        if(request.getSession().getAttribute("login").equals("admin"))
             result = (client_session.removeOneClient(request.getParameter("client_name")))?"SUCCESS":"FAILED";
        else
            result = "You don't have the right to do such operation.";
        
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet removeOnClientServlet</title>");
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");            
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println(result);
            out.println("</div>");
            out.println("</br>");
            out.println("</br>");
            out.println("<center><a href=\"BooksTitles\">Return to the homepage...</a></center>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### ShowMyBasket.java

*ShowMyBasket* est une servlet permettant de lister tout le panier enregistré par l'utilisateur.

```
public class ShowMyBasket extends HttpServlet {

   private static final String BASKET_BEAN_SESSION_KEY = "basket_key";
    
    @EJB
    private BookFacade em;
    
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        String result ="";
        String list = "";
        if(request.getSession() == null || request.getSession().getAttribute("login")==null){//error case
            result = "You need to be authentificate.";
            result += "<br/><a href=\"index.html\">Go to the authentification page...</a>";
            result += "<br/><a href=\"menu.html\">Return to the homepage...</a>";
        }
        else {
            
            BasketITF b;
            b = (BasketITF) request.getSession().getAttribute(BASKET_BEAN_SESSION_KEY);
            if ( b == null){ //basket doesn't exist

                try {
                    InitialContext ic = new InitialContext();
                    b = (BasketITF) ic.lookup("java:global/TP04_Carette_Verkyndt/Basket");
                
                    request.getSession().setAttribute(BASKET_BEAN_SESSION_KEY,b);
                
                } catch (NamingException ex) {
                    throw new ServletException(ex);
                }
                
            }
            
            List<String> b_list = b.getBasket_list();
            if(b_list.size()>0){
                    
                list = "<div>Command: </div><table>";
                
                for (int i = 0; i < b.getBasket_list().size(); i++)
                    list += "<tr><td>" + b.getBasket_list().get(i) + "<td></tr>";
                list+= "</table>";
            }
            else {
                list += "empty";
            }
        }
    
            
            
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Your Basket</title>"); 
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");               
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println("<fieldset>");
            out.println("<legend>My basket</legend>");
            out.println(list);
            if(! request.getSession().getAttribute("login").equals("admin")) {
                out.println("<br/><br/><form method=\"post\" action=\"OperationsOnBasket\">"
                                + "<table><tr><td>Remove from basket:</td><td><input type=\"text\" name=\"remove_book\"  /></td></tr>"
                                + "<tr><td></td><td><input type=submit value=\"Remove\"></td></tr>"
                                + "</table></form>");
            }
            out.println("</fieldset>");
            out.println("</div>");
            out.println("</br>");
            out.println("</br>");
            out.println("<center><a href=\"menu.html\">Return to the homepage...</a></center>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

##### VerifAuthServlet.java

*VerifAuthServlet* est une servlet permettant de vérifier l'identité d'une personne s'étant loggé - afin de vérifier si elle est bien enregistrée dans la base de données.

```
public class VerifAuthServlet extends HttpServlet {

    @EJB
    private ClientFacade user_session;
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        //get the login and password to log in
        String login = (String)request.getParameter("login"),
               password = (String) request.getParameter("password");
        
        String result = "Authentification failed.";
        
        if("null".equals(login) || "null".equals(password)) { //check error case
            result += "  Empty field has been detected.";
        }
        else if(user_session.AuthValid(login,password)){ // if authentification OK
            System.out.println("Authentification OK for " + login + ".");
            result = "Authentification OK. New session has been created.";
            
            //initialisation of a new session
            request.getSession(true).setAttribute("login", login);
            request.getSession().setMaxInactiveInterval(600); //TIMEOUT 10 min
            
            //go to the menu of the application
            response.sendRedirect("menu.html");
        }      
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Authentification service</title>"); 
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");             
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println(result);
            out.println("</div>");
            out.println("<br/>");
            out.println("<br/>");
            out.println("<center><a href=\"index.html\">return</a></center>");
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    ...
    ...
    
}
```

####<a name="sessions_code_samples"></a>Sessions

Les sessions vont communiquer elles directement avec la base de données, agir sur elle puis ensuite retourner une réponse à la servlet appelante.

##### BookFacade.java

*BookFacade* sera la session pour l'entité *Book* - elle étendra une classe abstraite de type *Book*.  
Elle contiendra une méthode *init()* permettant d'initialiser par défaut la base de données de *x* livres.

Aussi, elle ne conservera aucun état entre les différents appels - elle sera donc **Stateless**.

```
@Stateless
public class BookFacade extends AbstractFacade<Book> {
    @PersistenceContext(unitName = "WebApplication1PU")
    private EntityManager em;

    @Override
    protected EntityManager getEntityManager() {
        return em;
    }

    /**
     * Default constructor
     */
    public BookFacade() {
        super(Book.class);
    }
    
    /**
     * Method to add in the database default Book objects
     */
    public void init() {
        
        Book b1 = new Book("Shining", "Stephen_King", "1977");
        Book b2 = new Book("La_Tour", "Stephen_King", "2004");
        Book b3 = new Book("Le_Talisman","Stephen_King", "1984");
        
        em.persist(b1);
        em.persist(b2);
        em.persist(b3);
        System.out.println("Initialization has been done.");
    }
    
    ...
    ...
    
}
```

Selon les requêtes faites, il y aura 3 méthodes d'implémenter.

```
public String getAllAuthors() {
    Query q = em.createNamedQuery("allauthors");
    List<String> list = (List<String>) q.getResultList();
    String result = "Authors list :<br/><br/><ul>";
    for(String a : list){
        result += "<li>" + a + "</li>";
    }
    result += "</ul></br>The End...<br/>";
    System.out.println("Authors list has been send.");
    return result;
}
```
,

```
public String getAllBooks() {
    Query q = em.createNamedQuery("allbooks");
    List<String> list = (List<String>) q.getResultList();
    String result = "Books list :<br/><br/><ul>";
    for(String a : list){
        result += "<li>" + a + "</li>";
    }
    result += "</ul></br>The End...<br/>";
    System.out.println("Books list has been send.");
    return result;
}
```

et enfin

```
public boolean removeOneBook(String title) {
    Book b = em.find(Book.class, title);
    if(b == null)
        return false;
    else
       em.remove(b);
    
    System.out.println("Books list has been deleted.");
    return true;
}
```

##### BasketFacade.java

*BasketFacade* sera la session pour l'entité *Basket* - elle étendra une interface *BasketITF*. 

Aussi, elle conservera les états entre les différents appels - elle sera donc **Stateful**.  
De plus, elle les conservera dans un certain laps de temps - il y a donc un *Timeout* dessus.

```
@Stateful
@StatefulTimeout(unit = TimeUnit.MINUTES, value = 10)
public class Basket implements BasketITF{

    @PersistenceContext
    private EntityManager em;
    
    private List<String> basket_list;
    
    @PostConstruct
    private void init(){
        basket_list = new ArrayList<String>();
    }
    
    @Override
    public void addBook(String title){
        basket_list.add(title);
    }
    
    @Override
    public void removeBook(String title){
        basket_list.remove(title);
    }

    @Override
    public List<String> getBasket_list() {
        return basket_list;
    }
    
    @Override
    public void clearBasket(){
        basket_list.clear();
    }
}
```

##### ClientFacade.java

*ClientFacade* sera la session pour l'entité *Facade* - elle étendra la classe abstraite *AbstractFace*. 

Aussi, elle ne conservera pas les états entre les différents appels - elle sera donc **Stateless**.

```
@Stateless
public class ClientFacade extends AbstractFacade<ClientUser> {
    @PersistenceContext(unitName = "WebApplication1PU")
    private EntityManager em;

    @Override
    protected EntityManager getEntityManager() {
        return em;
    }

    public ClientFacade() {
        super(ClientUser.class);
    }


    public boolean AuthValid(String login, String password) {
        ClientUser u = em.find(ClientUser.class, login);
        if(null == u)
            return false;
       return u.getPassword().equals(password);
    }

    public boolean exist(String login) {
        Query q = em.createQuery("SELECT u.login FROM ClientUser u WHERE (u.login = :l)");
        q.setParameter("l", login);
        try{
            System.out.println(q.getSingleResult());
        }catch(NoResultException e){
            System.out.println("The user doesn't exist.");
            return false;
        }
        return true;        
    }

    public String getAllLogins() {
        Query q = em.createNamedQuery("alllogins");
        List<String> list = (List<String>) q.getResultList();
        String result = "<table>";
        for (int i = 0; i < list.size(); i++)
            if(!list.get(i).equals("admin")){
                result += "<tr>";
                result += "<td>" + list.get(i) + "</td>";
                result += "</tr>";
            }
        result += "</table>";
        System.out.println("User list has been send.");
        return result;
    }

    public boolean removeOneClient(String client_name) {
        if(client_name.equals("admin"))
            return false;
        ClientUser b = em.find(ClientUser.class, client_name);
        if(b == null)
            return false;
        else
           em.remove(b);
        
        System.out.println("The client " +client_name+  "has been removed form database.");
        return true;
    }
    
}
```

###<a name="utilisation"></a>Utilisation

Pour ce projet, importez TP04_Carette_Verkyndt dans NetBeans.  
```Clean and build``` sur le projet, puis ```run``` après avoir créer un serveur avec GlassFish.  
Connectez vous en localhost sur le port ```4848```, puis profitez de l'application!

###<a name="remarques"></a>Remarques

"Have fun!"
