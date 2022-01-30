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
            while(!op.empty()&&op.top()!='('&&(Priority(op.top())>=Priority(ch))){
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

string InfixToPrefix(string str){

    stack<char> op;
    stack<string> val;

    for(int i=0; i<str.length(); i++){

        char ch=str[i];

        if(ch==' '){
            continue;
        }
        else if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')){
            string s; s.push_back(ch);
            val.push(s);
        }
        else if(ch=='('){
            op.push(ch);
        }
        else if(ch==')'){
            while(op.top()!='('){
                string val2=val.top(); val.pop();
                string val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                string res =  oprator+val1+val2;
                val.push(res);
            }
            op.pop();
        }
        else{
            while(!op.empty()&&op.top()!='('&&(Priority(op.top())>=Priority(ch))){
                string val2=val.top(); val.pop();
                string val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                string res =  oprator+val1+val2;
                val.push(res);
            }
            op.push(ch);
        }


    }

    while(!op.empty()){
                string val2=val.top(); val.pop();
                string val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                string res =  oprator+val1+val2;
                val.push(res);
    }

    return val.top();

}

string InfixToPostfix(string str){
    
    stack<char> op;
    stack<string> val;

    for(int i=0; i<str.length(); i++){

        char ch=str[i];

        if(ch==' '){
            continue;
        }
        else if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')){
            string s; s.push_back(ch);
            val.push(s);
        }
        else if(ch=='('){
            op.push(ch);
        }
        else if(ch==')'){
            while(op.top()!='('){
                string val2=val.top(); val.pop();
                string val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                string res =  val1+val2+oprator;
                val.push(res);
            }
            op.pop();
        }
        else{
            while(!op.empty()&&op.top()!='('&&(Priority(op.top())>=Priority(ch))){
                string val2=val.top(); val.pop();
                string val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                string res =  val1+val2+oprator;
                val.push(res);
            }
            op.push(ch);
        }


    }

    while(!op.empty()){
                string val2=val.top(); val.pop();
                string val1=val.top(); val.pop();
                char oprator=op.top(); op.pop();
                string res =  val1+val2+oprator;
                val.push(res);
    }

    return val.top();

}

int EvaulatePrefix(string str){

    stack<int> stk;

    for(int i=str.length()-1; i>=0; i--){

        char ch=str[i];
        if(ch>='0'&&ch<='9'){
            stk.push(ch-'0');
        }
        else{
            char oprator = ch;
            int val1 = stk.top(); stk.pop();
            int val2 = stk.top(); stk.pop();
            int res = Solve(val1, val2, oprator);
            stk.push(res);
        }
    }

    return stk.top();
    
}

string PrefixToInfix(string str){

    stack<string> stk;

    for(int i=str.length()-1; i>=0; i--){

        char ch=str[i];
        if(ch>='0'&&ch<='9'){
            string s; s.push_back(ch);
            stk.push(s);
        }
        else{
            char oprator = ch;
            string val1 = stk.top(); stk.pop();
            string val2 = stk.top(); stk.pop();
            string res = "("+val1+oprator+val2+")";
            stk.push(res);
        }
    }

    string res=stk.top();
    return res;
    
}

string PrefixToPostfix(string str){

    
    stack<string> stk;

    for(int i=str.length()-1; i>=0; i--){

        char ch=str[i];
        if(ch>='0'&&ch<='9'){
            string s; s.push_back(ch);
            stk.push(s);
        }
        else{
            char oprator = ch;
            string val1 = stk.top(); stk.pop();
            string val2 = stk.top(); stk.pop();
            string res = val1+val2+oprator;
            stk.push(res);
        }
    }

    string res=stk.top();
    return res;
    
}

int EvaulatePostfix(string str){

    stack<int> stk;

    for(int i=0; i<str.length(); i++){

        char ch=str[i];
        if(ch>='0'&&ch<='9'){
            stk.push(ch-'0');
        }
        else{
            char oprator = ch;
            int val2 = stk.top(); stk.pop();
            int val1 = stk.top(); stk.pop();
            int res = Solve(val1, val2, oprator);
            stk.push(res);
        }
    }

    return stk.top();
    
}

string PostfixToInfix(string str){

    stack<string> stk;

    for(int i=0; i<str.length(); i++){

        char ch=str[i];
        if(ch>='0'&&ch<='9'){
            string s; s.push_back(ch);
            stk.push(s);
        }
        else{
            char oprator = ch;
            string val2 = stk.top(); stk.pop();
            string val1 = stk.top(); stk.pop();
            string res = "("+val1+oprator+val2+")";
            stk.push(res);
        }
    }

    return stk.top();
    
}

string PostfixToPrefix(string str){

    stack<string> stk;

    for(int i=0; i<str.length(); i++){

        char ch=str[i];
        if(ch>='0'&&ch<='9'){
            string s; s.push_back(ch);
            stk.push(s);
        }
        else{
            char oprator = ch;
            string val2 = stk.top(); stk.pop();
            string val1 = stk.top(); stk.pop();
            string res = oprator+val1+val2;
            stk.push(res);
        }
    }

    return stk.top();
    
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

    //cout<<EvaulateInfix(str)<<endl;
    //cout<<InfixToPrefix(str)<<endl;
    //cout<<InfixToPostfix(str)<<endl;

    //Prefix

    cout<<EvaulatePrefix(str)<<endl;
    cout<<PrefixToInfix(str)<<endl;
    cout<<PrefixToPostfix(str)<<endl;

    //Postfix

    //cout<<EvaulatePostfix(str)<<endl;
    //cout<<PostfixToInfix(str)<<endl;
    //cout<<PostfixToPrefix(str)<<endl;
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