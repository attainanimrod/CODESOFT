#include<iostream>
#include<ctime>

using namespace std;
//random number geneator function
int randomNumber(int intLow, int intHigh)
{
    int intRange = intHigh - intLow;

    return rand() % intRange + intLow;
}
int main()
{
    bool blnReplay = true;
    do
    {
        //User Menu
        cout<<"Welcome to The Number Guessing game!! "<<endl
            <<"please enter the lowest number you want to guess from: "<<endl;
        int intLowest = 0;
        cin>>intLowest;
        cout<<"please enter the highest number you want to guess to: "<<endl;
        int intHighest = 0;
        cin>>intHighest;

        //Validating user input
        while(intHighest <= intLowest)
        {
            cerr<<"Make sure the values are inserted correctly and are not the same (:"<<endl;

            cout<<"please enter the lowest number you want to guess from: "<<endl;
            cin>>intLowest;
            cout<<"please enter the highest number you want to guess to: "<<endl;
            cin>>intHighest;
        }
        //seeding the random number generator
        srand(static_cast<unsigned int>(time(0)));
        int intRandom = randomNumber(intLowest,intHighest);

        cout<<"Enter a random number between "<<" and "<<intHighest<<endl;

        //getting the user's gueesed number
        int intValue=0;
        cin>>intValue;

        while(intRandom != intValue)
        {
            if(intValue < intRandom)
            {
                cout<<"Your guess is too low (:"<<endl
                    <<"Enter new value: "<<endl;
                //getting the user's gueesed number
                cin>>intValue;
            }
            else if(intValue > intRandom)
            {
                cout<<"Your guess is too high (:"<<endl
                    <<"Enter new value: "<<endl;
                //getting the user's gueesed number
                cin>>intValue;
            }
        }


        cout<<"Congratulations!!, you have guessed the number currectly. "<<intValue<<" is the correct guess."<<endl
            <<"You want to replay again? Y->Yes or N->No"<<endl;
        char option = '/0';
        cin>>option;
        if(option == 'N' || option == 'n')
        {
            blnReplay = false;
        }
    }
    while(blnReplay);

	return 0;

}
