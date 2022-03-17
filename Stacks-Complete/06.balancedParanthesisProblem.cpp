#include<iostream>
#include<stack>
using namespace std;
/*
check if the paranthesis are balance or not
1. Iterate through all the chars
2. If ch == "(", push() on the stack
3. if ch == ")" and stack.top() == "(", consider this as a pair and do pop()
4. at the end if stack is empty, then the paranthesis were balanced
*/
bool check(char *s){
    
    stack<char> stk;
    
    for(int i = 0; s[i] != '\0'; i++){
        char ch = s[i];
        if(ch == '('){
            stk.push(ch);
        }
        else if(ch == ')'){
            if(stk.empty() or stk.top() != '('){
                return false;
            }
            stk.pop();
        }     
    }
    return stk.empty();
}
int main()
{
    char s[100] = "(((a+b)+(c-d+f)))";
    if(check(s)){
        cout<<"Balanced paranthesis"<<endl;
    }
    else{
        cout<<"Unbalanced paranthesis"<<endl;
    }
    return 0;
}