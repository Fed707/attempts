
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
   double number1, number2;
   char operation;
   cout<<"Please enter your first number: ";
   cin>>number1;
   cout<<"please choose your operation: (+ - / *)";
   cin>>operation;
   cout<<"please enter your second number: ";
    cin>>number2;
   switch (operation)
   {
   case '+': cout<< "the result is: "<< number1+number2;
    break;
   case '/': cout<< "the result is: "<< number1/number2;
    break;
    case '-': cout<< "the result is: "<< number1-number2;
    break;
    case '*': cout<< "the result is: "<< number1*number2;
    break;
   default: cout<<"invalid";
    break;
   }
    return 0;
}