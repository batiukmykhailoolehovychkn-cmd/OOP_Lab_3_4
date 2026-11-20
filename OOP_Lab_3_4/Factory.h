#pragma once
#include "SymString.h"
#include "OctString.h"

class Factory {
public:
    static SymString* createSymString(const string& id, const string& value);
    static OctString* createOctString(const string& id, const string& value);
    static void deleteObject(SymString*& obj);
};