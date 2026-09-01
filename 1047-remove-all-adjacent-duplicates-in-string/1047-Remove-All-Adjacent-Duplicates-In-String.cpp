class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        for(int i=0;i<s.size();i++){
            if(st.size()!=0){
                if(st.top()==s[i]){
                    st.pop();

                }else{ st.push(s[i]);}
            }
            else{
                st.push(s[i]);
            }
        }
        string s1="";
        while(st.size()!=0){
            s1=st.top()+s1;
            st.pop();
        }
        return s1;
    }
};