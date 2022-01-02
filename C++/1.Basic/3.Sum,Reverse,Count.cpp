#include<bits/stdc++.h>
using namespace std;

int main(){

    int sum,reverse,count;
    sum=reverse=count=0;

    int num,digit; cin>>num;

    while(num){
        digit = num%10;
        sum=sum+digit;
        reverse=reverse*10+digit;
        count++;
        num/=10;
    }

    cout<<"Sum: "<<sum<<endl<<"Reverse: "<<reverse<<endl<<"Count: "<<count<<endl;
}