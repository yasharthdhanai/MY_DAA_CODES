#include <stdio.h>
#include <stdlib.h>
int c(const void *a, const void *b){
    return (*(int*)a - *(int*)b);}
void s() {
    int n, k;
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        scanf("%d", &k);
    qsort(a, n, sizeof(int), c);
    int l = 0, r = n - 1, f = 0;
    while(l < r) {
        int sum = a[l] + a[r];
        if(sum == k) {
            printf("%d %d\n", a[l], a[r]);
            f = 1; break; 
        }else if(sum < k)
            l++;
        else
            r--;
    }
    if(!f) printf("No Such Elements Exist\n");
    free(a);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        s();
    return 0;
}