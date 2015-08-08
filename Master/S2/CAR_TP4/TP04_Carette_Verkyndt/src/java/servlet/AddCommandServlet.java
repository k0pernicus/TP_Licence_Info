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
import session.BasketITF;
import session.BookCommandFacade;

/**
 * AddCommandServlet class
 * Servlet which permits to add a command
 */
public class AddCommandServlet extends HttpServlet {

    private static final String BASKET_BEAN_SESSION_KEY = "basket_key";

    @EJB
    private BookCommandFacade command_session;
    
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
        
        String result = "";
        if(request.getSession() == null || request.getSession().getAttribute("login")==null || request.getSession().getAttribute(BASKET_BEAN_SESSION_KEY) == null){//error case
            result = "You need to be authentificate.";
            result += "<br/><a href=\"index.html\">Go to the authentification page...</a>";
            result += "<br/><a href=\"BooksTitles\">Return to the book list...</a>";
        }
        else {
  
            BasketITF b;
            b = (BasketITF)request.getSession().getAttribute(BASKET_BEAN_SESSION_KEY);
            String user = (String)request.getSession().getAttribute("login");
            
            if(b.getBasket_list().size() > 0){
        
                String basket_str = "";
        
                for (String s : b.getBasket_list())
                    basket_str += s+";";
        
                this.command_session.addCommand(user, basket_str);
            
                result = "The commande has been added.";
            }
            else {
                result = "The commande is empty.";
            }
        }
        
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet AddCommandServlet</title>");  
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");          
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println(result);
            out.println("</div>");
            out.println("</br>");
            out.println("</br>");
            out.println("<center><a href=\"menu.html\">Return to the homepage...</a></center>");
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
