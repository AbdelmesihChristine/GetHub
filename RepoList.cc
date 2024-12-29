#include "RepoList.h"
#include <iostream>

// Constructor
RepoList::RepoList() : head(nullptr), tail(nullptr), numRepos(0) {}

// Destructor
RepoList::~RepoList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete->data;  // Delete the Repo
        delete toDelete;        // Delete the Node
    }
}

// Add Repo at the end of the list
bool RepoList::add(Repo* repo) {
    Node* newNode = new Node{repo, nullptr, tail};
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    numRepos++;
    return true;
}

// Get Repo by title
Repo* RepoList::get(const std::string& title) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->getTitle() == title) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

// Get Repo by index
Repo* RepoList::get(int index) const {
    if (index < 0 || index >= numRepos) return nullptr;
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }
    return current->data;
}

// Remove Repo by title
Repo* RepoList::remove(const std::string& title) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data->getTitle() == title) {
            Repo* repo = current->data;
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
            numRepos--;
            return repo;
        }
        current = current->next;
    }
    return nullptr;
}

// Remove Repo by index
Repo* RepoList::remove(int index) {
    if (index < 0 || index >= numRepos) return nullptr;
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }
    Repo* repo = current->data;
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
    numRepos--;
    return repo;
}

// Get the number of repos in the list
int RepoList::size() const {
    return numRepos;
}

bool RepoList::isEmpty() const {
    return numRepos == 0;
}

bool RepoList::isFull() const {
    return false; 
}