//17. Letter Combinations of a Phone Number
class Solution {
public:
    void myfn(vector<string>&res, string substring, unordered_map<char, string>& myMap, string digits, int start)
    {
        if(substring.size() == digits.size())
            res.push_back(substring);
        else
            for(int i = start; i < digits.size(); i++)
            {
                string letters = myMap[digits[i]]; // find letters group of digits
                for(int j = 0; j < letters.size(); j++)
                {
                    substring.push_back(letters[j]);
                    myfn(res, substring, myMap, digits, i+1);
                    substring.pop_back();
                }                   
            }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, string> myMap = {{'2',"abc"},
                                             {'3',"def"},
                                             {'4',"ghi"},
                                             {'5',"jkl"},
                                             {'6',"mno"},
                                             {'7',"pqrs"},
                                             {'8',"tuv"},
                                             {'9',"wxyz"}};
        string substrings;
        vector<string> res;
        if(digits.size() == 0)
            return res;
        myfn(res, substrings, myMap, digits, 0);
        return res;    
    }
};