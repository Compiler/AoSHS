class Solution {
public:
    // How I would solve it in an interview/production
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueNums;
        for(int i = 1; i < nums.size(); i++) uniqueNums.insert(i);

        for(auto& num : nums){
            auto numIt = uniqueNums.find(num);
            if(numIt == uniqueNums.end()) return num;
            uniqueNums.erase(numIt);
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[nums[0]];
        int fast = nums[nums[nums[0]]];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;

    }
};