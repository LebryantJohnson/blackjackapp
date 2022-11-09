#include <iostream>
#include <string>
#include <ctime>
#include "mainheader.h"
using namespace std;


int main() {
    srand(time(0));
    //introduction to the game
    cout<<"Welcome To the Blackjack Shack" << endl;
    cout<<"What is your Name: ";
    string Name;
    cin>> Name;
    cout<<"Welcome " << Name << " Before we continue, what is your age?"<< endl;

    //decide if the player can play the game
    int Age;
    cin>>Age;
    if (Age>=18){
        cout<<"Great you are old enough to play!" <<endl ;
        playGame();
    }
    else{
        cout<<"Unfortunately you are not old enough to play this game :(" << endl;
    }
    return 0;
}
