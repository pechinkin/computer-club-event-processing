#ifndef TABLE_HPP
#define TABLE_HPP
#include <vector>
#include <time.hpp>

using namespace std;

class Table {
private:
    bool is_taken;
    Time taken_at;
    vector<Time> taken_time;
public:
    int taken_hours();
    Time time_used();
    bool take_me(Time t);
    bool leave_me(Time t);
    Table();
};
#endif