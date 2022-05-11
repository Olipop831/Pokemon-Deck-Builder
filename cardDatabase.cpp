#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "cardDatabase.h"

using namespace std;

cardDatabase::cardDatabase()
{
    string fileName = "pokemon.txt";
    ifstream inFS;
    string data;
    inFS.open(fileName);
    if (!inFS.is_open())
    {
        cout << "Could not open file " << fileName << endl;
        exit(-1);
    }

    while (inFS.good())
    {
        while (getline(inFS, data))
        {
            vector<string> line;
            istringstream inSS;
            string word;
            inSS.str(data);
            while (inSS >> word)
            {
                line.push_back(word);
            }
            if (line.at(1) == "Trainer")
            {
                addCard(line.at(0), line.at(1), "");
            }
            else if (line.at(1) == "Energy")
            {
                addCard(line.at(0), line.at(1), line.at(0));
            }
            else
            {
                addCard(line.at(0), "Pokemon", line.at(1));
            }
        }
    }
    inFS.close();
}

void cardDatabase::addCard(string name, string cardType, string pokemonType)
{
    Card card(name, cardType, pokemonType);
    if (cardType == "Pokemon")
    {
        if (pokemonType == "Fire")
        {
            Fire.push_back(card);
        }
        else if (pokemonType == "Water")
        {
            Water.push_back(card);
        }
        else if (pokemonType == "Grass")
        {
            Grass.push_back(card);
        }
        else if (pokemonType == "Electric")
        {
            Electric.push_back(card);
        }
        else if (pokemonType == "Fighting")
        {
            Fighting.push_back(card);
        }
        else if (pokemonType == "Psychic")
        {
            Psychic.push_back(card);
        }
        else if (pokemonType == "Normal")
        {
            Normal.push_back(card);
        }
    }
    else if (cardType == "Trainer")
    {
        Trainers.push_back(card);
    }
    else if (cardType == "Energy")
    {
        Energy.push_back(card);
    }
}

void cardDatabase::printByPokemonType(string pokemonType)
{
    vector<Card> selector = getPokemonType(pokemonType);

    for (unsigned i = 0; i < selector.size(); ++i)
    {
        cout << selector.at(i).getName() << endl;
    }
}

void cardDatabase::printTrainers()
{
    for (unsigned i = 0; i < Trainers.size(); ++i)
    {
        cout << Trainers.at(i).getName() << endl;
    }
}
void cardDatabase::printEnergy()
{
    for (unsigned i = 0; i < Energy.size(); ++i)
    {
        cout << Energy.at(i).getName() << endl;
    }
}

vector<Card> cardDatabase::getPokemonType(string type) const
{
    vector<Card> selector;
    if (type == "Fire")
    {
        selector = Fire;
    }
    else if (type == "Water")
    {
        selector = Water;
    }
    else if (type == "Grass")
    {
        selector = Grass;
    }
    else if (type == "Electric")
    {
        selector = Electric;
    }
    else if (type == "Fighting")
    {
        selector = Fighting;
    }
    else if (type == "Psychic")
    {
        selector = Psychic;
    }
    else if (type == "Normal")
    {
        selector = Normal;
    }
    else if (type == "Trainer")
    {
        selector = Trainers;
    }
    else if (type == "Energy")
    {
        selector = Energy;
    }
    return selector;
}

string cardDatabase::getCardType(string cardName) const
{
    for (unsigned i = 0; i < Trainers.size(); ++i)
    {
        if (cardName == Trainers.at(i).getName())
        {
            return "Trainer";
        }
    }

    for (unsigned i = 0; i < Energy.size(); ++i)
    {
        if (cardName == Energy.at(i).getName())
        {
            return "Energy";
        }
    }
    return "Pokemon";
}

bool cardDatabase::cardExists(string cardName)
{
    if (cardExistsHelper(cardName, Fire) ||
        cardExistsHelper(cardName, Water) ||
        cardExistsHelper(cardName, Grass) ||
        cardExistsHelper(cardName, Fighting) ||
        cardExistsHelper(cardName, Electric) ||
        cardExistsHelper(cardName, Psychic) ||
        cardExistsHelper(cardName, Normal) ||
        cardExistsHelper(cardName, Trainers) ||
        cardExistsHelper(cardName, Energy))
    {
        return true;
    }
    return false;
}

bool cardDatabase::cardExistsHelper(string cardName, vector<Card> cards)
{
    for (unsigned i = 0; i < cards.size(); ++i)
    {
        if (cardName == cards.at(i).getName())
        {
            return true;
        }
    }
    return false;
}
