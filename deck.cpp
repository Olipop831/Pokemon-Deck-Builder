#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#include "deck.h"

const int POKEMON_WIDTH = 18;
const int TRAINER_WIDTH = 27;
const int ENERGY_WIDTH = 11;

Deck::Deck()
{
    _deckType = "";
}

Deck::Deck(string deckType, vector<Card> deckList)
{
    _deckType = deckType;
    _deckList = deckList;
}

string Deck::getDeckType() const
{
    return _deckType;
}

void Deck::setDeckType(string deckType)
{
    _deckType= deckType;
}

void Deck::addCard(Card card)
{
    _deckList.push_back(card);
}

void Deck::printDeck() const
{
    cout << "\nCard count " << _deckList.size() << endl;
    cout << setw(POKEMON_WIDTH) << left << "POKEMONS";
    cout << setw(TRAINER_WIDTH) << left << "TRAINERS";
    cout << setw(ENERGY_WIDTH) << right << "ENERGYS" << endl;

    vector<Card> pokemon;
    vector<Card> trainer;
    vector<Card> energy;
    for (unsigned int i = 0; i < _deckList.size(); ++i)
    {
        Card card = _deckList.at(i);
        if (card.getCardType() == "Pokemon")
        {
            pokemon.push_back(card);
        }
        else if (card.getCardType() == "Trainer")
        {
            trainer.push_back(card);
        }
        else
        {
            energy.push_back(card);
        }
    }
    unsigned int maxRange = max(pokemon.size(), trainer.size());
    for (unsigned i = 0; i < maxRange; ++i)
    {
        if (i < pokemon.size())
        {
            cout << setw(POKEMON_WIDTH)
                 << left << pokemon.at(i).getName();
        }
        else
        {
            cout << setw(POKEMON_WIDTH) << left << " ";
        }
        if (i < trainer.size())
        {
            cout << setw(TRAINER_WIDTH)
                 << left << trainer.at(i).getName();
        }
        else
        {
            cout << setw(TRAINER_WIDTH) << left << " ";
        }
        if (i < energy.size())
        {
            cout << setw(ENERGY_WIDTH) << right
                 << energy.at(i).getName() << endl;
        }
        else
        {
            cout << endl;
        }
    }
}

int Deck::getSize() const
{
    return _deckList.size();
}

void Deck::removeCard(string cardName, int amount) 
{
    int removed = 0;
    for (int i = 0; i < amount; ++i)
    {
        for (unsigned j = 0; j < _deckList.size(); ++j)
        {
            if (_deckList.at(j).getName() == cardName)
            {
                _deckList.at(j) = _deckList.at(_deckList.size() - 1);
                _deckList.pop_back();
                removed++;
                break;
            }
        }
    }
    if (removed != amount) {
        cout << "\nOnly " << removed << " cards were found and removed\n";
    }
}

bool Deck::cardLimit(string cardName)
{ 
   int count = 0;
    for (unsigned i = 0; i < _deckList.size(); ++ i)
    {
        if (_deckList.at(i).getName() == cardName)
        {
            count++;
        }
    }
    if (count < 4)
    {
        return false;
    }
    return true;
}

vector<Card> Deck::getDeck() const {
    return _deckList;
}

