#include <iostream>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthLargest(int arr[], int l, int r, int k) {
    if (l <= r) {
        int pos = partition(arr, l, r);
        if (pos == k -1)
            return arr[pos];
        else if (pos > k - 1)
            return kthLargest(arr, l, pos - 1, k);
        else
            return kthLargest(arr, pos + 1, r, k);
    }
    return -1;
}

int main() {    
    int arr[] = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << kthLargest(arr, 0, 5, k);
    return 0;
}