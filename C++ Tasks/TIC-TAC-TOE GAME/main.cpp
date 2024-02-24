#include "GAMEWORLD.H"

using namespace std;

int main()
{
    TTTGame objGameWorld;

    bool blnContinue = true;
    int intGameState = 0;

    do
    {
        system("cls");
        objGameWorld.displayWorld();
        ///Checking for game state
        intGameState = objGameWorld.gameState();

        switch(intGameState)
        {
        case -1:
        {
            cout<<"Player: 1 Won!!"<<endl;
            blnContinue = false;
            break;
        }
        case -2:
        {
            cout<<"Player: 2 Won!!"<<endl;
            blnContinue = false;
            break;
        }
        case -3:
        {
            cout<<"Draw!!"<<endl;
            blnContinue = false;
            break;
        }
        default:
        {
            break;
        }
        }

        if(blnContinue)
        {
            ///taking the user's move
        int intValue = 0;
        cout<<"Player "<<objGameWorld.getPlayer()<<": ";
        cin>>intValue;
        //validating user input
        while(cin.fail())
        {
            // Clear the error state from cin
            std::cin.clear();
            // Ignore the invalid input in cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cin>>intValue;
        }

        objGameWorld.makeMove(objGameWorld.getPlayer(), intValue);
        }
        else
        {
            cout<<" You want to play again? Y/N"<<endl;
            char chrPlay ='/0';
            cin>>chrPlay;

            if(chrPlay=='y' || chrPlay == 'Y')
            {
                objGameWorld.resertGame();
                blnContinue = true;
            }
        }


    }
while(blnContinue);


    return 0;
}
