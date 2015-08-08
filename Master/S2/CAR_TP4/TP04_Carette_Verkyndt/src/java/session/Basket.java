/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package session;

import entity.Book;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;
import javax.annotation.PostConstruct;
import javax.ejb.Stateful;
import javax.ejb.StatefulTimeout;
import javax.ejb.TransactionAttribute;
import javax.ejb.TransactionAttributeType;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;


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
