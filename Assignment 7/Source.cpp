/*COSC 1410, Assignment 7
Thursday, October 30, 2014
Write a program that reads numbers from a file, sorts the numbers in numerical order from highest to lowest values
(descending order) or vice versa (ascending order), and finally write the sorted numbers in another file. The input file
will contain the number of elements in the file, type of sorting required (a or d), and the numbers.
Follow these steps:
i)		Read the number of elements in the file
ii)		Read the type of sorting (ascending or descending)
iii)	Create a dynamic array to store the number (size must be equal to the number read from the file)
iv)		Sort the array
v)		In the output file, please first write the number of elements, and the numbers in the desired order.
Assume that the user will always enter proper type of value (integer).
*/

#include <iostream>
#include <fstream> //File I/O Libraries
using namespace std;

void main() 
{	//declaring the needed variables
	int numOfElements;
	char letter = 'A' || 'a' || 'd' || 'D';
	int numbers;
	int counter = 0;
	int temp;
	//opening the text file
	fstream info;
	info.open("input.txt", ios::in);
	//giving an error if the file fails or has an error
	if (info.fail()) {
		cerr << "Error opening file...";
		exit(1);
	}
	//reading the number of elements(1st) and the letter(2nd)
	info >> numOfElements >> letter;
	//setting the size equal to the number of elements
	int size = numOfElements;
	//creating a dynamic array
	int *Dyn;
	Dyn = new int[size];
	//putting the numbers in the array
	while (!info.eof()) 
	{
		info >> numbers;
		Dyn[counter] = numbers;
		counter++;
	}
	//switch statement for ascending or descending (sorting array)
	switch (letter)
	{ //Ascending order option
	case 'a':
	case 'A':
		//for loop in a for loop to compare all the elements to each other
		for (int counter = 0; counter < size; counter++)
		{
			for (int index = 0; index < size; index++) 
			{
				//an if statement to arrange them in correct order based on the elements
				if(Dyn[counter] < Dyn[index])
				{
					temp = Dyn[counter];
					Dyn[counter] = Dyn[index];
					Dyn[index] = temp;
				}
			}
		}
		break; //break the loop after ascending
	//Descending order option
	case 'd':
	case 'D':
		//for loop in a for loop to compare all the elements to each other
		for (int counter = 0; counter < size; counter++) {
			for (int index = 0; index < size; index++) {
				//an if statement to arrange them in correct order based on the elements
				if (Dyn[counter] > Dyn[index]) 
				{
					temp = Dyn[counter];
					Dyn[counter] = Dyn[index];
					Dyn[index] = temp;
				}
			}
		}
	}
	info.close(); //close the file
	//open the file as an output
	info.open("output.txt", ios::out);
	//giving an error if the file fails or has an error
	if (info.fail()) {
		cerr << "Error opening file...";
		exit(1);
	}
	//outputting the array
	info << numOfElements << endl;
	for (int index = 0; index < size; index++)
	{
		info << Dyn[index] << endl;
	}
	info.close();

	cout << "Check the output.txt file!! " << endl;
	system("pause");
}
	