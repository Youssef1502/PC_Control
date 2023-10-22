#include "Server.hpp"

int main() {
    // Create a server instance on port 8080
    Server server(8080);

    // Start the server
    server.start();

    return 0;
}
