// https://leetcode.com/problems/interleaving-string/
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",

// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.


class Solution {
public:
    // create a function f which returns 1 if the string s3 can be made by interleaving the strings s1 and s2.
    int f(string a, string b, string c, int i, int j, int k, vector<vector<int> >  &dp){
        // i stores the pointer to string a/s1, j to b/s2 and k to c/s3. 
        // if all the three pointers have reached the end of the string then return true
        if(k>=c.length() and i>=a.length() and j>=b.length()){ 
            return 1;
        }
        // else check if the character at the end of string a and c matches and/or b and c matches. 
        // if yes, incerment i and k and/or j and k respectively.
        // if no matching occurs then return false.
        if(dp[i][k]==-1){
            if(i<a.length() and c[k]==a[i] and j<b.length() and c[k]==b[j]) return dp[i][k]=(f(a,b,c,i+1,j,k+1,dp) || f(a,b,c,i,j+1,k+1,dp));
            else if(i<a.length() and c[k]==a[i]) return dp[i][k]=f(a,b,c,i+1,j,k+1,dp);
            else if(j<b.length() and c[k]==b[j]) return dp[i][k]=f(a,b,c,i,j+1,k+1,dp);
            else return 0;
        }
        return dp[i][k];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<int>t(s3.length()+1,-1);
        vector<vector<int> > s(s3.length()+1, t);
        // vector<vector<vector<int> > > dp(1+s1.length(), s);
        if(f(s1,s2,s3,0,0,0,s)) return true;
        return false;
        
    }
};
