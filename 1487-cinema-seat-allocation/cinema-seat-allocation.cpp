class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>&reservedSeats) {
      int families=0;
 unordered_map<int,vector<int>>umpp;

for(auto it:reservedSeats){
    int row= it[0];
    int col=it[1];

    umpp[row].push_back(col);
}

for(auto it:umpp){
    vector<int>seats=it.second;
bool left=false;
bool middle=false;
bool right=false; 

for(auto ite:seats){
    if(ite==2||ite==3){
        left=true;
    }
    if(ite==4||ite==5){
        left=true;
        middle=true;
    }
    if(ite==6||ite==7){
        middle=true;
        right=true;
    }
    if(ite==8||ite==9){
        right=true;
    }

}
if(!left&&!right){
    families+=2;
}else if(!left||!right||!middle){
    families+=1;
}
}
int empty=n-umpp.size();
families+=empty*2;
return families;  
    }
};