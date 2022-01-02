#include<bits/stdc++.h>
#include<cmath>
using namespace std;


int main(){

    int num,k; cin>>num>>k;
    int tempnum,count;  
    tempnum = num;
    count = 0;

    //Getting the count of digits
    while(tempnum){
        count++;
        tempnum/=10;
    }

    k = k % count;  //In case K is greater than the count of digits. To prevent TLE

    if(k<0){ k = count+k; } //For negative k

    int tenpower, restpower;
    tenpower=restpower=1;

    //Generating tenpower & restpower for leftval, rightval, result calculations
    for(int i=1; i<=count; i++){
        if(i<=k){
            tenpower*=10;
        }
        else{
            restpower*=10;
        }
    }

    //Using the tenpower to calculate leftval & rightval
    int leftval = num%tenpower;
    int rightval = num/tenpower;

    //Using the restpower to calculate result
    int result = leftval*restpower + rightval;
    cout<<result;
}