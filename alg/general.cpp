#include <iostream>
#include "function.cpp"
#include <chrono>

int main()
{
	int n, i;
	int start = 1; int j = 0;
	int cost = 0;
	int cost_max = 0;
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




	int* bestP;
	bestP = new int[n - 1];

	int* worstP;
	worstP = new int[n - 1];


	//установка отсчета
	std::chrono::high_resolution_clock::time_point timeStart = std::chrono::high_resolution_clock::now();


	//цикл подсчета стоимости
	do
	{
		cost = 0;
		cost += matr[start][p[0]];
		for (i = 0; i < n - 2; i++) cost += matr[p[i]][p[i+1]]; //3	
		cost += matr[p[i]][start];
		
		
		if (cost < cost_min) { cost_min = cost; CopyArr(p, bestP, n-1); }
		if (cost > cost_max) {cost_max = cost; CopyArr(p, worstP, n-1); }
		
		//std::cout << "\np = "; OutputPerm(p, n - 1);
		//std::cout << "    min cost = " << cost_min;
	} while (Permutation(p, n - 1));



	std::cout << "\nmin cost = " << cost_min<<std::endl;
	std::cout << "Best Permutation: " << "[" << start; OutputPerm(bestP, n - 1); std::cout<<"\t"<< start << "]" << std::endl;
	std::cout << "max cost = " << cost_max<<std::endl;
	std::cout << "Worst Permutation: " << "[" << start; OutputPerm(worstP, n - 1); std::cout<<"\t"<< start << "]" << std::endl;
	

	//вывод времени
	std::chrono::high_resolution_clock::time_point timeEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = timeEnd - timeStart;
	std::cout << "time: " << duration.count() << std::endl;


	
	//3 метод
	
	int step = 0, cost_min_new = 0, in_min_el = 0, start_new = start, k = 0, f = 0;
	int* NewPerm;
	NewPerm = new int[n + 1];
	for (i = 0; i < n + 1; i++) NewPerm[i] = -1;
	NewPerm[k] = start; k++;
	for(int z = 0; z<n+1;z++){
			std::cout<<NewPerm[z]<<" ";
	}
	std::cout<<"\n";	

	std::chrono::high_resolution_clock::time_point timeStartNew = std::chrono::high_resolution_clock::now();

	while (step < n-1)
	{
		FindMinEl(matr, n, &start_new, &in_min_el);
		//std::cout<<"in_min_el="<<in_min_el<<std::endl;
		
		f = Find(NewPerm, n + 1, in_min_el);
		//std::cout<<"f = "<<f<<std::endl;
		
		if (f != -1) { matr[start_new][in_min_el] = 0; FindMinEl(matr, n, &start_new, &in_min_el); /*std::cout<<"in_min_el v ife = "<<in_min_el<<std::endl;*/ }
		
		cost_min_new += matr[start_new][in_min_el];
		//std::cout<<"cost_min_new = "<<cost_min_new<<std::endl;
		
		NewPerm[k] = in_min_el; 
		// for(int z = 0; z<n+1;z++){
		// 	std::cout<<NewPerm[z]<<" ";
		// }
		k++;
		
		
		for (i = start_new, j = 0; j < n; j++) matr[i][j] = 0;
		for (i = 0, j = in_min_el; i < n; i++) matr[i][j] = 0;
		//std::cout<<"\n";
		//OutputMatrIntD(matr,n, n);
		
		//std::cout << start_new << " " << in_min_el << std::endl;
		
		start_new = in_min_el;
		
		
		step++;
	}
	cost_min_new += matr[start_new][start];
	NewPerm[k] = start;


	std::chrono::high_resolution_clock::time_point timeEndNew = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> durationNew = timeEndNew - timeStartNew;
	std::cout << "time: " << durationNew.count() << std::endl;
	std::cout << "min cost 3d metod = " << cost_min_new;
	std::cout << "; NewPermutation: " << "[ "; OutputPerm(NewPerm, n + 1); std::cout << " ]";

	

	
	for (i = 0; i < n; i++) delete[] matr[i];
	delete[] matr; delete[] p; delete[] bestP; delete[] worstP; delete[] NewPerm;

}