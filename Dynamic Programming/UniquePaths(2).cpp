// Memoization
long mod = 1e9 + 7;

int f(int i,int j,vector<vector<int>>&dp, vector< vector< int> > &mat){
    if(i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;
    if(i == 0 && j == 0)
		return 1;

    if(i < 0 || j < 0)
		return 0;

    if(dp[i][j] != -1)
		return dp[i][j];

    int up = f(i-1,j,dp, mat);
    int left = f(i,j-1,dp, mat);

    return dp[i][j] = (up+left) % mod;

}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,dp, mat);
}

// Tabulation
int mod = (int)1e9 + 7;


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int dp[n][m];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
            if(i >= 0 && j >= 0 && mat[i][j] == -1)
                dp[i][j] = 0;
			else if(i == 0 && j == 0)
				dp[i][j] = 1;
			else
			{
				int up = 0;
				int left = 0;
				if(i > 0)
					up = dp[i-1][j];
				if(j > 0)
					left = dp[i][j-1];
				dp[i][j] = (up + left) % mod;
			}
		}
	}
	return dp[n-1][m-1];
}

// Tabulation with space optimisation
long mod = 1e9 + 7;


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int> prev(m, 0);

	for(int i = 0; i < n; i++)
	{
		vector<int> cur(m, 0);
		for(int j = 0; j < m; j++)
		{
            if(mat[i][j] == -1)
                cur[j] = 0;

			else if(i== 0 && j == 0)
				cur[j] = 1;
			else
			{
				int up = 0;
				int left = 0;
				if(i > 0)
					up = prev[j];
				if(j > 0)
					left = cur[j-1];
				
				cur[j] = (up + left) % mod;
			}
		}
		prev = cur;
	}

	return prev[m-1];
}