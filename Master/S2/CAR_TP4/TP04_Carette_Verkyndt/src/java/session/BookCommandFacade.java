/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package session;

import entity.BookCommand;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

/**
 * BookCommandFacade class
 * Session bean for the BookCommand entity class
 */
@Stateless
public class BookCommandFacade extends AbstractFacade<BookCommand> {
    @PersistenceContext(unitName = "WebApplication1PU")
    private EntityManager em;

    @Override
    protected EntityManager getEntityManager() {
        return em;
    }

    public BookCommandFacade() {
        super(BookCommand.class);
    }

    /**
     * Method to create a new command
     * @param user The user
     * @param list The list of books to add
     */
    public void addCommand(String user, String list) {
       BookCommand c = new BookCommand();
       c.setBook_list(list);
       c.setlogin(user);
        System.out.println("########### " + user);
       System.out.println("######### " + list );
       System.out.println("############  " + c.getId());
       em.persist((c));
    }
    
}
