#include "Schedule.h"
#include <cassert>
#include <string>
 
using namespace std;
 
int main() {
    
    Schedule s;
    cout << s.add("CSU Tonight!", "CSU", 23*4, 4, true);
    int id = s.add("Secret Agent XN-10756010", "Spy Television", 0, 4);
    cout << id;
    cout << s.add("Keeping up with the Applins", "FCTV", 9*4, 2);
    cout << s.add("Jeopardy"s, "FCTV", 0, 5) << "\n";


//  Cases where the program should print -1 or throw error
    cout << s.add("Bad show","FCTV", 1, 6) << "\n";
//    cout << s.add("", "Fox", 2, 8) << "\n";
//    cout << s.add("Bad Show", "", 7, 9) << "\n";
//    cout << s.add("Bad Show", "NBC", 5,5) << "\n";
//    cout << s.add("Bad show", "CBS", 23*4, 8) << "\n";

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
    cout << "---------\n";

//  New Test Cases
    Schedule s1;
    Show a("Secret Agent XN-13115306", "Spy Television", 0, 7);
    const Schedule s2(s1);
    const Show b("War War War", "War", 7, 24*4-7, true);
    assert(b.name() == "War War War");
    assert(b.channel() == "War");
    assert(b.start() == 105);
    assert(b.length() == 1335);
    assert(!a.adult());
    assert(b.adult());
    assert(!(a.id() < 0));
    assert(!(b.id() < 0));
    assert(a.id() != b.id());
    cout << a.id() << " " << b.id() << "\n";
    s1 += a;
    s1 += b;
    cout << s1 << "---\n";
    assert(s1.size() == 2);
    bool caught = false;
    try {
        s -= -16;
    }
    catch (const runtime_error &) {
        caught = true;
    }
    assert(caught);
    assert(s1.size() == 2);
    cout << a.id() << " " << b.id() << "\n";
    s1 -= a.id();
    assert(s1.size() == 1);
    cout << s1 << "---\n";
    s1 -= b.id();
    assert(s1.size() == 0);
    cout << s1 << "---\n";
 
    Schedule love;
    love += Show("Love Isthmus", "LUV", 0, 7, true);
    Schedule war;
    war += Show("Trek Wars: Spock vs. Vader", "SyFi", 0, 7, false);
    Schedule life;
    life = s2;          // will soon be overwritten
    life += a;          // will soon be overwritten
    life = love+war;
    assert(life.size()==2);
    cout << life << "---\n";
    assert(life[0].channel() == "LUV"  || life[1].channel() == "LUV");
    assert(life[0].channel() == "SyFi" || life[1].channel() == "SyFi");

    caught=false;
    try {
        cout << life[987].name();
    }
    catch (const range_error &r) {
        caught = true;
        const string message = r.what();
        assert(message.find("987") != string::npos);    // bad index
        assert(message.find("2") != string::npos);      // current size
    }
    assert(caught);
    return 0;
}
