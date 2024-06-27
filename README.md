# Overview - Minitalk
In the Minitalk project, our goal is to develop a small data exchange program using UNIX signals. This project involves creating a communication program consisting of a client and a server.

To start with, the server must print its Process ID (PID) as soon as it launches. This is essential for the client to know where to send its data. The client program will then take the server's PID and a string as input parameters. The client sends this string to the server.

Once the server receives the string, it must print the string promptly. Quick printing is crucial; for example, if it takes a second to display 100 characters, that is considered too slow. Furthermore, the server should be capable of receiving strings from multiple clients sequentially without needing to restart between clients. All communication between the client and the server should be accomplished using only the UNIX signals SIGUSR1 and SIGUSR2.

For the bonus part of the project, I can implement additional features. One such feature is having the server acknowledge each received message by sending a signal back to the client. Another enhancement is supporting Unicode characters. However, it's important to note that the bonus part will only be evaluated if the mandatory part is completed perfectly, meaning it must work flawlessly and meet all specified requirements.

# Test cases

To make sure your project is on track, test by:
  1. Basic Communication Test:

     Test Case 1:
        Start the server and ensure it prints its PID.

     Test Case 2: 
        Run the client with the server's PID and a simple string. Verify that the server  receives and prints the string promptly.
     
  2. Multiple Clients Test:

      Test Case 3:
        Start the server, then run multiple clients sequentially, each sending a different string. Verify that the server receives and prints each string in the correct order without needing to restart.
     
  3. Signal Handling Test:

      Test Case 4:
        Ensure that only SIGUSR1 and SIGUSR2 signals are used for communication. Verify that other signals do not interfere with the operation.

  4. Error Handling Tests:

      Test Case 5:
        Run the client with an invalid server PID and verify that it handles the error gracefully.

     Test Case 6:
       Send an empty string from the client and verify that the server handles it correctly.
     
  5. Performance Test:

      Test Case 7: Use https://www.lipsum.com/feed/html to generate your random words, it sends a long string (e.g., 1000 characters) from the client and verifies that the server prints it quickly (within a reasonable time frame).
     
  6. Memory Management Test:

      Test Case 8: Use tools like "valgrind" to check for memory leaks while running the server and client programs.
     
  7. Global Variable Justification Test:

      Test Case 9: Verify the use of a single global variable per program (client and server) and ensure there is a valid justification for its use.

  8. Bonus Features Tests:

      Test Case 10: Implement the server acknowledgment feature. Verify that the server sends a signal back to the client after receiving a message.
     
     Test Case 11:
       Send a string containing Unicode characters from the client and verify that the server prints it correctly.

  10. Concurrency Test:
     
      Test Case 12: Start the server and run multiple clients simultaneously. Verify that the server can handle concurrent messages without issues.

  11. Stress Test:

      Test Case 13: Continuously send a high volume of messages from the client to the server to test the robustness and stability of the communication system.
  
  12. Makefile Test:

        Test Case 14: Ensure that the Makefile correctly compiles the source files without relinking, handles all specified rules (e.g., all, clean, fclean, re), and includes a bonus rule if applicable.
      
        Test Case 15: Run a YouTube video background (kinda harsh imo if somebody does so, but hardly to argue if it fails)

These test cases cover a comprehensive range of scenarios to ensure that the Minitalk project functions correctly, handles errors gracefully, and meets all the requirements outlined in the project document.

## LUCK be with you in THESE TESTS 🙈
