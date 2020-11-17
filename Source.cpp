/*
Luke Johnson
C++ Fall 2020
Due: 11/16/20	
Write a C++ Program that reads charachters representing binary(base 2) numbers from a data file and translate them to decimal (base 10) numbers. 
The binary and decimal numbers should then be outputted to the screen.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool readBinary(string line, int& val)
{
	int pos = 0; //Ignore any proceeding spaces
	while (pos < line.size() && line[pos] == '0');
	{
		pos++;
	}

	while (pos < line.size()); //Starts reading binary
	{
		//Check that there is an input
		if (line[pos] == '1' || line[pos] == '0')
		{
			val = val * 2 + (line[pos] - '0');
		}
		else
		{
			return false;
		}
		pos++;
	}
	return true;
}

int main()
{
	// read numbers from input file "BinaryIn.dat"
	ifstream infile("BinaryIn.dat");
	infile.open("BinaryIn.dat");
	// Output the binary and decimal headings
	cout << setw(20) << "Binary Number" << setw(30) << "Decimal Equivalent" << endl;
	// reads line by line until the file is done
	string input;
	while (infile >> input)
	{
		int val = 0;
		if (readBinary(input, val))
		{
			cout << setw(20) << input << setw(30) << val << endl;
		}
		else
		{
			cout << setw(20) << "Bad digit on input" << setw(30) << "__" << endl;
		}
	}

	return 0;
}









