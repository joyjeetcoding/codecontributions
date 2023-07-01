// Memoization
// T.C = O(n x n) {Nearly}
// S.C = O(n x n) {DP Space} + O(n) {Recursion Stack Space}


#include <bits/stdc++.h> 

int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& triangle, int n)
{
	if(i == n-1)
		return triangle[i][j];
	
	if(dp[i][j] != -1)
		return dp[i][j];

	int down = triangle[i][j] + f(i+1, j, dp, triangle, n);
	int diag = triangle[i][j] + f(i+1, j+1, dp, triangle, n);

	return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));

	return f(0, 0, dp, triangle, n);
}


// Tabulation
// T.C = O(n x n) {Nearly}
// S.C = O(n x n) {DP Space}


#include <bits/stdc++.h> 

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, 0));

	// base case
	for(int j = 0; j < n; j++)
		dp[n-1][j] = triangle[n-1][j];

	for(int i = n-2; i >= 0; i--)
	{
		for(int j = i; j >= 0; j--)
		{
			int down = triangle[i][j] + dp[i+1][j];
			int diag = triangle[i][j] + dp[i+1][j+1];

			dp[i][j] = min(down, diag);
		}
	}
	return dp[0][0];
	
}

// Tabulation with Space Optimisation
// T.C = O(n x n) {Nearly}
// S.C = O(1) {DP Space}


#include <bits/stdc++.h> 

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> front(n, 0);

	// base case
	for(int j = 0; j < n; j++)
		front[j] = triangle[n-1][j];

	for(int i = n-2; i >= 0; i--)
	{
		vector<int> curr(n, 0);
		for(int j = i; j >= 0; j--)
		{
			int down = triangle[i][j] + front[j];
			int diag = triangle[i][j] + front[j+1];

			curr[j] = min(down, diag);
		}
		front = curr;
	}
	return front[0];
	
}