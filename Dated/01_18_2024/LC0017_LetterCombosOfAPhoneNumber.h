class Solution {
private:
    unordered_map<char, vector<char>> mapping;
public:

    void generateOptions(std::vector<std::string>& result, std::string& digits, std::string slate = "", int index = 0){
        if(index == digits.size())return result.push_back(slate);
        for(auto& letter : mapping[digits[index]]){
            generateOptions(result, digits, slate + letter, index + 1);
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        mapping['2'] = {'a','b','c'};
        mapping['3'] = {'d','e','f'};
        mapping['4'] = {'g','h','i'};
        mapping['5'] = {'j','k','l'};
        mapping['6'] = {'m','n','o'};
        mapping['7'] = {'p','q','r','s'};
        mapping['8'] = {'t','u','v'};
        mapping['9'] = {'w','x','y','z'};

        std::vector<std::string> result;

        generateOptions(result, digits);
        return result;
        
    }
};