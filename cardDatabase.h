#ifndef CARDDATABASE_H
#define CARDDATABASE_H

#include <vector>
#include "card.h"
using namespace std;

class cardDatabase
{
public:
    cardDatabase();
    void addCard(string name, string cardType, string pokemonType);
    void printByPokemonType(string pokemonType);
    void printTrainers();
    void printEnergy();
    string getCardType(string cardName) const;
    vector<Card> getPokemonType(string type) const;
    bool cardExists(string cardName);
    bool cardExistsHelper(string cardName, vector<Card> cards);

private:
    vector<Card> Fire;
    vector<Card> Water;
    vector<Card> Grass;
    vector<Card> Electric;
    vector<Card> Fighting;
    vector<Card> Psychic;
    vector<Card> Normal;
    vector<Card> Trainers;
    vector<Card> Energy;
};
#endif