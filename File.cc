#include "File.h"
#include <iostream>

// Constructor
File::File(const std::string& name, const std::string& content, const Date& date) 
    : name(name), content(content), date(date) {}

// lessThan function 
bool File::lessThan(const File& otherFile) const {
    // Compare file names alphabetically
    if (name < otherFile.name) {
        return true;
    } else if (name == otherFile.name) {
        // If names are identical, order by last modified date
        return date.lessThan(otherFile.date);
    } else {
        return false;
    }
}

// equals function
bool File::equals(const File& otherFile) const {
    // Check for equality based on name and date, ignoring content
    return (name == otherFile.name) && date.equals(otherFile.date);
}

// Print (File title and date)
void File::print() const {
    std::cout << "File: " << name << std::endl;
    std::cout << "Date added: ";
    date.print();
    std::cout << std::endl;
}

// Print file metadata and contents
void File::printContents() const {
    print(); 
    std::cout << "Contents: " << content << std::endl;
}

// Getter for name
const std::string& File::getName() const {
    return name;
}