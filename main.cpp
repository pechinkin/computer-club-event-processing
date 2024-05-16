#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.hpp>
#include <table.hpp>
#include <club.hpp>
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
//    while (getline(file, str)) {
//        cout << str << endl;
//    }

    Time ex1(10, 2);
    Time ex2(10, 5);
    Time ex3(10, 3);
    Time ex4(10, 4);
    int n = 2, p = 2;
    string c1 = "client1", c2 = "client2", c3 = "client3", c4 = "client4";
    Club c(n, p, ex1, ex2);
    c.come(c1, ex3);
    c.come(c2, ex4);
    c.come(c3, ex1);
    c.come(c4, ex2);
    int x1 = 0, x2 = 1;
    c.sit(c1, ex3, x1);
    c.sit(c2, ex4, x2);
    c.print();
    return 0;
}
