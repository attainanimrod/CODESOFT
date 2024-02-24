#include "GAMEWORLD.H"

void TTTGame::initialiseGame()
{
    //Assigning memory
    intPlayerNumber = 1;
    int intValues[9] = {7,8,9,4,5,6,1,2,3};
    int intIndex = 0;
    arrGameWorld = new int*[3];
    for(int r=0; r<3; r++)
    {
        arrGameWorld[r] = new int[3];
        for(int c=0; c<3; c++)
        {
            arrGameWorld[r][c] = intValues[intIndex];;
            intIndex++;
        }
    }


}


TTTGame::TTTGame()
{
    initialiseGame();
}

 int TTTGame::getPlayer()
 {
     return intPlayerNumber;
 }

void TTTGame::displayWorld()
{
    ///Game Menu
    cout<<"Tic Tac Toe Game"<<endl
        <<"Player 1: O"<<endl
        <<"Player 2: X"<<endl<<endl;
    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(c != 0)
            {
                 //cout<<" | "<<arrGameWorld[r][c];
                 if(arrGameWorld[r][c] == -1)
                {
                    cout<<" | "<<"O";   ///We display O for player 1

                }else if(arrGameWorld[r][c] == -2)
                {
                    cout<<" | "<<"X";  ///Display X for player 2
                }
                else if(arrGameWorld[r][c] != -1 && arrGameWorld[r][c] != -2)
                {
                    cout<<" | "<<arrGameWorld[r][c];
                }
            }
            else
            {

                if(arrGameWorld[r][c] == -1)
                {
                    cout<<"O";   ///We display O for player 1

                }else if(arrGameWorld[r][c] == -2)
                {
                    cout<<"X";  ///Display X for player 2
                }
                else if(arrGameWorld[r][c] != -1 && arrGameWorld[r][c] != -2)
                {
                    cout<<arrGameWorld[r][c];
                }
            }

        }
        cout<<endl;
        cout<<"-----------"<<endl;
    }
    cout<<endl;

}

void TTTGame::makeMove(int intPlayer, int intValue)
{
    ///We are going to store values -1 on the 2D array where player 1 choses to play to and -2 for player 2

    switch(intValue)
    {
    case 7:
        {
            if(canMakeMove(0, 0))
            {
                arrGameWorld[0][0] = intPlayer * (-1);

                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
            break;
        }
    case 8:
        {
            if(canMakeMove(0, 1))
            {
                arrGameWorld[0][1] = intPlayer * (-1);
                //switch to the other player
                if(intPlayer == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
            break;
        }
    case 9:
        if(canMakeMove(0, 2))
            {
                arrGameWorld[0][2] = intPlayer * (-1);
                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
        break;
    case 4:
        if(canMakeMove(1, 0))
            {
                arrGameWorld[1][0] = intPlayer * (-1);
                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
        break;
    case 5:
        if(canMakeMove(1, 1))
            {
                arrGameWorld[1][1] = intPlayer * (-1);

                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
        break;
    case 6:
        if(canMakeMove(1, 2))
            {
                arrGameWorld[1][2] = intPlayer * (-1);

                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
        break;
    case 1:
        if(canMakeMove(2, 0))
            {
                arrGameWorld[2][0] = intPlayer * (-1);

                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
        break;
    case 2:
        if(canMakeMove(2, 1))
            {
                arrGameWorld[2][1] = intPlayer * (-1);

                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
        break;
    case 3:
        if(canMakeMove(2, 2))
            {
                arrGameWorld[2][2] = intPlayer * (-1);

                //switch to the other player
                if(intPlayerNumber == 1)
                {
                    intPlayerNumber++;
                }
                else
                {
                    intPlayerNumber--;
                }
            }
        break;

    default:
        {
            break;
        }
    }
}

int TTTGame::gameState()
{
    ///Checking for win state
        //checking per row
    if(arrGameWorld[0][0] == arrGameWorld[0][1] && arrGameWorld[0][0] == arrGameWorld[0][2])
    {
        return arrGameWorld[0][0];
    }
    else if(arrGameWorld[1][0] == arrGameWorld[1][1] && arrGameWorld[1][0] == arrGameWorld[1][2])
    {
        return arrGameWorld[1][0];
    }
    else if(arrGameWorld[2][0] == arrGameWorld[2][1] && arrGameWorld[2][0] == arrGameWorld[2][2])
    {
        return arrGameWorld[2][0];
    }
        //checking per column
    else if(arrGameWorld[0][0] == arrGameWorld[1][0] && arrGameWorld[0][0] == arrGameWorld[2][0])
    {
        return arrGameWorld[0][0];
    }
    else if(arrGameWorld[0][1] == arrGameWorld[1][1] && arrGameWorld[0][1] == arrGameWorld[2][1])
    {
        return arrGameWorld[0][1];
    }
    else if(arrGameWorld[0][2] == arrGameWorld[1][2] && arrGameWorld[0][2] == arrGameWorld[2][2])
    {
        return arrGameWorld[0][2];
    }

        //checking diagonal
    else if(arrGameWorld[0][0] == arrGameWorld[0][1] && arrGameWorld[0][0] == arrGameWorld[2][2])
    {
        return arrGameWorld[0][0];
    }
    else if(arrGameWorld[0][2] == arrGameWorld[1][1] && arrGameWorld[0][2] == arrGameWorld[2][0])
    {
        return arrGameWorld[0][2];
    }

    bool blnFreeSpace = false;
    ///Checking for Draw
    for(int r=0; r<3; r++)
    {
        for(int c=0; c<3; c++)
        {
            if(arrGameWorld[r][c] != -1 && arrGameWorld[r][c] != -2)
            {
                return 0;
            }
        }
    }

    return -3;

}


void TTTGame::resertGame()
{
    initialiseGame();
}



TTTGame::~TTTGame()
{
    for(int r=0; r<3; r++)
    {
        delete[] arrGameWorld[r];
    }
    delete[] arrGameWorld;
}


///Helper functions
bool TTTGame::canMakeMove(int intRow, int intCol)
{
    //checking if its in bound
    if(intRow >= 0 && intRow < 3 && intCol >= 0 && intCol <3)
    {
        //checking if playe can make a move on the index
        if(arrGameWorld[intRow][intCol] != -1 && arrGameWorld[intRow][intCol] != -2)
        {
            return true;
        }
    }

    return false;
}

