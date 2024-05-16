#include <table.hpp>
#include <cmath>

using namespace std;

int Table::taken_hours() {
    int ans = 0;
    for (Time &el : taken_time) {
        ans += el.hours;
        ans += el.minutes > 0;
    }
    return ans;
};

bool Table::take_me(Time t) {
    if (is_taken) return false;
    is_taken = true;
    taken_at = t;
    return true;
};

bool Table::leave_me(Time t) {
    if (!is_taken) return false;
    is_taken = false;
    taken_time.push_back(t - taken_at);
    return true;
};

