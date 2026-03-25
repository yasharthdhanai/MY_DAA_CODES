#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int c_cnt;
int s_cnt;
void sw(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
    s_cnt++;
}
int part(int *a, int l, int r) {
    int rnd = l + rand() % (r - l + 1);
    sw(&a[rnd], &a[r]);
    int piv = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        c_cnt++;
        if (a[j] < piv) {
            i++;
            sw(&a[i], &a[j]);
        }
    }
    sw(&a[i + 1], &a[r]);
    return i + 1;
}
void qs(int *a, int l, int r) {
    if (l < r) {
        int pi = part(a, l, r);
        qs(a, l, pi - 1);
        qs(a, pi + 1, r);
    }
}
void solv() {
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    c_cnt = 0;
    s_cnt = 0;
    qs(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d%s", a[i], (i == n - 1) ? "" : " ");
    }
    printf("\ncomparisons = %d\n", c_cnt);
    printf("swaps = %d\n", s_cnt);
    free(a);
}
int main() {
    srand(time(0)); 
    int t;
    scanf("%d", &t);
    while (t--) {
        solv();
    }
    return 0;
}