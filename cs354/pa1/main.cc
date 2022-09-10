#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

void blockCipher(string text) {

}

void streamCipher(string text) {

}

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

    string key;
    string plaintext;
    ifstream in(ifile);
    ifstream in2(kfile);
    if (!in) {
        error(program, "Can't open " + ifile);
        return 1;
    }
    if (!in2) {
        error(program, "Can't open " + kfile);
    }
    getline(in2, key);
    while (getline(in,plaintext)) {
        if(cipherfunc == "B") {
            blockCipher(plaintext);
        } else {
            streamCipher(plaintext);
        }
    }

    return 0;
}