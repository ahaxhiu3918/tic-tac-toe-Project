#include <iostream>
#include <string>
#include <stdlib.h>

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
string firstTurnIsIt(string player);
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

     
    do{// game loop, runs at least one with do-while loop 

        if(player == ""){
            player = firstTurnIsIt(player);}
        else{
            player = whoseTurnIsIt(player);
        }
        getUserInput(player,gameBoard);
        printCurrentBoard(gameBoard);
        winner = getWinner(gameBoard);

        if(isBoardFull(gameBoard) && winner.empty()){
            winner = 'C';
        }

        
    }while(winner.empty());

    cout<<"the winner is "<<winner<<endl;
    

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


void getUserInput(string player, string gameBoard[ROWS][COLS]){

    // https://www.geeksforgeeks.org/cpp/convert-string-to-int-in-cpp/ 
    // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    // https://www.daniweb.com/programming/software-development/threads/432818/user-input-char-array


    char playerMove[3];

    cout<<"This is "<<player<<"'s turn"<<endl;
    cout<<"Please make your move , enter the row THEN the column, separated by a space "<<endl;
    cin>> playerMove;
    //cin.get();
    //getline(cin,playerMove);

    int playerRow = playerMove[0] - '0'; // coverts char('') to int in C++
    int playerCol = playerMove[-1] - '0';

    if(!(playerRow>=0 && playerRow<= ROWS-1) || !(playerCol>=0 && playerCol<= COLS-1)){
        cout<<"There is a mistake, please re-enter your move"<<endl;
        getUserInput(player,gameBoard);
    }

    else if(cellAlreadyOccupied(playerRow, playerCol, gameBoard)){
        cout<<"This cell is already occupied, please enter another move"<<endl;
        getUserInput(player,gameBoard);

    }
    else{gameBoard[playerRow][playerCol] = player;}

}


bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]){

    if(gameBoard[row][col] == "."){

        return true;
    }
    else {
        return false;
    }
}

string getWinner(string gameBoard[ROWS][COLS]){

    string winner;





    return winner;

}


bool isBoardFull(string gameBoard[ROWS][COLS]){

    int count = 0;

    for(int i = 0;i<ROWS;i++){
        for(int j = 0;j<COLS;j++){
            if(gameBoard[i][j] != "."){count++;}
        }
    }

    if(count < COLS*ROWS){return false;}
    else {return true;}
}


string whoseTurnIsIt(string player){
    string player;
    cout<<"Please enter the first player(either O or X) :";
    cin>>player;


}

