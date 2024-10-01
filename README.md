# BinarySearchTree-Operations
This project implements a **Binary Search Tree (BST)** in C, providing several fundamental operations such as node insertion, deletion, searching, and finding the nth smallest element. The program allows users to input numbers from a file and interactively manipulate the tree through a command-line interface.

## Features
- **Add a Node**: Insert a new key into the BST.
- **Delete a Node**: Remove a key from the BST and automatically reorganize the tree.
- **Search for a Node**: Find whether a specific key exists in the tree.
- **Find the kth Smallest** Element: Retrieve the nth smallest key in the BST.
- **In-Order Traversal**: Display all the keys in sorted order (from smallest to largest).

## Getting Started
### Prerequisites
You need a C compiler installed on your machine, such as `gcc`.

### Compilation
To compile the program, use the following command:
`gcc -o bst_operations main.c`

### Running the Program
Once compiled, run the program as follows:
`./bst_operations`

### Example Input
Upon running the program, you will be prompted to enter a file path containing integers to initialize the Binary Search Tree.
Example file content `(test.txt)`:
```
15
10
20
8
12
17
25
```

### Example Output
After reading from the file, the tree will be constructed, and the program will display an in-order traversal of the BST. You will then be presented with the following options:
```
* Function Table *
1. Add a new Key value
2. Delete a Key value
3. Find a Key value
4. Find the nth smallest key value
5. Output sorting results of Key values (from min to max)
6. End the program
```
You can select the desired operation by entering the corresponding number.

### Sample Execution
```
Enter the txt file path >> test.txt
Inorder traversal:
8 10 12 15 17 20 25

* Function Table *
1. Add a new Key value
2. Delete a Key value
3. Find a Key value
4. Find the nth smallest key value
5. Output sorting results of Key values (from min to max)
6. End the program

Select a function you want to test (1~6)>> 4
Enter the kth smallest Key you want to find >> 3
kth smallest: 3, Key: 12
```

### Functions Description
- `addNode()`: Inserts a new value into the binary search tree. If the value already exists, it won't be added.
- `deleteNode()`: Removes a node with the specified value from the tree, adjusting the tree structure accordingly.
- `findNode()`: Searches the tree for a specified key and prints whether it's found or not.
- `kthSmallest()`: Finds and returns the k-th smallest element in the tree.
- `inTraversal()`: Performs an in-order traversal, printing the keys in sorted order.

## Project Structure
- `main.c`: Contains the main function and user interaction logic.
- `bst_operations.c`: Contains all the BST operations such as adding, deleting, searching, and in-order traversal.
- `bst_operations.h`: Header file for function declarations and struct definitions.
