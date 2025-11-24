#include "WorkersFiles.h"

#include <iostream>
using namespace std;

// Function prototypes for sorting
void Ascending(Worker*, int);
void goingDown(Worker*, int);

// Opens a new file for writing, returns true if successful
bool WorkersFile::openNewFileForWriting() 
{
    if (status == OPEN_W)
    {
        cout << "ERROR";
        return false;
    }
    iofile.open(fileName, ios::out);
    if (!iofile.is_open())
    {
        status = ERROR;
        cout << "ERROR";
        return false;
    }
    status = OPEN_W;
    return true;
}

// Opens an existing file for reading, returns true if successful
bool WorkersFile::openFileForReading()
{
    if (status == OPEN_R) 
    {
        cout << "ERROR";
        return false;
    }
    iofile.open(fileName, ios::in);
    if (!iofile.is_open()) 
    {
        status = ERROR;
        cout << "ERROR";
        return false;
    }
    status = OPEN_R;
    return true;
}

// Closes the file
void WorkersFile::closeFile() 
{
    iofile.close();
    status = CLOSED;
}

// Constructor that initializes the WorkersFile with a given filename
WorkersFile::WorkersFile(string name)
{
    fileName = name;
    size = 0;
    status = CLOSED;
    this->openNewFileForWriting();
    this->closeFile();
}

// Copy constructor
WorkersFile::WorkersFile(const WorkersFile& WorkersFileCopy)
{
    fileName = WorkersFileCopy.fileName;
    size = WorkersFileCopy.size;
    status = CLOSED;
}

// Destructor
WorkersFile::~WorkersFile()
{
    closeFile();
}

// Friend function to input WorkersFile data from an input stream
istream& operator>>(istream& is, WorkersFile& WorkersFileNew) 
{
    Worker worker1;
    WorkersFileNew.openNewFileForWriting();
    while (true) 
    {
        is >> worker1;
        if (0 == worker1) 
        {
            WorkersFileNew.closeFile();
            break;
        }
        WorkersFileNew.iofile << worker1;
        WorkersFileNew.size++;
    }
    return is;
}

// Friend function to output WorkersFile data to an output stream
ostream& operator<<(ostream& io, WorkersFile& WorkersFileCout)
{
    Worker worker1;
    if (WorkersFileCout.openFileForReading()) 
    {
        while (WorkersFileCout.iofile >> worker1) 
        {
            io << worker1;
        }
    }
    WorkersFileCout.closeFile();
    return io;
}

// Sorts the Worker records, ascending if flag is true, descending otherwise
void WorkersFile::sort(bool flag) 
{
    Worker* Workers = new Worker[size];
    openFileForReading();
    for (int i = 0; i < size; i++)
        iofile >> Workers[i];
    closeFile();
    if (flag)
        Ascending(Workers, size);
    else
        goingDown(Workers, size);
    openNewFileForWriting();
    for (int i = 0; i < size; i++)
        iofile << Workers[i];
    closeFile();
    delete[] Workers;
}

// Sorts the Worker records in ascending order
void Ascending(Worker* Workers, int size) 
{
    Worker temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++)
        {
            if (!(Workers[i].operator<(Workers[j])))
            {
                temp = Workers[i];
                Workers[i] = Workers[j];
                Workers[j] = temp;
            }
        }
    }
}

// Sorts the Worker records in descending order
void goingDown(Worker* Workers, int size)
{
    Worker temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++)
        {
            if ((Workers[i].operator<(Workers[j])))
            {
                temp = Workers[i];
                Workers[i] = Workers[j];
                Workers[j] = temp;
            }
        }
    }
}

// Overloaded subscript operator to access Worker records by index
Worker WorkersFile::operator[](const int index)
{
    Worker temp;
    openFileForReading();
    for (int i = 0; i < index + 1; i++)
        iofile >> temp;
    closeFile();
    return temp;
}

// Overloaded += operator to add a bonus to all Worker payments
WorkersFile& WorkersFile::operator+=(float bonus)
{
    Worker* Workers = new Worker[size];
    openFileForReading();
    for (int i = 0; i < size; i++)
        iofile >> Workers[i];
    closeFile();
    for (int i = 0; i < size; i++)
        Workers[i] += bonus;
    openNewFileForWriting();
    for (int i = 0; i < size; i++)
        iofile << Workers[i];
    closeFile();
    delete[] Workers;
    return *this;
}

// Overloaded + operator to combine two WorkersFile objects
WorkersFile WorkersFile::operator+(WorkersFile& WorkersFile1)
{
    Worker temp;
    string name = "all workers";
    WorkersFile newWorkersFile(name);
    newWorkersFile.openNewFileForWriting();
    openFileForReading();
    WorkersFile1.openFileForReading();
    while (this->iofile >> temp)
        newWorkersFile.iofile << temp;
    while (WorkersFile1.iofile >> temp)
        newWorkersFile.iofile << temp;
    closeFile();
    WorkersFile1.closeFile();
    newWorkersFile.closeFile();
    newWorkersFile.size = size + WorkersFile1.size;
    return newWorkersFile;
}

