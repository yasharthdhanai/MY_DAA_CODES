#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int p(int *a, int l, int r) {
    int rnd = l + rand() % (r - l + 1);
    swap(&a[rnd], &a[r]);
    int x = a[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] <= x) {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[r]);
    return i;
}
int kth(int *a, int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int pos = p(a, l, r);
        if (pos - l == k - 1)
            return a[pos];
        if (pos - l > k - 1)
            return kth(a, l, pos - 1, k);
        return kth(a, pos + 1, r, k - (pos - l + 1));
    }
    return -1; 
}
void s() {
    int n, k;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &k);
    if (k > n || k < 1)
        printf("not present\n");
    else
        printf("%d\n", kth(a, 0, n - 1, k));
    free(a);
}
int main() {
    srand(time(0));
    int t;
    scanf("%d", &t);
    while(t--)
        s();
    return 0;
}