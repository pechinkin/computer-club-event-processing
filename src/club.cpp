#include <club.hpp>
Club::Club(int &n, int &p, Time &o_t, Time &c_t): open_at(o_t), close_at(c_t) {
    price = p;
    open_at = o_t;
    close_at = c_t;
    tables = vector<Table>(n, Table());
};
