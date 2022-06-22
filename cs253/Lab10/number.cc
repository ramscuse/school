#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Number {
  public:
    Number() = default;
    Number(const Number &) = default;
    Number(int v) : value(v) {}
    Number& operator=(int n) { value = n; return *this; }
    operator int() const { return value; }
  private:
    int value = 0;			// default value unless otherwise given
};

istream& operator>>(istream &is, Number &rhs) {
    string n;
    vector<string> numbers = {"one","two","three","four","five"};
    is >> n;
    for(int i = 0; i < static_cast<int>(numbers.size()); i++) {
      if (n == numbers[i]) {
        rhs = i+1;
        return is;
      }
    }
    rhs = stoi(n);
    return is;
}


int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five");

    while (ss >> n)
	  cout << n << ' ';
    cout << '\n';
}
