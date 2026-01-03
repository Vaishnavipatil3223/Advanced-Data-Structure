#include <iostream>
using namespace std;

int findMin(int arr[], int left, int right) {
    if (left == right) return arr[left];
    if (arr[left] < arr[right]) return arr[left];

    int mid = (left + right) / 2;
    if (arr[mid] >= arr[left])
        return findMin(arr, mid + 1, right);
    else
        return findMin(arr, left, mid);
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    cout << findMin(arr, 0, 4);
    return 0;
}
