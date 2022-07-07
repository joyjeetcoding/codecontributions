class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row * col;
        
        //index initialization
        int startingrow = 0;
        int endingcol = col-1;
        int endingrow = row-1;
        int startingcol = 0;
        
        while(count < total)
        {
            //printing starting row
            for(int index = startingcol; count < total && index <= endingcol; index++)
            {
                ans.push_back(matrix[startingrow][index]);
                count++;
            }
            startingrow++;
            
            //printing ending col
            for(int index = startingrow; count < total && index <= endingrow; index++)
            {
                ans.push_back(matrix[index][endingcol]);
                count++;
            }
            endingcol--;
            
            //printing ending row
            for(int index = endingcol; count < total && index >= startingcol; index--)
            {
                ans.push_back(matrix[endingrow][index]);
                count++;
            }
            endingrow--;
            
            //printing starting col
            for(int index = endingrow; count < total && index >= startingrow; index--)
            {
                ans.push_back(matrix[index][startingcol]);
                count++;
            }
            startingcol++;
        }
        return ans;
        
        
    }
};