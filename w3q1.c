#include <stdio.h>

void solve() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int comp = 0;
    int shifts = 0;
    int current, j;

    for (int i = 1; i < n; i++) {
        current = arr[i];
        for (j = i - 1; j >= 0; j--) {
            comp++;
            if (arr[j] > current) {
                arr[j + 1] = arr[j];
                shifts++;
            } else {
                comp--;
                break;
            }
        }
        arr[j + 1] = current;
        shifts++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("comparisons = %d\n", comp);
    printf("shifts = %d\n", shifts);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}