#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
  
using namespace std;

int main(){

    unordered_map<char, int> mymap;
    string s; cin>>s;

    for(char c : s){
        if(mymap[c]!=0){
            mymap[c]++;
        }
        else{
            mymap[c]=1;
        }
    }

    char maxfrequencychar = 'a';
    int maxfrequency = 0;

    for(unordered_map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
        if(it->second > maxfrequency){
            maxfrequency = it->second;
            maxfrequencychar = it->first;
        }
    }

    cout<<maxfrequencychar;

    return 0;
}
