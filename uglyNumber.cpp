// https://leetcode.com/problems/ugly-number-ii/

// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// Note that 1 is typically treated as an ugly number.

class Solution {
public:
    int nthUglyNumber(int n) {
        map<int, int> hash; //to store what all numbers have already been pushed into the ugly vector
        vector<int> ugly;
        ugly.push_back(1); // 1 is by default an ugly number
        int a, b, c;
        a=b=c=0; // to store which multiple of 2 3 or 5 has been added to the ugly number vector
        while(ugly.size()<n){
            //multiplly by 2, 3 and 5 to obtain the next ugly number
            int x=ugly[a]*2;
            int y=ugly[b]*3;
            int z=ugly[c]*5;
            //take the minima of these to be insterted
            int m=min(x,y);
            m=min(m,z);
            // increase a,b or c depending upon which multiple is added to the ugly number list
            if(m==x) a++;
            else if(m==y) b++;
            else c++;
            if(hash.find(m)==hash.end()){ //check if the number has already been inserted. if not then insert else continue
            ugly.push_back(m);
            hash[m]=1;
            }
            else continue;
        }
       return ugly[n-1];
    }
        
         
};

