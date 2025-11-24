#pragma once
#include <iostream>
using namespace std;

class Worker
{
private:
    long num;         // Worker number/ID
    string name;      // Worker's name
    float payment;    // Worker's payment


public:
    
    // Default constructor
    Worker();

    // Overloaded += operator to add a float value to the payment
    Worker& operator+=(const float);

    // Overloaded < operator to compare workers based on their payment
    bool operator<(const Worker&) const;

    // Friend function to check equality between a long value and the worker's num
    friend bool operator==(const long&, const Worker&);

    // Friend function to check equality between a string value and the worker's name
    friend bool operator==(const string&, const Worker&);

    // Friend function to input worker data from an input stream
    friend istream& operator>>(istream&, Worker&);

    // Friend function to output worker data to an output stream
    friend ostream& operator<<(ostream&, const Worker&);
};

