class Solution {
    int findarea(vector<int>&height){
        int maxi=0;
        int n=height.size();
        stack<int>st;//saves idx
        for(int i=0;i<height.size();i++){
            while(!st.empty()&&height[st.top()]>height[i]){
                int eleidx=st.top();
                st.pop();

               int  nse=i;
                int pse=st.empty()?-1:st.top();

                maxi=max(maxi,height[eleidx]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int eleidx=st.top();
            st.pop();
           int nse=n;
            int pse=st.empty()?-1:st.top();

            maxi=max(maxi,height[eleidx]*(nse-pse-1));
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
     int n=matrix.size();
     int m=matrix[0].size();
     int maxi=0;

     if(matrix.empty()||matrix[0].empty()) return 0;
     vector<int>height(m,0);
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='1') height[j]++;
            else height[j]=0;
        }
        int area=findarea(height);
        maxi=max(maxi,area);
     }
     return maxi; 
    }
};