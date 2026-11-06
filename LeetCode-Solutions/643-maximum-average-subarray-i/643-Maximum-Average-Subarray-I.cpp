class Solution { 
public: 
    double findMaxAverage(vector<int>& nums, int k) { 
        double avg = 0; 
        int low = 0; 
        
        // Calculate initial window average
        for(int i = 0; i < k; i++) { 
            avg += ((double)nums[i]) / k; 
        } 
        
        double res = avg; 
        
        // Removed 'hi++' inside the loop body so it only increments via the loop header
        for(int hi = k; hi < nums.size(); hi++) { 
            avg -= ((double)nums[low]) / k; 
            low++; 
            
            // Fixed the missing closing parenthesis in this line
            avg += ((double)nums[hi]) / k; 
            
            res = max(res, avg); 
        } 
        
        return res; 
    } 
};
