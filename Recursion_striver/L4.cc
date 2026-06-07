#include<bits/stdc++.h>
using namespace std;
    
// reverse an array using recursion.
void rev_arr(int arr[], int i, int n){
    if(i >= n/2)
        return;
    swap(arr[i], arr[n-i-1]);
    rev_arr(arr, i+1, n);
}

// check if a string is a pallindrome or not.

bool is_pallindrome(string s, int i, int j){
    if(i >= j)
        return true;
    if(s[i] != s[j])
        return false;
    return is_pallindrome(s, i+1, j-1);
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    rev_arr(arr, 0, 5); // 0 is the starting index and 5 is the size of the array.
    cout << "Reversed array: ";
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    string s = "racecar";
    if(is_pallindrome(s, 0, s.length()-1))
        cout << "The string is a palindrome." << endl;
    else
        cout << "The string is not a palindrome." << endl;

    return 0;
}