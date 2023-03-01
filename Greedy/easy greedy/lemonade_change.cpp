// https://leetcode.com/problems/lemonade-change
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[3]={0};
        for(int i=0;i<bills.size(); i++){
            if(bills[i]==5){
                arr[0]++;
            }else if(bills[i]==10){
                if(arr[0]==0){
                    return false;
                }
                arr[0]--;
                arr[1]++;
            }else{
                if(arr[0]==0 || (arr[1]==0 && arr[0]<3)){
                    return false;
                }
                if(arr[1]>0){
                    arr[1]--;
                    arr[0]--;
                }else{
                    arr[0]-=3;
                }
                arr[2]++;
            }
        }
        return true;
    }
};