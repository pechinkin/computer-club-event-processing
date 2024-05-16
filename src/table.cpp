#include <table.hpp>
#include <cmath>

using namespace std;

Table::Table(): taken_at(Time(0, 0)), taken(false) {};

bool Table::is_taken() {
    return taken;
};

int Table::taken_hours() {
    int ans = 0;
    for (Time &el : taken_time) {
        ans += el.hours;
        ans += (el.minutes > 0);
    }
    return ans;
};

Time Table::time_used() {
    Time ans(0, 0);
    for (Time &el : taken_time) ans += el;
    return ans;
};

void Table::take_me(Time t) {
    if (taken) return;
    taken = true;
    taken_at = t;
};

void Table::leave_me(Time t) {
    if (!taken) return;
    taken = false;
    taken_time.push_back(t - taken_at);
};

