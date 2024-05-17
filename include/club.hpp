#ifndef CLUB_HPP
#define CLUB_HPP
#include <time.hpp>
#include <table.hpp>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

class Club {
private:
    int price;
    Time open_at;
    Time close_at;
    vector<Table> tables;
    unordered_map<string, int> visitors; // 0...N-1 - table number, -1 - in queue, -2 - just came, -3 - already left
    queue<string> q;
    bool is_inside(string& username);
    bool is_opened(Time& t);
    bool is_table_busy(int& table_number);
    bool is_queue_full();

public:
    void come(string& username, Time& t);
    void sit(string& username, Time& t, int& table_number);
    void wait(string& username, Time& t);
    void gone(string& username, Time& t);
    void goodbye();
    void print();
    Club() = delete;
    Club(int &n, int &p, Time &o_t, Time &c_t);
};
#endif