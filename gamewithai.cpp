#include <iostream>
#include<iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main ()
{
char board [3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',}; // This is going to create the 3X3 board for the X's and O's to be placed
bool playing = true;
int x,y; // the X and Y will correspond to the rows and columns
int randomX, randomY;

while (playing) {

   for (int i=0;i<3; i++){
    for (int j=0;j<3; j++){
        cout<<board[i][j];
        if (j<2){
            cout << "|";
        }
    }
    if (i<2){
    cout<<endl;
    cout << "-----";
    cout << endl;
    }
   }
   cout << endl << "Where would you like to move? ";
   cin >> x >> y;
   if (x < 1 || x > 3 || y < 1 || y > 3 || board[x-1][y-1] != ' ') {
       cout << "Invalid move. Try again." << endl;
       continue;
   }
   board [x-1][y-1] = 'x';

   // Check for player win (simple row/col/diag check)
   for (int i = 0; i < 3; ++i) {
       if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') playing = false;
       if (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x') playing = false;
   }
   if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') playing = false;
   if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x') playing = false;
   if (!playing) {
       cout << "You win!" << endl;
       break;
   }

   // AI move (random empty cell)
   srand(time(0));
   do {
       randomX = rand() % 3;
       randomY = rand() % 3;
   } while (board[randomX][randomY] != ' ');
   board[randomX][randomY] = 'o';

   // Check for AI win
   for (int i = 0; i < 3; ++i) {
       if (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o') playing = false;
       if (board[0][i] == 'o' && board[1][i] == 'o' && board[2][i] == 'o') playing = false;
   }
   if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') playing = false;
   if (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o') playing = false;
   if (!playing) {
       cout << "AI wins!" << endl;
       break;
   }
}

return 0;
}