#ifndef FILELIST_H
#define FILELIST_H

#include <string>
#include "File.h"

class FileList {
private:
    struct Node {
        File* data;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    int numFiles;

public:
    FileList();
    FileList(const FileList& other); // Copy constructor
    ~FileList();

    bool add(File* file);
    File* get(const std::string& name) const;
    File* get(int index) const;
    File* remove(const std::string& name);
    File* remove(int index);

    int getNumFiles() const;
    bool isEmpty() const;
    bool isFull() const;

    void print() const;
};

#endif // FILELIST_H