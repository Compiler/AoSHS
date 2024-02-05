class Solution {
public:

    void permuteHelper(vector<int>& nums, vector<vector<int>>& result, vector<int> slate = {}, int level = 0){
        if(slate.size() == nums.size()) return result.push_back(slate);

        for(int i = level; i < nums.size(); i++){
            slate.push_back(nums[i]);
            std::swap(nums[i], nums[level]);
            permuteHelper(nums, result, slate, level + 1);
            std::swap(nums[i], nums[level]);
            slate.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteHelper(nums, result);
        return result;
    }
};