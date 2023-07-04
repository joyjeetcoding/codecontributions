class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        dfs(0, candidates, {}, 0, results, target);
        return results;
    }
    
    
    void dfs(int i, vector<int>& candidates, vector<int> curOutput, int curSum, vector<vector<int>>& results, int& target)
    {
        if(i >= candidates.size())
        {
            return;
        }
        dfs(i + 1, candidates, curOutput, curSum, results, target);
        curOutput.push_back(candidates[i]);
        curSum += candidates[i];
        if(curSum == target)
        {
            results.push_back(curOutput);
            return;
        }
        if(curSum > target)
        {
            return;
        }
        dfs(i, candidates, curOutput, curSum, results, target);
    }
};
