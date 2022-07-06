class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        
        //two pointers occurs
        
        while(left <= right)
        {
            if(nums[left] == val)
            {
                swap(nums[left],nums[right]);
                right--;
            }
            else
                left++;
        }
        
        for(int left = 0; left < nums.size(); left++)
        {
            if(nums[left] == val)
                return left;
        }
        
        return nums.size();     //for not matching val
        
    }
};