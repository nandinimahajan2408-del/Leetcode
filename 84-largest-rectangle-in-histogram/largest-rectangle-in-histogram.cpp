class Solution {
    vector<int>findnse(int n,vector<int>&heights){
        vector<int>ans(n);
        
        stack<int>st;//stores idx
        
        for(int i=n-1;i>=0;i--){
         while(!st.empty()&&heights[st.top()]>heights[i]){
            st.pop();
         }
         ans[i]=st.empty()?n:st.top(); 
         st.push(i); 
        }
        return ans;
    }
    vector<int>findpse(int n,vector<int>&heights){
        vector<int>ans(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
      vector<int>nse=findnse(n,heights);
      vector<int>pse=findpse(n,heights);
      int maxi=0;    
      for(int i=0;i<n;i++){
        maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
      }
      return maxi;
    }
};