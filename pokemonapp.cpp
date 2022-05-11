/*
    CS-11 Final Project, pokemonapp.cpp
    Purpose: Building your own Pokemon trading card game deck.

    @author Oliver Urbano
    @version 2.0  05/06/2022
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "deck.h"
#include "card.h"
#include "cardDatabase.h"

using namespace std;

const int POKEMON_WIDTH = 18;
const int TRAINER_WIDTH = 27;
const int ENERGY_WIDTH = 11;

Deck chooseDeck(cardDatabase database);

void addCardsToDeck(cardDatabase database, string deckType, Deck &deck);

void editDeck(cardDatabase database, Deck &deck);

void deleteCards(Deck &deck, cardDatabase database);

void saveDeck(const Deck &deck);

void loadDeck(Deck &deck, cardDatabase database);

int main()
{
    Deck deck;
    cardDatabase database;
    string choice;
    cout << endl;
    cout << "****   ***  *   * *****  *   *  ***  *   * \n"
         << "*   * *   * *  *  *      ** ** *   * **  * \n"
         << "****  *   * ***   *****  * * * *   * * * * \n"
         << "*     *   * *  *  *      * * * *   * *  ** \n"
         << "*      ***  *   * *****  *   *  ***  *   * \n\n"
         << "****  *****  **** *   * \n"
         << "*   * *     *     *  *  \n"
         << "*   * ***** *     ***   \n"
         << "*   * *     *     *  *  \n"
         << "****  *****  **** *    *\n\n"
         << "****  *   * ***** *     ****  ***** ****  \n"
         << "*   * *   *   *   *     *   * *     *   * \n"
         << "****  *   *   *   *     *   * ***** ****  \n"
         << "*   * *   *   *   *     *   * *     * *   \n"
         << "****   ***  ***** ***** ****  ***** *  *  \n";
    cout << endl;

    do
    {
        cout << "\nPlease choose one of the following operations:\n"
             << "0. Exit program\n"
             << "1. View Deck\n"
             << "2. Build Deck\n"
             << "3. Edit Deck\n"
             << "4. Save Deck\n"
             << "5. Load Deck\n"
             << "Choice (0 - 5): ";
        getline(cin, choice);
        if (choice == "1")
        {
            deck.printDeck();
        }
        else if (choice == "2")
        {
            if (deck.getSize() != 0)
            {
                cout << "Deck already exists, would you like to edit instead? "
                     << "Press y for yes. ";
                getline(cin, choice);
                if (choice == "y")
                {
                    editDeck(database, deck);
                }
            }
            else
            {
                deck = chooseDeck(database);
            }
        }
        else if (choice == "3")
        {
            if (deck.getSize() == 0)
            {
                cout << "Error, no deck has been built. Build deck to edit.\n\n";
            }
            else
            {
                editDeck(database, deck);
            }
        }
        else if (choice == "4")
        {
            saveDeck(deck);
        }

        else if (choice == "5")
        {
            loadDeck(deck, database);
        }

    } while (choice != "0");

    return 0;
}

Deck chooseDeck(cardDatabase database)
{
    Deck deck;
    string choice;
    cout << endl;
    cout << "Choose Deck Type (0 to Exit):\n"
         << "1.Fire\n"
         << "2.Water\n"
         << "3.Grass\n"
         << "4.Electric\n"
         << "5.Fighting\n"
         << "6.Psychic\n"
         << "Choice (0 - 6): ";
    getline(cin, choice);
    if (choice == "1")
    {
        addCardsToDeck(database, "Fire", deck);
        deck.setDeckType("Fire");
    }
    if (choice == "2")
    {
        addCardsToDeck(database, "Water", deck);
        deck.setDeckType("Water");
    }
    if (choice == "3")
    {
        addCardsToDeck(database, "Grass", deck);
        deck.setDeckType("Grass");
    }
    if (choice == "4")
    {
        addCardsToDeck(database, "Electric", deck);
        deck.setDeckType("Electric");
    }
    if (choice == "5")
    {
        addCardsToDeck(database, "Fighting", deck);
        deck.setDeckType("Fighting");
    }
    if (choice == "6")
    {
        addCardsToDeck(database, "Psychic", deck);
        deck.setDeckType("Psychic");
    }

    return deck;
}

void addCardsToDeck(cardDatabase database, string deckType, Deck &deck)
{
    vector<Card> pokemon = database.getPokemonType(deckType);
    vector<Card> normals = database.getPokemonType("Normal");
    vector<Card> trainer = database.getPokemonType("Trainer");
    vector<Card> energy = database.getPokemonType("Energy");
    pokemon.insert(pokemon.end(), normals.begin(),
                   normals.end());

    string cardName = "";
    int amount = 0;
    while (true)
    {
        cout << endl;
        cout << setw(POKEMON_WIDTH) << left << "POKEMONS";
        cout << setw(TRAINER_WIDTH) << left << "TRAINERS";
        cout << setw(ENERGY_WIDTH) << left << "ENERGYS" << endl;
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
                cout << setw(ENERGY_WIDTH) << left
                     << energy.at(i).getName() << endl;
            }
            else
            {
                cout << endl;
            }
        }
        cout << "\nEnter card name from list to add (or q to quit): ";
        getline(cin, cardName);
        if (cardName == "q")
        {
            break;
        }
        cout << "Enter amount of copys(max 4): ";
        cin >> amount;
        cin.ignore();

        string cardType = database.getCardType(cardName);

        for (int j = 0; j < amount; ++j)
        {
            if (!database.cardExists(cardName))
            {
                cout << "\ncard does not exist, try again\n\n";
                break;
            }
            if (deck.getSize() == 60)
            {
                cout << "\nMax deck size has been reached (60 cards max).\n\n";
                break;
            }
            if (!deck.cardLimit(cardName) || cardType == "Energy")
            {
                Card card(cardName, cardType, deckType);
                deck.addCard(card);
            }
            else
            {
                cout << "\nCard limit has been reached (max 4 cards).\n";
                break;
            }
        }
    }
}

void editDeck(cardDatabase database, Deck &deck)
{
    string choice = "";
    while (true)
    {
        cout << "\nNumber of cards: " << deck.getSize() << endl;
        deck.printDeck();
        cout << "\nChoose your action:\n"
             << "0. To quit\n"
             << "1. Add cards\n"
             << "2. Delete cards\n"
             << "Choice (0 - 2): ";
        getline(cin, choice);
        if (choice == "0")
        {
            break;
        }
        if (choice == "1")
        {
            addCardsToDeck(database, deck.getDeckType(), deck);
        }
        if (choice == "2")
        {
            deleteCards(deck, database);
        }
    }
}

void deleteCards(Deck &deck, cardDatabase database)
{
    string choice = "";
    int amount = 0;
    while (true)
    {
        deck.printDeck();
        cout << "\nEnter card name to delete (q to quit): ";
        getline(cin, choice);
        if (choice == "q")
        {
            break;
        }
        cout << "Enter amount to delete: ";
        cin >> amount;
        cin.ignore();
        if (!database.cardExists(choice))
        {
            cout << "\nCard does not exist, try again\n";
        }
        else
        {
            deck.removeCard(choice, amount);
        }
    }
}

void saveDeck(const Deck &deck)
{
    string fileName = deck.getDeckType() + "_deck.txt";
    cout << "\nSaving deck to file " << fileName << endl;
    ofstream fout;
    vector<Card> deckList = deck.getDeck();

    fout.open(fileName);
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(-1);
    }
    for (unsigned i = 0; i < deckList.size(); i++)
    {
        deckList.at(i).write(fout);
    }
    fout.close();
}

void loadDeck(Deck &deck, cardDatabase database)
{
    ifstream inFS;
    string fileName;
    cout << "Enter deck list to load: ";
    getline(cin, fileName);
    inFS.open(fileName);
    if (!inFS.is_open())
    {
        cout << "Could not open file " << fileName << endl;
        exit(-1);
    }
    while (inFS.good())
    {
        Card card;
        card.read(inFS);
        if (inFS.good())
        {
            string cardType = database.getCardType(card.getName());
            card.setCardType(cardType);
            deck.addCard(card);
        }
    }
    string change = "_deck.txt";
    size_t found = fileName.find(change);
    string deckType = fileName.replace(found, change.length(), "");
    deck.setDeckType(deckType);

    inFS.close();
    cout << "\nDeck has been successfully loaded.\n";
}