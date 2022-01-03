#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    int result = fib(n-1) + fib(n-2);
    return result;
}

int main(){
    int num; cin>>num;
    for(int i=1;i<=num;i++)
    cout<<fib(i)<<" ";
}