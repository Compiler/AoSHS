class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastCharInd = s.size() - 1; 
        int lastWordLen = 0;
        while(lastCharInd >= 0 && s[lastCharInd] == ' ')lastCharInd--;
        while(lastCharInd >= 0 && s[lastCharInd] != ' '){
            lastCharInd--;
            lastWordLen++;
        }

        return lastWordLen;
    }
};