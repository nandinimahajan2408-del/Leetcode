class Solution {  
public:
    int distinctSubseqII(string s) {
      vector<vector<string>>ans;
      int n=s.size();
      int MOD=1e9+7;
      vector<long long>last(26,0);//mapping no of strings end at ele
      for(int i=0;i<s.size();i++){//for string
        long long cursum=0;
        for(int j=0;j<26;j++){
            cursum=(cursum+last[j])%MOD;
        }
        last[s[i]-'a']=(cursum+1)%MOD;
      }

      long long total=0;
      for(int i=0;i<26;i++){
        total=(total+last[i])%MOD;
      }
      return total;
    }
};