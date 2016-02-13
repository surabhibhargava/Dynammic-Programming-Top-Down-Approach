<h3><b>What is Dynammic Programming?!? </b></h3>

Dynamic programming or DP is a very powerful technique to solve a particular class of problems. The idea is very simple - If you have solved a problem with the given input, then save the result for future reference, so as to avoid solving the same problem again.

Consider the following: <br>
	A *writes down "1+1+1+1+1+1+1+1 =" on a sheet of paper*.<br>
	A : "What's that equal to?"<br>
	B : *counting* "Eight!"<br>
	A *writes down another "1+" on the left*<br>
	A : "What about that?"<br>
	B : *quickly* "Nine!"<br>
	A : "How'd you know it was nine so fast?"<br>
	A : "You just added one more"<br>
	A : "So you didn't need to recount because you remembered there were eight! <b>Dynamic Programming is just a fancy way to say 'remembering stuff to save time later'"</b><br>

Such problems can generally be broken down into smaller subproblems over and over again and these smaller subproblems are in turn divided in to still-smaller ones until we reach the base case, the solution to which we specify.

<h3><b> How can these problem be approached ? </b></h3>

There are two approches to solve a DP problem-<br>

-A top down approach : <br>Start solving the given problem by breaking it down. If you see that the problem has been solved already, then just return the saved answer. If it has not been solved, solve it and save the answer. This is usually easy to think of and very intuitive. This is referred to as Memoization.

-A bottom up approach :<br>  Analyze the problem and see the order in which the sub-problems are solved and start solving from the trivial subproblem, up towards the given problem. In this process, it is guaranteed that the subproblems are solved before solving the problem.

The solutions to dynammic programming problems are widely available on the internet but most of the sources provide a bottom up approach to these problems while I feel that for a beginner, a top down approach is easier to follow as it is just an addition of memoization to a recursive solution. 

<h4><b> Seps to come up with a dynamic programming solution </b></h4>

1) <b> Think of a recursive approach to solving the problem and code it!</b><br>
Create a function that solves the problem at hand. Decide what all arguments should be passed to the function for it to work in the desired fashion. Take a leap of faith and assuming your function solves the problem, write a recursive code for it.

2) <b> Identify where in your code, same problems are being computed again and again. </b><br>

3) <b> Store results - Memoize! </b>
Save the results you get for every function run so that if its called again, you do not recompute the whole thing and return just the stored value.

As an example, I have solved the problem of finding the Nth term of Fibbonacci Series using both the Dynammic Programming approaches:

TOP DOWN APPROACH:

		#include <iostream>
		#include <vector>
		using namespace std;
		// The function fib returns the n th term of the Fibonacci Series
		int fib (int n, vector<int> &dp){
			if (n==0 || n==1) return 1; // base case
			else if(dp[n]==-1){
			// enters inside this else only if the value of n th term of the fibonacci series is not calculated
				dp[n] = fib(n-1, dp) + fib(n-2, dp); // memoization of the recursive approach
			}
			return dp[n]; // return the stored value
		}

		int main() {
			int n;
			cin >> n;
			vector<int> dp(n+1,-1); // create a vector for memoization, initialize it to -1 i.e. value hasn't been computed yet
			cout << fib(n,dp) << endl;
			return 0;
		}

BOTTOM UP APPROACH:

		#include <iostream>
		#include <vector>
		using namespace std;

		// The function fib returns the n th term of the Fibonacci Series
		int fib(int n) {
		  vector<int> f(n+1,-1); // array to store the computed values
		  int i;
		  f[0] = 0;   
		  f[1] = 1; 
		  for (i = 2; i <= n; i++)
		      f[i] = f[i-1] + f[i-2]; // a for loop which calculates the values of fibonacci series for all i<=n
		  return f[n];
		}
		  
		int main () {
		  int n;
		  cin >> n;
		  cout << fib(n) << endl;
		  return 0;
		}

The difference between the two approaches is in the order in which the value for a particular 'n' is calculated.<br>
 In the bottom up approach, we build the solution from n=0 to n while in top down approach we break the problem for computing fib(n) in to two smaller subproblems of computing fib(n-1) and fib(n-2) and so on.

The idea behind these is essentially the same - "Save the results you get for every function run so that if its called again, you do not recompute the whole thing and return just the stored value."

I have solved various Dynammic Programming problems using the top down approach which can be found here.<br>
The idea behind DP is very simple but solving these problems may get overwhelming. <br>
Following is a list of resources that I followed for understanding DP.<br>
-<a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#DynamicProgramming" target="_blank">GeeksForGeeks</a><br>
-Tushar Roy's Youtube<a href="https://www.youtube.com/watch?v=8LusJS5-AGo&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr" target="_blank"> Videos</a><br>
-If you're preparing for Placement interviews then you may try <a href="https://leetcode.com/tag/dynamic-programming/" target="_blank">Leetcode</a>, <a href="https://www.interviewbit.com/" target="_blank">InterviewBit</a> and the book  <a href="http://www.eenadupratibha.net/Engineering-Colleges/Engineering-Jobs/Documents/crackingthecodinginterview.pdf" target="_blank">Cracking the Coding Interview </a>for your preparation.

