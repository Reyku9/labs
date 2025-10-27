#include <iostream>
#include "function.cpp"
#include <chrono>

int main()
{
	int n, i;
	int start = 1; int j = 0;
	int cost = 0; 
	int cost_min = 100000;
	int** matr;

	std::cout << "num cities: ";
	std::cin >> n;

	std::cout << "start towm: ";
	std::cin >> start;

	matr = new int* [n];
	for (i = 0; i < n; i++) matr[i] = new int[n]();

	RandMatrAnyIntD(matr, n, n);
	std::cout << "Your cost matrix:\n";
	OutputMatrIntD(matr,n, n);

	int* p;
	p = new int[n-1];

	for (i = 0; i < n-1; i++, j++)
	{	
		if (j == start) p[i] = ++j;
		else p[i] = j;
	}

	// for(int z = 0; z<n-1;z++){
	// 	std::cout<<p[z];
	// }
	// 	std::cout<<std::endl;

	std::chrono::high_resolution_clock::time_point timeStart = std::chrono::high_resolution_clock::now();

	do
	{
		cost = 0;
		cost += matr[start][p[0]];
		for (i = 0; i < n - 2; i++) cost += matr[p[i]][p[i+1]]; //3	
		cost += matr[p[i]][start];
		
		
		if (cost < cost_min) cost_min = cost;
		
		std::cout << "\np = "; OutputMasPtr(p, n - 1);
		//std::cout << "    min cost = " << cost_min;
	} while (Permutation(p, n - 1));


	std::cout << "\nmin cost = " << cost_min<<std::endl;
	
	std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = timeEnd - timeStart;
	std::cout << "time: " << duration.count() << std::endl;
	
	
	for (i = 0; i < n; i++) delete[] matr[i];
	delete[] matr; delete[] p;


}