from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer
import os

pathfile = os.path.abspath("FTPDirectory/") 

authorizer = DummyAuthorizer()
authorizer.add_user("alex", "alex", pathfile, perm="elradfmw")
authorizer.add_user("antonin", "antonin", pathfile, perm="elradfmw")
authorizer.add_anonymous(pathfile)

handler = FTPHandler
handler.authorizer = authorizer

server = FTPServer(("127.0.0.1", 1025), handler)
server.serve_forever()
