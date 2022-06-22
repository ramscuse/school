#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>


class Show{
    public:
        Show() = delete;
        Show(std::string n, std::string ch, int si, int le, bool ad = false);
        std::string name() const;
        std::string channel() const;
        int start() const;
        int length() const;
        bool adult() const;
        int id() const;
        bool testShow();
    private:
        std::string n;
        std::string c;
        int s;
        int l;
        bool a;
        int idNumber;
};