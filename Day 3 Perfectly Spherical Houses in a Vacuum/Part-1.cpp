#include <iostream>
#include <fstream>
using namespace std;

int neighborhood[300][300];

int main()
{
    ifstream myInput("input.txt");

    string directions;
    int gifts = 0, i = 150, j = 150;
    neighborhood[150][150] = 1;

    getline(myInput, directions);
    myInput.close();

    for (char item : directions)
    {
        if (item == '^')
            i++;
        if (item == '<')
            j--;
        if (item == '>')
            j++;
        if (item == 'v')
            i--;

        neighborhood[i][j]++;
    }

    for (int a = 0; a < 300; a++)
    {
        for (int b = 0; b < 300; b++)
        {
            if (neighborhood[a][b] > 0)
                gifts++;
        }
    }

    cout << gifts;

    return 0;
}