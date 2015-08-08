/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entity;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQuery;


@NamedQuery(name="alllogins", query="select u.login from ClientUser u")

/**
 * Client object
 * The Client object will contains the login and password of this user
 */
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

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (login != null ? login.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof ClientUser)) {
            return false;
        }
        ClientUser other = (ClientUser) object;
        if ((this.login == null && other.login != null) || (this.login != null && !this.login.equals(other.login))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "entity.User[ login=" + login + " ]";
    }

    public String getPassword() {
        return this.password;
    }
    
}