class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int>st;//saves idx;
      int maxarea=0;
      int n=heights.size();
      for(int i=0;i<heights.size();i++){
        while(!st.empty()&&heights[st.top()]>heights[i]){
            int eleidx=st.top();
            st.pop();

           int nse=i;
           int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,(heights[eleidx]*(nse-pse-1)));
        }
        st.push(i);
      }
      while(!st.empty()){
        int eleidx=st.top();
        st.pop();
        int nse=n;
        int pse=st.empty()?-1:st.top();

        maxarea=max(maxarea,(heights[eleidx]*(nse-pse-1)));
      }
      return maxarea;  
    }
};