#include<bits/stdc++.h>
using namespace std;


bool DuplicateBrackets(string str){

    stack<char> stk;

    for(int i=0; i<str.size(); i++){

        if(str[i]==')'){

            if(stk.top()=='(') return true;

            while(stk.top()!='('){
                stk.pop();
            }
            stk.pop();
            
        }
        else{
            stk.push(str[i]);
        }
    }

    return false;
}

bool BalancedBrackets(string str){

    stack<char> stk;

    for(int i=0; i<str.size(); i++){

        if(str[i]==')'||str[i]==']'||str[i]=='}'){

            char openingbrack;
            if(str[i]==')') openingbrack='('; else if(str[i]==']') openingbrack='['; else if(str[i]=='}') openingbrack='{';

            if(stk.empty()||stk.top()!=openingbrack){
                return false;
            }
            stk.pop();
        }
        else if(str[i]=='('||str[i]=='['||str[i]=='{'){
            stk.push(str[i]);
        }
        else{
            continue;
        }
    }

    return stk.empty();
}

int Priority(char op);

int Solve(int val1, int val2, char op);

int EvaulateInfix(string str){

    stack<char> op;
    stack<int> val;

    for(int i=0; i<str.length(); i++){

        char ch=str[i];

        if(ch==' '){
            continue;
        }
        else if(ch>='0'&&ch<='9'){
            val.push((int)(ch-'0'));
        }
        else if(ch=='('){
            op.push(ch);
        }
        else if(ch==')'){
            while(op.top()!='('){
                int val2=val.top(); val.pop();
                int val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                int res =  Solve(val1, val2, oprator);
                val.push(res);
            }
            op.pop();
        }
        else{
            while(!op.empty()&&op.top()!='('&&(Priority(op.top())>=ch)){
                int val2=val.top(); val.pop();
                int val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                int res =  Solve(val1, val2, oprator);
                val.push(res);
            }
            op.push(ch);
        }

    }

    while(!op.empty()){
                int val2=val.top(); val.pop();
                int val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                int res =  Solve(val1, val2, oprator);
                val.push(res);
    }

    return val.top();
}

void InfixToPrefix(string str){

}

void InfixToPostfix(string str){
    
}

int EvaulatePrefix(string str){
    
}

void PrefixToInfix(string str){
    
}

void PrefixToPostfix(string str){
    
}

int EvaulatePostfix(string str){
    
}

void PostfixToInfix(string str){
    
}

void PostfixToPrefix(string str){
    
}

//Helpers

int Priority(char op){
    if(op=='/'||op=='*') return 2;
    else if(op=='+'||op=='-') return 1;
    else return 0;
}

int Solve(int val1, int val2, char op){
    if(op=='/') return (val1/val2);
    else if(op=='*') return (val1*val2);
    else if(op=='+') return (val1+val2);
    else if(op=='-') return (val1-val2);
    else return 0;
}

void Evaluations(string str){

    //Infix

    cout<<EvaulateInfix(str)<<endl;

    //Prefix

    //cout<<EvaulatePrefix(str)<<endl;

    //Postfix

    //cout<<EvaulatePostfix(str)<<endl;
}

int main(){

    string str;
    //cin.ignore();
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,str); 

    //cout<<(DuplicateBrackets(str)?"true":"false")<<endl;
    //cout<<(BalancedBrackets(str)?"true":"false")<<endl;
    Evaluations(str);
}