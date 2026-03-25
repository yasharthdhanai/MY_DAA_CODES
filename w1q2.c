#include<stdio.h>
int main(){
    int size, key;
    scanf("%d",&size);
    int arr[size];
    for(int i=0 ; i<size; i++){
        scanf("%d",&arr[i]); //Enter sorted array
    }
    scanf("%d",&key);
    int a = 0, b = size-1, mid;
    int i = 0;
    while(a < b){
        mid = (b-a)/2 + a ;
        i++;
        if(key > arr[mid])
            a = mid;
        else if(key < arr[mid])
            b = mid;
        else{
            printf("Present. %d",i);
            return 0;
        }
    }
printf("Not Present. %d",i);
return 0;
}