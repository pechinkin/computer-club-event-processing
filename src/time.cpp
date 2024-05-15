#include "time.hpp"

Time::Time(int h, int m): hours(h), minutes(m) {};

int Time::toMinutes() {
    return hours * 60 + minutes;
};

