// https://leetcode.com/problems/unique-paths/
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

class Solution {
public:
    //create a function that returns the number of unique paths
    // m signifies the row number and n is the column number
    //create a recursive function and apply memoization
    //here hash is the vector<vector> used for memoization
    int f(int m, int n, vector<vector<int> > &hash){
        if(m==0 and n==0) return 1; // if at the bottom right corner, then number of ways of reaching there is 1, i.e. already there -dont move
        if(m==0 and n>0) return f(m,n-1,hash); // if at the bottom but not at the right most point, then stay at the bottom and move right
        if(n==0 and m>0) return f(m-1,n,hash); // if at the right most column but not at the bottom most row, stay right and move down
        if(m<0 || n<0) return 0; 
        if(hash[m][n]==-1){
            return hash[m][n]=f(m,n-1,hash) + f(m-1, n, hash);
        }
        else return hash[m][n];
    }
    
    int uniquePaths(int m, int n) {
        vector<int> temp(n,-1);
        vector<vector<int> > hash(m, temp);
        return f(m-1,n-1,hash);
    }
};