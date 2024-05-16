#ifndef TABLE_HPP
#define TABLE_HPP
#include <vector>
#include <time.hpp>

using namespace std;

class Table {
private:
    bool taken;
    Time taken_at;
    vector<Time> taken_time;
public:
    bool is_taken();
    int taken_hours();
    Time time_used();
    void take_me(Time t);
    void leave_me(Time t);
    Table();
};
#endif