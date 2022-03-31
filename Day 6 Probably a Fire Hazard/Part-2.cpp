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
            i++;

        if (i == 4)
            i = 0;
    }
}

void toggle(int lightsTemp[][1000], int coordinates[])
{
    for (int i = coordinates[0]; i <= coordinates[2]; i++)
    {
        for (int j = coordinates[1]; j <= coordinates[3]; j++)
        {
            lightsTemp[i][j] += 2;
        }
    }
}

void turnOn(int lightsTemp[][1000], int coordinates[])
{
    for (int i = coordinates[0]; i <= coordinates[2]; i++)
    {
        for (int j = coordinates[1]; j <= coordinates[3]; j++)
        {
            lightsTemp[i][j] += 1;
        }
    }
}

void turnOff(int lightsTemp[][1000], int coordinates[])
{
    for (int i = coordinates[0]; i <= coordinates[2]; i++)
    {
        for (int j = coordinates[1]; j <= coordinates[3]; j++)
        {
            if (lightsTemp[i][j] != 0)
                lightsTemp[i][j] -= 1;
        }
    }
}

int lights[1000][1000] = {0};

int main(int argc, char const *argv[])
{
    string line;
    int coordinates[4] = {0}, count = 0;

    ifstream myInput("input.txt");

    while (getline(myInput, line))
    {
        for (int i = 0; i < line.length(); i++)
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

    int sum = 0;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum += lights[i][j];
        }
    }

    cout << sum;
    return 0;
}
