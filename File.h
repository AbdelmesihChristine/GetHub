#ifndef FILE_H 
#define FILE_H

#include <string>
#include "Date.h"

class File {
private:
    std::string name;
    std::string content;
    Date date;

public:
    // Constructor
    File(const std::string& name, const std::string& content, const Date& date);

    bool lessThan(const File& otherFile) const;
    bool equals(const File& otherFile) const;

    // Print functions
    void print() const;
    void printContents() const;

    // Getter for name
    const std::string& getName() const;
};

#endif // FILE_H