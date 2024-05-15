#include <string>
#include <time.hpp>
#ifndef EVENT_HPP
#define EVENT_HPP
using namespace std;
struct Event {
    Time time;
    string mode;
    Event(Time t, string username);
};
#endif