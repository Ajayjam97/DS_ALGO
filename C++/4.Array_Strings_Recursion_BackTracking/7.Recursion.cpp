#include <bits/stdc++.h>
using namespace std;  

void printIncDec(int n){

    if(n==0) return;
    
    cout<<n<<endl;
    printIncDec(n-1);
    cout<<n<<endl;
    
}

int factorial(int n){

    if(n==0) return 1;
    
    int ans=n*factorial(n-1);
    return ans;
    
}

int power(int x,int n){
  
   if(n==0) return 1;
   return x*power(x,n-1);

}

int main(){

    int x,n; cin>>x>>n;
    //printIncDec(n);
    //factorial(n);
    power(x,n);

}