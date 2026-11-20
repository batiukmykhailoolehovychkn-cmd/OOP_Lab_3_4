#include "SymString.h"

SymString::SymString() {
    setId("unnamed");
    setValue("");
}

SymString::SymString(const string& id, const string& value) {
    setId(id);
    setValue(value);
}

SymString::SymString(const SymString& other) {
    setId(other.id);
    setValue(other.value);
}

SymString::~SymString() {}

string SymString::getId() const { return id; }
string SymString::getValue() const { return value; }

void SymString::setId(const string& id) {
    this->id = id.empty() ? "unnamed" : id;
}

void SymString::setValue(const string& value) {
    this->value = value;
}

void SymString::Show() const {
    cout << "[SymString] ID: " << getId() << " | «наченн€: \"" << getValue() << "\"" << endl;
}

SymString& SymString::operator=(const SymString& other) {
    if (this != &other) {
        setId(other.getId());
        setValue(other.getValue());
    }
    return *this;
}

// якщо s2 Ї п≥др€дком s1 Ч видал€Їмо його; ≥накше повертаЇмо s1
SymString operator-(const SymString& s1, const SymString& s2) {
    string res = s1.getValue();
    if (!s2.getValue().empty()) {
        size_t pos = res.find(s2.getValue());
        if (pos != string::npos) {
            res.erase(pos, s2.getValue().length());
        }
    }
    return SymString(s1.getId() + "_minus_" + s2.getId(), res); // конструктор викликаЇ setId() та setValue()
}