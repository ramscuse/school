#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main() {
	vector<int> list;
	int input;
	while (cin >> input && input!=0) {
		list.push_back(input);
	}
	for (auto i : list) {
		cout << i << '\n';
	}
	
	ifstream in("/etc/resolv.conf");
	char c;
	string file;
	while (in.get(c)) {
		file = file + c;
	}

	multiset<char> ms;
	for (int i = 0; i < static_cast<int>(file.size()); i++) {
		ms.insert(file[i]);
	}
	
	set<char> set;
	for (char i : ms) {
		set.insert(i);
	}
	
	cout << "string: size=" << file.size() << " " << file << "\n";
	cout << "set: size=" << set.size() << " ";
	for (char i : set) {
		cout << i;
	}
	cout << "\n";
	cout << "multiset: size=" << ms.size() << " ";
	for (char i : ms) {
		cout << i;
	}
	cout << "\n";
	/* Question 7 
 * 	The size of the string 113 and it remains the same in the multiset because the multiset keeps all
 * 	the characters in the original string, just organizes them. The decrease in size happens with the set
 * 	because sets don't allow for repeats meaning it only contain one version of each char found in 
 * 	the string.
	*/
	return 0;
}
