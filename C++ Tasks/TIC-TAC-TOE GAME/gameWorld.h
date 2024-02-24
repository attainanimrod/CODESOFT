#include<iostream>
#include <limits>

using namespace std;

class TTTGame
{
    public:
        //Constructor
        TTTGame();
        //Destructor
        ~TTTGame();
        int getPlayer();
        //Display the game
        void displayWorld();
        //checking for game state(win/draw)
        int gameState();
        //take the user's move
        void makeMove(int intPlayer, int intValue);
        //resert function
        void resertGame();


    private:
        int intPlayerNumber;
        int** arrGameWorld;

        void initialiseGame();
        //Check if player can make a move on the index
        bool canMakeMove(int intRow, int intCol);


};
