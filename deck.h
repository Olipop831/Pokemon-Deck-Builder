#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"
using namespace std;

class Deck
{
public:
    Deck();
    Deck(string deckType, vector<Card> deckList);
    void setDeckType(string deckName);
    void addCard(Card card);
    void printDeck() const;
    string getDeckType() const;
    int getSize() const;
    void removeCard(string cardName, int amount);
    bool cardLimit(string cardName);
    vector<Card> getDeck() const;

private:
    string _deckType;
    vector<Card> _deckList;
};

#endif