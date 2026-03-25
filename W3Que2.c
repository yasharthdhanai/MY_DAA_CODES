#include <stdio.h>
#include <stdlib.h>

void solve() {
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int c = 0, s = 0, m, t;
    for(int i = 0; i < n - 1; i++) {
        m = i;
        for(int j = i + 1; j < n; j++) {
            c++;
            if(a[j] < a[m]) {
                m = j;
            }
        }
        t = a[m];
        a[m] = a[i];
        a[i] = t;
        s++;
    }
    for(int i = 0; i < n; i++) {
        printf("%d%s", a[i], (i == n - 1) ? "" : " ");
    }
    printf("\ncomparisons = %d\n", c);
    printf("swaps = %d\n", s);
    free(a);
}
int main() {
    int t_cases;
    scanf("%d", &t_cases);
    while(t_cases--) {
        solve();
    }
    return 0;
}