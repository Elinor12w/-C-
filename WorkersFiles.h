#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
using namespace std;

// Enumeration for file status
enum FILE_STATUS { ERROR, CLOSED, OPEN_R, OPEN_W };

class WorkersFile 
{
private:
    string fileName;        // Name of the file
    fstream iofile;         // File stream for input/output operations
    FILE_STATUS status;     // Status of the file
    int size;               // Number of Worker records in the file

    // Opens a new file for writing, returns true if successful
    bool openNewFileForWriting();

    // Opens an existing file for reading, returns true if successful
    bool openFileForReading();

    // Closes the file
    void closeFile();

public:
    // Constructor that initializes the WorkersFile with a given filename
    WorkersFile(string);

    // Copy constructor
    WorkersFile(const WorkersFile&);

    // Destructor
    ~WorkersFile();

    // Friend function to input WorkersFile data from an input stream
    friend istream& operator>>(istream&, WorkersFile&);

    // Friend function to output WorkersFile data to an output stream
    friend ostream& operator<<(ostream&, WorkersFile&);

    // Sorts the Worker records, ascending if flag is true, descending otherwise
    void sort(bool flag = true);

    // Overloaded subscript operator to access Worker records by index
    Worker operator[](const int);

    // Overloaded += operator to add a bonus to all Worker payments
    WorkersFile& operator+=(float);

    // Overloaded + operator to combine two WorkersFile objects
    WorkersFile operator+(WorkersFile&);
};

#pragma once
