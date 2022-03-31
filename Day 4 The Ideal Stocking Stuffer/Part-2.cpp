#include <iostream>
#include <fstream>
#include <string>
#include "md5.h"
using namespace std;

int main(int argc, char *argv[])
{
    string code;
    string need = "000000";
    string hash;
    int key;

    ifstream myInput("input.txt");
    getline(myInput, code);
    myInput.close();

    for (key = 0; hash.compare(0, 6, need) != 0; key++)
        hash = md5(code + to_string(key));

    cout << key - 1;
}