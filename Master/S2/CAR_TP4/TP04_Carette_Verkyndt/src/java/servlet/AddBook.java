package servlet;

import entity.Book;
import java.io.IOException;
import java.io.PrintWriter;
import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import session.BookFacade;

/**
 * AddBook class.
 * Class which permits to create a new Book object and to add it in the database.
 */
public class AddBook extends HttpServlet {
    
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
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        String title = (String)request.getParameter("title"),
                   author =  (String)request.getParameter("author"),
                   parution_year = (String) request.getParameter("parution_year");
        String result;
        if(request.getSession() == null || request.getSession().getAttribute("login") == null){
            result = "You need to be log to add a new book into the database."
                    + "<br/><br/><a href=\"index.html\">Go to authentification page...</a>";
        }
        else if("".equals(title) || "".equals(author) || "".equals(parution_year))
            result = "Empty field has been detected.";
        else if(book_session.exists(title)){
            result = "This title exists.";
        }else {
            /*
            Creation of a new book, with 3 parameters : 'titre', 'auteur' and 'annee_parution'
            */
            book_session.create(new Book(title,author,parution_year));
            result = "The book has been added.";
            System.out.println("A new book has been added");
        }
            
        try (PrintWriter out = response.getWriter()) {
            /*
            Basic webpage header and footer
            */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet AddBook</title>");
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
