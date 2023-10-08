#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<conio.h>
#include<stdio.h>
#define rows 3
#define columns 3
using namespace std;

void GameImplimentationFunction()
{
    cout <<"\n\n\t Press any key to continue...";
    cin.get();
    system("cls");    
    string player1,player2;
    cout <<"\n\n\n\t Enter player 1 name: ";
    getline(cin,player1);
    cout <<"\t Enter player 2 name: ";
    getline(cin,player2);
    cout <<"\n\n\t Press any key to continue...";
    cin.get();
    system("cls");
    // Game board implimentation
    char ** space = new char*[rows];  
    for (int i = 0; i < rows; i++)
    {
        space[i] = new char[columns];
    }
    char value = '0';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            space[i][j] = ++value;
        }
    }
    cout <<"\n\n\n\t\t             |         |    \n";
    cout <<"\t\t          " << space[0][0] << "  |   " << space[0][1]       << "     |   " << space[0][2] <<  "\n";
    cout <<"\t\t      _______|_________|________   \n";
    cout <<"\t\t             |         |    \n";
    cout <<"\t\t          " << space[1][0] << "  |   " << space[1][1]       << "     |   " << space[1][2] <<  "\n";
    cout <<"\t\t      _______|_________|________   \n";
    cout <<"\t\t             |         |    \n";    
    cout <<"\t\t          " << space[2][0] << "  |   " << space[2][1]       << "     |   " << space[2][2] <<  "\n";
    cout <<"\t\t             |         |    \n";     

    bool foundPlayer1 = false; bool foundPlayer2 = false;
    int cellsPlayer = 9;
    int p1 = 0, p2 = 0;
    int currentPlayer = 1; 
    int move = 0;
    while(cellsPlayer > 0 )
    { 
        // Player input
        cout <<"\n\t " << ((currentPlayer == 1)? player1:player2) <<"'s turn: ";
        cin >> move;
        while (move < 1 || move > 9)
        {
            cout <<"\n\t Invalid entered. Try again!";
            cin >> move;
        }
        
        // Update board
        int rowCell = (move - 1) / 3;
        int columnCell = (move - 1) % 3;
        if (space[rowCell][columnCell] == 'X' || space[rowCell][columnCell] == 'O')
        {
            cout <<"\n\t cell has already occupied. try again!";
            continue;
        }
        // Assign 'X' & 'O'
        space[rowCell][columnCell] = (currentPlayer == 1)? 'X':'O';
        
        // Display grid
        cout <<"\n\n\n\t\t             |         |    \n";
        cout <<"\t\t          " << space[0][0] << "  |   " << space[0][1]       << "     |   " << space[0][2] <<  "\n";
        cout <<"\t\t      _______|_________|________   \n";
        cout <<"\t\t             |         |    \n";
        cout <<"\t\t          " << space[1][0] << "  |   " << space[1][1]       << "     |   " << space[1][2] <<  "\n";
        cout <<"\t\t      _______|_________|________   \n";
        cout <<"\t\t             |         |    \n";    
        cout <<"\t\t          " << space[2][0] << "  |   " << space[2][1]       << "     |   " << space[2][2] <<  "\n";
        cout <<"\t\t             |         |    \n";         

        // Check winner 
        if ((space[0][0] == space[0][1] && space[0][0] == space[0][2]) || ( space[1][0] == space[1][1] && space[1][0] == space[1][2]) || (space[2][0] == space[2][1] && space[2][0] == space[2][2]) 
        || (space[0][0] == space[1][0] && space[0][0] == space[2][0]) || (space[0][1] == space[1][1] && space[0][1] == space[2][1]) || (space[0][2] == space[1][2] && space[0][2] == space[2][2]) 
        || (space[0][0] == space[1][1] && space[0][0] == space[2][2]) || (space[0][2] == space[1][1] && space[0][2] == space[2][0]))         
        {
            foundPlayer1 = (currentPlayer == 1)? true:false;
            foundPlayer2 = (currentPlayer == 2)? true:false;
            break;
        }              
        // switch player
        currentPlayer = (currentPlayer == 1)? 2:1;
        --cellsPlayer;        
    }
    // Display Result
    cout <<"\n\n\n\t\t             |         |    \n";
    cout <<"\t\t          " << space[0][0] << "  |   " << space[0][1]       << "     |   " << space[0][2] <<  "\n";
    cout <<"\t\t      _______|_________|________   \n";
    cout <<"\t\t             |         |    \n";
    cout <<"\t\t          " << space[1][0] << "  |   " << space[1][1]       << "     |   " << space[1][2] <<  "\n";
    cout <<"\t\t      _______|_________|________   \n";
    cout <<"\t\t             |         |    \n";    
    cout <<"\t\t          " << space[2][0] << "  |   " << space[2][1]       << "     |   " << space[2][2] <<  "\n";
    cout <<"\t\t             |         |    \n";  

    if (foundPlayer1 && !foundPlayer2)
    {
        cout <<"\n\t Congratulations! " << player1 <<" wins the game.";
    }
    else if (foundPlayer2 && !foundPlayer1)
    {
        cout <<"\n\t Congratulations! " << player2 <<" wins the game.";
    }  
    // If game is draw     
    else if (!foundPlayer1 && !foundPlayer2 && cellsPlayer == 0)
    {
        cout <<"\n\t It's a draw!";
    }     

    // deallocate memory
    for (int i = 0; i < rows; i++)
    {
        delete[] space[i];
    }
    delete[] space;
}
int main()
{
    system("cls");
    system("Color F4");
    cout <<"\n\t\t\t\t\t\t         **********************************     \n";
    cout <<"\n\t\t\t\t\t\t          Welcome to Tic Tac Toe game      \n";
    cout <<"\n\t\t\t\t\t\t         **********************************    \n\n";   
    cout << "\n\t Rules of the Game:-" << endl;
    cout << "\t 1. The game must be played by two players (in this program between HUMAN and COMPUTER)." << endl;
    cout << "\t 2. Both players mark their cells with the letters 'O' and 'X'." << endl;
    cout << "\t 3. The game ends when one of the players fills an entire row, column, or diagonal with either the character ('O' or 'X') of that player." << endl;
    cout << "\t 4. If no one wins, the match is considered a draw." << endl;
    cout <<"\n\n\t Press any key to continue...";
    cin.get();
    system("cls");    
    cout <<"\n\n\n\n\n\n\n\t\t\t\t\t\t          OKAY, Let's get started!      \n";    

    GameImplimentationFunction();

    // Play again
    char anotherGame;
    cout <<"\n\t Do you want to play another game (Y/N)? ";
    cin >> anotherGame;
    cin.ignore();
    if (anotherGame == 'Y' || anotherGame == 'y')
    {
        GameImplimentationFunction();
    }
    else if (anotherGame == 'N' || anotherGame == 'n')
    {
        cout <<"\t Okay!";
    }
    else
    {
        cout <<"\n\t Valid entered! Try again after running the code.";
    }

    cout <<"\n\n\t Press any key to exit...";
    cin.get();

    return 0;
}

