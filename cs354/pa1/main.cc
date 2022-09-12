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

char* pad(string block) {
    char* blockLoc = (char*) malloc(16*sizeof(char));
    if (blockLoc == NULL) {
        error("padding", "Problem allocating blocks");
        return NULL;
    }
    for (int i = 0; i < 16; i ++) {
        blockLoc[i] = 0x81;
    }
    for (int j = 0; j < block.length(); j++) {
        blockLoc[j] = block[j];
    }
    return blockLoc;
}

string removepad(char* block) {
    string res = "";
    
    for (int i = 0; i < 16; i ++) {
        if (block[i] != -127) {
            res += block[i];
        }
    }

    return res;
}

void blockCipherEncrypt(vector<char*> & blocks, string key, ofstream& out) {
    int keycount = 0;

    for (int i = 0; i != blocks.size(); i++) {
        for (int j = 0; j < 16; j++) {
            blocks[i][j] = blocks[i][j] ^ key[keycount];
            if (keycount == key.length()) {
                keycount = 0;
            }
        }
    }

    for (auto i = 0; i != blocks.size(); i++) {
        out << blocks[i];
    }
    out << "\n";
}

vector<char*> blockCipherDecrypt(vector<char*> & blocks, string key) {
    int keycount = 0;

    for (int i = 0; i != blocks.size(); i++) {
        for (int j = 0; j < 16; j++) {
            blocks[i][j] = blocks[i][j] ^ key[keycount];
            if (keycount == key.length()) {
                keycount = 0;
            }
        }
    }

    // for (auto i = 0; i != blocks.size(); i++) {
    //     cout << blocks[i] << "|";
    // }
    // cout << "\n";
    return blocks;
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
    out << res << "\n";
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

    if (cipherfunc == "S") {
        while (getline(in,text)) {
            streamCipher(text, key, out);
        }
    } else if(cipherfunc == "B") {
        if (mode == "E") {
            string block = "";
            while(getline(in,text)) {
                vector<char*> blocks;
                for (int i = 0; i < text.length(); i++) {
                    block += text[i];
                    if (block.length() == 16) {
                        char* blockLoc = (char*) malloc(16*sizeof(char));
                        if (blockLoc == NULL) {
                            error(program, "Problem allocating blocks");
                            return -1;
                        }
                        for (int j = 0; j < 16; j++) {
                            blockLoc[j] = block[j];
                        }
                        blocks.push_back(blockLoc);
                        block = "";
                    }
                }
                if (block.length() > 0) {
                    blocks.push_back(pad(block));
                }
                // for (auto i = 0; i != blocks.size(); i++) {
                //     cout << blocks[i] << "|";
                // }
                // cout << "\n";
                blockCipherEncrypt(blocks,key,out);
                for (int i = 0; i < blocks.size(); i++) {
                    free(blocks[i]);
                }
                block = "";
            }
        } else if (mode == "D") {
            string block = "";
            while(getline(in,text)) {
                vector<char*> blocks;
                for (int i = 0; i < text.length(); i++) {
                    block += text[i];
                    if (block.length() == 16) {
                        char* blockLoc = (char*) malloc(16*sizeof(char));
                        if (blockLoc == NULL) {
                            error(program, "Problem allocating blocks");
                            return -1;
                        }
                        for (int j = 0; j < 16; j++) {
                            blockLoc[j] = block[j];
                        }
                        blocks.push_back(blockLoc);
                        block = "";
                    }
                }
                // for (auto i = 0; i != blocks.size(); i++) {
                //     cout << blocks[i] << "|";
                // }
                // cout << "\n";

                vector<char*> res = blockCipherDecrypt(blocks,key);

                for (int i = 0; i < res.size() - 1; i++) {
                    out << res[i];
                }

                out << removepad(res[res.size()-1]);
                out << "\n";

                for (int i = 0; i < blocks.size(); i++) {
                    free(blocks[i]);
                }
            }
        } else {
            error(program, "Bad Arguements " + mode);
            return -1;
        }
    }

    return 0;
}