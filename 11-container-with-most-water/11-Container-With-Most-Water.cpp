class Solution {
public:
    int maxArea(vector<int>& height) {
       int j=height.size()-1;
       int result = 0;
      int i=0;
        while(i<j){
        int heght = min(height[i],height[j]);
        int width = j-i;
        result = max(result,width*heght);
        if(height[j]>height[i]) i++;
        else j--;
       }
        
       return result;
    }
};