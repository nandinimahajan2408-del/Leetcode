class Solution {   
public:
    int trap(vector<int>& height) {
        int n=height.size();
       long long total=0;
       int leftmax=INT_MIN;
       int rightmax=INT_MIN;
       int left=0;
       int right=n-1;

       while(left<right){
        if(height[left]<=height[right]){
            leftmax=max(leftmax,height[left]);
            total+=leftmax-height[left];
            left++;
        }else{
            rightmax=max(rightmax,height[right]);
            total+=rightmax-height[right];
            right--;
        }
       }
       return total;
       
    }
};