#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void getNumbers(string lineTemp, int coordinates[])
{
    string temp;
    stringstream ss;
    int i = 0;

    ss << lineTemp;
    while (!ss.eof())
    {
        ss >> temp;

        if (stringstream(temp) >> coordinates[i])
        {
            cout << coordinates[i] << " ";
            i++;
        }

        if (i == 4)
            i = 0;
        cout << endl;
    }
}

void toggle(int lightsTemp[][1000], int coordinates[])
{
    for (int i = coordinates[0]; i < coordinates[2]; i++)
    {
        if (coordinates[i])
    }
    for (int i = coordinates[1]; i < coordinates[3]; i++)
    {
    }
}

void turnOn(int lightsTemp[][1000], int coordinates[])
{
}

void turnOff(int lightsTemp[][1000], int coordinates[])
{
}

int lights[1000][1000] = {0};

int main(int argc, char const *argv[])
{
    string line;
    int coordinates[4] = {0}, count = 0;

    ifstream myInput("input.txt");

    while (getline(myInput, line))
    {
        for (int i = 0; i < sizeof(line) / sizeof(char); i++)
        {
            if (line[i] == ',')
                line[i] = ' ';
        }

        getNumbers(line, coordinates);

        if (line.find("toggle") != string::npos)
            toggle(lights, coordinates);

        if (line.find("turn on") != string::npos)
            turnOn(lights, coordinates);

        if (line.find("turn off") != string::npos)
            turnOff(lights, coordinates);
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (lights[i][j] == 1)
                count += 1;
        }
    }

    cout << count;
    return 0;
}
