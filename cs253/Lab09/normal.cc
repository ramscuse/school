#include <iostream>

using namespace std;

class Foo {
  public:
    double datum;
};

int main() {
    cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Foo) = " << sizeof(Foo) << '\n';
    Foo *p = new Foo;
    Foo *q = new Foo;
    for (int i = 0; i < 1000000; i++) {
      Foo *test = new Foo;
    }
    cout << "p=" << p << '\n'
	 << "q=" << q << '\n';
    delete p;
    delete q;
    return 0;
}
