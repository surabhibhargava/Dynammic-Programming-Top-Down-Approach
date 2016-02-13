// https://leetcode.com/problems/house-robber-ii/
// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    // create a function f which returns the maximum amount of money that can be robbed.
    // let i denote the current house the robber is at and e denote the last house
    int f(int i,int e, vector<int> nums, map<int, int> &hash){
        if(i>e){
            return 0;
        }
        if(hash.find(i)==hash.end()){
            // at each house the robber has the option of robbing that house and moving to the house after the adjacent house or to leave that particular house and move to the next. We need to take the maximum of the amount from both the cases.
            hash[i]=max(f(i+1,e,nums, hash),nums[i]+f(i+2,e,nums,hash));
        }
        return hash[i];
    }
        
        
    int rob(vector<int>& nums) {
     int ans;
     map<int,int> hash1, hash2;
     if(nums.size()==0) return 0;
     else if(nums.size()==1) return nums[0];
     // here two cases arise. The robber can start from house 0 and go till last but one house or start from the first house and go till the last house. This is because the last and first houses are adjacent and hence cannot be chosen in one single case.
     // we have to take the maximum of both these cases.
     ans=max(f(0,nums.size()-2,nums,hash1),f(1,nums.size()-1,nums, hash2));
     return ans;
    }
};