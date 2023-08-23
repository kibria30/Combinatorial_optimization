#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void LIS_Fast_DP(int a[], int n) {
    int L[n + 1], L_prime[n + 1], prev[n + 1];
    L[0] = -__INT_MAX__;
    L_prime[0] = -1;
    prev[0] = -1;

    int L_length = 0;

    for (int i = 1; i <= n; i++) {
        if (L[L_length] < a[i]) {
            L[++L_length] = a[i];
            L_prime[L_length] = i;
            prev[i] = L_prime[L_length - 1];
        } else {
            int s = 0, h = L_length;
            while (s < h) {
                int m = (s + h) / 2;
                if (L[m] < a[i]) {
                    s = m + 1;
                } else {
                    h = m;
                }
            }

            L[s] = a[i];
            L_prime[s] = i;
            prev[i] = L_prime[s - 1];
        }
    }

    //printf("L_prime array: ");
    //printArray(L_prime, n + 1);
    printf("prev array: ");
    printArray(prev, n + 1);

    // Extract the LIS elements using prev array
    int idx = L_prime[L_length];
    int lis[L_length];
    for (int i = L_length - 1; i >= 0; i--) {
        lis[i] = a[idx];
        idx = prev[idx];
    }

    printf("Longest Increasing Subsequence: ");
    for (int i = 0; i < L_length; i++) {
        printf("%d ", lis[i]);
    }
    printf("\nLength of LIS: %d\n", L_length);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n + 1];
    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    LIS_Fast_DP(a, n);

    return 0;
}