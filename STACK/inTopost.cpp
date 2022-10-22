#include<bits/stdc++.h>
using namespace std;

int precendence(char a)
{
    if(a=='/' || a=='*')
        return 2;
  
    return 1;
}

string infix_to_postfix(stack<int> st, string str)
{
    string pstr;
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' )
        {
            pstr=pstr+str[i];
        }
        else
        {
            if(st.empty())
                st.push(str[i]);
            else if(precendence(str[i]) > precendence(st.top()))
                st.push(str[i]);
            else if( precendence(str[i]) <= precendence( st.top() ))
            {
                while((!st.empty()) && precendence(str[i]) <= precendence( st.top() ) )
                {
                char temp = st.top();
                pstr+=temp;        
                st.pop();
                }
                 st.push(str[i]);
            }     
                     

        }
    }
    while(!st.empty())
    {
        char temp=st.top();
        st.pop();
        pstr+=temp;
    }

return pstr;
}

int main()
{
    stack<int> st;
    string str,str_post;
    cout<<"Enter string : ";
    cin>>str;
    str_post=infix_to_postfix(st,str);
    cout<<str_post;


    return 0;
}
