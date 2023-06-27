// Memoization
// T.C = O(N) & S.C. = O(N) + O(N)
#include <bits/stdc++.h>

int f(int ind, vector<int>&dp, vector<int> &nums)
{
    if(ind == 0)
        return nums[ind];
    if(ind < 0)
        return 0;

    if(dp[ind] != -1)
        return dp[ind];

    int pick = nums[ind] + f(ind-2, dp, nums);
    int notPick = 0 + f(ind-1, dp, nums);

    return dp[ind] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(n-1, dp, nums);
}


// Tabulation
// T.C = O(N) & S.C. = O(N)


#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++)
    {
        int take = nums[i];
        if(i > 1)
            take += prev2;
        int nontake = 0 + prev;

        int curi = max(take,nontake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}