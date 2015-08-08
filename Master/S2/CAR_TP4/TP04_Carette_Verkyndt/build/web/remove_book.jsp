<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="css/all.css">
        <title>JSP Page</title>
    </head>
    <body>
        <div id="menu_appplications">
            <fieldset>
                <legend>Please to enter the information of the book to remove</legend>
                <form method="post" action="RemoveOneBookServlet">
                    <table>
                        <tr>
                            <td>
                                Title:
                            </td>
                            <td>
                                <input type="text" name="title" value="<%= request.getParameter("title") %>" />
                            </td>
                        </tr>
                        <tr>
                            <td>
                            </td>
                            <td>
                                <input type=submit value="Remove this book">
                            </td>    
                        </tr>
                    </table>
                </form>
            </fieldset>
        </div>
        </br>
        </br>
        <center>
        <a href="menu.html">Return to the homepage...</a>
        </center>
    </body>
</html>
