#include<bits/stdc++.h>
using namespace std;

int main(){

    int num; cin>>num;

    int i=2;

    while(num!=1){
         if(num%i == 0){
            cout<<i<<" ";
            num/=i;
        }
        else{
            i++;
        }
    }

}