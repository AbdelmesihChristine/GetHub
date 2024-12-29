#include "FileList.h"
#include <iostream>

// Constructor
FileList::FileList() : head(nullptr), tail(nullptr), numFiles(0) {}

// Copy constructor (deep copy)
FileList::FileList(const FileList& other) : FileList() {
    Node* current = other.head;
    while (current != nullptr) {
        // Create a new File (deep copy)
        File* newFile = new File(*current->data);
        add(newFile);
        current = current->next;
    }
}

// Destructor
FileList::~FileList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete->data;  // Delete the File
        delete toDelete;        // Delete the Node
    }
}

// Add function
bool FileList::add(File* file) {
    Node* newNode = new Node{file, nullptr, nullptr};

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && !file->lessThan(*current->data)) {
            current = current->next;
        }
        if (current == head) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (current == nullptr) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
    }
    numFiles++;
    return true;
}

// Get file by name
File* FileList::get(const std::string& name) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->getName() == name) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

// Get file by index
File* FileList::get(int index) const {
    if (index < 0 || index >= numFiles) return nullptr;
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }
    return current->data;
}

// Remove file by name
File* FileList::remove(const std::string& name) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->getName() == name) {
            File* file = current->data;
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            numFiles--;
            return file;
        }
        current = current->next;
    }
    return nullptr;
}

// Remove file by index
File* FileList::remove(int index) {
    if (index < 0 || index >= numFiles) return nullptr;
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }
    File* file = current->data;
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }
    delete current;
    numFiles--;
    return file;
}

// Get the number of files in the list
int FileList::getNumFiles() const {
    return numFiles;
}

bool FileList::isEmpty() const {
    return numFiles == 0;
}

bool FileList::isFull() const {
    return false; 
}

// Print all files
void FileList::print() const {
    Node* current = head;
    while (current != nullptr) {
        current->data->print();
        current = current->next;
    }
}