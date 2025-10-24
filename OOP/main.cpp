#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
#include <stdio.h>



void RandMatrAnyIntD(int** matr, int m, int n, int a, int b)
{
	srand(time(0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if(i != j) matr[i][j] = rand() % (b - a + 1) + a;
		}
}

void OutputMatrIntD(int** matr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++){
            std::cout<<matr[i][j]<<"\t";
        }
            std::cout<<"\n";
	}
}

int main()
{
	int town, start;
	int** matr;
	int i = 0;

	std::cout << "num cities: ";
	std::cin >> town;

	std::cout << "start towm: ";
	std::cin >> start;

	matr = new int* [town];
	for (i = 0; i < town; i++)
		matr[i] = new int[town]();
	RandMatrAnyIntD(matr, town, town, 1, 15);
	std::cout << "Your cost matrix:\n";
	OutputMatrIntD(matr, town, town);


}