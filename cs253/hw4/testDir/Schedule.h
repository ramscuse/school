#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "Show.h"

class Schedule{
    public:
        Schedule();
        Schedule(const Schedule &);
        ~Schedule();

        int add(std::string name, std::string channel, int start, int length);
        int add(std::string name, std::string channel, int start, int length, bool adult);
        int add(Show s);
        bool testShow(Show s);
        [[nodiscard]] std::size_t size();
        int search(int id);
        bool erase(int id);
        void printTime(int time, std::ostream &out);
        void print();
        void print(std::ostream &out);

        Schedule& operator+=(const Show& s);
        Schedule& operator+=(const Schedule& s);
        Schedule& operator-=(const int& );
        Show& operator[](size_t);
        
    private:
        int idMaker = 0;
        std::size_t NumberOfShows;
        std::vector<Show> shows;
};

Schedule operator+(const Schedule&, const Schedule&);
std::ostream& operator<<(std::ostream &, Schedule&);