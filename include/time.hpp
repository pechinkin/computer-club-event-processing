#ifndef TIME_HPP
#define TIME_HPP
#include <iostream>

using namespace std;

struct Time {
    int hours;
    int minutes;
    Time(int h, int m);
    int toMinutes();
    bool operator>=(Time& other);
    bool operator<(Time& other);
    Time operator-(Time& other);
    Time& operator+=(Time& other);

    friend std::ostream& operator<<(std::ostream& os, Time time);

};
#endif