#include<bits/stdc++.h>
using namespace std;
float maxvalue(priority_queue<pair<float,int>>& pq, int capacity){
    if(capacity <= 0 || pq.empty()){
        return 0;
    }
    float ans = 0;
    if(pq.top().second <= 0){
        pq.pop();
        if(pq.empty()){
            return 0;
        }
    }
    float a = pq.top().first;
    ans = ans + a;
    int b = pq.top().second;
    pq.pop();
    pq.push({a,b-1});
    return maxvalue(pq, capacity-1) + ans;
}
int main(){
    int n, capacity;
    cin >> n;
    vector<int> value(n);
    for(int i=0; i<n; i++){
        cin>> value[i];
    }
    vector<int> weight(n);
    for(int i=0; i<n; i++){
        cin>> weight[i];
    }
    cin >> capacity;
    priority_queue<pair<float,int>> pq;
    for(int i=0 ; i<n ; i++){
        float a = (value[i]*1.0)/weight[i];
        pq.push({a, weight[i]}); 
    }
    float ans = maxvalue(pq, capacity);
    cout << ans ;
    return 0;
}