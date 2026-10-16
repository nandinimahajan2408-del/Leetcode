class Solution {
    static bool comp(pair<char,int>&a,pair<char,int>&b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    }
public:
    string frequencySort(string s) {
      
			int n=s.size();
            map<char,int>mpp;
            for(int i=0;i<n;i++){
                mpp[s[i]]++;
            }
           vector<pair<char,int>>vec(mpp.begin(),mpp.end());
           sort(vec.begin(),vec.end(),comp);
           string ans="";
           for(int i=0;i<vec.size();i++){
            while(vec[i].second){
               ans+=(vec[i].first);
                vec[i].second--;
            }
           } 
           return ans;
    }
};