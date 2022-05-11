#ifndef CARD_H
#define CARD_H

using namespace std;

class Card
{
public:
    Card();
    Card(string name, string cardType, string pokemonType);
    void setName(string name);
    string getName() const;
    void setCardType(string cardType);
    string getCardType() const;
    void setPokemonType(string pokemonType);
    string getPokemonType() const;
    void write(ofstream &fout) const;
    void read(ifstream &fin);

private:
    string _name;
    string _cardType;
    string _pokemonType;
};

#endif