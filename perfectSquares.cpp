// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

// https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    
    int f(int n, vector<int> &hash){
        if(n<=0) return 0; // if n < 0, 0 number of squares can be added to get n
        if(n==1) return 1; // for n=1, number of ways = 1
        if(hash[n]==-1){ 
            int t,m;
            m=INT_MAX;
            for(int i=1;i*i<=n;i++){ //this loop finds out all the combinations of squares that must be added to obtain n
                t=1+f(n-(i*i),hash);
                m=min(t,m); // m stores the minimum number of squares in all the combinations
            }
            hash[n]=m;
        }
        return hash[n];
    }
    
    int numSquares(int n) {
        vector<int> hash(n+1,-1); // for memoization
        for(int i=1; i*i<=n; ++i) {
            hash[i*i] = 1;
        }
        return f(n,hash);
    }
};