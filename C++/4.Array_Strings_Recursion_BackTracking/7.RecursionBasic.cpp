#include <bits/stdc++.h>
using namespace std;  

void printIncDec(int n){

    if(n==0) return;
    
    cout<<n<<endl;
    printIncDec(n-1);
    cout<<n<<endl;
    
}

int factorial(int n){

    if(n==0) return 1;
    
    int ans=n*factorial(n-1);
    return ans;
    
}

int power(int x,int n){
  
    //LINEAR POWER
    // if(n==0) return 1;
    // return x*power(x,n-1);

    //LOGARTIHMIC POWER
    if(n==0) return 1;
    int ans=power(x,n/2);
    
    if(n%2!=0) return ans*ans*x;
    return ans*ans;

}

//GFG
class Solution{
    public:

    static long long count;

    long long toh(int N, int from, int to, int aux) {
        if(N==0){ 
            return count;
        }
        
        toh(N-1, from, aux, to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(N-1, aux, to, from);
        
        count++;
        return count;
    }

};

long long Solution::count=0;

int Max(int arr[], int idx, int n){
    // write your code here
    if(idx==n-1){
        return arr[idx];
    }

    int maxval=Max(arr,idx+1,n);
    return max(arr[idx],maxval);
    
}

int firstIndex(int arr[], int idx, int x, int n){
    // write your code here
    if(arr[idx]==x){
        return idx;
    }
    
    if(idx==n) return -1;

    int firstidx=firstIndex(arr,idx+1,x,n);
    return firstidx;
}

int lastIndex(int arr[], int idx, int x, int n){
    // write your code here
    
    if(idx==n) return -1;
    
    int lastidx=lastIndex(arr,idx+1,x,n);
    
    if(arr[idx]==x&&lastidx==-1){
        return idx;
    }
    
    return lastidx;
}

vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{
    if(idx==arr.size()){
        vector<int> bres(count);
        return bres;
    }
    
    
    if(arr[idx]==data){ 
        count++;
    }
    
    vector<int> res = allIndex(arr,idx+1,data,count);
    
    if(arr[idx]==data){ 
        res[count-1]=idx;
    }
    
    return res;
}

vector<string> gss(string s){
    // write your code here
    if(s.size()==0){
        vector<string> bres; bres.push_back("");
        return bres;
    }
    
    vector<string> res;
    vector<string> rres=gss(s.substr(1));
    
    for(string ss:rres){
        res.push_back(ss);
    }
    for(string ss:rres){
        res.push_back(s[0]+ss);
    }
    
    return res;
    
}

void printSS(string ques, string ans){
    // write your code here
    if(ques.size()==0){ 
        cout<<ans<<endl;
        return;
    }
    
    printSS(ques.substr(1),ans);
    printSS(ques.substr(1),ans+ques[0]);
    
}

vector<string> kpc = { ".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz" };

vector<string> getKPC(string s) {
  //Write your code here
  if(s.size()==0){
      vector<string> bres; bres.push_back("");
      return bres;
  }
  
  vector<string> rres=getKPC(s.substr(1));
  vector<string> res;
  
  for(char c:kpc[s[0]-'0']){
      for(string ss:rres){
          res.push_back(c+ss);
      }
  }
  
  return res;
  
}

void printKPC(string ques, string asf){
    // write your code here
    if(ques.size()==0){
        cout<<asf<<endl;
        return;
    }
    
    string code=kpc[ques[0]-'0'];
    
    for(int i=0; i<code.size(); i++){
        printKPC(ques.substr(1),asf+code[i]);
    }
    
}

vector<string> get_stair_paths(int n) {
  //Write your code here
  if(n==0){
      vector<string> bres; bres.push_back("");
      return bres;
  }
  
  vector<string> res;
  
  for(int jump=1; jump<=3&&n-jump>=0; jump++){
      
      vector<string> rres=get_stair_paths(n-jump);
      
      for(string s:rres){
          
          res.push_back(to_string(jump)+s);
      }
  }
  
  return res;
  
}

void printStairPaths(int n, string psf){
    // write your code here
    if(n==0){
        cout<<psf<<endl;
        return;
    }
    
    for(int jump=1; jump<=3&&n-jump>=0; jump++){
        printStairPaths(n-jump,psf+to_string(jump));
    }
    
}

int main(){

    //int x,n; cin>>x>>n;
    //printIncDec(n);
    //factorial(n);
    //power(x,n);

    // Solution ob;
    // int n; cin>>n;
    // cout<<ob.toh(n,1,3,2)<<endl;

    // int arr[] = {15, 30, 40, 4, 11, 9};
    // cout<<Max(arr,0,6)<<endl;

    //printSS("abc","");
    get_stair_paths(3);

}