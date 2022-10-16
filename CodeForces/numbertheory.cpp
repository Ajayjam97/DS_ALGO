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
//Powershell cmd: Get-Content input.txt | .\numbertheory.exe >  output.txt

int binExponentiation(int a, int b){
    int ans=1;
    while(b){
        if(b&1){ ans = (ans*a);}
        a=(a*a);
        b>>=1;
    }
    return ans;
}
void solution(){

  cout<<binExponentiation(2,10);

}


int main(){

fastio;
//tc(t)
solution();

//Modulo Arithmatic:
//(a+b)%m = ((a%m)+(b%m))%m
//(a*b)%m = ((a%m)*(b%m))%m

//(a-b)%m = ((a%m)-(b%m)+m)%m
//(a/b)%m = ((a%m)*((b)^-1%m))%m 
//Here b^-1 is mulitplicative inverse of b. We calculate this using binary exopnentiation.

// int factorial=1; int n; cin>>n;
// for(int i=2; i<n; i++) factorial=(factorial*i)%mod;



//GCD:
//GCD 4 & 12 = 2^2 * 3^0 & 2^2 * 3^1 = Lowest common factors (2^2 * 3^0) = 4
//LCM 4 & 12 = 2^2 * 3^0 & 2^2 * 3^1 = Greatest common factors (2^2 * 3^1) = 12
//LCM = (a*b)/GCD   LCM calculated in O(1) if a,b & their GCD is known

//Euclid algorithm for GCD
//long long gcd(long long a,long long b){ return (b==0)?a:gcd(b,a%b); }



//Binary Exponentiation:
//We calculate Power using pow(a,b), but this is not efficient for large values
//int ans=1; for(int i=1; i<=b; i++) ans*=a;

//Recursive Method
//Simplest way to reduce O(n) is by using divide & conquer
//2^16 = 2^8 * 2^8
//2^8 = 2^4 * 2^4
//2^4 = 2^2 * 2^2
//2^2 = 2^1 * 2^1
//n=16 ---> Iterations needed = 4. Complexity reduced to O(logn)

// int pwr(int a, int b) 
// { if(b==0) return 1;  int ans=pwr(a,b/2); return (b&1) ? a*ans*ans : ans*ans;}

//Iterative method
//Using binary representation of b we can calculate the power
//3^13 --> 3^(1101)base2 --> 3^(8+4+0+1) --> 3^8 * 3^4 * 3^0 * 3^1
//b=1101    a=3^1     ans=3^1
//b=110     a=3^2     ans=3^1
//b=11      a=3^4     ans=3^4 * 3^1
//b=1       a=3^8     ans=3^8 * 3^4 * 3^1
//We can get the result by right shifiting the value of b & squaring the value of a.

// int binExponentiation(int a, int b){
//     int ans=1;
//     while(b){
//         if(b&1){ ans = (ans*a);}
//         a=(a*a);
//         b>>=1;
//     }
//     return ans;
// }












}