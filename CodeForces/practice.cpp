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
    
int numbers[] = {40,20,30,10};
sort(numbers,numbers+sizeof(numbers)/sizeof(int));
for(auto c : numbers){
    cout<<c<<endl;
}

}

int main(){

fastio;
// tc(t)
solution();

}