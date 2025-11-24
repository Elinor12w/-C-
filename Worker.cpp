#include "Worker.h"

#include <iostream>
using namespace std;

// Default constructor initializing member variables
Worker::Worker() : num(0), name(""), payment(0) {}

// Overloaded += operator to add a bonus to the payment
Worker& Worker::operator+=(const float bonus) {
    payment += bonus;
    return *this;
}

// Overloaded < operator to compare workers based on their payment
bool Worker::operator<(const Worker& WorkerBig) const {
    if (payment < WorkerBig.payment)
        return true;
    return false;
}

// Friend function to check equality between a long value and the worker's num
bool operator==(const long& num, const Worker& WorkerSame) {
    if (num == WorkerSame.num)
        return true;
    return false;
}

// Friend function to check equality between a string value and the worker's name
bool operator==(const string& name, const Worker& WorkerSame) 

{
    if (name == WorkerSame.name)
        return true;
    return false;
}

// Friend function to input worker data from an input stream
istream& operator>>(istream& is, Worker& WorkerCin)
{
    is >> WorkerCin.num;
    is >> WorkerCin.name;
    is >> WorkerCin.payment;
    return is;
}

// Friend function to output worker data to an output stream
ostream& operator<<(ostream& os, const Worker& WorkerCout)
{
    os << WorkerCout.num << " ";
    os << WorkerCout.name << " ";
    os << WorkerCout.payment << endl;
    return os;
}



