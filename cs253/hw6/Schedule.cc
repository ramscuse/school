//Homework 4 Jameson Walter
#include "Schedule.h"
using namespace std;

Schedule::Schedule() {
    NumberOfShows = 0;
}

Schedule::Schedule(const Schedule &rhs) : NumberOfShows(rhs.NumberOfShows), shows(rhs.shows) {}

Schedule::~Schedule() {}

int Schedule::add(string name, string channel, int start, int length) {
    return add(name,channel,start,length,false);
}

int Schedule::add(string name, string channel, int start, int length, bool adult) {
    Show thing(name,channel,start,length,adult);
    return add(thing);
}

int Schedule::add(Show s) {
    if (!testShow(s)) { return -1; }
    NumberOfShows += 1;
    shows.push_back(s);
    return s.id();
}

bool Schedule::testShow(Show s) {
    if (!s.testShow()) {
        return false;
    }
    if(shows.size() > 0){
        for (Show test : shows) {
            if (test.channel() == s.channel()) {
                if ((s.start() > test.start() && s.start() < test.length() + test.start()) ||
                    (s.start() + s.length() > test.start() && s.start() + s.length() < test.length() + test.start())) {
                        return false;
                    }
            }
        }
    }
    return true;
}

[[nodiscard]] size_t Schedule::size() {
    return NumberOfShows;
}

bool Schedule::erase(int id) {
    if (id >= 0 && !shows.empty()) {
        int i = 0, loc = -1;
        for (Show look : shows) {
            if (look.id() == id) {
                loc = i;
            }
            i++;
        }
        if (loc >= 0){
            shows.erase(shows.begin() + loc);
            NumberOfShows -= 1;
            return true;
        }
    }
    return false;
}

void Schedule::printTime(int time, ostream &out) {
    if (time < 10) {
        out << '0' << time;
    } else {
        out << time;
    }
}

void Schedule::print() {
    print(cout);
}

void Schedule::print(ostream &out) {
    for (Show next : shows) {
        int startHour = next.start()/60;
        int startMin = (next.start() % 60);
        int endHour =  (next.start() + next.length()) / 60;
        int endMin = ((next.start() + next.length()) % 60);
        printTime(startHour,out);
        out << ":";
        printTime(startMin,out);
        out << "-";
        printTime(endHour,out);
        out << ":";
        printTime(endMin,out);
        out << " " << next.channel() << " " << next.name();
        if (next.adult()) {
            out << '*';
        }
        out << "\n";
    }
}

Schedule &Schedule::operator+=(const Show &s) {
    if (add(s) < 0) {
        throw runtime_error("Can't Add " + s.name());
    }
    return *this;
}

Schedule &Schedule::operator+=(const Schedule &s) {
    for (Show next : s.shows) {
        if (!testShow(next))
            throw runtime_error("Can't Add " + next.name());
    }
    for (Show next : s.shows) {
        add(next);
    }
    return *this;
}

Schedule &Schedule::operator-=(const int &i) {
    if (i<0) {
        throw runtime_error("Given a bad id: " + to_string(i));
    }
    if (!erase(i)) {
        throw runtime_error("Could not remove at: " + to_string(i));
    }
    return *this;
}

Show& Schedule::operator[](size_t i) {
    if (i >= NumberOfShows) {
        string msg = "That index " + to_string(i) + "was to big for schedule with size " + to_string(NumberOfShows);
        throw range_error(msg);
    }
    return shows[i];
}

Schedule operator+(const Schedule &s, const Schedule &c) {
    Schedule thing = s;
    thing += c;
    return thing;
}

std::ostream& operator<<(std::ostream &os, Schedule &s) {
    s.print(os);
    return os;
}