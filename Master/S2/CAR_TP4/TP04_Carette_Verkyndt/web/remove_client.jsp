<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
    <h1>If you want to remove a client, give us his name as follow! </h1>

        <form method="post" action="RemoveOneClientServlet">
            <p>Name of the client (to remove): <input type="text" name="client_name" /></p>
            <input type=submit value="Remove this client">
        </form>    </body>
</html>
