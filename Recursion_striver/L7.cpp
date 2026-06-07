#include<bits/stdc++.h>
using namespace std;
    
// Print subsequence whose sum is k.
void printSubsequences(vector<int>& arr, int idx, vector<int>& temp, int target){ //All SubSequence.
    if(target == 0){
        for(auto it : temp){
            cout << it << " " ;
        }
        cout << endl;
        return;
    }
    if(idx >= arr.size()){
        return;
    }

    if(arr[idx] <= target){ // this condtion is when all elements are positive.
        temp.push_back(arr[idx]);
        printSubsequences(arr, idx+1, temp, target-arr[idx]);
        temp.pop_back();
    }

    printSubsequences(arr, idx+1, temp, target);
}
    
bool print_1_subseq(vector<int>& arr, int idx, vector<int>& temp, int target){ // Only 1 SubSequence.
    if(target == 0){
        for(auto it : temp){
            cout << it << " " ;
        }
        cout << endl;
        return true; 
    }
    if(idx >= arr.size()){
        return false;
    }
    if(arr[idx] <= target){ // this condtion is when all elements are positive.
        temp.push_back(arr[idx]);
        if(print_1_subseq(arr, idx+1, temp, target-arr[idx])){
            return true;
        }
        temp.pop_back();
    }
    return print_1_subseq(arr, idx+1, temp, target);
}

int count_subseq(vector<int>& arr, int idx, vector<int>& temp, int target){ // Only 1 SubSequence.
    if(target == 0)
        return 1;
    if(idx >= arr.size())
        return 0;
    int l = 0;
    if(arr[idx] <= target){ // this condtion is when all elements are positive.
        temp.push_back(arr[idx]);
        l = count_subseq(arr, idx+1, temp, target-arr[idx]);
        temp.pop_back();
    }
    int r = count_subseq(arr, idx+1, temp, target);
    return l+r;
}

int main(){
    vector<int> arr = {8, 5, 9, 1, 2, 4, 3, 6};
    int sum = 9;
    vector<int> temp;
    printSubsequences(arr, 0, temp, 9);
    cout << "number of total subsequence (Target=9) : " <<  count_subseq(arr, 0, temp, 9) << endl;
    cout<< "2nd func :-\n" ;
    print_1_subseq(arr, 0, temp, 7);
    
    return 0;
}