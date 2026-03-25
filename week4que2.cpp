#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int comp = 0, swaps = 0;

//Divide and conqure technique. (Randomize Quick Sort).
int Partition(vector<int>& arr,int st, int end){
    int piv = st + rand()%(end-st+1);
    int i = st, j = end;
    while(i <= end){
        while(i < end && arr[i] < arr[piv]){
            comp++;
            i++;
        }
        while(j >= piv && arr[j] > arr[piv]){
            j++;
            comp++;
        }
        comp += 2;
        if(i == piv)
            piv = j;
        if(j == piv)
            piv = i;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; 
    }
    return piv;
}
void QuickSort(vector<int>& arr,int st, int end){
    if(st>=end)
        return;
    int pivIdx = Partition(arr, st, end);
    
    QuickSort(arr, st, pivIdx-1);
    QuickSort(arr, pivIdx+1, end);
}
int main(){
    srand(time(0));
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n ; i++){
            cin >> arr[i];
        }
        QuickSort(arr, 0, n-1);
        for(int i=0; i<n ; i++){
            cout << arr[i] << " ";
        }
        cout << endl << "comparisions : " << comp ;
        cout << endl << "swaps : " << swaps << endl;
        comp = 0;
        swaps = 0;
    }
    return 0;
}