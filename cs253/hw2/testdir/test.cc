#include "Schedule.h"
#include <cassert>
#include <string>
 
using namespace std;
 
int main() {
    Schedule s;
    s.add("CSU Tonight!", "CSU", 23*4, 4, true);
    int id = s.add("Secret Agent XN-10756010", "Spy Television", 0, 4);
    s.add("Keeping up with the Applins", "FCTV", 9*4, 2);
    s.add("Jeopardy"s, "FCTV", 0, 5);


//  Cases where the program should print -1
    cout << s.add("Bad show","FCTV", 1, 6) << "\n";
    cout << s.add("", "Fox", 2, 8) << "\n";
    cout << s.add("Bad Show", "", 7, 9) << "\n";
    cout << s.add("Bad Show", "NBC", 5,5) << "\n";
    cout << s.add("Bad show", "CBS", 23*4, 8) << "\n";

//  Cases that should be false
    assert(!s.erase(8));
    assert(!s.erase(-3));

    s.print();
    cout << "---\n";
    assert(s.size() == 4);
    assert(!s.erase(-17));
    assert(s.size() == 4);
    assert(s.erase(id));
    assert(s.size() == 3);
    s.print(cout);
    return 0;
}
