class Solution {
    void findpse(vector<int>&pse,vector<int>&arr){
        stack<int>st;

        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }

    void findnse(vector<int>&nse,vector<int>&arr){
        stack<int>st;

        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
     //find nse and pse for every element and multiply by the no;
     int n=arr.size();
     vector<int>pse(n);
     vector<int>nse(n);
     findpse(pse,arr);
     findnse(nse,arr);

     int mod=(int)(1e9+7);
     long long total=0;
     for(int i=0;i<n;i++){
        long long left=i-pse[i];
        long long right=nse[i]-i;

        total=(total+(right*left*1LL*arr[i])%mod)%mod;
     }
     return total; 
    }
};