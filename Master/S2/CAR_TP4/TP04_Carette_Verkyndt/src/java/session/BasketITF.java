/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package session;

import java.util.List;
import javax.ejb.Local;

/**
 * BasketITF Interface
 * Interface to implement a simple basket
 */
@Local
public interface BasketITF {

    /**
     * Method to add a book in the basket
     * @param title The title of the book
     */
    public void addBook(String title);
    
    /**
     * Method to remove a book from the basket
     * @param title The title of the book to remove
     */
    public void removeBook(String title);
    
    /**
     * Method to clear the basket
     */
    public void clearBasket();
    
    /**
     * Method to list all books contains in the list
     * @return A list of String - which are title of books contains in the basket
     */
    public List<String> getBasket_list();

}
