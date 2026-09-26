class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mpp;
        for(int i=0;i<knowledge.size();i++){
            mpp[knowledge[i][0]]=knowledge[i][1];
        }

        int i=0;
          string finalans="";
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                string ans="";
                while(s[i]!=')'){
                    ans.push_back(s[i]);
                    i++;
                }
                if(mpp.find(ans)!=mpp.end()){
                    finalans+=(mpp[ans]);
                }else{
                    finalans+='?';
                }
            }else{
                if(s[i]!='('&&s[i]!=')') finalans+=s[i];
            }
            i++;
        }
        return finalans;
    }
};