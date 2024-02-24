#include<iostream>
#include<ctime>
#include<limits>

using namespace std;
//random number geneator function
int randomNumber(int intLow, int intHigh)
{
    int intRange = intHigh - intLow;

    return rand() % intRange + intLow;
}

//function for validating integer input from user
double validateNumber(istream& LHS )
{
    int dblValue = 0;
    ///validating user data
    while(LHS.fail())
    {
        // Clear the error state from cin
        LHS.clear();
        // Ignore the invalid input in cin
        LHS.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        LHS>>dblValue;
    }
    return dblValue;
}
int main()
{
    bool blnReplay = true;
    do
    {
        //User Menu
        cout<<"Welcome to The Number Guessing game!! "<<endl
            <<"please enter the lowest number you want to guess from: "<<endl;
        double intLowest = 0;
        cin>>intLowest;
        //calling validate function
        if(cin.fail())
        {
            intLowest = validateNumber(cin);
        }

        cout<<"please enter the highest number you want to guess to: "<<endl;
        int intHighest = 0;
        cin>>intHighest;
        //calling validate function
        if(cin.fail())
        {
            intHighest = validateNumber(cin);
        }

        //Validating user input
        while(intHighest <= intLowest)
        {
            cerr<<"Make sure the values are inserted correctly and are not the same (:"<<endl;

            cout<<"please enter the lowest number you want to guess from: "<<endl;
            cin>>intLowest;
            if(cin.fail())
            {
                intLowest = validateNumber(cin);
            }

            cout<<"please enter the highest number you want to guess to: "<<endl;
            cin>>intHighest;
            if(cin.fail())
            {
                intHighest = validateNumber(cin);
            }

        }
        //seeding the random number generator
        srand(static_cast<unsigned int>(time(0)));
        int intRandom = randomNumber(intLowest,intHighest);

        cout<<"Enter a random number between "<<" and "<<intHighest<<endl;

        //getting the user's gueesed number
        int intValue=0;
        cin>>intValue;
        if(cin.fail())
        {
            intValue = validateNumber(cin);
        }

        while(intRandom != intValue)
        {
            if(intValue < intRandom)
            {
                cout<<"Your guess is too low (:"<<endl
                    <<"Enter new value: "<<endl;
                //getting the user's gueesed number
                cin>>intValue;
                if(cin.fail())
                {
                    intValue = validateNumber(cin);
                }

            }
            else if(intValue > intRandom)
            {
                cout<<"Your guess is too high (:"<<endl
                    <<"Enter new value: "<<endl;
                //getting the user's gueesed number
                cin>>intValue;
                if(cin.fail())
                {
                    intValue = validateNumber(cin);
                }
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
