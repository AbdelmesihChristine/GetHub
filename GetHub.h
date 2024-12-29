#ifndef GETHUB_H
#define GETHUB_H

#include "RepoList.h"

class GetHub {
private:
    RepoList repoList;

public:
    GetHub();
    ~GetHub();

    const Repo* getRepo(int index) const;

    void addRepo(const std::string& title, const std::string& owner);
    void deleteRepo(int index);
    int getNumRepos() const;

    void addFile(const std::string& repoTitle, const std::string& title, const std::string& content, const Date& date);
    void addFile(int repoIndex, const std::string& title, const std::string& content, const Date& date);

    void deleteFile(int repoIndex, int fileIndex);

    void printRepos() const;
    void printRepo(int index) const;
    void printFileContents(int repoIndex, int fileIndex) const;
};

#endif // GETHUB_H