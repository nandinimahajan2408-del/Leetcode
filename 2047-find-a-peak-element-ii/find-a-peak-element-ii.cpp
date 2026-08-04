class Solution {
public:
int findmaxidx(vector<vector<int>>&mat,int n,int m,int col){
    int maxi=INT_MIN;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxi){
            maxi=mat[i][col];
            idx=i;
        }
    }
    return idx;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxidx=findmaxidx(mat,n,m,mid);//mid=col,maxidx=col
            int left=mid-1>=0?mat[maxidx][mid-1]:-1;
            int right=mid+1<m?mat[maxidx][mid+1]:-1;

            if(mat[maxidx][mid]>left&&mat[maxidx][mid]>right){
                return{maxidx,mid};
            }else if(left>mat[maxidx][mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return{-1,-1};
    }
};
