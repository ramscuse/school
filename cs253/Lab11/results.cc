#include <iomanip>	// for right, setw
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    friend ostream& operator <<(ostream &os, const BarGraph& bg) {
        for (const auto &val : bg.data) {
            os << right << setw(10) << val.first << ' '
                << string(val.second, '*') << "\n";
        }
        os << "\n";
        return os;
    }
    private:
    map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
  public:
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    friend std::ostream& operator <<(std::ostream &os, const BarGraph<bool>& bg) {
        os << "     false " << string(bg.false_count, '*') << "\n"
              "      true " << string(bg.true_count,  '*') << "\n\n";
        return os;
    }
  private:
    unsigned false_count = 0, true_count = 0;
};

template<>
class BarGraph<char> {
    public:
    void operator+=(const char c) {
        charcount[int(c)] = charcount[int(c)] + 1;
    }
    void operator+=(const string s) {
        for (char c : s) {
            charcount[int(c)] = charcount[int(c)] + 1;
        }
    }
    friend ostream& operator <<(ostream &os, const BarGraph& bg) {
        int c = 0;
        for (const auto &val : bg.charcount) {
            if(val > 0)
                os << right << setw(10) << char(c) << ' '
                   << val << "\n";
            c++;
        }
        os << "\n";
        return os;
    }
    private:
    int charcount[128] = {0};
};

int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta;

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    cout << gamma;

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    delta += "Colorado";
    cout << delta;

    return 0;
}
