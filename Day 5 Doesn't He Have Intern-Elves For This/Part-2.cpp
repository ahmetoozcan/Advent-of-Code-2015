#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int twiceRow2(string lineTemp)
{
    char first, second;

    for (int i = 0; i < 15; i++)
    {
        first = lineTemp[i], second = lineTemp[i + 1];
        for (int j = i + 2; j < 15; j++)
        {
            if (lineTemp[j] == first && lineTemp[j + 1] == second)
                return 1;
        }
    }
    return 0;
}

int repeatOneLetter(string lineTemp)
{
    for (int i = 0; i < 14; i++)
    {
        if (lineTemp[i] == lineTemp[i + 2])
            return 1;
    }
    return 0;
}
int main()
{
    string line;
    int count = 0;
    ifstream myInput("input.txt");

    while (getline(myInput, line))
    {
        if (twiceRow2(line) == 1 && repeatOneLetter(line) == 1)
            count++;
    }

    cout << count;
    return 0;
}