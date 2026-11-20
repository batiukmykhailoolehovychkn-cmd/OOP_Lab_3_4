#pragma once
#include <iostream>
#include <string>

using namespace std;

class SymString {
private:
    string id;
    string value;

public:
    SymString();
    SymString(const string& id, const string& value);
    SymString(const SymString& other);
    virtual ~SymString();

    string getId() const;
    string getValue() const;
    void setId(const string& id);
    virtual void setValue(const string& value);

    virtual void Show() const;

    SymString& operator=(const SymString& other);
    friend SymString operator-(const SymString& s1, const SymString& s2);
};