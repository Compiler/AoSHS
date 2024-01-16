class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> windowChars;

        int maxWindow = 0;
        int left = 0;
        int right = 0;

        while(right < s.size()){
            char curRChar = s[right];
            // Current char is already seen & in our window
            if(windowChars.find(curRChar) != windowChars.end() && windowChars[curRChar] >= left){
                left = windowChars[curRChar] + 1;
            }
            windowChars[curRChar] = right;
            maxWindow = std::max(maxWindow, right - left + 1);
            right++;
        }
        return maxWindow;
        
    }
};