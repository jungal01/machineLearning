#include <cmath>
#include <unordered_set>
#include <cassert>
#include <iostream>
#include <string>

// global variables
// unordered_set memo;
int Computer = 1;
int Human = -1;

class Board{
  int board[3][3];
  public:
    // these are the prereqs for the board to function
    bool operator == (const Board &other) const{
      return (Member == other.Member());
    } // checking equality
    Board(const int &Board) : Member(Board){}
    // the constructor is overloaded in the event the 
    // board is being called with no parameters
    Board();
    Board(int[3][3]);
    ~Board();
    // these are the board's functions
    int getrow(int); // replaces the python magic method
    void reset();
    int eval();
    bool full();
    bool empty();
    
  private:
    int Member;
  
  // this makes board friends with hash so it can be hashed into memo
  friend std::hash<Board>::operator() (const Board&) const;
}; // end of board


namespace std{
  template<>
  size_t hash<Board>::operator()(const Board &board) const {
    return std::hash<std::string>()(*board.ps);
  } // end of hash
} // end of namespace


Board::Board(){
  for ( int i = 0; i < 3; i++ ){
    for ( int j = 0; j < 3; j++ ){
      board[i][j] = 0;
    }
  }
} // end of constructor

Board::Board(int items[3][3]){
  board = *items;
} // end of overloaded constructor

Board::~Board(){
  delete board;
}

int Board::getrow (int index){
  return board[index*];
} // end of getrow

void Board::reset() {
  for ( int i = 0; i < 3; i++ ){
    for ( int j = 0; j < 3; j++ ){
      board[i][j] = 0;
    }
  }
} // end of reset

int Board::eval() {
  for ( int row = 0; row < 3; row++ ) {
    int rowsum = 0;
    for ( int col = 0; col < 3; col++ ) {
      int x = board[row][col];

      if ( x.GetType() != int ) { std::cout << "not an integer"; }

      rowsum = rowsum + x.eval();
    } // end of col loop
    if ( std::abs(rowsum) == 3){ return rowsum / 3; }
  } // end of row loop

  for ( int col = 0; col < 3; col++ ) {
    int colsum = 0;
    for ( int row = 0; row < 3; row++ ) {
      colsum = colsum + board[row][col].eval();
    } // end of row loop
    if ( std::abs(colsum) == 3){ return colsum / 3; }
  } // end of col loop

  int diagsum = 0;
  for (int i = 0; i < 3; i++){
    int j = 2 - i;
    diagsum = diagsum + board[i][j].eval();
  }

  if ( std::abs(diagsum) == 3 ){ return diagsum // 3;}
  
  int zero = 0;
  return zero;
} // end of eval

bool Board::full(void){
  for ( int row = 0; row < 3; row++ ){
    for ( int col = 0; col < 3; col++ ){
      if ( board[row][col].eval() == 0 ){ return false; }
    } // end of col loop
  } // end of row loop
  return true;
} // end of full

bool Board::empty(void){ return !full(); }


int minimax(string player, Board board){
  if ( memo.count(board) ){ return memo; }

  int gameval = board.eval();

  if ( std::abs(gameval) == 1 ){ return gameval; }

  if ( memo.full() ){ return 0; }

  if ( player == Computer ){
    int maxval = -1;

    for (int row = 0; row < 3; row++){
      for(int col = 0; col < 3; col++){
        if ( board[row][col].eval() == 0 ){
          T newboard = Board Board(board);
	  newboard[row][col] = X X();
          int val = minimax(Human, newboard);
	  memo[newboard] = val;
	  if ( val == 1 ){ return 1; }

	  if ( val > maxval ){ maxval = val; }  
        } // if eval is 0
      } // inner col loop 
    } // row loop
    return maxval;
  } else{
    int minval = 1;
    for (int row = 0; row < 3; row++){
      for(int col = 0; col < 3; col++){
        if ( board[row][col].eval() == 0 ){
          T newboard = Board Board(board);
	  newboard[row][col] = O O();
          int val = minimax(Computer, newboard);
	  memo[newboard] = val;
	  if ( val == -1 ){ return -1; }

	  if ( val < minval ){ minval = val; }  
        } // if eval is 0
      } // inner col loop 
    } // row loop
    return minval;
  } // else statement for human move
}
