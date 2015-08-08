/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.ejb.EJB;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import session.BasketITF;
import session.BookFacade;

/**
 * OperationsOnBasket class.
 * Class which permits to make some operations on basket
 */
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
