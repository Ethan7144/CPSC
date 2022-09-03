//Ethan Tarlov
// p4.cpp
#include <iostream>
#include "queue.h"
#include "stack.h"
#include <ctime>
#include <cctype>

using namespace std;

const int MAX_VALUE = 13;
const int START_CARDS = 7;
const char YES = 'y';
char ans = YES;

Stack shuffle(); // shuffles the deck
void welcome(); // gives the rules to the game
void goodbye(); // thanks the user
int main()
{

    Stack dealCards; // dealers deck
    Stack discardPile; // discard pile
    Queue player1; // player 1 deck
    Queue player2; // player 2 deck


    bool P1Turn = true; // determins whos turn it is
    int top; // top of discardPile
    int newDiscard; // card from P1 or P2 to be added to discard pile
    int temp; // temp incase dealCards is empty
    welcome();

    while(tolower(ans) == YES){
        dealCards = shuffle();
        cout << "Cards are shuffled and being dealt..." << endl;
        for(int i = 0; i < START_CARDS; i++){
            player1.enqueue(dealCards.pop()); 
            player2.enqueue(dealCards.pop());
            // cards are handed one at a time to each player
        }
        top = dealCards.pop(); // this sets the top of the discard
        discardPile.push(top);
                //Game is starting here

        while(!player1.isEmpty() && !player2.isEmpty() &&!dealCards.isEmpty()){
            if(P1Turn){ // player 1 turn
                cout << endl << "It's player 1's turn!" << endl;
                cout << "Press enter to place a card" << endl;
                cin.get();                    
                 // sets the card as the one to be discarded
                newDiscard = player1.dequeue(); 
                discardPile.push(newDiscard);
                
                cout << "The players card is " << newDiscard << endl;
                cout << "The card being compared is " << top << endl;
                // checks if player needs to draw
                if(newDiscard > top){
                    cout << "Don't have to draw!" << endl;
                } else if(newDiscard == top){                        
                    cout << "Draw one card!" << endl;
                    player1.enqueue(dealCards.pop());
                } else if(newDiscard < top){
                    cout << "Draw two cards!" << endl;
                    player1.enqueue(dealCards.pop());
                    if(dealCards.isEmpty()){
                        cout << "Deal deck is empty!" << endl;
                        cout << "Refreshing the deal card pile." << endl;

                        temp = discardPile.pop();

                        while(!discardPile.isEmpty()){
                            dealCards.push(discardPile.pop());
                        }
                        discardPile.push(temp);
                    }
                    player1.enqueue(dealCards.pop());                   
                 }
                top = newDiscard;

                   cout << "Player 1 turn is over!" << endl;
                P1Turn = false;
            }else { // same thing as above, just player 2
                cout << endl << "It's player 2's turn!" << endl;
                cout << "Press enter to place a card" << endl;
                cin.get();

                newDiscard = player2.dequeue();
                discardPile.push(newDiscard);

                cout << "The players card is " << newDiscard << endl;
                cout << "The card being compared is " << top << endl;

                if(newDiscard > top){
                    cout << "Don't have to draw!" << endl;
                } else if(newDiscard == top){
                    cout << "Draw one card!" << endl;
                    player2.enqueue(dealCards.pop());
                } else if(newDiscard < top){
                    cout << "Draw two cards!" << endl;
                    player2.enqueue(dealCards.pop());
                    if(dealCards.isEmpty()){
                        cout << "Deal deck is empty!" << endl;
                        cout << "Refreshing the deal card pile." << endl;

                        temp = discardPile.pop();

                        while(!discardPile.isEmpty()){
                            dealCards.push(discardPile.pop());
                        }
                        discardPile.push(temp);
                    }
                    player2.enqueue(dealCards.pop());
                }
                top = newDiscard;

                cout << "Player 2 turn is over!" << endl;
                P1Turn = true;

            }
            // will give statements if one of the decks are empty
            if(player1.isEmpty()){
                cout << "Player 1 wins!" << endl;
            } else if (player2.isEmpty()){
                cout << "Player 1 wins!" << endl;
            } else if(dealCards.isEmpty()){
                cout << "Deal deck is empty!" << endl;
                cout << "Refreshing the deal card pile." << endl;

                temp = discardPile.pop();

                while(!discardPile.isEmpty()){
                    dealCards.push(discardPile.pop());
                }
                discardPile.push(temp);
            }
        }
        
        

        //check to see if user wants to play again
        cout << "Do you wish to replay the game? (y/n)" << endl;
        cin >> ans;
        while(ans != 'y' && ans != 'n')
        {
            cout << "Please insert 'y' or 'n' ";
            cin >> ans;
            cout << endl;
        }
    }
    goodbye();
    return 0;
}



Stack shuffle()
{
    const int MAX_COUNT = 4;
    Stack result;
    int cardSwap;
    int cards[MAX_VALUE * MAX_COUNT];

    for(int i = 1; i < MAX_VALUE + 1; i++){
        for(int j = 0; j < MAX_COUNT; j++){
            cards[(i - 1) * MAX_COUNT + j] = i;
        }
    }
    for(int i = 0; i < MAX_VALUE * MAX_COUNT - 1; i++){
        cardSwap = (rand() % (MAX_VALUE * MAX_COUNT - i));
        result.push(cards[cardSwap + i]);
        cards[cardSwap + i] = cards[i];
    }
    result.push(cards[MAX_VALUE * MAX_COUNT -1]);
    return result;
}

void goodbye()
{
    cout << "Thank you for playing!" << endl;
}

void welcome()
{
    cout << "Welcome to my card game!" << endl;
    cout << "It uses a special set of cards that " << endl;
    cout << "contain the numbers 1 to 13 " << endl;
    cout << "and there are four copies of each card in the deck." << endl;
    cout << "Each player is dealt 7 cards" << endl;
    cout << "For their turn, each player plays the next card to the discard";
    cout << endl << "If the card the player plays is HIGHER "<< endl;
    cout << "in number than the one on the top of the discard, " << endl;
    cout << "the player's turn is over" << endl;
    cout << "If the number drawn is EQUAL, the player draws one card" << endl;
    cout << "If the number is LOWER, the player draws two cards" << endl;
    cout << "Game will continue until the first player runs out of cards";
    cout << endl << "If the dealer pile runs out, the discard pile will be";
    cout << endl << "flipped and the game will continue" << endl;
    cout << "Goodluck and have fun! Hit enter to start!" << endl;
    cin.get();
}
