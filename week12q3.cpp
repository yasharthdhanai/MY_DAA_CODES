#include<bits/stdc++.h>
using namespace std;

void Permutation(string& s, int index, vector<string>& ans){
    // Base Case
    if(index == s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=index ; i<s.size() ; i++){
        // Swap characters
        swap(s[index], s[i]);
        // or we can do it with help of visited array and push back and pop back in string.

        // Recursive Call
        Permutation(s, index+1, ans);
        // Backtrack
        swap(s[index], s[i]);
    }
}

int main(){
    string s;
    cout << "Enter String : ";
    cin >> s;

    vector<string> ans;
    Permutation(s, 0, ans);

    // Sort in lexicographic order
    sort(ans.begin(), ans.end());

    cout << "\nPermutations in Lexicographic Order :\n";
    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}