class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<j){
           int ch = s[i];
           int ch1 = s[j];
            if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
          ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
               i++;
                 }
            else if(!(ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u' ||
    ch1 == 'A' || ch1 == 'E' || ch1 == 'I' || ch1 == 'O' || ch1 == 'U')){
        j--;
    }
    else {
        swap(s[i],s[j]);
        i++;
        j--;
    }
        }
       return s; 
    }
};