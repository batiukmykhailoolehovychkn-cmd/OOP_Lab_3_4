#include "Factory.h"

SymString* Factory::createSymString(const string& id, const string& value) {
    return new SymString(id, value);
}

OctString* Factory::createOctString(const string& id, const string& value) {
    return new OctString(id, value);
}

void Factory::deleteObject(SymString*& obj) {
    if (obj != nullptr) {
        delete obj;
        obj = nullptr;
    }
}