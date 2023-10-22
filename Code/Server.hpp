#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>

class Server {
public:
    // Constructor to initialize the server with a specified port
    Server(int port);

    // Method to start the server, listen for client commands, and handle them
    void start();

    // Destructor to close the server socket and perform cleanup
    ~Server();

private:
    int server_socket;                                      // Socket for the server to accept client connections
    struct sockaddr_in server_address;                      // Structure to store server address information
    int port;                                               // Port on which the server will listen
    const char* helpMsg;                                    // A message that provides help/menu information to clients
    void handleCommand(int client, const char* command);    // Method to handle client commands
    void executeCommand(int client, const char* cmd);       // Method to execute system commands
    void handleClient(int client);
};

#endif

