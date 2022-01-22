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

int main(){

    string str;
    //cin.ignore();
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,str);
    

    //cout<<(DuplicateBrackets(str)?"true":"false")<<endl;
    cout<<(BalancedBrackets(str)?"true":"false")<<endl;
}