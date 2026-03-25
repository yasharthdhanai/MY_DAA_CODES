#include <stdio.h>

void solve() {
    int n, key;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &key);

    int c = 0;
    int i = 0;

    while (i < n) {
        c++;
        if (a[i] >= key) {
            break;
        }
        i += 2;
    }

    if (i < n && a[i] == key) {
        printf("Present %d\n", c);
    } else {
        int p = i - 1;
        if (p >= 0 && p < n) {
            c++;
            if (a[p] == key) {
                printf("Present %d\n", c);
                return;
            }
        }
        printf("Not Present %d\n", c);
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}