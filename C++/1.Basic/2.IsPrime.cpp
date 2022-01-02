#include <bits/stdc++.h>
#include <cmath>
using namespace std;


bool IsPrime(int n){

    // for(int i = 2; i <=n; i++){
    //     if(n%i == 0)
    //     return false;
    // }

    //Optimized to O(sqrt(n)) complexity
    for(int i=2; i<=sqrt(n); i++){
        if(n%i == 0)
        return false;
    }

    return true;
}

void PrimeSieve(int n){

    //Set a Boolean array for the range
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    //Iterate from 2 to sqrt(n)
    for(int i=2; i<=sqrt(n); i++){
        //If the number is prime. Mark its multiples as Non Prime.
        if(prime[i-1]){
            //Marking multiples of i from i*i to n as Non Prime
            for(int j=i*i; j<=n; j+=i){
                prime[j-1] = false;
            }
        }
    }

    //Print the final Boolean array as result.
    for(int i=2; i<=n; i++){
        cout<<i<<": "<<(prime[i-1]? "True":"Flase")<<endl;
    }
}

int main(){

    int n; cin>>n;

    //Check if n is prime or not.
    //IsPrime(n) ? cout<<"True" : cout<<"False";

    //For quering all the prime numbers in a given range. The complexity is O(n*sqrt(n))
    // for(int i=2; i<=n; i++){
    //     cout<<i<<": ";
    //     IsPrime(i) ? cout<<"True"<<endl : cout<<"False"<<endl;
    // }

    //Using Sieve of Eratosthenes for getting prime numbers in a given range. Complexity is O(n)
    PrimeSieve(n);
}