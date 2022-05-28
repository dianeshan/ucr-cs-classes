#include <vector>
#include <iostream>

using namespace std;


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
   for (int i = 0; i < 9; i += 3) {
      cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
         << gameBoard.at(i + 2) << "  " << endl;
      if (i < 6) {
         cout << "-----|-----|-----" << endl;
      }
   }
   cout << endl;
    
   return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 2 then it will have characters a to b.
///     If the vector is size 6 then it will have characters a to f.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
   unsigned int i;
   
   if (v.size() <= 26) {
      for (i = 0; i < v.size(); ++i) {
         v.at(i) = 'a' + i;
      }
   }
      
   return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
   unsigned int i;
   vector <char> re(9);
   
   initVector(re);
   
   for (i = 0; i < re.size(); ++i) {
      if (boardPosition == re.at(i)) {
         return i;
      }
   }
   
   return -1;
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, unsigned int positionIndex) {
   
   if (positionIndex < gameBoard.size()) {
      if (gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O') {
         return true;
      }
   }
      
   return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///     Continues asking for a position until a valid position has been entered.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) {
   
   char boardPosition = ' ';
   int indexPosition;
   
   cout << "Please choose a position: ";
   
   cin >> boardPosition;
   
   cout << endl;
   
   indexPosition = convertPosition(boardPosition);
   
   while (!validPlacement(gameBoard, indexPosition)) {
      
      cout << "Please choose a position: ";
   
      cin >> boardPosition;
   
      cout << endl;
      
      indexPosition = convertPosition(boardPosition);
   } 
   
   return indexPosition;
   
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) {
   unsigned int i;
   
   //for rows
   for (i = 0; i < gameBoard.size(); i +=3) {
      if (gameBoard.at(i) == gameBoard.at(i + 1) && gameBoard.at(i) == gameBoard.at(i + 2)) {
         return true;
      }
   }
   
   //for columns
   for (i = 0; i < 3; ++i) {
      if (gameBoard.at(i) == gameBoard.at(i + 3) && gameBoard.at(i) == gameBoard.at(i + 6)) {
         return true;
      }
   }
   
   //for diagonals
   if (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(0) == gameBoard.at(8)) {
      return true;
   }
   else if (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(2) == gameBoard.at(6)) {
      return true;
   }
   
   return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {
   unsigned int i;
   int count = 0;
   
   for (i = 0; i < gameBoard.size(); ++i) {
      if (gameBoard.at(i) == 'X' || gameBoard.at(i) == 'O') {
         count = count + 1;
      }
   }
   
   if (count == 9) {
      return true;
   }
   
   return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
   // Variables that you may find useful to utilize
   vector<char> gameBoard(9);
   int curPlay;
   int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

   /// TODO: Initialize board to empty state
   initVector (gameBoard);

   /// TODO: Display the empty board
   drawBoard (gameBoard);


   /// TODO: Play until game is over
   while (!gameWon(gameBoard) && !boardFull(gameBoard)) {
      /// TODO: Get a play
      curPlay = getPlay (gameBoard);
      
      if (whosTurn == PLAYER1) {
         gameBoard.at(curPlay) = 'X';
      }
      else if (whosTurn == PLAYER2) {
         gameBoard.at(curPlay) = 'O';
      }

      /// TODO: Set the play on the board

      /// TODO: Switch the turn to the other player
      if (!gameWon(gameBoard) && !boardFull(gameBoard)) {
         if (whosTurn == PLAYER1) {
            whosTurn = PLAYER2;
         }
         else if (whosTurn == PLAYER2) {
            whosTurn = PLAYER1;
         }
      }
      
      /// TODO: Output the updated board
      drawBoard(gameBoard);
   }

   /// TODO: Determine winner and output appropriate message
   if (whosTurn == PLAYER1 && gameWon(gameBoard)) {
      cout << "Player 1 Wins!!" << endl;
   }
   else if (whosTurn == PLAYER2 && gameWon(gameBoard)) {
      cout << "Player 2 Wins!!" << endl;
   }
   else {
      cout << "No one wins" << endl;
   }

   return 0;
}