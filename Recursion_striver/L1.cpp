#include<bits/stdc++.h>
using namespace std;

void Function(int n){
    if(n==0){
        return;
    }
    cout << n << " ";
    Function(n-1);
}
    
int main(){
    Function(15);
    return 0;
}