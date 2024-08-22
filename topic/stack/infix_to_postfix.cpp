// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include<bits/stdc++.h>
using namespace std;

string infixToPostfix(string s) {
    int n=s.size();
    string ans="";
    stack<char> st;
    
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push('(');
        else if(s[i]==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i]=='+' || s[i]=='-'){
            while(!st.empty() && (st.top()=='^' || st.top()=='*' || st.top()=='/' ||st.top()=='-' || st.top()=='+')){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }else if(s[i]=='*' || s[i]=='/'){
            while(!st.empty() && (st.top()=='^' || st.top()=='/' || st.top()=='*')){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }else if(s[i]=='^'){
            while(!st.empty() && st.top()=='^'){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else ans+=s[i];        
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    
    return ans;
}

int main(){
    string s="(a/b)*(c-d)+(e*(f-g))";
    cout<<infixToPostfix(s);
}