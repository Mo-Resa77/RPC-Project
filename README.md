Substring Check RPC Application
Overview
This project implements a client-server application using Remote Procedure Call (RPC) over UDP. The server provides a service to check if one string is a substring of another, and the client sends two strings to the server and receives the result. The application is defined by an RPC specification (square.x) and implemented in C with square_server.c and square_client.c.
Features

Server:
Implements a remote procedure MORESA_CHECK_SUBSTRING that checks if str1 is a substring of str2.
Returns 1 (true) if str1 is a substring of str2, otherwise 0 (false).
Uses UDP for communication.


Client:
Takes a server hostname and two strings as command-line arguments.
Sends the strings to the server via RPC and displays the result ("Yes" or "No").


RPC Specification:
Defined in square.x, specifying a moresa_string_pair struct with two strings and a unique program number (0x20000002).



Files

square.x: RPC specification defining the moresa_string_pair struct and the MORESA_CHECK_SUBSTRING procedure.
square_server.c: Server implementation of the substring check procedure.
square_client.c: Client program that sends two strings to the server and prints the result.
Generated files (after running rpcgen):
square.h: Header file with struct and function declarations.
square_svc.c: Server stub code.
square_clnt.c: Client stub code.



Prerequisites

A C compiler (e.g., gcc).
RPC library (rpcsvc, included in most Unix-like systems).
rpcgen tool for generating stub code from square.x.
A Unix-like environment (Linux, macOS, or WSL on Windows).
The server and client can run on the same or different machines, provided the server hostname is accessible.

Compilation

Generate RPC Code:Use rpcgen to process the square.x file:
rpcgen square.x

This generates:

square.h: Header file with struct and function declarations.
square_clnt.c: Client stub code.
square_svc.c: Server stub code.


Compile the Server:
gcc -o square_server square_server.c square_svc.c -lrpcsvc


Compile the Client:
gcc -o square_client square_client.c square_clnt.c -lrpcsvc



Usage

Start the Server:

Run the server on the host machine:./square_server


The server runs as a daemon, listening for RPC requests on the program number 0x20000002 via UDP.
Note: Ensure the server is running before starting the client. You may need to run it with sudo if the RPC port is privileged.


Run the Client:

Run the client, specifying the server hostname and two strings:./square_client <hostname> <string1> <string2>


Example:./square_client localhost "cat" "scattered"

Output:Is 'cat' a substring of 'scattered'? Yes


Another example:./square_client localhost "dog" "scattered"

Output:Is 'dog' a substring of 'scattered'? No




Termination:

Stop the server with Ctrl+C or by killing the process.
The client exits automatically after displaying the result.



Notes

Limitations:
The server uses UDP, which is connectionless and may be less reliable than TCP for some networks.
The client expects exactly three command-line arguments (hostname, string1, string2); invalid input causes it to exit.
No explicit limit on string length is defined in square.x (uses string<>), but practical limits depend on the RPC implementation.
The server handles one request at a time; concurrent requests require additional configuration (e.g., RPC server threading).


Potential Improvements:
Add error handling for empty or overly long strings.
Implement a TCP-based version for more reliable communication.
Support multiple concurrent clients using threading or forking in the server.
Add input validation for special characters or string length.



Example Workflow

Generate RPC code:rpcgen square.x


Compile the server and client:gcc -o square_server square_server.c square_svc.c -lrpcsvc
gcc -o square_client square_client.c square_clnt.c -lrpcsvc


Start the server:./square_server


Run the client:./square_client localhost "test" "protest"

Output:Is 'test' a substring of 'protest'? Yes



Troubleshooting

"rpcgen: command not found":
Install the RPC development tools (e.g., sudo apt-get install rpcbind libtirpc-dev on Debian/Ubuntu).


"call failed" or "clnt_create error":
Ensure the server is running and accessible at the specified hostname.
Check if the RPC port is open (default RPC ports may vary; use rpcinfo -p to verify).
Ensure rpcbind is running (sudo systemctl start rpcbind).


"Permission denied" when running the server:
Run the server with sudo if it attempts to bind to a privileged port.


No output or unexpected results:
Verify the input strings and hostname are correct.
Check for network issues if the client and server are on different machines.



License
This project is provided as-is for educational purposes. No warranty is implied.
