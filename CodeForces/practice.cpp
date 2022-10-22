/*
Author: Ajay Singh
Linkedin: https://www.linkedin.com/in/ajay-jamwal97/
*/
#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define mod (int)1000000007
#define tc(t) int t; cin>>t; while(t--)
#define init(a,i) memset(a,i,sizeof(a));
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/__gcd(a,b)*b
//Powershell cmd: Get-Content input.txt | .\practice.exe >  output.txt



void solution(){
    
    int N,S;
    cin>>N>>S;

    int i=0; int j=N;

    while(i<=N&&j>=0){
        if(i+j==S){
            cout<<j-i<<endl; break;
        }
        else if(i+j>S){
            j--;
        }
        else if(i+j<S){
            i++;
        }
    }

}

int main(){

fastio;
tc(t)
solution();

}