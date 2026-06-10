#include<bits/stdc++.h>
using namespace std;
    
//Pallindrome partitioning.
// [aab] => [a,a,b], [aa,b].
// [aabb] => [a,a,b,b], [a,a,bb], [aa,b,b], [aa,bb].

string isPalindrome(const string& s, int i, int x){
    string a = "";
    int c = i;
    int d = x; 
    while(c<d){
        if(s[c] != s[d])
            return "0";
        c++;
        d--;
    }
    while(i<=x){
        a += s[i];
        i++;
    }
    return a;
}
void solve(vector<vector<string>>& result, vector<string>& temp, const string& s, int i){
    if(i == s.length()){
        result.push_back(temp);
        return;
    }
    for(int x=i; x<s.length(); x++){
        string y = isPalindrome(s, i, x);
        if(y != "0"){
            temp.push_back(y);
            solve(result, temp, s, x+1);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> temp;
    solve(result, temp, s, 0);
    return result;
}

    
int main(){
    
    return 0;
}