class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>vec(n);
        for(int i=0;i<n;i++){
            int nn=nums[i];
            int sum=0;
            while(nn){
                sum+=nn%10;
                nn=nn/10;
            }
            vec[i]={sum,nums[i],i};
        }
        sort(vec.begin(),vec.end(),[](const vector<int>&a,const vector<int>&b){
         if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
        });
        vector<bool>visited(n,false);
        int swaps=0;
        for(int i=0;i<n;i++){
            if(visited[i]||vec[i][2]==i) continue;
            int cyclesize=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                cyclesize++;
                j=vec[j][2];
            }
            if(cyclesize>1) swaps+=(cyclesize-1);
        }
        return swaps;
    }
};