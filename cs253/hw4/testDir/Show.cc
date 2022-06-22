//Homework 4 Jameson Walter
#include "Show.h"
using namespace std;

Show::Show(string na, string ch, int st, int le, bool ad) : 
        n(na), c(ch), s(st), l(le), a(ad) {
    if (!testShow()) { throw runtime_error("Improper Values to Create Show!"); }
    static int idNumbers = 0;
    idNumber = idNumbers;
    idNumbers++;
}

string Show::name() const {
    return n;
}

string Show::channel() const {
    return c;
}

int Show::start() const {
    return s*15;
}

int Show::length() const {
    return l*15;
}

bool Show::adult() const {
    return a;
}

int Show::id() const {
    return idNumber;
}

bool Show::testShow() {
    if (!(start() < 24*4*15 && start() + length() <= 24*4*15 && start() >= 0 && length() > 0)
            || channel() == "" || name() == "" || start() == length()) {
        return false;
    }
    return true;
}