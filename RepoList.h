#ifndef REPOLIST_H
#define REPOLIST_H

#include <string>
#include "Repo.h"

class RepoList {
private:
    struct Node {
        Repo* data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    int numRepos;

public:
    RepoList();
    ~RepoList();

    bool add(Repo* repo);              
    Repo* get(const std::string& title) const; 
    Repo* get(int index) const;        
    Repo* remove(const std::string& title);     
    Repo* remove(int index);           

    int size() const;  
    bool isEmpty() const;
    bool isFull() const;        
};

#endif // REPOLIST_H