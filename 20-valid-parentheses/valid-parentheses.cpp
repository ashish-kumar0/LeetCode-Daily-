// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char>st;
//         unordered_map<char, char> bracketMap = {
//         {')', '('},
//         {']', '['},
//         {'}', '{'}
//         };
//         for (char c : s){
//             if (bracketMap.count(c)) {
                
//             }
//         }
        
//     }
// };


class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.size() == 0){
                    return false;
                }

                if((st.top() == '(' && s[i] == ')') ||
                  (st.top() == '[' && s[i] == ']') ||
                  (st.top() == '{' && s[i] == '}')){
                  st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.size() == 0){
            return true;
        }
        return false;
    }
};