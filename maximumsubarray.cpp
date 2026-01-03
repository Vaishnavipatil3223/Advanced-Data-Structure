#include <iostream>
using namespace std;

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0, leftSum = -1000000;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > leftSum) leftSum = sum;
    }
    sum = 0;
    int rightSum = -1000000;
    for (int i = m+1; i <= r; i++) {
        sum += arr[i];
        if (sum > rightSum) rightSum = sum;
    }
    return leftSum + rightSum;
}

int maxSubarray(int arr[], int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    return max3(
        maxSubarray(arr, l, m),
        maxSubarray(arr, m+1, r),
        maxCrossingSum(arr, l, m, r)
    );
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubarray(arr, 0, 8);
    return 0;
}