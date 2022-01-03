#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n1,n2; cin>>n1>>n2;

    int rem,dividend,divisor;
    dividend = n1; divisor = n2;
    rem = dividend%divisor;
    while(rem){
        dividend = divisor;
        divisor = rem;
        rem = dividend%divisor;
    }

    cout<<"GCD: "<<divisor<<endl<<"LCM: "<<(n1*n2)/divisor<<endl;
}