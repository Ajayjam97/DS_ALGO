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




  vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
              
        vector<vector<string>> answer;
        
        //map<string, pair<int,vector<pair<int,string>>>> details;
        //details.first = name
        //details.second.first = count
        //details.second.second.first = maxviews
        //details.second.second.second = id

        // int maxviews=0;
        // for(int i=0; i<creators.size(); i++){
        //     details[creators[i]].second.first+=views[i];
        //     maxviews=max(maxviews,details[creators[i]].second.first);

        // }


        map<string, int> creator;
        for(int i=0; i<creators.size(); i++){
            creator[creators[i]]+=views[i];
        }
        
        vector<pair<int,string>> cdetails;
        for(auto itr=creator.begin(); itr!=creator.end(); itr++){
            cdetails.push_back({itr->second, itr->first});
        }
        
        sort(cdetails.rbegin(), cdetails.rend());
        
        vector<string> popularcreators;
        
        int i=0;
        popularcreators.push_back(cdetails[0].second);
        
        while(cdetails[i+1].first==cdetails[i].first){
            popularcreators.push_back(cdetails[i+1].second);
            i++;
        }

        sort(popularcreators.begin(),popularcreators.end());
        for(string s : popularcreators) {cout<<s<<endl;}

        vector<pair<string,int>> details(popularcreators.size());
        for(int i=0; i<popularcreators.size(); i++){
            for(int j=0; j<creators.size(); j++){
                if(popularcreators[i]==creators[j]){
                    if(views[j]>details[i].second){
                        details[i]={ids[j],views[j]};
                        cout<<ids[j]<<" "<<views[j]<<endl;
                    }

                    if(views[j]==details[i].second&&ids[j]<details[i].first){
                        details[i]={ids[j],views[j]};
                        cout<<ids[j]<<" "<<views[j]<<endl;
                    }
                }
            }
        }

        for(int i=0; i<popularcreators.size(); i++){
            answer.push_back({popularcreators[i],details[i].first});
        }

        for(int i=0; i<popularcreators.size(); i++){
            cout<<answer[i][0]<<" "<<answer[i][1];
        }
        
        return answer;
        
           
    }



void solution(){
    
   int A,B,A1,B1,A2,B2;
   cin>>A>>B>>A1>>B1>>A2>>B2;

   if((A==A1 || A==B1)&&(B==A1 || B==B1)) cout<<"1"<<endl;

   else if((A==A2 || A==B2)&&(B==A2 || B==B2)) cout<<"2"<<endl;

   else cout<<"0"<<endl;

}

int main(){

fastio;
vector<string> creators={"alice","alice","alice"};
vector<string> ids={"a","b","c"};
vector<int> views={1,2,2};
 vector<vector<string>> result=mostPopularCreator(creators,ids,views);
// tc(t)
// solution();

}