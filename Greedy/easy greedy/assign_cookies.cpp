// https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0,cnt=0,gsize=g.size(),ssize=s.size();
        if(ssize==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(j<ssize && i<gsize){
            if(g[i]<=s[j]){
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};