#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void printArray(int arr[], int size, int pass) {}

void insertionSort(int a[], int size) 
{
    for (int i = 1; i < size; i++) 
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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
        insertionSort(a, size);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << "Size: " << size << ", Time: " << search_time << " ms\n";
        delete[] a;
    }
    return 0;
}