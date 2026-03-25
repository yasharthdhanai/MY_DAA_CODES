#include <stdio.h>

void solve() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int k = n - 1; k >= 2; k--) {
        int i = 0;
        int j = k - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                printf("%d, %d, %d\n", i + 1, j + 1, k + 1);
                return;
            } else if (sum < arr[k]) {
                i++;
            } else {
                j--;
            }
        }
    }

    printf("No sequence found\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}