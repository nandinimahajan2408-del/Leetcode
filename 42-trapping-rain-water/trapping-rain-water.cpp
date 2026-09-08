class Solution {
    void findprefix(vector<int>&height,vector<int>&prefixmax){
        prefixmax[0]=height[0];
        for(int i=1;i<height.size();i++){
            prefixmax[i]=max(prefixmax[i-1],height[i]);
        }
    }
    void findsuffix(vector<int>&height,vector<int>&suffixmax){
        suffixmax[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            suffixmax[i]=max(suffixmax[i+1],height[i]);
        }
    }
    
public:
    int trap(vector<int>& height) {
        int n=height.size();
       vector<int>prefixmax(n);
       vector<int>suffixmax(n);
       findprefix(height,prefixmax);
       findsuffix(height,suffixmax);

       int total=0;
       for(int i=0;i<n;i++){
        if(height[i]<prefixmax[i]&&height[i]<suffixmax[i]){
            total=total+(min(prefixmax[i],suffixmax[i])-height[i]);
        }
       }
       return total;
    }
};