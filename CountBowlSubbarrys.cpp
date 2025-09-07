class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        vector<int>left(n,-1),right(n,-1);
        for(int i=0;i<nums.size();i++){
            while(s.size()>0&&s.top()<=nums[i])s.pop();
            if(s.size()>0){
                left[i]=s.top();
            }
            s.push(nums[i]);
        }
        stack<int> s1;
        for(int i=nums.size()-1;i>=0;i--){
            while(s1.size()>0&&s1.top()<=nums[i])s1.pop();
            if(s1.size()>0){
                right[i]=s.top();
            }
            s1.push(nums[i]);
        }
       long long count=0;
       for(int i=0;i<n;i++){
        if(left[i]!=-1&&right[i]!=-1)count++;
       }
       return count;
    }
    /* https://leetcode.com/problems/count-bowl-subarrays/description/ */