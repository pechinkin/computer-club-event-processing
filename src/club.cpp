#include <club.hpp>
#include <algorithm>
Club::Club(int &n, int &p, Time &o_t, Time &c_t): open_at(o_t), close_at(c_t) {
    price = p;
    open_at = o_t;
    close_at = c_t;
    tables = vector<Table>(n, Table());
    cout << open_at << endl;
};

bool Club::is_inside(string& username) {
    return visitors.count(username) && visitors[username] != -3;
};

bool Club::is_opened(Time& t) {
    return t >= open_at && t < close_at;
};

bool Club::is_table_busy(int& table_number) {
    return tables[table_number].is_taken();
};

bool Club::is_queue_full() {
    return q.size() >= tables.size();
};

void Club::come(string& username, Time& t) {
    if (is_inside(username)) {
        cout << t << " 13 YouShallNotPass" << endl;
        return;
    }
    if (!is_opened(t)) {
        cout << t << " 13 NotOpenYet" << endl;
        return;
    }
    visitors[username] = -2;
};

void Club::sit(string& username, Time& t, int& table_number) {
    if (!is_inside(username)) {
        cout << t << " 13 ClientUnknown" << endl;
        return;
    }
    if (is_table_busy(table_number)) {
        cout << t << " 13 PlaceIsBusy" << endl;
        return;
    }
    if (visitors[username] >= 0) tables[visitors[username]].leave_me(t);
    visitors[username] = table_number;
    tables[table_number].take_me(t);
};

void Club::wait(string& username, Time& t) {
    if (!is_inside(username)) {
        cout << t << " 13 ClientUnknown" << endl;
        return;
    }
    for (int i = 0; i < tables.size(); ++i) {
        if (!is_table_busy(i)) {
            cout << t << " 13 ICanWaitNoLonger!" << endl;
            return;
        }
    }
    if (is_queue_full()) {
        cout << t << " 11 " << username << endl;
        visitors[username] = -2;
        return;
    }
    visitors[username] = -1;
    q.push(username);
};

void Club::gone(string& username, Time& t) {
    if (!is_inside(username)) {
        cout << t << " 13 ClientUnknown" << endl;
        return;
    }
    if (visitors[username] == -1) {
        queue<string> newq;
        while (!q.empty()) {
            if (q.front() != username) newq.push(username);
            q.pop();
        }
        q = newq;
    }
    if (visitors[username] >= 0) {
        int table_number = visitors[username];
        tables[table_number].leave_me(t);
        if (!q.empty()) {
            visitors[q.front()] = table_number;
            q.pop();
            tables[table_number].take_me(t);
            cout << t << " 12 " << username << ' ' << table_number + 1<< endl;
        }
    }
    visitors[username] = -3;
};

void Club::goodbye() {
    vector<pair<string, int>> arr;
    for (pair<string, int> el : visitors) {
        if (el.second != -3) arr.push_back(el);
    }
    sort(arr.begin(), arr.end(), [](pair<string, int>& a, pair<string, int>& b) {
        return a.first < b.first;
    });

    for (pair<string, int> el : arr) {
        gone(el.first, close_at);
        cout << close_at << " 11 " << el.first << endl;
    }
}

void Club::print() {
    goodbye();
    cout << close_at << endl;
    for (int i = 0; i < tables.size(); ++i) {
        cout << i + 1 << ' ' << tables[i].taken_hours() * price << ' ' << tables[i].time_used() << endl;
    }
};
