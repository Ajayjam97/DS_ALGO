#include <bits/stdc++.h>
using namespace std;  


static bool intervalCompare(vector<int> a, vector<int> b){
    return (a[0] < b[0]);
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> resintervals;

        sort(intervals.begin(), intervals.end(), intervalCompare);

        stack<pair<int,int>> s;
        s.push(make_pair(intervals[0][0],intervals[0][1]));
        
        for(int i=0; i<intervals.size(); i++){

            //check if the current interval is overlapping with previous
            if(intervals[i][0]<=s.top().second){
                //check if we can merge current & previous intervals (end of current interval is > end of previous interval)
                if(intervals[i][1]>s.top().second){
                    s.top().second = intervals[i][1];
                }
            }
            else{
                s.push(make_pair(intervals[i][0], intervals[i][1]));
            }
        }

        while(s.size()>0){
            pair<int,int> p = s.top(); s.pop();
            resintervals.push_back({p.first, p.second});
        }

        reverse(resintervals.begin(), resintervals.end());
        return resintervals;
        
}

int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (m.find(k - arr[i]) != m.end()) {
                count += m[k - arr[i]];
            }
            m[arr[i]]++;
        }
        return count;
    }

string transform(string S){
    //complete the function here
    stack<char> stk;
    stk.push(S[0]);
    string answer="";
    for(int i=1; i<S.size(); i++){

        char ccomp = S[i];

        if(S[i]<97)
        ccomp=S[i]+32; 

        if(stk.size()!=0&&stk.top()!=ccomp){
            int count=0;
            char c=stk.top();
            while(stk.size()>0){
                stk.pop(); count++;
            }
            answer+=to_string(count);
            answer+=c;
            stk.push(ccomp);
        }
        else{
            if(S[i]<97){
            char temp=S[i]+32;
            stk.push(temp);
            }
            else{
            stk.push(S[i]);
            }
        }
    }

            int count=0;
            char c=stk.top();
            while(stk.size()>0){
                stk.pop(); count++;
            }
            answer+=to_string(count);
            answer+=c;
    
    return answer;
    
}

string removeDups(string S) 
	{
	    // Your code goes here
	    
	    string ans="";
	    unordered_set<char>us;
	    for(int i=0;i<S.size();i++){
	        if(us.find(S[i])==us.end()){
	            ans+=S[i];
	            us.insert(S[i]);
	        }
	    }
	    return ans;
	}

string reverseWords(string S) 
    { 
        // code here 
        
        stringstream sentence(S);
        string word;
        vector<string> words;
        while(getline(sentence,word,'.')){
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        string answer="";
        for(int i=0; i<words.size(); i++){
            answer+=words[i];
            if(i!=words.size()-1)
            answer+=".";
        }
        
        return answer;
    }
    
int main(){

    cout<<transform("aaABBb")<<endl;
}
