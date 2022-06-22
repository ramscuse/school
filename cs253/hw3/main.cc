//Homework 3 Jameson Walter
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string censor(string text, vector<string> & censorWords) {
    string censored = "CENSORED";
    for (int i = 0; i < static_cast<int>(censorWords.size()); i++) {
        string::size_type loc = text.find(censorWords[i]);
        while (loc!=string::npos) {
            bool okay = true;
            if (loc !=0) {
                if (isalpha(text[loc - 1]) || isalpha(text[loc + censorWords[i].size()])) {
                    okay = false;
                }
            } else {
                if (isalpha(text[loc + censorWords[i].size()])) {
                    okay = false;
                }
            }
            if (okay) {
                if (loc == 0) {
                    text = censored + text.substr(censorWords[i].size());
                } else {
                    text = text.substr(0, loc) + censored + text.substr(loc + censorWords[i].size());
                }
                loc = text.find(censorWords[i]);
            } else {
                loc = text.substr(loc + censorWords[i].size()).find(censorWords[i]);
            }
        }
    }
    return text;
}

void error(string name,string wrong) {
    cerr << "There was a error in " << name << " : "  << wrong <<"\n";
    return;
}

int findarg(string arg, int size, char *array[]) {      //returns the amount of item in the array
    int amount = 0;
    for (int i = 0; i < size; i++) {
        if (string(array[i]) == arg) {
            amount ++;
        }
    }
    return amount;
}

int main(int argc, char *argv[]) {
    vector<string> censorWords;
    vector<string> files;
    string program = argv[0];
    if (findarg("-",argc,argv) < 1) {
        error(program, "You must include a '-'");
        return 1;
    }
    if (findarg("-",argc,argv) > 1) {
        error(program, "You must include only one '-'");
        return 1;
    }
    int loc = 1;
    string s = argv[loc];
    while (s != "-") {
        for (char c : s) {
            if (!isalpha(c)) {
                error(program, "Bad Arguement " + s);
                return 1;
            }
        }
        for (string thing : censorWords) {
            if (thing == s) {
                error(program, "Bad Arguement " + s);
                return 1;
            }
        }
        censorWords.push_back(s);
        loc++;
        s = argv[loc];
    }
    loc++;
    while (loc < argc) {
        files.push_back(string(argv[loc]));
        loc++;
    }
    
    string input; string output;
    if (files.size() > 0) {
        for (string file : files) {
            ifstream in(file);
            if (!in) {
                error(program, "Can't open " + file);
                return 1;
            }
            while (getline(in, input)) {
                output = censor(input,censorWords);
                cout << output << "\n";
            }
        }
    } else {
        while (getline(cin,input)) {
            output = censor(input,censorWords);
            cout << output << "\n";
        }
        return 1;
    }
}