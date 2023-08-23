#include <iostream>
#include <algorithm>
using namespace std;

void LIS_Naive_DP(int a[], int n) {
    int L[n];      // Length of LIS ending at index i
    int prev[n];   // Previous index contributing to LIS ending at index i
    int maxLength = 0;  // Length of the longest LIS
    int maxIndex = 0;   // Index where the longest LIS ends
    
    // Initialize arrays
    for (int i = 0; i < n; ++i) {
        L[i] = 1;  // Base case: LIS ending at index i is at least 1
        prev[i] = -1;
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && L[j] + 1 > L[i]) {
                L[i] = L[j] + 1;
                prev[i] = j;
            }
        }
        
        if (L[i] > maxLength) {
            maxLength = L[i];
            maxIndex = i;
        }
    }
    
    // Reconstruct the LIS
    int lis[maxLength];
    int currentIndex = maxIndex;
    int lisIndex = maxLength - 1;
    while (currentIndex != -1) {
        lis[lisIndex] = a[currentIndex];
        currentIndex = prev[currentIndex];
        lisIndex--;
    }
    
    cout << "Longest Increasing Subsequence: ";
    for (int i = 0; i < maxLength; ++i) {
        cout << lis[i] << " ";
    }
    cout << "\nLength of LIS: " << maxLength << endl;
}

int main() {
    freopen("LIS_input.txt", "r", stdin);
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int a[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    LIS_Naive_DP(a, n);
    
    return 0;
}
