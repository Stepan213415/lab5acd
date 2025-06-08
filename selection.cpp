#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void printArray(int arr[], int size, int pass) {}

void selectionSort(int a[], int size) 
{
    int min, num, t;
    for (int i = 0; i < size - 1; i++) 
    {
        t = 0; num = i; min = a[i];
        for (int j = i + 1; j < size; j++) 
        {
            if (a[j] < min) 
            {
                num = j; min = a[j]; t = 1;
            }
        }
        if (t == 1) 
        {
            a[num] = a[i]; a[i] = min;
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
        selectionSort(a, size);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        cout << "Size: " << size << ", Time: " << search_time << " ms\n";
        delete[] a;
    }
    return 0;
}
