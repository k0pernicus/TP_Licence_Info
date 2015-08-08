/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package session;

import entity.Book;
import entity.ClientUser;
import java.util.List;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.NoResultException;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 *
 * @author alexandre
 */
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