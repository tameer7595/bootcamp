//
// Created by tameer on 9/3/19.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H


#include <iostream>
#include <cassert>

using namespace std;

class String {

public:
    String();

    String(const String &);

    String(const char *);

    ~String();

    int length() const;


    void insert(unsigned int, String &);

    void operator=(const String &s);

    void operator+=(const String &);

    void operator+(const String &str);

    bool operator==(const String &);

    bool operator<=(const String &);

    bool operator<(const String &);

    bool operator>(const String &str);

    bool operator>=(const String &str);

    char &operator[](unsigned int);

    friend ostream &operator<<(ostream &os, const String &);
    String substring(int start,int end);

private:
    int m_size;
    char *m_buffer;

    int lenOfChar(const char *);
};

#endif //STRING_STRING_H