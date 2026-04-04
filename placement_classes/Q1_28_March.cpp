#include<bits/stdc++.h>
using namespace std;

// E energy and N number of exercises. if energy is equals to or less than you gets tired.
// You can do a exercises max twice. Minimum number of exercises you have to do to get tired, else -1.
int main(){
    int E, N;
    cin >> E >> N;
    vector<int> AI(N); // AI is energy.
    for(int i=0 ; i<N ; i++){
        cin >> AI[i];
    }
    sort(AI.begin(), AI.end(), greater<int>());

    int count = 0;
    for(int i=0 ; i<N ; i++){
        if(E <= 0)
            break;
        E -= AI[i];
        count++;
        if(E <= 0)
            break;
        E -= AI[i];
        count++;
    }
    cout << (E <= 0 ? count : -1) << endl;
    return 0;
}