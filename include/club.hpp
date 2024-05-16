#ifndef CLUB_HPP
#define CLUB_HPP
#include <time.hpp>
#include <table.hpp>
#include <queue>
#include <string>
#include <vector>

class Club {
private:
    int price;
    Time open_at;
    Time close_at;
    vector<Table> tables;
    unordered_map<string, int> visitors; // 0...N - comp number, -1 - in queue
    queue<string> q;
public:
    Club() = delete;
    Club(int &n, int &p, Time &o_t, Time &c_t);
};
#endif