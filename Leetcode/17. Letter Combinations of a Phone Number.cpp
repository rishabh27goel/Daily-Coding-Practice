class Solution {
public:

    vector<string> output;
    vector<string> letterMap = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void combinationHelper(string combo, int index, string digits){
        
        if(index == digits.size()){
            
            output.push_back(combo);
            return;
        }
        
        string letters = letterMap[digits[index]-'0'];
        
        for(int i=0; i<letters.size(); i++){
            
            combinationHelper(combo+letters[i], index+1, digits);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {

        if(digits.size() == 0) return output;
        
        combinationHelper("", 0, digits);
        
        return output;
    }
};