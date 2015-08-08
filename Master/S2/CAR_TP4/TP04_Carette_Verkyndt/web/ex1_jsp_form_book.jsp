<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Formulaire de livre</title>
    </head>
    <body>
    
        <!--
            Formulaire, pointant sur AddBook
        -->
        <form method="post" action="print_book.jsp">
            <p>Title: <input type="text" name="title" value="<%= request.getParameter("title") %>"    /></p>
            <p>Author: <input type="text" name="author" value="<%= request.getParameter("author") %>" /></p>
            <p>Parution year: <input type="text" name="parution_year" value="<%= request.getParameter("parution_year") %>" /></p>
            <input type=submit value="Print It">
        </form>
            
        <br/>
        
    </body>
</html>
