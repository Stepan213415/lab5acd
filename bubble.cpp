#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void printArray(int arr[], int size, int pass) {}

void bubbleSort(int a[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = size - 1; j > i; j--) 
        {
            if (a[j] < a[j - 1]) 
            {
                int x = a[j]; a[j] = a[j - 1]; a[j - 1] = x;
            }
        }
    }
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
        bubbleSort(a, size);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << "Size: " << size << ", Time: " << search_time << " ms\n";
        delete[] a;
    }
    return 0;
}