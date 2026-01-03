#include <iostream>
#include <algorithm>
using namespace std;

#define N 100  // Max number of shops

// Structure to store a shop's start and end time
struct Shop {
    int start;
    int end;
};

// Comparator function to sort by end time
bool compare(Shop a, Shop b) {
    return a.end < b.end;
}

int main() {
    int S[] = {1, 8, 3, 2, 6};  // Start times
    int E[] = {5, 10, 6, 5, 9}; // End times
    int n = 5;
    int K = 2; // Number of persons

    Shop shops[N];
    for (int i = 0; i < n; i++) {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

    // Sort shops by end time
    sort(shops, shops + n, compare);

    int personEnd[10] = {0}; // Stores last end time for each person
    int count = 0;

    for (int i = 0; i < n; i++) {
        // Try to assign this shop to any available person
        for (int j = 0; j < K; j++) {
            if (shops[i].start >= personEnd[j]) {
                personEnd[j] = shops[i].end;
                count++;
                break; // Shop assigned to a person, move to next shop
            }
        }
    }

    cout << "Maximum shops visited: " << count << endl;

    return 0;
}