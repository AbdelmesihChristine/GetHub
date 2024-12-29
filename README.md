# GetHub: A Simple Repository Management System

## 1. Introduction
**GetHub** is a C++ application that models a simplified repository management system. It demonstrates core OOP principles such as doubly linked lists, deep copying, and encapsulation, while also showcasing a client component that clones repositories independently. The project emphasizes memory management through copy constructors and destructors, ensuring no leaks or shallow copies.

It allows you to:
- Create and manage repositories.
- Add or remove files within repositories.
- Demonstrate how a separate Client can clone a repository (deep copy).

---

## 2. Video Demo
*(Tip: Right-click and choose "Open Link in New Tab")*

[![Watch the video](https://img.youtube.com/vi/ApyV-565dYc/hqdefault.jpg)](https://youtu.be/ApyV-565dYc)

---

## 3. Features and Learning Outcomes
- **Doubly Linked Lists**: Used for storing files and repositories.
- **Deep Copy**: Custom copy constructors ensure proper memory management.
- **Encapsulation and Const-Correctness**: Promotes robust class design.
- **Client Cloning Functionality**: Enables creating a local copy of a remote repository.
- **Automated Testing**: Includes a testing framework for validation.

---

## 4. Project Structure
The project is organized as follows:

├── main.cc           // Entry point for the interactive GetHub program  
├── test.cc           // Entry point for the automated tests  
├── Makefile          // Build instructions  
├── Date.*            // Date class (stores & compares dates)  
├── File.*            // File class (manages file name, content, date)  
├── FileList.*        // Doubly linked list of File pointers  
├── Repo.*            // Represents a single repository  
├── RepoList.*        // Doubly linked list of Repo pointers  
├── GetHub.*          // Manages multiple Repo objects  
├── Client.*          // Client that clones (deep copies) a Repo from GetHub  
├── Control.*         // Orchestrates interactions between View, GetHub, and Client  
├── TestControl.*     // Orchestrates automated tests (uses Tester)  
├── Tester.*          // Captures and analyzes output for test verification  
├── View.*            // Boundary class for console I/O menus  
└── README.md         // This file

---

## 5. Core Concepts Implemented
1. **Doubly Linked Lists**  
   Both `FileList` and `RepoList` use a node structure with `prev` and `next` pointers.
2. **Deep Copy and Copy Constructors**  
   `Repo`, `FileList`, and other classes implement copy constructors to ensure no shallow copying of dynamically allocated memory.
3. **Encapsulation & Const-Correctness**  
   Classes mark appropriate methods as `const` and pass parameters as `const` where modifications are unnecessary.
4. **Client Cloning**  
   Demonstrates how a `Client` can create its own local copy of a `Repo` independently.

---

## 6. Quick Start
1. **Clone or download** this repository.  
2. **Build** the project using the provided Makefile:
   make

This produces two executables:
1. getHub (interactive program)
2. getHubtest (automated tests)

Run the interactive application:
./getHub

valgrind ./getHub

Run the automated tests:
./getHubtest

valgrind ./getHubtest

---

## 7. Usage Example
After running ./getHub, you will be presented with a menu of options:

1. Print all repos
2. Print repo
3. Print file
4. Remove repo
5. Remove file
6. Download repo (Client functionality)
7. Print client repo
8. Print file content (client)
You can follow the prompts to create, view, and delete repositories or files. The Client menu items let you clone a selected repository and view its files independently.

---

## 8. Classes Overview
**Date**  //Manages date fields (year, month, day), with lessThan/equals.
**File**  //Stores a file’s name, content, and date.
**FileList**  // Doubly linked list of File*. Handles adding, removing, and retrieving files.
**Repo** Holds a title, owner, and a FileList*. Includes a deep copy constructor.
**RepoList** Doubly linked list of Repo*. Adds, gets, and removes repos.
**GetHub** Manages Repo objects via RepoList, offering methods to add/delete repos and files.
**Client** Maintains a single Repo* that can be a deep copy of a Repo from GetHub.
**Control** Coordinates interactions between the user (via View), GetHub, and Client.
**View** Displays menus and gathers user input.
**TestControl & Tester** Automates test scenarios and verifies output.



