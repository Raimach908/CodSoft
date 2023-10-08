/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<ctime>
#include<conio.h>
using namespace std;

int main()
{
    system("cls");
    system("Color F4");
    cout <<"\n\t\t\t\t\t\t         **********************************     \n";
    cout <<"\n\t\t\t\t\t\t          Welcome to Guess the Number game      \n";
    cout <<"\n\t\t\t\t\t\t         **********************************    \n\n";   
    cout <<"\n\t Instructions:- ";
    cout <<"\n\t In this game, the computer generates a secret number in the range of 1 to 100, and you have to guess it. The game runs till you guess ";
    cout <<"\n\t the correct number.";
    cout <<"\n\n\t Press any key to continue...";
    _getch();
    system("cls");
    cout <<"\n\n\n\n\n\n\n\t\t\t\t\t\t          OKAY, Let's get started!      \n";
    cout <<"\n\n\t Press any key to continue...";
    _getch();
    system("cls"); 
    // Generate random number    
    srand(time(0));
    int secretNumber = 1 + rand() % 100;
    // Ask guessed number
    int guessedNumber = 0;
    cout <<"\n\t Enter guessed number: ";
    cin >> guessedNumber;
    while (guessedNumber < 1 || guessedNumber > 100)
    {
        cout <<"\n\t You crossed the limit. Try again!";
        cout <<"\n\t Enter valid guessed number: ";
        cin >> guessedNumber;
    }
    // Check status
    int attempts = 0;
    while (guessedNumber != secretNumber)
    {
        ++attempts;
        if (guessedNumber > secretNumber)
        {
            cout <<"\n\t Guessed Number is too high. Try again!";
            cout <<"\n\t Enter guessed number: ";
            cin >> guessedNumber;
        }
        else if (guessedNumber < secretNumber)
        {
            cout <<"\n\t Guessed Number is too low. Try again!";
            cout <<"\n\t Enter guessed number: ";
            cin >> guessedNumber;
        }
    }
    cout <<"\n\n\t Press any key to continue...";
    _getch();
    system("cls"); 
    // game win 
    if (guessedNumber == secretNumber)
    {
        cout <<"\n\n\t  Hurrahhh! You have guessed the correct number. It took you " << attempts << " attempts.\n";

    }
    cout <<"\n\n\t Press any key to exit...";
    _getch();
    return 0;
}