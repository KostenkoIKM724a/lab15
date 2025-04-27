#include <iostream>
#include <windows.h>
using namespace std;

// Bubble Sort
void bubbleSort(int a[], int n) {
    int buff;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                buff = a[j];
                a[j] = a[j + 1];
                a[j + 1] = buff;
            }
        }
    }
}

// Selection Sort
void selectionSort(int a[], int n) {
    int max, buff;
    for (int i = 0; i < n - 1; i++) {
        max = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max]) { 
                max = j;
            }
        }
        if (max != i) {
            buff = a[i];
            a[i] = a[max];
            a[max] = buff;
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    int buff, j;
    for (int i = 1; i < n; i++) {
        buff = a[i];
        j = i - 1;
        while (j >= 0 && a[j] < buff) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = buff;
    }
}

// Quick Sort
void quickSort(int* a, int n) {
    int i = 0;
    int j = n - 1;
    int mid = a[n / 2];

    do {
        while (a[i] > mid) i++;
        while (a[j] < mid) j--; 
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) quickSort(a, j + 1);
    if (i < n) quickSort(&a[i], n - i);
}

// Function to print the array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Main function
void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Generate Fibonacci numbers
    const int n = 10;
    int fib[n] = { 21, 8, 3, 5, 13, 0, 34, 1, 2, 1 };

    cout << "Fibonacci array:" << endl;
    printArray(fib, n);

    // Copy arrays for sorting
    int a1[n], a2[n], a3[n], a4[n];
    for (int i = 0; i < n; i++) {
        a1[i] = a2[i] = a3[i] = a4[i] = fib[i];
    }

    // Bubble Sort
    bubbleSort(a1, n);
    cout << "After Bubble Sort:" << endl;
    printArray(a1, n);

    // Selection Sort
    selectionSort(a2, n);
    cout << "After Selection Sort:" << endl;
    printArray(a2, n);

    // Insertion Sort
    insertionSort(a3, n);
    cout << "After Insertion Sort:" << endl;
    printArray(a3, n);

    // Quick Sort
    quickSort(a4, n);
    cout << "After Quick Sort:" << endl;
    printArray(a4, n);
}
