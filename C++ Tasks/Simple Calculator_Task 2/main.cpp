#include<iostream>
#include<cassert>
#include<sstream>
using namespace std;

//addition function
double addition(double firstValue, double secondValue)
{
    return firstValue + secondValue;
}

//subtraction function
double subtraction(double firstValue, double secondValue)
{
    return firstValue - secondValue;
}

//multiplication function
double multiplication(double firstValue, double secondValue)
{
    return firstValue * secondValue;
}

//division function
double division(double firstValue, double devisor)
{
    ///Stop the program if the divisor is zero
    assert(devisor != 0 );
    return firstValue / devisor;
}



int main()
{

    //declaration of the two numbers
    double dblFirstNum = 0.0;
    double dblSecondNum = 0.0;
    stringstream ssResult;
    bool blnContinue = true;
    int intOption = 0;

    do
    {
        //Menu option
        cout<<"Welcome to The SIMPLE CALCULATOR"<<endl
            <<endl
            <<"You are expected to enter two numbers, "<<endl
            <<"then choose the operation you want me to perform."<<endl
            <<endl;
        cout<<"Enter the first number: ";
        cin>> dblFirstNum;
        cout<<"Enter the second number: ";
        cin>> dblSecondNum;

        cout<<"Whoose the arithmetic operations you want me to perform,"<<endl
            <<"1. for Addition"<<endl
            <<"2. for Subtraction"<<endl
            <<"3. for Multiplication"<<endl
            <<"4. for Division"<<endl
            <<"6. to Exit"<<endl;

        ///Getting the user's option
        cin>>intOption;

        ///Using while loop to force user to choosing a valid option
        while(true)
        {
            //using switch statement to check wich option user chose
            switch(intOption)
            {
            case 1 :
            {
                ssResult<< dblFirstNum<< " + "<<dblSecondNum<< " = "<<addition(dblFirstNum,dblSecondNum);
                break;
            }
            case 2 :
            {
                ssResult<< dblFirstNum<< " - "<<dblSecondNum<< " = "<<subtraction(dblFirstNum,dblSecondNum);
                break;
            }
            case 3:
            {
                ssResult<< dblFirstNum<< " * "<<dblSecondNum<< " = "<<multiplication(dblFirstNum,dblSecondNum);
                break;
            }
            case 4:
            {
                ssResult<< dblFirstNum<< " / "<<dblSecondNum<< " = "<<division(dblFirstNum,dblSecondNum);
                break;
            }
            case 6:
            {
                ssResult<<"Tank You for using The SIMPLE CALCULATOR"<<endl;
                blnContinue = false;
                break;
            }

            default:
            {
                cerr<<"You did not choose a valid option :("<<endl;
                cout<<"Enter a valid option :) "<<endl;
                cin>>intOption;

                ///Go to the beginning of the while loop ie. switch statement.
                continue;
            }
            }

            ///Break out of the while loop
            break;
        }

        ///displaying final resut
        cout<<ssResult.str()<<endl<<endl;
        ///Clearing the content in the string stream
        ssResult.str("");
    }
    while(blnContinue);


    return 0;
}
