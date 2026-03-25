#include <stdio.h>

int find_first(int a[], int n, int k) {
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == k) {
            res = mid;
            r = mid - 1;
        } else if (a[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int find_last(int a[], int n, int k) {
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] == k) {
            res = mid;
            l = mid + 1;
        } else if (a[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

void solve() {
    int n, k;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);

    int f = find_first(a, n, k);
    int l = find_last(a, n, k);

    if (f != -1) {
        int count = l - f + 1;
        printf("%d - %d\n", k, count);
    } else {
        printf("Key not present\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}