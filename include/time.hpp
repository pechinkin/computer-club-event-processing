#ifndef TIME_HPP
#define TIME_HPP
struct Time {
    int hours;
    int minutes;
    Time() = delete;
    Time(int h, int m);
    int toMinutes();
};
#endif