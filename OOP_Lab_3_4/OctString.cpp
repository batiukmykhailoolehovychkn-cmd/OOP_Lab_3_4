#include "OctString.h"
#include <sstream>

OctString::OctString() : SymString("unnamed_oct", "0") {}

OctString::OctString(const string& id, const string& value) : SymString(id, "0") {
    setValue(value);
}

OctString::OctString(const OctString& other) : SymString(other) {}

OctString::~OctString() {}

bool OctString::isValidOct(const string& val) {
    if (val.empty()) return false;
    for (char c : val) {
        if (c < '0' || c > '7') return false;
    }
    return true;
}

void OctString::setValue(const string& value) {
    if (isValidOct(value)) {
        SymString::setValue(value);
    }
    else {
        cerr << "Помилка: \"" << value << "\" не є коректним вісімковим числом! Встановлено \"0\"." << endl;
        SymString::setValue("0");
    }
}

unsigned long long OctString::toDecimal() const {
    return stoull(getValue(), nullptr, 8);
}

string OctString::fromDecimal(unsigned long long dec) {
    stringstream ss;
    ss << oct << dec;
    return ss.str();
}

void OctString::Show() const {
    cout << "[OctString] ID: " << getId() << " | Вісімкове значення: " << getValue() << endl;
}

void OctString::ShowBin() const {
    unsigned long long dec = toDecimal();
    string bin = "";
    if (dec == 0) {
        bin = "0";
    }
    else {
        while (dec > 0) {
            bin = (dec % 2 == 0 ? "0" : "1") + bin;
            dec /= 2;
        }
    }
    cout << "[OctString] ID: " << getId() << " | Двійкове зображення: " << bin << endl;
}

OctString& OctString::operator=(const OctString& other) {
    if (this != &other) {
        SymString::operator=(other);
    }
    return *this;
}

OctString operator-(const OctString& s1, const OctString& s2) {
    unsigned long long v1 = s1.toDecimal();
    unsigned long long v2 = s2.toDecimal();
    unsigned long long diff = (v1 >= v2) ? (v1 - v2) : 0;
    return OctString(s1.getId() + "_minus_" + s2.getId(), OctString::fromDecimal(diff));
}