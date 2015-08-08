package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import session.BookFacade;

/**
 *  BooksTitles class
 *  Class which permits to process to requests for 'titre' field
 */
public class BooksTitles extends HttpServlet {
    
    /**
     * BookFacade is the session EJB.
     */
    @EJB
    private BookFacade book_session;

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
        /*
        Basic webpage
        */
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet BooksTitles</title>");
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");            
            out.println("</head>");
            out.println("<body>");
            /*
            Call to the getAllBooks() method
            */
            out.println("<div id=\"menu_appplications\">");
            out.println("<fieldset>");
            out.println("<legend>List of our amazing books</legend>");
            out.println(book_session.getAllBooks());
            if(request.getSession().getAttribute("login").equals("admin")) //remove book = admin p
                 out.println("<a href=\"remove_book.jsp\">Remove a book</a><br/>");
            else{ //client
                out.println("<br/><br/><form method=\"post\" action=\"OperationsOnBasket\">"
                                + "<p>Add to basket: <input type=\"text\" name=\"book\"  /></p>"
                                + "<input type=submit value=\"Add to basket\">"
                                + "</form><br/><br/>");
            }
            out.println("</fieldset>");
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
