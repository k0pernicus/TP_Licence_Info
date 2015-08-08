<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="css/all.css">
        <title>Print JSP</title>
    </head>
    <body>
	Some informations: 
</br>

<!--
Permettra de demander à la requête quel est le résultat de 'titre'
-->

Book's title :
<%= request.getParameter("title") %>
</br>

<!--
Permettra de demander à la requête quel est le résultat de 'auteur'
-->
Book author :
<%= request.getParameter("author") %>
</br>

<!--
Permettra de demander à la requête quel est le résultat de 'annee_parution'
-->
Book's parution year :
<%= request.getParameter("parution_year") %>

<!--
Formulaire, pointant sur form_book.jsp
-->
<form method="post" action="ex1_jsp_form_book.jsp">
            <input type="hidden" name="title" value="<%= request.getParameter("title") %>" />
            <input type="hidden" name="author" value="<%= request.getParameter("author") %>"/>
            <input type="hidden" name="parution_year" value="<%= request.getParameter("parution_year") %>" />
            <input type=submit value="Return...">
        </form>
</body>
</html>