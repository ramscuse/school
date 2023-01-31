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

void blockCipherEncrypt(string text, string key, ofstream& out) {
    int keycount = 0;
    string res = text;

    for (int i = 0; i < text.length(); i++) {
        res[i] = (text[i] ^ key[keycount]);
        keycount += 1;
        if (keycount == key.length()) {
            keycount = 0;
        }
    }

    int start = 0;
    int end = res.length() -1;
    keycount = 0;
    while (start < end) {
        if (key[keycount]%2 == 0) {
            start += 1;
        } else {
            char temp = res[start];
            res[start] = res[end];
            res[end] = temp;
            start += 1;
            end -= 1;
        }
        keycount += 1;
        if (keycount == key.length()) {
            keycount = 0;
        }
    }

    out << res;
}

string blockCipherDecrypt(string text, string key) {
    int start = 0;
    int end = text.length() -1;
    int keycount = 0;
    while (start < end) {
        if (key[keycount]%2 == 0) {
            start += 1;
        } else {
            char temp = text[start];
            text[start] = text[end];
            text[end] = temp;
            start += 1;
            end -= 1;
        }
        keycount += 1;
        if (keycount == key.length()) {
            keycount = 0;
        }
    }

    string res = text;
    keycount = 0;
    for (int i = 0; i < text.length(); i++) {
        res[i] = (text[i] ^ key[keycount]);
        keycount += 1;
        if (keycount == key.length()) {
            keycount = 0;
        }
    }

    return res;
}

void streamCipher(string text, string key, ofstream& out) {
    int keycount = 0;
    string res = text;

    for (int i = 0; i < text.length(); i++) {
        res[i] = (text[i] ^ key[keycount]);
        keycount += 1;
        if (keycount == key.length()) {
            keycount = 0;
        }
    }
    out << res;
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
    string text = "";
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

    while (in) {
        text += in.get();
    }
    text = text.substr(0, text.size()-1);

    if (cipherfunc == "S") {
        streamCipher(text, key, out);
    } else if(cipherfunc == "B") {
        if (mode == "E") {

            int padc = 16 - (text.length() % 16);
            if (padc < 16) {
                for (int i = 0; i < padc; i++) {
                    text += static_cast<char>(0x81);
                }
            }
            blockCipherEncrypt(text,key,out);

        } else if (mode == "D") {

            string plaintext = blockCipherDecrypt(text,key);
            int loc;
            for (int i = 0; i < plaintext.length(); i++) {
                if (plaintext[i] != static_cast<char>(0x81)) {
                    loc = i;
                }
            }
            plaintext = plaintext.substr(0,loc+1);
            out << plaintext;
            
        } else {
            error(program, "Bad Arguements " + mode);
            return -1;
        }
    }

    return 0;
}