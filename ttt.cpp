/*This is a standard game of Tic tactoe
 *Trevor Horine
 *10/5/17*/
#include<iostream>
#include<cstring>
using namespace std;
//methods
void clearboard();
void printboard();
void move();
bool checkwin(char player);
bool checktie();

char board[4][4];
int turn = 1;//1 = x 2=o
//min method
int main(){
  int owins = 0;
  int xwins = 0;
  char play;
  bool stillplaying = true;
  //still playing allows multiple games
  while (stillplaying == true){
    clearboard();
    while (checkwin('X') == false && checkwin('O') == false && checktie() == false){
      printboard();
      move();
    } 
    printboard();
    if (checktie() == true){
      cout << "X wins: " << xwins << endl << "O wins: " << owins << endl;
    }
    else if (turn == 1){
      owins++;
      cout << "O Won! That is a total of " << owins << " winns for O and " << xwins << " for x!" << endl;
    }
    else if (turn == 2){
      xwins++;
      cout << "X won! That is a total of " << xwins << " wins for X and " << owins << " for O!" << endl;
    }
    cout << "Do you want to play again?(y for yes, n for no)" << endl;
    cin >> play;
    if (play == 'n' || play == 'N'){
      stillplaying = false;
    }
    else if (play == 'y' || play == 'Y'){
      stillplaying = true;
      clearboard();
      turn = 1;
    }
  }
}
//method to print the board out
void printboard(){
  cout << "\t1\t2\t3" << endl;
  for (int row = 0; row < 4; row++) {
    for (int column = 0; column < 4; column++) {
      cout << board[row][column] << '\t';
    }
    cout << endl;
  }
}
//method to clear the board
void clearboard(){
  for (int i = 0; i < 4; i++){
    for(int j = 1; j < 4; j++){
      board[i][j] = ' ';
    }
  }
  board[0][0] = 'a';
  board[1][0] = 'b';
  board[2][0] = 'c';
}
//method that actualy makes the move
void move(){
  cout << "Please select a place to go. Rows are a, b, or c. Columns are 1, 2, or 3." << endl;
  char in[2];
  int r;
  int c;
  int num;
  cin >> in;
  if(strlen(in) == 2){
    if(in[0] == 'a' || in[0] == 'b'||in[0] == 'c'){
      if(in[1] == '1' || in[1] == '2' || in[1] == '3'){
	if(in[0] == 'a'){
	  r = 0;
	}
	else if (in[0] =='b'){
	  r = 1;
	}
	else if (in[0] == 'c'){
	  r = 2;
	}
	if (in[1] == '1'){
	  c = 1;
	}
	if (in[1] == '2'){
	  c = 2;
	}
	if (in[1] == '3'){
	  c = 3;
	}
	if(board[r][c] == ' '){
	  if (turn == 1){
	    board [r][c] = 'X';
	    turn = 2;
	  }
	  else if(turn == 2){
	    board[r][c] = 'O';
	    turn = 1;
	  }
	}
	else{
	  cout << "Pick a place to go that does not alredy have a pice on it!" << endl;
	}
      }
    }
  }
}
//method to check wins (player may be pased in to check for x wins and o wins with same method)
bool checkwin(char player){
  if (board[0][1] == player && board[0][2] == player && board[0][3] == player){
    return true;
  }
  else if (board[1][1] == player && board[1][2] == player && board[1][3] == player){
    return true;
  }
  else if (board[2][1] == player && board[2][2] == player && board[2][3] == player) {
    return true;
  }
  else if (board[0][1] == player && board[1][1] == player && board[2][1] == player){
    return true;
  }
  else if (board[0][2] == player && board[1][2] == player && board[2][2] == player){
    return true;
  }
  else if (board[0][3] == player && board[1][3] == player && board[2][3] == player){
    return true;
  }
  else if (board[0][1] == player && board[1][2] == player && board[2][3] == player){
    return true;
  }
  else if (board[2][1] == player && board[1][2] == player && board[0][3] == player){
    return true;
  }
  return false;
}
//method to check ties
bool checktie(){
  for(int i = 0; i < 3; i++){
    for (int j = 1; j < 4; j++){
      if (board[i][j] == ' '){
	return false;
      }
    }
  }
  return true;
}
# TicTacToe
