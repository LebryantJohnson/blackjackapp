//
// Created by Braden Dhillon on 11/7/22.
//

#ifndef BLACKJACKAPP_MAINHEADER_H
#define BLACKJACKAPP_MAINHEADER_H

#endif //BLACKJACKAPP_MAINHEADER_H

using namespace std;

//global variables
int CardValue;
int DealerCardValue=0;
int AccountBalance=100;
int standorhit;
int wager;
int playagain;

void BlackJackCore();
void StandHitMenu();
void playGame();

void firstdeal(){
    CardValue= rand()%11+1 + rand()%11+1;
}

void dealerDraw(){
    DealerCardValue=rand()%11+1 + DealerCardValue;
}

void openShop() {
    int shopchoices;
    cout<<"You Have $" << AccountBalance << endl;
    cout<<"Options:"<<endl;
    cout<<"Buy Drinks (Press 1, Costs $50) "<<endl;
    cout<<"Buy Food (Press 2, costs $30)"<<endl;
    cout<<"Buy Clothes (Press 3, costs $100)"<<endl;
    cout<<"Return to Menu (Press 4)"<<endl;
    cin>>shopchoices;
    if(shopchoices==1){
        if(AccountBalance>=50){
            AccountBalance-=50;
            cout<<"Purchase made" << endl;
            cout<<"New Balance $" << AccountBalance << endl;
            openShop();
        }
        else{
            cout<<"No Balance"<<endl;
            openShop();
        }
    }
    if(shopchoices==2){
        if(AccountBalance>=30){
            AccountBalance-=30;
            cout<<"Purchase made" << endl;
            cout<<"New Balance $" << AccountBalance << endl;
            openShop();
        }
        else{
            cout<<"No Balance"<<endl;
            openShop();
        }
    }if(shopchoices==3){
        if(AccountBalance>=100){
            AccountBalance-=100;
            cout<<"Purchase made" << endl;
            cout<<"New Balance $" << AccountBalance << endl;
            openShop();
        }
        else{
            cout<<"No Balance"<<endl;
            openShop();
        }
    }
    if(shopchoices==4){
        playGame();
    }
    else{
        openShop();
    }
}

void PlayAgainFunc(){
    cout<<"Play again?"<<endl;
    cout<<"Yes (1) No (2)"<<endl;
    cin>>playagain;

    if (playagain==1){
        DealerCardValue=0;
        CardValue=0;
        BlackJackCore();
    }
    else if(playagain==2){
        exit(0);
    }
    else{
        PlayAgainFunc();
    }
}
void quitGame(){

}
void Lose(){

    cout<<"Unfortunately the dealer has won the game"<<endl;
    AccountBalance-=wager;
    cout<<"Account Balance: $" << AccountBalance << endl;
    PlayAgainFunc();

}

void Win(){
    cout<<"Congrats you have won the game!" << endl;
    cout<<"You have won $" << wager<<endl;
    AccountBalance+=wager;
    cout<<"New balance: $" << AccountBalance <<endl;
    PlayAgainFunc();

}
void Stand(){
    while (DealerCardValue<17){
        dealerDraw();
    }
    cout<<"Dealer Drew: " << DealerCardValue<< endl;
    if(DealerCardValue<22 && DealerCardValue>CardValue){
        Lose();
    }
    else if(CardValue>DealerCardValue && CardValue<22){
        Win();
    }
    else if(DealerCardValue==21 && CardValue==21){
        cout<<"Draw" << endl;
        BlackJackCore();
    }
    else {
        Win();
    }

}

void Hit(){
    CardValue+=rand()%12+2;
    cout<<"You drew: " << CardValue<<endl;
    if(CardValue==21 && DealerCardValue !=21){
        Win();
    }
    if (CardValue>21){
        Lose();
    }
    if(CardValue<21){
        StandHitMenu();
    }
}

void StandHitMenu(){
    cout << "You drew: " << CardValue << endl;
    cout << "The dealer drew: " << DealerCardValue << endl;
    cout<<"Would you like to stand (1) or hit (2): ";
    cin>>standorhit;
    //stand code
    if (standorhit==1){
        Stand();
    }
        //hit code
    else if(standorhit==2){
        Hit();
    }
        //restart from the stand/hit selection
    else{
        cout<<"Option Not Valid";
        StandHitMenu();
    }
}
void BlackJackCore(){
    // get wager from player
    cout<<"You have $" << AccountBalance << endl;
    cout<< "You must set a wager. What will yours be?" << endl;
    cout<<"$ ";
    cin>>wager;

    // if the wager makes sense deal cards and start game
    if(wager<=AccountBalance && wager>=1){
        firstdeal();
        dealerDraw();
        StandHitMenu();
    }
        // Wager Exceeds Reasonable Value
    else{
        wager=0;
        cout<<"That is not a valid wager. Please try again.";
        BlackJackCore();
    }

}

void playGame(){

    int BlackJackOptionsMenu;

    //player selects options
    cout<<"Welcome To Blackjack. Here are your options"<< endl;
    cout<<"Play a match (1)" << endl;
    cout<<"Learn rules (2)" << endl;
    cout<<"Go to store (3)" << endl;
    cin>>BlackJackOptionsMenu;

    //open the corresponding choice
    if(BlackJackOptionsMenu==1){
        BlackJackCore();
    }
    else if (BlackJackOptionsMenu==2){
        cout<<"Rules:  Card game whose object is to be dealt cards having a higher count than those of the dealer, up to but not exceeding 21. The dealer may use a single deck of 52 cards or two or more decks from a holder called a shoe. Aces count as 1 or 11, and face cards as 10. Bets may be placed before the deal " << endl;
        playGame();

    }
    else if(BlackJackOptionsMenu==3){
        openShop();
    }
    else {
        cout << "Your choice was not valid. Please try again." << endl;
        playGame();
    }
}
