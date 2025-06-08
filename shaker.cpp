#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void printArray(int arr[], int size, int pass) {}

void shakerSort(int a[], int size) 
{
    int lb = 0, ub = size - 1, k = size - 1, x;
    do 
    {
        for (int j = ub; j > lb; j--) 
        {
            if (a[j - 1] > a[j]) 
            {
                x = a[j - 1]; a[j - 1] = a[j]; a[j] = x; k = j;
            }
        }
        lb = k;
        for (int j = lb; j < ub; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                x = a[j]; a[j] = a[j + 1]; a[j + 1] = x; k = j;
            }
        }
        ub = k;
    } while (lb < ub);
}

int main() 
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    srand(time(NULL));
    const int sizes[] = {1400, 14000, 140000};

    for (int s = 0; s < 3; s++) 
    {
        int size = sizes[s];
        int* a = new int[size];
        for (int i = 0; i < size; i++) 
        {
            a[i] = -280 + rand() % (560 + 1);
        }

        unsigned int start_time = clock();
        shakerSort(a, size);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << "Size: " << size << ", Time: " << search_time << " ms\n";
        delete[] a;
    }
    return 0;
}