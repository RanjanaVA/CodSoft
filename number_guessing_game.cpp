#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
    int random_number;
    int guess;
    srand(time(0));
    random_number=rand() % 100 + 1;
    cout<<"Welcome to Guess the Number game\n\n";
    cout<<"Let's start playing\n\n";
    cout<<"You will have 5 chances to guess the correct number\n\n";
    int chance_Left=5;
    int chances=0;
    for(int i=1;i<=5;i++){
        cout<<"Enter your guess between 1 and 100 : ";
        cin>>guess;
        chances++;
        if(guess==random_number)
        {
           cout<<"\n Congrats!!! Yoy got the right guess "<<guess<<" in "<<chances<<" tries\n";
           break;
        }
        else
        {
            if(guess<random_number){
            cout<<"The "<<guess <<" is too low\n\n";
            }
            else{
            cout<<"The "<<guess <<" is too high\n\n";
            }
        }
        chance_Left--;
        cout<<"\n Chances Left to guess the random number: "<<chance_Left <<endl;
        if(chance_Left==0)
        {
            cout<<"\n Your chances has been finished\n";
        }
    }
    return 0;
}
