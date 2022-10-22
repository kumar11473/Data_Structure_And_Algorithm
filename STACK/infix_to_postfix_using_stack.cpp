#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c)
{
    if(c=='+' || c=='*' || c=='-' || c=='^' || c=='/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='+' || c=='-')    
        return 1;
    else
        return -1;
}

string InfixToPostfix(stack<char> s, string infix)
{
  string postfix;
  int i;
  for(i=0;i<infix.length();i++)
  {
      if((infix[i] >='a' && infix[i]<='z') || infix[i]>='A' && infix[i]<='Z')
      {
          postfix+=infix[i];
      }
      else if(infix[i]=='(')
      {
          s.push(infix[i]);
      }
      else if(infix[i]==')')
      {
          while((s.top()!='(') && (!s.empty()) )
          {
           char temp=s.top();
           postfix+=temp;
           s.pop();
          }    
          if(s.top()=='(')
          {
              s.pop();
          }
      }
      else if(isOperator(infix[i]))
      {
        if(s.empty())
        {
            s.push(infix[i]);
        }
        else
        {
          if(precedence(infix[i])>precedence(s.top()))
          {
              s.push(infix[i]);
          }
          else if((precedence(infix[i])==precedence(s.top()) && (infix[i]=='^')))  // a unique condition when infix contain two or more '^'
          {
              s.push(infix[i]);
          } 
          else //
          {
                while((!s.empty()) && precedence(infix[i])<=precedence(s.top()))
                {
                    char temp=s.top();
                    postfix+=temp;
                    s.pop();
                }
                s.push(infix[i]);
          }
        }
      }
 
  }
 // for printing remaining operator in the stack
 while(!s.empty())
 {
    //  char temp=s.top();
    //  postfix=+temp;
    //  s.pop();
    postfix+=s.top();
    s.pop();
 }

  return postfix;
}

int main(){
    string infix_exp,postfix_exp;

    cout<<"Enter a infix Expression :"<<endl;
    cin>>infix_exp;
    stack<char> stack;
    cout<<"Infix Expression :"<<infix_exp<<endl;
    postfix_exp=InfixToPostfix(stack,  infix_exp);
    cout<<"PostFix Expression : "<<postfix_exp<<endl;

    return 0;
}