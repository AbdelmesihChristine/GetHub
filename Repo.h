#ifndef REPO_H
#define REPO_H

#include <string>
#include "FileList.h"

class Repo {
private:
    std::string title;
    std::string owner;
    FileList* fileList;  

public:
    Repo(const std::string& title, const std::string& owner);
    Repo(const Repo& other); // Copy constructor
    ~Repo();

    bool lessThan(const Repo& otherRepo) const;
    bool equals(const Repo& otherRepo) const;
    const std::string& getTitle() const;

    bool addFile(const std::string& name, const std::string& content, const Date& date);
    bool removeFile(int index);
    int getNumFiles() const;

    void print() const;
    void printFiles() const;
    void printContents(int index) const;

    const File* getFile(int index) const;
};

#endif // REPO_H