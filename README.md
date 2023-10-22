# PC_Control
This repository includes a basic C++ server application that allows you to send requests from a phone acting as a client to a PC acting as a server to execute specified instructions on the PC server.

## Table of Contents
- Features
- Prerequisites
- Getting Started
- Usage
- Setup Client
- Execution Result

## Features
- Accepts incoming connections from multiple clients
- Executes predefined commands based on client requests.
- Handles errors by writing the wrong message.


## Prerequisites

Make sure you meet the following prerequisites before you start:

- C++ compiler (e.g., g++)
- Linux-based operating system (the example is tested on Ubuntu)
- Basic knowledge of C++ and socket programming


## Getting Started

1. Clone this repository to your local machine:

   ```bash
   https://github.com/Youssef1502/PC_Control.git
   ```

2. Compile the server program:

      ```bash
      g++ main.cpp Server.cpp -o myserver
      ```


## Usage
1. Start the server:

   ```bash
   ./myserver
   ```

   The server will start listening on the specified port (default is 8080).

2. Connect to the server using a client application or a terminal.

3. Send one of the predefined commands to the server, such as [ terminal / calendar / firefox / nautilus / sudoku / calculator ].
   

## Setup Client

1. Download [Tcp Udp Server & Client](https://play.google.com/store/apps/details?id=tcpudpserverclient.steffenrvs.tcpudpserverclient&pcampaignid=web_share)
2. follow these steps:

![client](https://github.com/Youssef1502/PC_Control/assets/83795307/7d6a2cc9-a47b-48a5-9f1c-fee56d5532f1)



## Execution Result

[PC Control_Drive](https://drive.google.com/file/d/1yiLjsTqHiOy00_jVtLhZOtp8r6amcXej/view)
