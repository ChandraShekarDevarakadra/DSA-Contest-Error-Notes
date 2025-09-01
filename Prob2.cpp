class Solution {
public:
int bestD=INT_MAX;
vector<int> best;
    void Rec(int n,int k,int fac,vector<int>& v){
        if(k==1){
            if(n>=fac){
                v.push_back(n);
                check(v);
                v.pop_back();
            }
            return ;
        }

        for(int i=fac;i<=n;i++){
            if(n%i==0){
                v.push_back(i);
                Rec(n/i,k-1,i,v);
                v.pop_back();
            }
        }
    }
    void check(vector<int>& v){
        int mn=*min_element(v.begin(),v.end());
        int ma=*max_element(v.begin(),v.end());
        if(ma-mn<bestD){
            bestD=ma-mn;
            best=v;
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int> v;
        Rec(n,k,1,v);
        return best;
    }
};
//https://leetcode.com/problems/balanced-k-factor-decomposition/