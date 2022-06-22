//Homework 2 Jameson Walter
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "Schedule.h"
using namespace std;

show::show(string n, string c, int s, int l, bool a) {
    name = n;
    channel = c;
    start = s;
    length = l;
    adult = a;
}

Schedule::Schedule() {
    s = 0;
}

Schedule::Schedule(const Schedule &rhs) : s(rhs.s), shows(rhs.shows) {}

Schedule::~Schedule() {}

int Schedule::add(string name, string channel, int start, int length) {
    return add(name, channel,start, length, false);
}

int Schedule::add(string name, string channel, int start, int length, bool adult) {
    if (!(start < 24*4 && start + length <= 24*4 && start >= 0 && length > 0)
            || channel == "" || name == "" || start == length) {
        return -1;
    }
    if(shows.size() > 0){
        for (show test : shows) {
            if (test.channel == channel) {
                if ((start > test.start && start < test.length + test.start) ||
                    (start + length > test.start && start + length < test.length + test.start)) {
                        return -1;
                    }
            }
        }
    }
    s += 1;
    show thing(name,channel,start,length,adult);
    shows.push_back(thing);
    return static_cast<int>(s) - 1;
}

[[nodiscard]] size_t Schedule::size() {
    return s;
}

bool Schedule::erase(int id) {
    if (id < static_cast<int>(s) && id >= 0 && !shows.empty()) {
        shows.erase(shows.begin() + id);
        s -= 1;
        return true;
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
    for (show next : shows) {
        int startHour = next.start/4;
        int startMin = (next.start % 4) * 15;
        int endHour =  (next.start + next.length) / 4;
        int endMin = ((next.start + next.length) % 4) * 15;
        printTime(startHour,out);
        out << ":";
        printTime(startMin,out);
        out << "-";
        printTime(endHour,out);
        out << ":";
        printTime(endMin,out);
        out << " " << next.channel << " " << next.name;
        if (next.adult) {
            out << '*';
        }
        out << "\n";
    }
}