#include <stdio.h>
#include <stdlib.h>

long long c = 0;
long long in = 0;

void m(int *a, int l, int mid, int r) {
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        c++;
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
            in += (n1 - i);
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void ms(int *a, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        ms(a, l, mid);
        ms(a, mid + 1, r);
        m(a, l, mid, r);
    }
}

void s() {
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    c = 0;
    in = 0;
    ms(a, 0, n - 1);

    for(int i = 0; i < n; i++) {
        printf("%d%s", a[i], (i == n - 1) ? "" : " ");
    }
    printf("\ncomparisons = %lld\n", c);
    printf("inversions = %lld\n", in);

    free(a);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        s();
    }
    return 0;
}