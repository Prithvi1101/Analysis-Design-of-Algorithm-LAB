#include <iostream>
#include <limits.h>
using namespace std;

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;


    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];


    for (int i = 1; i <= n1; i++) {
        L[i] = arr[p + i - 1];
    }
    for (int j = 1; j <= n2; j++) {
        R[j] = arr[q + j];
    }


    L[n1 + 1] = INT_MAX;
    R[n2 + 1] = INT_MAX;


    int i = 1, j = 1;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }


    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);

}
}

int main() {
    int arr[25], n;

    cout << "Input the size of array (up to 25 elements of integer numbers): ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
