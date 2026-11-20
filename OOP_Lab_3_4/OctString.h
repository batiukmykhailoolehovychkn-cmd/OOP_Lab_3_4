#pragma once
#include "SymString.h"

class OctString : public SymString {
public:
    OctString();
    OctString(const string& id, const string& value);
    OctString(const OctString& other);
    ~OctString() override;

    static bool isValidOct(const string& val);
    unsigned long long toDecimal() const;
    static string fromDecimal(unsigned long long dec);

    void setValue(const string& value) override;
    void Show() const override;
    void ShowBin() const;

    OctString& operator=(const OctString& other);
    friend OctString operator-(const OctString& s1, const OctString& s2);
};