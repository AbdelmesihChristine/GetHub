#include "GetHub.h"
#include <iostream>

GetHub::GetHub() {}

GetHub::~GetHub() {
}

void GetHub::addRepo(const std::string& title, const std::string& owner) {
    Repo* newRepo = new Repo(title, owner);
    if (!repoList.add(newRepo)) {
        std::cout << "Error: Could not add repo. RepoList might be full." << std::endl;
        delete newRepo; 
    }
}

const Repo* GetHub::getRepo(int index) const {
    if (index < 0 || index >= repoList.size()) {
        return nullptr; 
    }
    return repoList.get(index);
}

void GetHub::deleteRepo(int index) {
    Repo* repo = repoList.remove(index);
    if (!repo) {
        std::cout << "Error: Repo not found." << std::endl;
    } else {
        delete repo;
    }
}

int GetHub::getNumRepos() const {
    return repoList.size();
}

void GetHub::addFile(const std::string& repoTitle, const std::string& title, const std::string& content, const Date& date) {
    Repo* repo = repoList.get(repoTitle);
    if (!repo) {
        std::cout << "Error: Repo not found." << std::endl;
        return;
    }
    if (!repo->addFile(title, content, date)) {
        std::cout << "Error: Could not add file. Repo might be full." << std::endl;
    }
}

void GetHub::addFile(int repoIndex, const std::string& title, const std::string& content, const Date& date) {
    Repo* repo = repoList.get(repoIndex);
    if (!repo) {
        std::cout << "Error: Repo not found." << std::endl;
        return;
    }
    if (!repo->addFile(title, content, date)) {
        std::cout << "Error: Could not add file. Repo might be full." << std::endl;
    }
}

void GetHub::deleteFile(int repoIndex, int fileIndex) {
    Repo* repo = repoList.get(repoIndex);
    if (!repo) {
        std::cout << "Error: Repo not found." << std::endl;
        return;
    }
    if (!repo->removeFile(fileIndex)) {
        std::cout << "Error: File not found." << std::endl;
    }
}

void GetHub::printRepos() const {
    std::cout << "GetHub" << std::endl;
    std::cout << "========" << std::endl;
    for (int i = 0; i < repoList.size(); ++i) {
        std::cout << i << ") ";
        repoList.get(i)->print();
    }
}

void GetHub::printRepo(int index) const {
    Repo* repo = repoList.get(index);
    if (repo) {
        repo->printFiles();
    } else {
        std::cout << "Error: Repo not found." << std::endl;
    }
}

void GetHub::printFileContents(int repoIndex, int fileIndex) const {
    Repo* repo = repoList.get(repoIndex);
    if (repo) {
        repo->printContents(fileIndex);
    } else {
        std::cout << "Error: Repo not found." << std::endl;
    }
}