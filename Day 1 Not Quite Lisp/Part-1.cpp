#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myInput("Part-1-input.txt");

    string inst;
    int floor = 0;

    getline(myInput, inst);
    myInput.close();

    for (char item : inst)
    {
        if (item == '(')
            floor++;
        else
            floor--;
    }

    cout << floor;
}