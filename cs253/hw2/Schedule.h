//test
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>


class show{
    public:
        show() = delete;
        show(std::string n, std::string c, int s, int l, bool a);
        std::string name;
        std::string channel;
        int start;
        int length;
        bool adult;
};

class Schedule{
    public:
        Schedule();
        Schedule(const Schedule &);
        ~Schedule();

        int add(std::string name, std::string channel, int start, int length);
        int add(std::string name, std::string channel, int start, int length, bool adult);
        [[nodiscard]] std::size_t size();
        bool find(std::string id);
        bool erase(int id);
        void printTime(int time, std::ostream &out);
        void print();
        void print(std::ostream &out);

        
    private:
        std::size_t s;
        std::vector<show> shows;
};