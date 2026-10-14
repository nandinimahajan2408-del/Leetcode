class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";

        string ans="";
        while(num){
           int digit=min(9,sum);
           ans+=char(digit+'0');
           sum=sum-digit; 
           num--;
        }
        return sum==0?ans:"";
    }
};