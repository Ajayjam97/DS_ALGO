#include<bits/stdc++.h>
using namespace std;


pair<long long, long long> getMinMax(long long a[], int n) {
    
    pair<long long, long long> result;
    long long min = 10e12;
    long long max = 1;
    
    for(int i=0; i<n; i++){
        
        if(a[i]>max) max=a[i];
        
        if(a[i]<min) min=a[i];
        
    }
    
    result = {min, max};
    
    return result; 
    
}