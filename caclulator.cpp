#include<iostream>
using namespace std;

int main()
{
	//define variables
	
    double num1,num2;
    char op;
    
    //get user input 
    
    cout << "enter the operator ( + - * /) :";
    cin >> op;

    cout << "enter the two numbers one by one :";
    cin >> num1 >>num2;

    switch (op)
    {
        case '+':
        cout << num1 << op << num2 << "="<< num1 + num2 << endl;
        break;

        case '-':
        cout << num1 << op << num2 <<"="<< num1 - num2 << endl;
        break;

        case '*':
        cout << num1 << op << num2<<"=" << num1 * num2 << endl;
        break;

        case '/':
        if(num2 ==0.0)
		{	
           	cout << "divide by zero situation"<<endl;
        }
        else
        {
        	cout << num1 << op << num2<<"=" << num1 / num2 << endl;	
		}
        break;
        
   	 default:;  
    }
}
