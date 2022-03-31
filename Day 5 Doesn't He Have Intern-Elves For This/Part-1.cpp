#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int twiceRow(string lineTemp)
{
    int ret = 0;

    for (int i = 0; i < 15; i++)
    {
        if (lineTemp[i] == lineTemp[i + 1])
            ret = 1;
    }
    return ret;
}

int checkVowel(string lineTemp)
{
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;

    for (char item : lineTemp)
    {
        for (int i = 0; i < 5; i++)
        {
            if (item == vowels[i])
                count++;
        }
    }
    return count;
}

int checkNot(string lineTemp)
{
    for (int i = 0; i < 15; i++)
    {
        if (lineTemp[i] == 'a' && lineTemp[i + 1] == 'b')
            return 0;
        if (lineTemp[i] == 'c' && lineTemp[i + 1] == 'd')
            return 0;
        if (lineTemp[i] == 'p' && lineTemp[i + 1] == 'q')
            return 0;
        if (lineTemp[i] == 'x' && lineTemp[i + 1] == 'y')
            return 0;
    }
    return 1;
}

int main()
{
    string line;
    int count = 0;
    ifstream myInput("input.txt");

    while (getline(myInput, line))
    {
        int twiceRowInt = twiceRow(line);
        int checkVowelInt = checkVowel(line);
        int checkNotInt = checkNot(line);

        cout << twiceRow << " " << checkVowelInt << " " << checkNotInt << endl;

        if (twiceRowInt == 1 && checkVowelInt >= 3 && checkNot(line) == 1)
            count++;
    }

    cout << count;
    return 0;
}