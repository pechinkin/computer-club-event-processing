#include <iostream>
#include <string>
#include <unordered_set>
#include <club.hpp>
#include <time.hpp>
#include <input_processing.hpp>

using namespace std;

void input_processing(istream& in) {
    int table_nums, price, open_hour, open_min, close_hour, close_min;
    string str;

    if (!getline(in, str)) return;
    for (char c : str) {
        if (c < '0' || c > '9') {
            cout << str << endl;
            return;
        }
    }
    table_nums = stoi(str);
    if (table_nums < 0) {
        cout << table_nums << endl;
        return;
    }

    string time_str;
    if (!getline(in, time_str)) return;
    vector<int> int_pos = {0, 1, 3, 4, 6, 7, 9, 10};
    for (int& i : int_pos) {
        if (time_str[i] < '0' || time_str[i] > '9') {
            cout << time_str;
            return;
        }
    }
    open_hour = stoi(time_str.substr(0, 2));
    open_min = stoi(time_str.substr(3, 2));
    close_hour = stoi(time_str.substr(6, 2));
    close_min = stoi(time_str.substr(9, 2));
    Time opening_time(open_hour, open_min);
    Time closing_time(close_hour, close_min);
    if (open_hour < 0 || open_hour > 23 || close_hour < 0 || close_hour > 23 ||
        open_min < 0 || open_min > 59 || close_min < 0 || close_min > 59 || closing_time < opening_time) {
        cout << time_str << endl;
        return;
    }

    if (!getline(in, str)) return;
    for (char c : str) {
        if (c < '0' || c > '9') {
            cout << str << endl;
            return;
        }
    }
    price = stoi(str);
    if (price < 0) {
        cout << price << endl;
        return;
    }

    Club club(table_nums, price, opening_time, closing_time);

    vector<int> int_pos_short = {0, 1, 3, 4};
    unordered_set<char> possible_chars;
    for (int i = 0; i < 26; ++i) possible_chars.insert('a' + i);
    for (int i = 0; i < 10; ++i) possible_chars.insert('0' + i);
    possible_chars.insert('_');
    possible_chars.insert('-');

    while (getline(in, str)) {

        cout << str << endl;
        if (str.size() < 9) return;
        if (str[2] != ':') return;
        for (int &i: int_pos_short) if (str[i] < '0' || str[i] > '9') return;
        int hours = stoi(str.substr(0, 2));
        int minutes = stoi(str.substr(3, 2));
        if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) return;
        Time time(hours, minutes);
        if (str[5] != ' ' || str[7] != ' ') return;
        if (str[6] < '1' || str[6] > '4') return;
        int action = str[6] - '0';
        string username;
        int table;
        int i = 8;
        while (i < str.size() && possible_chars.count(str[i])) username += str[i++];
        if (action != 2) {
            if (i < str.size()) return;
        } else {
            if (i + 1 >= str.size()) return;
            string table_str = str.substr(i + 1, str.size() - i);
            for (char c : table_str) if (c > '9' || c < '0') return;
            table = stoi(table_str) - 1;
            if (table < 0 || table > table_nums) return;
        }
        switch (action) {
            case 1:
                club.come(username, time);
                break;
            case 2:
                club.sit(username, time, table);
                break;
            case 3:
                club.wait(username, time);
                break;
            case 4:
                club.gone(username, time);
                break;
            default:
                break;
        }
    }
    club.print();
}