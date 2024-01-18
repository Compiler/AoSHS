class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freqMap;
        std::for_each(s.begin(), s.end(), [&freqMap](const char character){freqMap[character]++;});
        std::for_each(t.begin(), t.end(), [&freqMap](const char character){
            if(--freqMap[character] == 0) freqMap.erase(character);
        });
        return freqMap.size() == 0;
    }
};