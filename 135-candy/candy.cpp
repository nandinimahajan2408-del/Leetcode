class Solution {
public:
    int candy(vector<int>& ratings) {
       //if it is higher than nei then get higher candies
       int n=ratings.size();
       int sum=1;
       int i=1;
       while(i<n){       
        //check for flat;
        if(ratings[i]==ratings[i-1]){
            sum=sum+1;
            i++;
        }
        //check for inc slope
        int peak=1;
        while(i<n&&ratings[i]>ratings[i-1]){
            peak++;
            sum=sum+peak;
            i++;
        }

        //check for dec slope
        int down=1;
        while(i<n&&ratings[i]<ratings[i-1]){
            sum=sum+down;
            down++;
            i++;
        }
        if(down>peak) sum=sum+(down-peak);

       } 
       return sum;
    }
};