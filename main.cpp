#include <iostream>
#include <fstream>
#include <string>
#include "time.hpp"
#include "club.hpp"
using namespace std;
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Error! Usage: task.exe <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);
    string str;
    if (!file.is_open()) {
        cout << "Error! File is not found" << endl;
        return 2;
    }
    while (getline(file, str)) {
        cout << str << endl;
    }
    Time ex(10, 2);
    cout << ex.toMinutes() << endl;
    return 0;
}
