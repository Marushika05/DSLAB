//Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

#include <iostream>
#include<string>
using namespace std;

class Stack{

//private
 int top;
 char arr[50];

//constructor
 public:
 Stack(){
    top=-1;

 }

bool isEmpty(){
    if(top==-1){
        cout<<"The stack is empty"<<endl;
        return true;
    }
    else{
        return false;
    }
    
 }

  bool isFull(){
    if(top==49){
        cout<<"The stack is full"<<endl;
        return true;
 }
 else{
    return false;
 }
      
 }
void push(char x){
    if(isFull()){
 cout<<" stack overflow"<<endl;
    }
    else{
        arr[++top]=x;
        
    }
   
}
 char pop(){
    if(isEmpty()){
        cout<<" the stack is empty"<<endl;
        return '\0';
    }
    else{
        char popchar;
        popchar=arr[top];
        top--;
        return popchar;


    }
 }
};

 // str is not a copy of the original string; it's a reference to the original string
 //& is important for the code is imp foro correcct working
 void reverseString(string& str){
   Stack s1;
   
        // pushing the characters in the stack;
        for(int i=0; i<str.length(); i++){
            s1.push(str[i]);
        }

        // poping the char
        for(int i=0; i<str.length(); ++i){
            str[i]=s1.pop();
        }
    }


 
int main(){
    string myval="DataStructure";
    reverseString(myval);
    cout<<myval;
    return 0;


}
