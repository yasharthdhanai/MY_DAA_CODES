#include<bits/stdc++.h>
using namespace std;
    
// Factorial of a number
    void factorial(int n, int ans){ // parametrized
        if(n == 0){
            cout << ans << endl;
            return;
        }
        factorial(n-1, ans*n);
    }

    int factorial2(int n){ // functional
        if(n == 0){
            return 1;
        }
        return n * factorial2(n-1);
    }
int main(){
    cout<< " 5! = " ;
    factorial(5, 1) ;
    cout<< "8! = " << factorial2(8) << endl;
    return 0;
}