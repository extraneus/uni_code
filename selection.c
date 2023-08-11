#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    selectionSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
