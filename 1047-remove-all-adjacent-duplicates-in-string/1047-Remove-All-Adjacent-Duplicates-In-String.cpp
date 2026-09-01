class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        for (char c : s) {
        // If the stack (string) is not empty and the top matches the current char, pop it
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    
    return result;
    }
};