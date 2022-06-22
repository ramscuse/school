#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cmath>

int increase (int i) { return ++i; }
bool even(int i) { return i%2 == 0; }

using namespace std;

int main() {
    vector<short> pi = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4};
    string alpha="abcdefghijklmnopqrstuvwxyz", digits="0123456789";
    char cbuf[100] = { };	// contains 100 '\0' chars
    list<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    short powers[] = {1,2,4,8,16,32,64};
    int ibuf[100];		// contains unknown values

    cout << "Exercise 0\n";
    copy(alpha.begin(), alpha.end(), cbuf);
    cout << cbuf << '\n';
    cout << "Exercise 1\n";
    reverse(begin(cbuf),begin(cbuf) + 26);
    cout << cbuf << "\n";
    cout << "Exercise 2\n";
    transform(primes.begin(),primes.end(),ibuf, increase);
    for (int i=0; i<static_cast<int>(primes.size()); i++)
        cout << ibuf[i] << " ";
    cout << "\n";
    cout << "Exercise 3\n";
    if (any_of(primes.begin(), primes.end(), even)) {
        cout << "div 2\n";
    }
    if (any_of(primes.begin(), primes.end(), [](int i) {return i%42 ==0;})) {
        cout << "div 42\n";
    }
    cout << "Exercise 4\n";
    list<int>::iterator res;
    res = find(primes.begin(), primes.end(), 13);
    cout << *next(res,1) <<"\n";
    cout << "Exercise 5\n";
    cout << count(pi.begin(), pi.end(), 3) << "\n";
    cout << "Exercise 6\n";
    cout << count_if(pi.begin(), pi.end(), [](int i) {return i < 5;}) << "\n";
    cout << "Exercise 7\n";
    vector<short>::iterator res2;
    res2 = max_element(pi.begin(),pi.end());
    cout << pi[distance(pi.begin(), res2)] << "\n";
    cout << "Exercise 8\n";
    vector<short> copy = pi;
    sort(copy.begin(),copy.end());
    for (int i : copy)
        cout << i << " ";
    cout << "\n";
    cout << "Exercise 9\n";
    
    cout << "Exercise 10\n";
}
