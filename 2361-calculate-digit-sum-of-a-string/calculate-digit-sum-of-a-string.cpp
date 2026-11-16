class Solution {
    string digit(string&s,int k){
        if(s.size()<=k) return s;

        string st="";
        int cnt=0;
         int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            sum+=s[i]-'0';
            cnt++;
            if(cnt==k||i==n-1){
                st+=to_string(sum);
                cnt=0;
                sum=0;
            }
        }
        return digit(st,k);
    }
public:
    string digitSum(string s, int k) {
       int n=s.size();
       return digit(s,k); 
    }
};