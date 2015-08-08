package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
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
 * ShowMyBasket class
 * Class which permits to list all books contains in the database
 */
public class ShowMyBasket extends HttpServlet {

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
        String list = "";
        if(request.getSession() == null || request.getSession().getAttribute("login")==null){//error case
            result = "You need to be authentificate.";
            result += "<br/><a href=\"index.html\">Go to the authentification page...</a>";
            result += "<br/><a href=\"menu.html\">Return to the homepage...</a>";
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
            
            List<String> b_list = b.getBasket_list();
            if(b_list.size()>0){
                    
                list = "<div>Command: </div><table>";
                
                for (int i = 0; i < b.getBasket_list().size(); i++)
                    list += "<tr><td>" + b.getBasket_list().get(i) + "<td></tr>";
                list+= "</table>";
            }
            else {
                list += "empty";
            }
        }
    
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Your Basket</title>"); 
            out.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/all.css\">");               
            out.println("</head>");
            out.println("<body>");
            out.println("<div id=\"menu_appplications\">");
            out.println("<fieldset>");
            out.println("<legend>My basket</legend>");
            out.println(list);
            if(! request.getSession().getAttribute("login").equals("admin")) {
                out.println("<br/><br/><form method=\"post\" action=\"OperationsOnBasket\">"
                                + "<table><tr><td>Complete your command: </td><td><input type=\"text\" name=\"complete\"  /></td></tr>"
                                + "<tr><td></td><td><input type=submit value=\"complete\"></td></tr>"
                                + "</table></form>");
                out.println("<br/><br/><form method=\"post\" action=\"OperationsOnBasket\">"
                                + "<table><tr><td>Remove from basket:</td><td><input type=\"text\" name=\"remove_book\"  /></td></tr>"
                                + "<tr><td></td><td><input type=submit value=\"Remove\"></td></tr>"
                                + "</table></form>");
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
