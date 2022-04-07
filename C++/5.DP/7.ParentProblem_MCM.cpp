#include <bits/stdc++.h>
using namespace std;

int mcm(int i, int j, int arr[]){
        
        if(i==j) return 0;
        
        int mini=1e9;
        
        for(int k=i+1; k<=j; k++){
            int steps = arr[i-1]*arr[k-1]*arr[j] + mcm(i, k-1, arr) + mcm(k, j, arr);
            if(steps<mini) mini=steps;
        }
        
        return mini;
        
    }
    
int matrixMultiplication(int N, int arr[])
    {
        // code here
        return mcm(1, N-1, arr);
    }

int main() {

    int arr[] = {40, 20, 30, 10, 30};
    cout<<matrixMultiplication(5, arr);

}