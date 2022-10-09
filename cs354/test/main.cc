#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

void error(string name,string wrong) {
    cerr << "There was a error in " << name << " : "  << wrong <<"\n";
    return;
}

int main (int argc, char* argv[]) {
    if (argc != 6) {
        error(argv[0],"Too many or not enough arguments!");
        return 1;
    }
    string program = argv[0];
    string cipherfunc = argv[1];
    string ifile = argv[2];
    string ofile = argv[3];
    string kfile = argv[4];
    string mode = argv[5];

    if (!(cipherfunc == "S" || cipherfunc == "B")) {
        error(program, "Bad Arguements " + cipherfunc);
        return -1;
    }
    if (!(mode == "D" || mode == "E")) {
        error(program, "Bad Arguements " + mode);
        return -1;
    }

    string key;
    string text;
    ifstream in(ifile);
    ifstream in2(kfile);
    ofstream out(ofile);
    if (!in) {
        error(program, "Can't open " + ifile);
        return 1;
    }
    if (!in2) {
        error(program, "Can't open " + kfile);
    }
    if (!out) {
        error(program, "Could not open output File " + ofile);
    }
    getline(in2, key);

    char mychar;
    string test = "";
    while ( in ) {
        test += in.get();
    }
    test = test.substr(0, test.size()-1);
    out << test;
    return 0;
}