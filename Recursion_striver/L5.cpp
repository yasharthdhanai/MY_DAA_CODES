#include<bits/stdc++.h>
using namespace std;
    
// nth fibonachii number.
int fibnum(int n){
    if(n <= 1){
        return n;
    }
    return fibnum(n-1) + fibnum(n-2);
}
    
int main(){
    int n = 8;
    cout << "The " << n << "th Fibonacci number is: " << fibnum(n) << endl;
    return 0;
}