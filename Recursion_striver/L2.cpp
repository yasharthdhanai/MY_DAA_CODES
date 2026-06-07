#include<bits/stdc++.h>
using namespace std;
    
void OneToN(int n){  // Backtracking
    if(n == 0)
        return;
    OneToN(n - 1);
    cout << n << " ";
}

void NToOne(int n, int i){  // Backtracking
    if(i > n)
        return;
    NToOne(n, i+1);
    cout << i << " ";
}
    
int main(){
    OneToN(5);
    cout << endl;
    NToOne(5 ,1);
    return 0;
}