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
void printLines(int columns);
void printNumbers(int columns);

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

    /* 
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
    */

}

void intializeGameBoard(string gameBoard[ROWS][COLS]){

    for(int i =0; i<ROWS;i++){
        for(int j = 0;j<ROWS;j++){
            gameBoard[i][j] = "."; // point instead of an space 
        }
    }
}

void printCurrentBoard(string gameBoard[ROWS][COLS]){

    // https://stackoverflow.com/questions/48737248/how-do-i-print-a-tic-tac-toe-board-after-the-user-enters-in-the-rows-and-columns

    printNumbers(COLS);
    printLines(COLS);
    for(int i = 0; i < ROWS; i++)
    {
        cout << " " << i;
        for(int j = 0; j < COLS; j++)
        {
            cout << " | "<<gameBoard[i][j];
        }
        cout << " | " << endl;
        printLines(COLS);
    }
    // printNumbers(COLS);
}

void printLines(int columns)
{
    cout << "   ";
    for(int i = 0; i < columns; i++)
    {
        cout << " ---";
    }
    cout << endl;
}

void printNumbers(int columns)
{
    cout << "   ";
    for(int i = 0; i < columns; i++)
    {
        cout << "  " << i << " ";
    }
    cout << endl;
}

