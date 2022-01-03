#include<bits/stdc++.h>
using namespace std;

int AnyBaseToDecimal(int n,int b){

    int power=1; int res=0;

    while(n){
        int digit = n%10;
        n/=10;
        res+=digit*power;
        power*=b;
    }

    return res;
}

int DecimalToAnyBase(int n,int b){

    int power=1; int res=0;

    while(n){
        int digit = n%b;
        n/=b;
        res = res + digit*power;
        power*=10;
    }

    return res;
}


int main(){

    int n,b;    
    cin>>n>>b;
    cout<<AnyBaseToDecimal(n,b);
    cin>>n>>b;
    cout<<DecimalToAnyBase(n,b);
    
}