/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
/**
 * BookCommand object
 * The BookCommand object will contains the ID, a book list and the login of the user
 */

public class BookCommand implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    @Column(name = "login", nullable = false)
    private String login;
    @Column(name = "book_list", nullable = false)
    private String book_list;
    
    
    

    
    public BookCommand() {
    }
    
    /**
     * Constructor of the BookCommand object
     * @param login A string which represents the name of the user who made this command
     * @param book_list list of books
     */
    public BookCommand(String login, String book_list) {
        this.login = login;
        this.book_list = book_list;
    }
    
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (id != null ? id.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof BookCommand)) {
            return false;
        }
        BookCommand other = (BookCommand) object;
        if ((this.id == null && other.id != null) || (this.id != null && !this.id.equals(other.id))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "entity.Command[ id=" + id + " ]";
    }

    public String getLogin() {
        return login;
    }

    public void setlogin(String login) {
        this.login = login;
    }

    public String getBook_list() {
        return book_list;
    }

    public void setBook_list(String book_list) {
        this.book_list = book_list;
    }
    
}
