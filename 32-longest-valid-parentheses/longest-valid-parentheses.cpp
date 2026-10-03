class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt=0;
        int n=s.size();
        int maxi=0;

        vector<int>vec={-1};
        for(int i=0;i<n;i++){
          if(s[i]=='('){
            vec.push_back(i);
          }else{
            vec.pop_back();
          if(vec.empty()){
            vec.push_back(i);
          }else{
            maxi=max(maxi,i-vec.back());
          }
          }
        }
        return maxi;
    }
};