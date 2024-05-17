#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.hpp>
#include <table.hpp>
#include <club.hpp>
#include <input_processing.hpp>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Error! Usage: task.exe <filename>" << endl;
        return 1;
    }
    string filename = argv[1];
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error! File is not found" << endl;
        return 2;
    }

    input_processing(file);


    return 0;
}
