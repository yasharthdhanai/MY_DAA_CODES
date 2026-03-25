#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int size, key;
        scanf("%d",&size);
        int arr[size];
        for(int i=0 ; i<size; i++){
            scanf("%d",&arr[i]);
        }
        scanf("%d",&key);
        int c = 0;
        int i = 0;
        for(i ; i<size; i++){
            if(arr[i] == key){
                printf("Present. %d\n", i+1);
                c++;
                break;
            }
        }
        if(c == 0){
            printf("Not Present. %d\n", i);
        }
    }
    return 0;
}