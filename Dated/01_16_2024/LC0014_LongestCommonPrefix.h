class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Linearly find smallest string
        int maxPrefixLen = std::min_element(strs.begin(), strs.end(), [](const std::string& a, const std::string& b) {return a.size() < b.size();})->size();

        auto firstNArePrefix = [](const std::string& s, std::string prefix, int n) { return s.substr(0, n) == prefix; };
        //First to baseline check
        bool allMatchFirstChar = std::all_of(strs.begin(), strs.end(), [prefix = strs[0].substr(0, 1)](const std::string& s) { return s.substr(0, prefix.size()) == prefix; });
        if(!allMatchFirstChar) return "";
        bool allMatchMaxChar = std::all_of(strs.begin(), strs.end(), [prefix = strs[0].substr(0, maxPrefixLen)](const std::string& s) {return s.substr(0, prefix.size()) == prefix; });
        if(allMatchMaxChar) return strs[0].substr(0, maxPrefixLen);
        // Binary search between 1-maxPrefixLen
        int len = 2;
        std::string currentAnswer = allMatchFirstChar ? strs.begin()->substr(0, 1) : "";
        while(len <= maxPrefixLen && len > 1){
            int m = (maxPrefixLen - len) / 2 + len;
            bool allMatchFirstNChars = std::all_of(strs.begin(), strs.end(), [prefix = strs[0].substr(0, m)](const std::string& s) { return s.substr(0, prefix.size()) == prefix; });
            if(!allMatchFirstNChars){
                maxPrefixLen = m - 1;
            }else{
                currentAnswer = strs[0].substr(0, m);
                len = m + 1;
            }
        }
        return currentAnswer;
    }
};