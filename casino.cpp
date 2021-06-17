
//still a wip! adding new features
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

static int money = 1000;
void game_select();
void slots();
void blackjack();

void game_select(){
    int game = 0;
    cout << "You have: " << money << "dollars." "\n";
    cout << "Type [1] to play blackjack." << "\n";
    cout << "Type [2] to play slots." << "\n";
    cout << "Type [3] to quit" << "\n";
    cin >> game;
    if(game == 1){
        blackjack();
    } else if(game == 2){
        slots();
    } else {

    }
}

string draw(string decks[52]){
    srand(time(0));
    int r = rand() % 52;
    string card = decks[r];
    return card;
    
}

int intialize_deck() {
    string suits[4] = {"of Hearts", "of Clubs", "of Diamonds", "of Spades"};
    string val[13] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    string deck[52];
    int counter = 0;
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 4; j++){
            deck[counter] = val[i];// + suits[j];
            counter++;
        }
    }
    //for(int x = 0; x < 52; x++){
     //   cout << deck[x] << "\n";
    //}
    string card = draw(deck);
    cout << "card drawn: " <<card << "\n";
    cout << "\n" << "Shuffled deck: " << "\n";
    
    srand(time(0));
    for(int x = 0; x < 52; x++){
        int r = rand() % 52;
        string temp = deck[r];
        deck[r] = deck[x];
        deck[x] = temp;
    }
     
    return 0;
}
int getval(string card){
    char v = card.at(0);
    int val = v - '0';
    switch(val){
        case(2):
            return 2;
        case(3):
            return 3;
        case(4):
            return 4;
        case(5):
            return 5;
        case(6):
            return 6;
        case(7):
            return 7;
        case(8):
            return 8;
        case(9):
            return 9;
        case(17):
            return 11;
        default:
            return 10;

    }
}
void blackjack(){
    bool win = false;
    bool replay = false;
    bool aces = false;
    int aceCount = 0;
    int daceCount = 0;
    int bet;
    int in;
    cout << "Type your bet amount: ";
    cin >> bet;
    string dealer_hand = "";
    string player_hand = "";
    string card1 = draw();
    string card2 = draw();
    dealer_hand = dealer_hand + card1;
    player_hand = player hand + card2;
    int dval = getval(card1);
    int pval = getval(card2);
    if(dval == 11){
        aces = true;
        daceCount++;
    }
    if(pval == 11){
        aces = true;
        aceCount++;
    }       
    card1 = draw();
    card2 = draw();
    if(getval(card1) == 11){
        aces = true;
        daceCount++;
    }
    if(getval(card2) == 11){
        aces = true;
        aceCount++;
    }
    pval = pval + getval(card2);   
    player_hand = player hand + " " + card2;
    cout << "Dealer hand: " << dealer_hand << " ? " << "\n";
    dealer_hand = dealer_hand + " " + card1;
    cout << "\n";
    cout << "Player hand: " << player_hand << " \n";
    cout << "Type [H] to hit, [S] to stand, [D] to double.";
    cin >> in;
    if(strcmp(in, "H") == 0){
        while(true){
            string nc = draw();
            int v = getval(nc);
            if(v == 11){
                aces = true;
                aceCount++;
            }
            pval = pval + v;
            while(pval > 21 && aceCount > 0){
                aceCount--;
                pval = pval - 10;
            }
            player_hand = player_hand + " " + nc;
            cout << "Player hand: " << player_hand << " \n";
            if(pval == 21){
               
                cout << "Blackjack! You win: " << bet << "dollars." << "\n";
                money = money + bet;
                cout << "You now have: " << money << "dollars." << "\n";
                break;
            } else if(pval > 21){
                
                cout << "Bust! You lose: " << bet << "dollars." << "\n";
                money = money - bet;
                cout << "You now have: " << money << "dollars." << "\n";
                break;
            } else if(pval < 21){
                cout << "Would you like to hit again? (Y/N)";
                string response = "";
                cin >> response;
                if(strcmp(response, "Y") == 0){
                    continue;
                } else {
                    do{
                    
                    string nc = draw();
                    int n = getval(nc);
                    if(n == 11){
                        aces = true;
                        daceCount++;
                    }
                    dval = dval + n;
                    while(dval > 21 && daceCount > 0){
                        daceCount--;
                        dval = dval - 10;
                    }
                    dealer_hand = dealer_hand + " " + nc;
                    cout << "Dealer hand: " << dealer_hand << ;
                    cout << "Player hand: " << player_hand << " \n";
                    } while(dval < 18);

                    if(dval > 21){
                        
                        cout << "Dealer bust! You win: " << bet << "dollars.";
                        money = money + bet;
                        cout << "You now have: " << money << "dollars." << "\n";
                    } else if(pval > dval){
                        
                        cout << "You win!" << "\n";
                        money = money + bet;
                        cout << "You now have: " << money << "dollars." << "\n";
                    } else if(pval < dval){
                         cout << "You lose!" << "\n";
                        money = money - bet;
                        cout << "You now have: " << money << "dollars." << "\n";
                   }
                   break;
                }
            } 
        }
    } else if(strcmp(in, "S") == 0){
        cout << "Dealer hand: " << dealer_hand << ;
        cout << "Player hand: " << player_hand << " \n";
        
        do{
            
            string nc = draw();
            int n = getval(nc);
            if(n == 11){
                aces = true;
                daceCount++;
            }
            dval = dval + n;
            while(dval > 21 && daceCount > 0){
                daceCount--;
                dval = dval - 10;
            }
            dealer_hand = dealer_hand + " " + nc;
            cout << "Dealer hand: " << dealer_hand << ;
            cout << "Player hand: " << player_hand << " \n";
        }while(dval < 18);
        
        if(dval > 21){
            
            cout << "Dealer bust! You win: " << bet << "dollars.";
            money = money + bet;
            cout << "You now have: " << money << "dollars." << "\n";
        } else if(pval > dval){
            
            cout << "You win!" << "\n";
            money = money + bet;
            cout << "You now have: " << money << "dollars." << "\n";
        } else if(pval < dval){
            cout << "You lose!" << "\n";
            money = money - bet;
            cout << "You now have: " << money << "dollars." << "\n";
        } 
    } else if(strcmp(in, "D") == 0){
        bet = bet * 2;
        string card = draw();
        player_hand = player_hand + " " + card;
        int v = getval(card);
        while(pval > 21 && aceCount > 0){
                aceCount--;
                pval = pval - 10;
        }
        if(pval > 21){
            cout << "Bust! You lose: " << bet << "dollars." << "\n";
            money = money - bet;
            cout << "You now have: " << money << "dollars." << "\n";
        do{
            
            string nc = draw();
            int n = getval(nc);
            dval = dval + n;
            while(dval > 21 && daceCount > 0){
                daceCount--;
                dval = dval - 10;
            }
            dealer_hand = dealer_hand + " " + nc;
            cout << "Dealer hand: " << dealer_hand << ;
            cout << "Player hand: " << player_hand << " \n";
        }while(dval < 18);
        if(dval > 21){
            
            cout << "Dealer bust! You win: " << bet << "dollars.";
            money = money + bet;
            cout << "You now have: " << money << "dollars." << "\n";
        } else if(pval > dval){
            
            cout << "You win!" << "\n";
            money = money + bet;
            cout << "You now have: " << money << "dollars." << "\n";
        } else if(pval < dval){
            cout << "You lose!" << "\n";
            money = money - bet;
            cout << "You now have: " << money << "dollars." << "\n";
        } 
    }
    cout << "Would you like to play again? (Y/N)";
    string response = "";
    cin >> response;
    if(strcmp(response, "Y") == 0){
        blackjack();
    } else {
        game_select();
    }

}

void slots(){
    srand(time(0));
    int c = 0;
    int rows[3][3];
    bool win = false;
    bool replay = false;
    int bet;
    cout << "Type Your bet amount: ";
    cin >> bet;

    while(c < 6){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                rows[i][j] = rand() % 10;
            }
        }
        cout << rows[0][0] <<" " << rows[0][1] << " " << rows[0][2] << "\n";
        cout << rows[1][0] <<" " << rows[1][1] << " " << rows[1][2] << "\n";
        cout << rows[2][0] <<" " << rows[2][1] << " " << rows[2][2] << "\n";
        c++;
        sleep(1);
    }
    if((rows[0][0] == rows[0][1]) && (rows[0][1] == rows[0][2])){
        win = true;
    } 
    else if((rows[1][0] == rows[1][1]) &&( rows[1][1] == rows[1][2])){
        win = true;
    }
    else if((rows[2][0] == rows[2][1]) && (rows[2][1] == rows[2][2])){
        win = true;
    }
    else if((rows[0][0] == rows[1][0]) && (rows[1][0] == rows[2][0])){
        win = true;
    } 
    else if((rows[0][1] == rows[1][1]) && (rows[1][1] == rows[2][1])){
        win = true;
    }
    else if((rows[0][2] == rows[1][2]) && (rows[1][2] == rows[2][2])){
        win = true;
    } 
    else if((rows[0][0] == rows[1][1]) && (rows[1][1] == rows[2][2])){
        win = true;
    }
    else if((rows[0][2] == rows[1][1]) && (rows[1][1] == rows[2][0])){
        win = true;
    }
    if(win){
        bet = bet * 2;
        money = money + bet;
        cout << "Congrats! You win" << bet << '\n';
        cout << "You now have:" << money << "dollars.";
    } else {
        money = money - bet;
        cout << "Sorry! You lose" << '\n';
        cout << "You now have:" << money << "dollars.";
    }
        cout << "Would you like to play again? (Y/N)" << '\n';
        string p;
        cin >> p;
        if(strcmp(p,"Y") == 0){
            replay = true;
        }
        if(replay){
            slots();
        } else {
            game_select();
        }
}

int main(){

    cout << "Welcome to the Casino!" << "\n";
    game_select();
    return 0;
   
}