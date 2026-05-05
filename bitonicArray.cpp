#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

//Bitonic Sort the Array

int swaps=0;
int comps=0;

void bubbleSort(int arr[], int st, int end) {
    for (int i = st; i < end; i++) {
        for (int j = end; j > i; j--) {
            comps++;
            if (arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
                swaps++;
            }
        }
    }
}

void selectionSort(int arr[], int st, int end) {
    int max=0;
    for (int i = st; i < end; i++) {
        max = i;
        for (int j = i+1; j <= end; j++) {
            comps++;
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        comps++;
        if (max != i) {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            swaps++;
        }
    }
}

void bitonicMerge(int arr[], int st, int end) {
    int mid = (st+end)/2;
    for (int i = st; i < st + mid; i++) {
        comps++;
        if (arr[i] > arr[i+mid]) {
            swap(arr[i], arr[i+mid]);
            swaps++;
        }
    }

}

void bitonicSort(int arr[], int size, int st, int end) {
    int mid = (st+end)/2;
    bubbleSort(arr, st, mid);
    selectionSort(arr, mid+1, end);

}

void searchElement(int arr[], int size, int searchItem) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchItem) {
            cout << "Item found at index " << i << '\n';
            return;
        }
    }
    cout << "Item not found!\n";
}

int main() {
    int a[] = {3, 4, 12, 8, 16, 43, 4, 3};
    int b[] = {5, 5, 5, 2, 3, 5, 7};
    int n = 8;

    bitonicSort(a, n, 0, n-1);

    for (int it:a) {
        cout << it << ' ';
    }
    cout << '\n';

    cout << "Total number of swaps: " << swaps << '\n';
    cout << "Total number of comparisons: " << comps << '\n';

    int searchItem; cin >> searchItem;
    searchElement(a, n, searchItem);

}