/*Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform.
*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;

double additionFunc(double firstNum, double secondNum)
{
    return firstNum + secondNum;
}
double subtructionFunc(double firstNum, double secondNum)
{
    return firstNum - secondNum;
}
double multiplicationFunc(double firstNum, double secondNum)
{
    return firstNum * secondNum;
}
double divisionFunc(double firstNum, double secondNum)
{
    return firstNum / secondNum;
}
int main()
{
    system("cls");
    system("Color F4");
    cout <<"\n\t\t <<----Welcome to Simple Arithmatic Calculator--->>\n";
    int choice = 0;
    while (choice <= 0)
    {
        double first = 0.0, second = 0.0;
        cout <<"\n  Enter first number: ";
        cin >> first;
        cout <<"  Enter second number: ";
        cin >> second;
        cout <<"\n\n  1. Addition";
        cout <<"\n  2. Subtraction";
        cout <<"\n  3. Multiplication";
        cout <<"\n  4. Division";
        cout <<"\n\n  Select operation: ";
        cin >> choice;
        while (choice > 4 || choice <= 0)
        {
            cout <<"\n  You entered wrong! Please select valid opeartion."; 
            cout <<"\n  Select operation: ";
            cin >> choice;
        }
        
        switch (choice)
        {
            case 1:
            {
                cout << endl << "\t" << first <<" + " << second << " = " << additionFunc(first,second);
                break;
            }
            case 2:
            {
                cout << endl << "\t" << first <<" - " << second << " = " << subtructionFunc(first,second);
                break;
            }
            case 3:
            {
                cout << endl << "\t" << first <<" * " << second << " = " << multiplicationFunc(first,second);
                break;
            }
            case 4:
            {
                if (second == 0)
                {
                    cout << endl << "\t" << first <<" / " << second << "  is undefind.";
                }
                else
                {
                    cout << endl << "\t" << first <<" / " << second << " = " << divisionFunc(first,second);
                }
                break;
            }
            default:
                break;
        }
    }
    return 0;
}