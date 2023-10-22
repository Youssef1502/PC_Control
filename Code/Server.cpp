#include "Server.hpp"
#include <iostream>
#include <thread>
#include <vector>

Server::Server(int port) : port(port) {
    // Create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the specified address and port
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));

    // Start listening for incoming connections
    listen(server_socket, 5);

    // Initialize the help message
    helpMsg = "--------------------------------\n"
              "help menu \n"
              "--------------------------------\n "
              "Type any commands:\n"
              "1. terminal\n"
              "2. calendar\n" 
              "3. firefox\n"
              "4. nautilus\n"
              "5. sudoku\n"
              "6. calculator\n"
              "--------------------------------\n";
}

void Server::start() {
    std::cout << "Server is listening on port: " << port << std::endl;
    
    std::vector<std::thread> client_threads;

    while (true) {
        int client = accept(server_socket, NULL, NULL);

        // Send the help message to the client at the start
        send(client, helpMsg, strlen(helpMsg), 0);

        // Create a new thread to handle the client
        client_threads.push_back(std::thread(&Server::handleClient, this, client));
    }

    // Wait for all client threads to finish
    for (auto& thread : client_threads) {
        thread.join();
    }
}

Server::~Server() {
    // Close the server socket
    close(server_socket);
}

void Server::handleCommand(int client, const char* command) {
    if (strcmp(command, "terminal\n") == 0) {
        executeCommand(client, "gnome-terminal");
    } else if (strcmp(command, "calendar\n") == 0) {
        executeCommand(client, "gnome-calendar");
    } else if (strcmp(command, "firefox\n") == 0) {
        executeCommand(client, "firefox");
    } else if (strcmp(command, "nautilus\n") == 0) {
        executeCommand(client, "nautilus");
    } else if (strcmp(command, "sudoku\n") == 0) {
        executeCommand(client, "gnome-sudoku");
    } else if (strcmp(command, "calculator\n") == 0) {
        executeCommand(client, "gnome-calculator");
    } else {
        const char* errorMessage = "Wrong Command";
        send(client, errorMessage, strlen(errorMessage), 0);
        std::cout << "Wrong command" << std::endl;
    }
}

void Server::executeCommand(int client, const char* cmd) {
    // Create a new process
    pid_t pid = fork();

    // If we're in the child process
    if (pid == 0) {
        // Replace the child process with the specified command
        execlp(cmd, cmd, NULL);
        // Exit the child process
        exit(0);
    }
    // In the parent process, we continue listening for new client commands.
}

void Server::handleClient(int client) {
    char buffer[1024];
    int bytes = 1;

    while (bytes) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read data from the client into the buffer
        bytes = read(client, buffer, sizeof(buffer));

        // Process the command
        handleCommand(client, buffer);

        // Send the help message to the client before each command
        send(client, helpMsg, strlen(helpMsg), 0);
    }

    if (bytes == 0) {
        std::cout << "Client Disconnected" << std::endl;
    } else {
        std::cerr << "Error!!" << std::endl;
    }

    close(client);
}