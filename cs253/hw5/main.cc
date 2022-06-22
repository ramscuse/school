//Homework 3 Jameson Walter
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <getopt.h>
#include <algorithm>

using namespace std;

string censor(string text, vector<string> & censorWords, string censored) {
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

string independentcensor(string text, vector<string> & censorWords, string censored) {
    string lowtext = text;
    transform(lowtext.begin(),lowtext.end(),lowtext.begin(), ::tolower);
    for (int i = 0; i < static_cast<int>(censorWords.size()); i++) {
        string word = censorWords[i];
        transform(word.begin(),word.end(),word.begin(), ::tolower);
        string::size_type loc = lowtext.find(word);
        while (loc!=string::npos) {
            bool okay = true;
            if (loc !=0) {
                if (isalpha(text[loc - 1]) || isalpha(text[loc + word.size()])) {
                    okay = false;
                }
            } else {
                if (isalpha(text[loc + word.size()])) {
                    okay = false;
                }
            }
            if (okay) {
                if (loc == 0) {
                    text = censored + text.substr(word.size());
                    lowtext = censored + lowtext.substr(word.size());
                } else {
                    text = text.substr(0, loc) + censored + text.substr(loc + word.size());
                    lowtext = lowtext.substr(0, loc) + censored + lowtext.substr(loc + word.size());
                }
                loc = lowtext.find(word);
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
    if (argc < 2) {
        error("input","not enough arguements");
        return 1;
    }

    int option = 0;
    vector<string> censorWords;
    vector<string> files;
    string censored = "CENSORED";
    string program = argv[0];
    int rflag = 0, iflag = 0, vflag = 0;
    string word;

    while ((option = getopt(argc, argv, "+r:ic:v")) != -1) {
         switch (option) {
            case 'r' :
                rflag++;
                if (rflag > 1) {
                    error(program, "Can't use -r more than once!");
                    return 1;
                }
                if (optarg) {
                    censored = optarg;
                }
                break;
            case 'c' :
                if (optarg) {
                    word = optarg;
                    for (char c : word) {
                        if (!isalpha(c)) {
                            error(program, "Bad Arguement " + word);
                            return 1;
                        }
                    }
                    for (string thing : censorWords) {
                        if (thing == word) {
                            error(program, "Bad Arguement " + word);
                            return 1;
                        }
                    }
                    censorWords.push_back(word);
                }
                break;
            case 'i' :
                if (iflag == 0) {
                    iflag = 1;
                }
                break;
            case 'v' :
                if (vflag == 0) {
                    vflag = 1;
                }
                break;
            default:
                error("your flags","Sometimng was wrong with your input!");
                return 1;
         }
    }
    int loc = optind;
    while (loc < argc) {
        files.push_back(string(argv[loc]));
        loc++;
    }

    string input; string output;
    if (files.size() > 0) {
        for (string file : files) {
            if (vflag) {
                cout << "Readingstop " << file << "\n";
            }
            ifstream in(file);
            if (!in) {
                error(program, "Can't open " + file);
                return 1;
            }
            while (getline(in, input)) {
                if (iflag) {
                    output = independentcensor(input,censorWords,censored);
                } else {
                    output = censor(input,censorWords,censored);
                }
                cout << output << "\n";
            }
        }
    } else {
        if (vflag) {
            cout << "Reading standard input.\n";
        }
        while (getline(cin,input)) {
            if (iflag) {
                output = independentcensor(input,censorWords,censored);
            } else {
                output = censor(input,censorWords,censored);
            }
            cout << output << "\n";
        }
        return 1;
    }
}