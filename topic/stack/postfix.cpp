#include<bits/stdc++.h>
using namespace std;

int main(){
    string s="345+*9/2+";
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/'){
            st.push(s[i]-'0');
        }else{
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(s[i]=='+') st.push(a+b);
            else if(s[i]=='*') st.push(a*b);
            else if(s[i]=='-') st.push(a-b);
            else st.push(a/b);
        }
    }
    cout<<st.top();

}