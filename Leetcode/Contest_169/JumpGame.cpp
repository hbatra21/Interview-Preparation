class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if (nums.size() == 1)
        {
            return true;
        }
        int maxStep = 0;
        for (int i = 0; i < nums.size()-1 && i <= maxStep; ++i)
        {
            maxStep = max(maxStep, i+nums[i]);
            if (maxStep >= nums.size()-1)
            {
                return true;
            }
        }
       return false;
    }
};
