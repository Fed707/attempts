#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<double> numbers;
    vector<char> operations;
    double num;
    char op;
    

    cout<< "Enter the first number: ";
    cin>>num;
    numbers.push_back(num); 
    operations.push_back(op);

    while(true){
        cout<< "enter your operation(+ - / *)"<<endl;
        cin>> op;
        if (op == '=') break;
        if (op == '+' || op == '-' || op == '*' || op == '/')
        {
            cout<<"enter the next number:";
            cin>> num;
            numbers.push_back(num);
            operations.push_back(op);
        }
        
        double results = numbers[0];
        for (int i = 0; i<operations.size(); i++){
            switch (operations[i]){
                case '+':
                results += numbers[i+1];
                break;
                case '-':
                results = numbers[i+1]-numbers[i];
                break;
                case '*':
                results *= numbers[i+1];
                break;
                case '/':
                if (numbers[i+1] !=0){
                    results /= numbers[i+1];
                }else{
                    cout<< "zero! operation denied!";
                }
                break;
                
            }
        }
        cout<< "the result: " <<results<< endl;
        return 0;
        
    }
}