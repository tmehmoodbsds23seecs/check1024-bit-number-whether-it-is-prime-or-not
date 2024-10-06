Very Large Prime Number Calculation
Prime Number Determination for 1024-bit Numbers
This project demonstrates how to store very large numbers (1024-bit) using a linked list, and implements a primality test for these large numbers. The number is split into 64-bit segments stored in each node of the linked list, allowing you to handle very large numbers efficiently. The project uses the Miller-Rabin primality test to probabilistically determine whether the number is prime.

Table of Contents
Project Description
Features
Installation
Usage
Example
Contributing
License
Project Description
In this project, a 1024-bit random number is split and stored across multiple nodes of a linked list. Each node holds a 64-bit chunk of the large number. This linked list structure is used to manage the number due to its large size, which cannot be handled by standard primitive data types.

A primality test, specifically the Miller-Rabin test, is implemented to check whether the number is prime. The test is applied to the full number, which is distributed across the nodes of the linked list, ensuring memory efficiency.

Features
Linked List Representation: A very large number is split into 64-bit segments, each stored in a node of the linked list.
Miller-Rabin Primality Test: This probabilistic test is used to check if the large number is prime.
Random 1024-bit Number Generation: The project generates a random 1024-bit number split into multiple nodes for testing.
Efficient Memory Usage: By using linked lists, the project ensures that large numbers can be processed without requiring extensive memory allocation for a single variable.

Contributing
If you'd like to contribute to this project, feel free to submit a pull request. Contributions are welcome for:

Improving the linked list structure.
Enhancing the primality testing methods.
Optimizing memory usage or adding new features.
Please ensure all contributions are well-documented and tested.
