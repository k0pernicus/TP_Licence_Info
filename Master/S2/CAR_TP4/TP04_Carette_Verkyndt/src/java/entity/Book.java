/*
 * Book.java
 * This object has been created to represents a Book object.
 */
package entity;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;

@Entity

/**
 * 'allauthors' will get all authors from the Book base
 * 'allbooks' will get all book from the Book base
 */
@NamedQueries(value={ @NamedQuery(name="allauthors", query="select distinct b.author from Book b"), 
                      @NamedQuery(name="allbooks"  , query="select distinct b.title from Book b")})

/**
 * Book object
 * The Book object will contains the title, author and parution date of this book
 */
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
     * Default Constructor
     */
    public Book() {
        this.title  = "Default_book";
        this.author = "Default_Author";
        this.parution_date = "Default_date";
    }
    
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

    /**
     * Method to get the title of the Book object
     * @return A string which contains the title (or id) of the Book object
     */
    public String getTitle() {
        return this.title;
    }

    /**
     * Method to set the title of the Book object
     * @param title A string which is the title of the Book object to set
     */
    public void setTitle(String title) {
        this.title = title;
    }
    
    /**
     * Method to get the author of the Book object
     * @return A string which contains the name of the author
     */
    public String getAuthor() {
        return author;
    }

    /**
     * Method to set the author of the Book object
     * @param author A string which is the name of the author of the Book object to set
     */
    public void setAuthor(String author) {
        this.author = author;
    }

    /**
     * Method to get the parution date of the Book object
     * @return The parution date of the Book object to set
     */
    public String getParution_date() {
        return parution_date;
    }

    /**
     * Method to set the parution date of the Book object
     * @param parution_date A string which is the parution date of the Book object to set
     */
    public void setParution_date(String parution_date) {
        this.parution_date = parution_date;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (this.title != null ? this.title.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Book)) {
            return false;
        }
        Book other = (Book) object;
        if ((this.title == null && other.title != null) || (this.title != null && !this.title.equals(other.title))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "entity.Book[ Title= " + this.title + " ]";
    }
    
}
