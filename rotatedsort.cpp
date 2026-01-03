#include <iostream>
using namespace std;

int search(int arr[], int left, int right, int target) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target) return mid;

    if (arr[left] <= arr[mid]) {    
        if (arr[left] <= target && target < arr[mid])
            return search(arr, left, mid - 1, target);
        else
            return search(arr, mid + 1, right, target);
    } else {
        if (arr[mid] < target && target <= arr[right])
            return search(arr, mid + 1, right, target);
        else
            return search(arr, left, mid - 1, target);
    }
}

int main() {
    int arr[] = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(arr, 0, 6, target);
    return 0;
}




















