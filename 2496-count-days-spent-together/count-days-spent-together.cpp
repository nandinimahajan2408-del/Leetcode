class Solution {
    int calttoday(string&s){
        vector<int>month={31,28,31,30,31,30,31,31,30,31,30,31};
        int m=(s[0]-'0')*10+(s[1]-'0');
        int d=(s[3]-'0')*10+(s[4]-'0');
        int res=d;
        for(int i=0;i<m-1;i++) res+=month[i];
        return res;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
     int salice=calttoday(arriveAlice);
     int ealice=calttoday(leaveAlice);
     int sbob=calttoday(arriveBob);
     int ebob=calttoday(leaveBob);

     int start=max(salice,sbob);
     int end=min(ealice,ebob);

     return start<=end?end-start+1:0;   
    }
};