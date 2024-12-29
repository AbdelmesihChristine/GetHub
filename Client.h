#ifndef CLIENT_H
#define CLIENT_H

#include "Repo.h"
#include "GetHub.h"

class Client {
private:
    Repo* repoPtr; // Pointer to the current Repo

public:
    Client();
    ~Client();

    void downloadRepo(const GetHub& getHub, int index);
    void printRepo() const;
    void printFileContents(int index) const;
};

#endif // CLIENT_H