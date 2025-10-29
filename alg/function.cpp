#include <random>
#include <chrono>
#include <iostream>

std::random_device randomDevice;
std::mt19937_64 generator(randomDevice());
int rangeStart = 1;
int rangeEnd = 25;
std::uniform_int_distribution<int> distribution(rangeStart, rangeEnd);


void RandMatrAnyIntD(int** matr, int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (i != j) matr[i][j] = distribution(generator);
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


void Swap(int* a, int* b)
{
    int per = *a;
    *a = *b;
    *b = per;
}

bool Permutation(int* p, int n) //получение следующей перестановки
{
    int i = n - 2;
    
	while(i >= 0 && p[i] >= p[i+1]) i--;
    if(i < 0) return false;
    
	int j = n - 1;
	while(p[i] >= p[j]) j--;
    
	Swap(&p[i], &p[j]);
	
	int left = i + 1;
	int right = n - 1;
	
	while (left < right)
	{
		Swap(&p[left], &p[right]);
		left++;
		right--;
	}
	
	return true;
}

void OutputPerm(int* a, int n)
{
	for (int* p = a; p < a + n; p++) std::cout<<"\t"<<*p;
}

void CopyArr(int* a, int* b, int n)
{
	for(int i = 0; i<n; i++) b[i] = a[i];
}

void FindMinEl(int** matr, int n, int* str, int* col_min)
{
	int min = 100000;
	for (int col = 0; col < n; col++)
		if (matr[*str][col] < min && matr[*str][col] != 0) {*col_min = col; min = matr[*str][col];}
}


int Find(int* a, int n, int B)
{
	for (int i = 0; i < n; i++)
		if (a[i] == B) return i;
	return -1;
}








