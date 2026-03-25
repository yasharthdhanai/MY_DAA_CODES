#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void solve() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k;
    scanf("%d", &k);

    qsort(a, n, sizeof(int), compare);

    int count = 0;
    int l = 0;
    int r = 1;

    while (r < n) {
        int diff = a[r] - a[l];

        if (diff == k) {
            count++;
            l++;
            r++;
        } else if (diff < k) {
            r++;
        } else {
            l++;
        }
        if (l == r) {
            r++;
        }
    }

    printf("%d\n", count);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}