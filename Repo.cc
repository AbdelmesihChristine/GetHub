#include "Repo.h"
#include <iostream>

// Constructor
Repo::Repo(const std::string& title, const std::string& owner) 
    : title(title), owner(owner) {
    fileList = new FileList();  // Dynamically allocate FileList
}

// Copy constructor (deep copy)
Repo::Repo(const Repo& other)
    : title(other.title), owner(other.owner) {
    fileList = new FileList(*other.fileList);
}

// Destructor
Repo::~Repo() {
    delete fileList;  // Delete the dynamically allocated FileList
}

const std::string& Repo::getTitle() const {
    return title;
}

// lessThan function
bool Repo::lessThan(const Repo& otherRepo) const {
    return title < otherRepo.title;
}

// equals function
bool Repo::equals(const Repo& otherRepo) const {
    return (title == otherRepo.title) && (owner == otherRepo.owner);
}

// Add a file to the repo
bool Repo::addFile(const std::string& name, const std::string& content, const Date& date) {
    File* newFile = new File(name, content, date);
    return fileList->add(newFile);  // Add file to the FileList
}


// Remove file by index
bool Repo::removeFile(int index) {
    File* file = fileList->remove(index);
    if (file) {
        delete file;  // Delete the removed File
        return true;
    }
    return false;
}

// Get the number of files in the repo
int Repo::getNumFiles() const {
    return fileList->getNumFiles();
}

// Print repo metadata
void Repo::print() const {
    std::cout << "Repo: " << title << std::endl;
    std::cout << "Owner: " << owner << std::endl;
}

// Print repo metadata and all files
void Repo::printFiles() const {
    print();
    for (int i = 0; i < getNumFiles(); ++i) {
        std::cout << i << ") ";
        fileList->get(i)->print();
    }
}

// Print contents of a file by index
void Repo::printContents(int index) const {
    File* file = fileList->get(index);
    if (file) {
        file->printContents();
    } else {
        std::cout << "Invalid file index." << std::endl;
    }
}

// Get File by index
const File* Repo::getFile(int index) const {
    return fileList->get(index);
}