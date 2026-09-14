class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec 1 left of rec2
        if(rec1[2]<=rec2[0]) return false;
        //rec 1 is right od rec2
        else if(rec2[2]<=rec1[0]) return false;
        //rec1 is down of rec2
        else if(rec1[3]<=rec2[1]) return false;
        //rec1 is above rec2
        else if(rec1[1]>=rec2[3]) return false;

        return true;
    }
};