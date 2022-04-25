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


int main(){

    
}
