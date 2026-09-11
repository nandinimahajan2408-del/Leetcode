class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int five=0;
       int ten=0;

       if(bills[0]!=5) return false;
       int n=bills.size();
       for(int i=0;i<n;i++){
        if(bills[i]==5){
            five++;
        }else if(bills[i]==10){
            if(five>=1) {
                five--;
                ten++;
            }else{
                return false;
            }
        }else{
            if(ten>=1&&five>=1){
                ten--;
                five--;
            }else if(five>=3){
                five=five-3;
            }else{
                return false;
            }
        }
       }
       return true; 
    }
};