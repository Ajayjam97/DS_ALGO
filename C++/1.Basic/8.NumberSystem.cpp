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

int AnyBaseAddition(int b, int n1, int n2){

    int carry,power,res;
    carry = 0; power = 1; res = 0;

    while(n1 != 0 || n2 != 0 || carry != 0){
        int val1 = n1%10; n1/=10;
        int val2 = n2%10; n2/=10;

        int sum = val1 + val2 + carry;
        int val = sum%b;
        carry = sum/b;
        res = res + val*power;
        power*=10;
    }

    return res;
}

int AnyBaseSubtraction(int b, int n2, int n1){

    int carry = 0;
    int power = 1;
    int res = 0;

    while(n2!=0){

        int val1 = n1%10; n1/=10;
        int val2 = n2%10; n2/=10;

        int val = val2 - val1 + carry;

        if(val < 0){
            val+=b;
            carry=-1;
        }
        else{
            carry=0;
        }

        res = res + val*power;
        power*=10;
    }
    return res;
}

int main(){

    int n,b;    
    cin>>n>>b;
    cout<<AnyBaseToDecimal(n,b)<<endl;
    cin>>n>>b;
    cout<<DecimalToAnyBase(n,b)<<endl;

    int n1,n2;  
    cin>>b>>n1>>n2;
    cout<<AnyBaseAddition(b, n1, n2)<<endl;
    cin>>b>>n1>>n2;
    cout<<AnyBaseSubtraction(b, n1, n2)<<endl;
    
}