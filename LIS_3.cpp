#include <iostream>
#include <vector>

using namespace std;

const int N = 100000;

int L[N + 1], L_prime[N + 1], prevIndex[N + 1];
int lengthL = 0;

void calculateLIS(int a[], int n) {
    L[0] = -1000;   
    L_prime[0] = -1;
    prevIndex[0] = -1;

    

    for (int i = 1; i <= n; ++i) {
        if (L[lengthL] < a[i]) {
            L[lengthL++] = a[i];
            L_prime[lengthL] = i;
            prevIndex[i] = L_prime[lengthL - 1];
        } else {
            int s = 0, h = lengthL;
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
            prevIndex[i] = L_prime[s - 1];
        }
    }
    printf("\nLength of LIS: %d\n", lengthL);
}

void printLISPath(int a[], int n) {
    if(n == 0) return;
    printLISPath(a, prevIndex[n]);
    cout<<a[n]<<" ";
}

int main() {
    freopen("LIS_input.txt", "r", stdin);
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int i, count = 0;
    // for( i=0;; i++){
    //     count++;
    //     if(L[i] == -1000) break;
       
    // }
    cout<<"Length: "<< lengthL <<endl;


    //cout<<"Length: "<< L.size() <<endl;

    //printLISPath(a, n);

    return 0;
}
