#include <iostream>
#include <string>

using namespace std;

const int ROWS =3;
const int COLS = 3;

void runGame();
void intializeGameBoard(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(string player, string gameBoard[ROWS][COLS]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);
string whoseTurnIsIt(string player);


int main()
{

    runGame();

    return 0;

}//end main

void runGame(){
    
    string winner;// can be X,O or C
    string gameBoard[ROWS][COLS];
    string player; // X or O
    
    intializeGameBoard(gameBoard);
    printCurrentBoard(gameBoard);

    do{// game loop, runs at least one with do-while loop 

        player = whoseTurnIsIt(player);
        getUserInput(player,gameBoard);
        printCurrentBoard(gameBoard);
        winner = getWinner(gameBoard);

        if(isBoardFull && winner.empty()){
            winner = 'C';
        }

        
    }while(winner.empty());

    cout<<"the winner is "<<winner<<endl;

}


