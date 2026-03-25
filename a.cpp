#include<bits/stdc++.h>
using namespace std;
void Qs(vector<int>&a,int l ,int r){
    if(l>=r){
        return;
    }
    int i =l,j=r;
    int pivot = a[l+(r-l)/2];
    while(i<=j){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j]>=pivot){
            j--;
        }
        if(i<=j){
            swap(a[i++],a[j--]);
        }
    }
    Qs(a,l,j);
    Qs(a,i,r);
}

void Ss(vector<int>&a){
    int n= a.size();
    for(int i=0;i<n;i++){
        int min =i;
        for(int j=i+1;i<n;i++){
            if(a[j]>a[min]){
                min =j;
            }
        }
        int temp =a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

void ms(vector<int>&a){
    if(a.size()<=1){
        return;
    }
    int mid =(a.size())/2;
    vector<int>l(a.begin(),a.begin()+mid);
    vector<int>r(a.begin()+mid,a.end());
    ms(l);
    ms(r);
    merge(l.begin(),l.end(),r.begin(),r.end(),a.begin());
}

bool dfs(int s ,int d ,vector<vector<int>>&adj,vector<int>&vist){
    if(s==d){
        return true;
    }
    vist[s]=true;
    for(int x:adj[s]){
        if(vist[x]==false){
            if(dfs(x,d,adj,vist)){
                return true;
            }
        }
    }
    return false;
}

bool dfs(int u ,vector<vector<int>>&adj,vector<int>&vist,vector<int>&path){
    vist[u]=1;
    path[u]=1;
    for(int i :adj[u]){
        if(vist[i]==false&&dfs(i,adj,vist,path)){
            return true;
        }
        if(path[i]){
            return true;
        }
    }
    path[u]=0;
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1 ; i<=n ; i++){
        int x;
        cin >> x;
        for(int j=1 ; j<=x ; j++){
            int y;
            cin >> y;
            adj[i].push_back(y);
        }
    }
    vector<int> vist(n,0),path(n,0);
    for(int i =0 ;i<n;i++){
        if(!vist[i] && dfs(i,adj,vist,path)){
            cout<<"Cycle exist";
            return 0;
        } 
    }
    cout<<"Cycle not found";
}

