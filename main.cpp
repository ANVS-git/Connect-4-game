/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std; 

const int rows=6; 
const int cols=7; 

char board[rows][cols]; 

void InitialiseBoard (){
   for(int i=0;i<rows;i++){
       for(int j=0;j<cols;j++){
           board[i][j]=' '; 
       }
   }
}

void Printboard(){
    cout<<"1234567"<<endl; 
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isFull(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(board[i][j]==' '){
                return false;
            }
        }
    }
    cout<<"Game Tie!"<<endl;
    return true;
}

bool Insert(int col,char token){
    for(int i=rows-1;i>=0;i--){
        if(board[i][col]==' '){
            board[i][col]=token;
            return true;
        }
    }
    return false;
}

bool checkWin(char token) {
    // Check horizontal
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= cols - 4; ++j) {
            if (board[i][j] == token &&
                board[i][j+1] == token &&
                board[i][j+2] == token &&
                board[i][j+3] == token) {
                return true;
            }
        }
    }
    
    // Check vertical
    for (int i = 0; i <= rows - 4; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == token &&
                board[i+1][j] == token &&
                board[i+2][j] == token &&
                board[i+3][j] == token) {
                return true;
            }
        }
    }
    
    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i <= rows - 4; ++i) {
        for (int j = 0; j <= cols - 4; ++j) {
            if (board[i][j] == token &&
                board[i+1][j+1] == token &&
                board[i+2][j+2] == token &&
                board[i+3][j+3] == token) {
                return true;
            }
        }
    }
    
    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < rows; ++i) {
        for (int j = 0; j <= cols - 4; ++j) {
            if (board[i][j] == token &&
                board[i-1][j+1] == token &&
                board[i-2][j+2] == token &&
                board[i-3][j+3] == token) {
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
  
   InitialiseBoard(); 
   Printboard();
   
   char token='X'; 
   int a=0,z=0,col; 
   
   while(!isFull()){
       if(a%2==0){
           cout<<"Player 1's turn (Enter column number to insert): "; 
           cin>> col;
           token='X';
           z=Insert(col,token);
           if(z!=1){
               continue; 
           }
           Printboard();
       }
       else{
           cout<<"Player 2's turn (Enter column number to insert): "; 
           cin>>col;
           token='0';
           z=Insert(col,token);
           if(z!=1){
               continue; 
           }
           Printboard(); 
       }
       if(checkWin(token)==1){
           if(token=='X'){
              cout<<"Player 1 wins"<<endl;
              break;
           }
            else {
               cout<<"Player 2 wins"<<endl;
               break;
            }
       }
       a++;
   }

    return 0;
}