class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        
        string output = "";
        int j = 0;
        
        while(j < strs[0].size()){
            
            for(int i=1; i<strs.size(); i++){
                
                if(strs[0][j] != strs[i][j]){
                    
                    return output;
                }
            }
            output = output + strs[0][j];
            j++;
        }
        
        
        return output;
    }
};