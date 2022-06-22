//Homework 1 Jameson Walter
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<string> censorWords = {"alpha","beta","gamma","delta"};
string censored = "CENSORED";

string censor(string text) {
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

int main(int argc, char *argv[]) {
    if (argc != 1) {
        error(argv[0],"Too many arguments!");
        return 1;
    }
    string input; string output;
    while (getline(cin,input)) {
        output = censor(input);
        cout << output << "\n";
    }
}
