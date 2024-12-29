#include "Client.h"
#include <iostream>

Client::Client() : repoPtr(nullptr) {}

Client::~Client() {
    delete repoPtr;
}

void Client::downloadRepo (const GetHub& getHub, int index) {
    const Repo* sourceRepo = getHub.getRepo(index);
    if (sourceRepo == nullptr) {
        std::cout << "Error: Invalid repository index." << std::endl;
        return;
    }
    // Ensure previous repo pointer is deleted to avoid memory leaks
    delete repoPtr;
    repoPtr = new Repo(*sourceRepo); // Deep copy using copy constructor
}

void Client::printRepo() const {
    if (repoPtr == nullptr) {
        std::cout << "Error: No repository cloned." << std::endl;
        return;
    }
    repoPtr->printFiles();
}

void Client::printFileContents(int index) const {
    if (repoPtr == nullptr) {
        std::cout << "Error: No repository cloned." << std::endl;
        return;
    }
    const File* file = repoPtr->getFile(index);
    if (file == nullptr) {
        std::cout << "Error: Invalid file index." << std::endl;
        return;
    }
    file->printContents();
}