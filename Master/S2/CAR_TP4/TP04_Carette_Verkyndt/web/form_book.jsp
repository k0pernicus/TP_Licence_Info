<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Formulaire de livre</title>
        <link rel="stylesheet" type="text/css" href="css/all.css">
    </head>
    <body>
    
        <!--
            Formulaire, pointant sur AddBook
        -->
        <div id="menu_appplications">
            <fieldset>
                <legend>Please to register the book you like</legend>
                <form method="post" action="AddBook">
                    <table>
                        <tr>
                            <td>
                                Title:
                            </td>
                            <td>
                                <input type="text" name="title"/>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                Author:
                            </td>
                            <td>
                                <input type="text" name="author"/>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                Parution year:
                            </td>
                            <td>
                                <input type="text" name="parution_year"/>
                            </td>
                        </tr>
                        <tr>
                            <td>
                            </td>
                            <td>
                                <input type=submit value="Add to the database">
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
