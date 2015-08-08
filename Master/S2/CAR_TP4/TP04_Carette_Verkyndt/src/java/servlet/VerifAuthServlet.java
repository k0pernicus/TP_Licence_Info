/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import session.ClientFacade;

/**
 * VerifAuthServlet class
 * Class which permits to verify the authentification of the user with the database
 */
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

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}