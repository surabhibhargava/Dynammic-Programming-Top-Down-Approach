// https://leetcode.com/problems/climbing-stairs/

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    //create a function f which gives the number of distinct ways to climb to the top
    int f(int n, map<int, int> &hash){
        if(n==0) return 1;
        if(n<0) return 0;
        if(hash.find(n)==hash.end()){
            hash[n]=f(n-1,hash)+f(n-2,hash); // since the number of steps at one time can be 1 or 2, therefore add both the possibilities
        }
        return hash[n];
    }
    
    int climbStairs(int n) {
        map<int, int> hash;
        return f(n, hash);
    }
};