class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            //case 1: opening parantheses -> just push it
            if(s[i] == '(')
                st.push(i);
            //case 2: closing parantheses -> look for corresponding opening parantheses, if not found, push it
            else if(s[i] == ')'){
                if(!st.empty() && s[st.top()] == '(')
                    st.pop();
                else st.push(i);
            }
        }

        //now erase all elements which remain in stack as they violate the order from s
        while(!st.empty()){
            s.erase(st.top(), 1);
            st.pop();
        }
        return s;
    }
};