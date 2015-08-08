package session;

import entity.Book;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 * BookFacade class
 * Session bean for the Book entity class
 */
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

    /**
     * Method to get all authors from the database
     * @return A string which contains all authors in the database
     */
    public String getAllAuthors() {
        Query q = em.createNamedQuery("allauthors");
        List<String> list = (List<String>) q.getResultList();
        String result = "<table>";
        for(int i = 0; i < list.size(); i++){
            result += "<tr>";
            result += "<td>" + list.get(i) + "</td>";
            result += "</tr>";
        }
        result += "</table>";
        System.out.println("Authors list has been send.");
        return result;
    }
    
    /**
     * Method to get all books from the database
     * @return A string which contains all books in the database
     */
    public String getAllBooks() {
        Query q = em.createNamedQuery("allbooks");
        List<String> list_books = (List<String>) q.getResultList();
        String result = "<table>";
        for(int i = 0; i < list_books.size(); i++){
            result += "<tr>";
            result += "<td>" + list_books.get(i) + "</td>";
            result += "</tr>";
        }
        result += "</table>";
        System.out.println("Books list has been send.");
        return result;
    }
    
    /**
     * Method to remove all books from the database
     * @return if the removal was well done.
     */
    public boolean removeAllBooks() {
        Query q = em.createNamedQuery("allbooks");
        List<String> list = (List<String>) q.getResultList();
        Book b;
        for(String a : list){
            b = em.find(Book.class, a);
            if(b == null)
                return false;
            else
                em.remove(b);
        }
        System.out.println("Books list has been deleted.");
        return true;
    }
    
    /**
     * Method to remove a book from the database
     * @return if the removal was well done.
     */
    public boolean removeOneBook(String title) {
        Book b = em.find(Book.class, title);
        if(b == null)
            return false;
        else
           em.remove(b);
        
        System.out.println("Books list has been deleted.");
        return true;
    }
    
    public boolean exists(String title){
        return (em.find(Book.class, title) != null);
    }
}
