#include<iostream>
#include<algorithm> // Include the <algorithm> header for the swap function
using namespace  std;
int part(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (pivot >= arr[i] && i <= high - 1) {
            i++;
        }
        while (pivot < arr[j] && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = part(arr, low, high);
        quickSort(arr, low, pIndex - 1); // Update the recursive call
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "before quick sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, n - 1);

    cout << "after quick sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
