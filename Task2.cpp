#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string pathIn = "C:\\Users\\ярик\\source\\repos\\HomeWork\\Task2\\matrix_input.txt";
    string pathOut = "C:\\Users\\ярик\\source\\repos\\HomeWork\\Task2\\matrix_output.txt";
    string s;
    vector<vector<int>> matrix;
    fstream input, output;

    input.open(pathIn, fstream::in);

    if (!input.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        while (getline(input, s, '\n'))
        {
            stringstream stream{ s };

            string number;
            vector<int> result;

            while (getline(stream, number, ' '))
                result.push_back(stoi(number));

            matrix.push_back(result);
        }
    }

    input.close();

    sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        });


    output.open(pathOut, fstream::out);

    if (!output.is_open())
    {
        cout << "Error" << endl;
    }

    else
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                output << matrix[i][j] << " ";
            }
            output << endl;
        }
    }

    output.close();
}
