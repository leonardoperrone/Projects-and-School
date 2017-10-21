# Import socket module

from socket import *
# Create a TCP server socket
# (AF_INET is used for IPv4 protocols)
# (SOCK_STREAM is used for TCP)
serverSocket = socket(AF_INET, SOCK_STREAM)

# Assign a port number
serverPort = 6789

# Bind the socket to server address and server port
serverSocket.bind(('', serverPort))

# Listen to at most 1 connection at a time
serverSocket.listen(1)

# Server should be up and running and listening to the incoming connections
while True:
    print 'Ready to serve...'

    # Set up a new connection from the client
    cliConnection, address = serverSocket.accept()

    # If an exception occurs during the execution of try clause
    # the rest of the clause is skipped
    # If the exception type matches the word after except
    # the except clause is executed
    try:
        # Receive the request message from the client
        message = cliConnection.recv(1024)

        # Extract the path of the requested object from the message
        # The path is the second part of HTTP header, identified by [1]
        filename = message.split()[1]
        # Because the extracted path of the HTTP request includes
        # a character '\', we read the path from the second character
        f = open(filename[1:])
        # Store the entire contenet of the requested file in a temporary buffer
        outputdata = f.read()
        # Send the HTTP response header line to the connection socket
        cliConnection.send(
        """HTTP/1.0 200 OK
		Content-Type: text/html
		<html>
        <head>
        <title>Connection Successful</title>
        <body></body>
        </head>
        </html>""".encode())

        # Send the content of the requested file to the connection socket
        for i in range(0, len(outputdata)):

            cliConnection.send(outputdata)
            cliConnection.send(message)

            # Close the client connection socket
        cliConnection.close()

    except IOError:  # Send HTTP response message for file not found
            cliConnection.send("404 Not Found")
            cliConnection.send("<html><head></head><body><h1>HTTP/1.0 404 Not Found</h1></body></html>")
            # Close the client connection socket
            cliConnection.close()
            # Close the Socket
            serverSocket.close()