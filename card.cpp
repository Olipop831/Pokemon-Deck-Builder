#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "card.h"
#include "deck.h"

Card::Card()
{
    _name = "";
    _cardType = "";
    _pokemonType = "";
}
Card::Card(string name, string cardType, string pokemonType)
{
    _name = name;
    _cardType = cardType;
    _pokemonType = pokemonType;
}
void Card::setName(string name)
{
    _name = name;
}

string Card::getName() const
{
    return _name;
}

void Card::setCardType(string cardType)
{
    _cardType = cardType;
}

string Card::getCardType() const
{
    return _cardType;
}

void Card::setPokemonType(string pokemonType)
{
    _pokemonType = pokemonType;
}

string Card::getPokemonType() const
{
    return _pokemonType;
}

void Card::write(ofstream &fout) const
{
    fout << _name << endl;
}
void Card::read(ifstream &fin)
{
    fin >> ws;
    getline(fin, _name);
}
