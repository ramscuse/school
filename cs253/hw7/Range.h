#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstddef>
#include <getopt.h>
#include <algorithm>
#include <set>
#include <iterator>


template <typename T>
class Range {
  private:
    T x; 
    T y;
  public:
    using value_type = T;
    Range() = delete;
    Range(T val) {
        x = val;
        y = val;
    }
    Range(T low, T high) {
        assign(low,high);
    }

    Range(const Range<T>& old) : x(old.x), y(old.y) {}
    ~Range() {}

    void assign (T low, T high) {
        if (low > high) {
            throw std::runtime_error("Range is out of Order. [min: " + std::to_string(low)
             + ", max: " + std::to_string(high) + "]\n");
        }
        x = low; y = high;
    }

    [[nodiscard]] T min() const {
        return x;
    }

    [[nodiscard]] T max() const {
        return y;
    }

    Range<T>& operator+=(const Range<T>& Range2) {
        std::multiset<T, std::less<T>> stuff;
        stuff.insert(min()+Range2.min());
        stuff.insert(min()+Range2.max());
        stuff.insert(max()+Range2.min());
        stuff.insert(max()+Range2.max());
        assign(*stuff.begin(), *(--stuff.end()));
        return *this;
    }

    Range<T>& operator-=(const Range<T>& Range2) { 
        std::multiset<T, std::less<T>> stuff;
        stuff.insert(min()-Range2.min());
        stuff.insert(min()-Range2.max());
        stuff.insert(max()-Range2.min());
        stuff.insert(max()-Range2.max());
        assign(*stuff.begin(), *(--stuff.end()));
        return *this;
    }

    Range<T>& operator*=(const Range<T>& Range2) { 
        std::multiset<T, std::less<T>> stuff;
	    stuff.insert(min()*Range2.min());
    	stuff.insert(min()*Range2.max());
	    stuff.insert(max()*Range2.min());
	    stuff.insert(max()*Range2.max());
	    assign(*stuff.begin(), *(--stuff.end()));
        return *this;
    }

    Range<T>& operator/=(const Range<T>& Range2) {
	    std::multiset<T, std::less<T>> stuff;
	    if (Range2.min() < 0 && Range2.max() > 0)
	        throw std::runtime_error("You shall not divide by 0!");
	    stuff.insert(min()/Range2.min());
	    stuff.insert(min()/Range2.max());
	    stuff.insert(max()/Range2.min());
	    stuff.insert(max()/Range2.max());
        assign(*stuff.begin(), *(--stuff.end()));
        return *this;
    }
};

template<typename T>
Range<T> operator+(const Range<T>& Range1, const Range<T>& Range2) {
    Range<T> solution(Range1);
    solution += Range2;
    return solution;
}

template<typename T>
Range<T> operator-(const Range<T>& Range1, const Range<T>& Range2) {
    Range<T> solution(Range1);
    solution -= Range2;
    return solution;
}

template<typename T>
Range<T> operator*(const Range<T>& Range1, const Range<T>& Range2) {
    Range<T> solution(Range1);
    solution *= Range2;
    return solution;
}

template<typename T>
Range<T> operator/(const Range<T>& Range1, const Range<T>& Range2) {
    Range<T> solution(Range1);
    solution /= Range2;
    return solution;
}

template<typename T>
[[nodiscard]] bool operator==(const Range<T>& Range1, const Range<T>& Range2) {
    return Range1.min()==Range2.min() && Range1.max()==Range2.max();
}

template<typename T>
[[nodiscard]] bool operator!=(const Range<T>& Range1, const Range<T>& Range2) {
    return !(Range1 == Range2);
}

template<typename T>
std::ostream& operator<<(std::ostream & os, Range<T> Range1) {
    os << "[" << Range1.min() << std::fixed << "," << Range1.max() << std::fixed << "]";
    return os;
}

template<typename T>
std::istream& operator>>(std::istream & is, Range<T> &Range1) {
    T x,y;
    char c;
    is >>  c >> x >> c >> y >> c;
    Range1.assign(x,y);
    return is;
}
