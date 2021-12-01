#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string pathIn = "C:\\Users\\ярик\\source\\repos\\HomeWork8\\Task1\\matrix_input.txt";
	string pathOut = "C:\\Users\\ярик\\source\\repos\\HomeWork8\\Task1\\matrix_output.txt";
	string s;
	fstream input, output;
	vector<vector<int>> matrix;

	input.open(pathIn, fstream::in);

	if (!input.is_open())
	{
		cout << "Error" << endl;
	}

	else
	{
		while (getline(input, s, '\n'))
		{
			stringstream linestream(s);
			string number;
			vector <int> line;

			while (getline(linestream, number, ' '))
				line.push_back(stoi(number));

			matrix.push_back(line);
		}
	}

	input.close();

	matrix.resize(matrix.size(), std::vector<int>(matrix.size()));

	for (int i = 0; i < matrix.size(); i++)
	{
		sort(matrix[i].begin(), matrix[i].end());
	}

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
