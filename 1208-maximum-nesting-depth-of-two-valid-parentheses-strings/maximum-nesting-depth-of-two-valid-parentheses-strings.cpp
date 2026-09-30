class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
       int cnt=0;
       int n=seq.size();
       vector<int>ans(n);
       for(int i=0;i<n;i++){
        if(seq[i]=='('){
            cnt++;
            ans[i]=cnt%2;
        }else{
            ans[i]=cnt%2;
            cnt++;
        }
       } 
       return ans;
    }
};