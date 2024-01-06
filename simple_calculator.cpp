#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    char op;
    cout<<"Enter the first value:\n";
    cin>>a;
    cout<<"Enter the second value:\n";
    cin>>b;
    cout<<"Enter operation(+ - * / %)";
    cin>>op;
    if(op=='+')
    {
        c=a+b;
        cout<<"The Addition of two numbers is: "<<c<<endl;
    }
    else if(op=='-')
    {
        c=a-b;
        cout<<"The Subtraction of two numbers is: "<<c<<endl;
    }
    else if(op=='*')
    {
        c=a*b;
        cout<<"The Multiplication of two numbers is: "<<c<<endl;
    }
    else if(op=='/')
    {
        c=a%b;
        cout<<"The Division of two numbers is: "<<c<<endl;
    }
    else
    {
        cout<<"Entered wrong input";
    }
    return 0;
}