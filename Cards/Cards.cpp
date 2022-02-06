#include "Cards.h"
#include <experimental/random>

// ======================== Deck class ========================

Deck::Deck() = default;

Deck::Deck(const Deck &deck) {
    for (Card* card : cards) {
        Card* c = card->clone(); // create a deep copy of card objects
        this->cards.push_back(c);
    }
}

Deck &Deck::operator=(const Deck &deck) {
    // Check if the current object and the passed object is the same
    if (this == &deck) return *this;

    // Deallocate all the memory associated with this Deck of cards
    for (const Card* card : this->cards) {
        delete card;
        card = nullptr;
    }
    this->cards.clear();

    for (Card* card : deck.cards) {
        Card* c = card->clone(); // create a deep copy of card objects
        this->cards.push_back(c);
    }
    return *this;
}

ostream& operator<<(ostream &out, const Deck &deck) {
    for (const Card* c : deck.cards) {
        out << *c << endl;
    }
    return out;
}

Card* Deck::draw() {
    // randomly draw a card from the deck, remove it from the deck and return a pointer to that card
    int nbrOfCards = this->cards.size()-1;
    int random = experimental::randint(0, nbrOfCards);
    Card* c =this->cards.at(random);
    this->cards.erase(this->cards.begin() + random);
    return c;
}

Deck::~Deck() {
    for (const Card* card : cards) {
        delete card;
        card = nullptr;
    }
}

// ======================== Hand class ========================

Hand::Hand() = default;

Hand::Hand(const Hand &hand) {
    for (Card* card : hand.cards) {
        Card* c = card->clone(); // create a deep copy of card objects
        this->cards.push_back(c);
    }
}

Hand &Hand::operator=(const Hand &hand) {
    if (this ==  &hand) return *this;

    // Deallocate all the memory associated with this Hand of cards
    for (const Card* card : this->cards) {
        delete card;
        card = nullptr;
    }
    this->cards.clear();
    for (Card* card : hand.cards) {
        Card* c = card->clone(); // create a deep copy of card objects
        this->cards.push_back(c);
    }
    return *this;
}

ostream &operator<<(ostream &out, const Hand &hand) {
    for (const Card* c : hand.cards) {
        out << *c << endl;
    }
    return out;
}

Hand::~Hand() {
    for (const Card* card : this->cards) {
        delete card;
        card = nullptr;
    }
}

// ======================== Card class ========================

ostream &operator<<(ostream &out, const Card &card) {
    out << "Card type: " << card.getType() << endl;
    return out;
}

Card::~Card() = default;

// ======================== Bomb class ========================

Bomb::Bomb() = default;

Bomb::Bomb(const Bomb &bomb) {
    this->type = bomb.type;
}

Bomb& Bomb::operator=(const Bomb &bomb) {
    if (this == &bomb) return *this;
    this->type = bomb.type;
    return *this;
}

string Bomb::getType() const {
    return this->type;
}

Card* Bomb::clone() {
    return new Bomb(*this);
}

void Bomb::play() {

}

Bomb::~Bomb() = default;


// ======================== Reinforcement class ========================

Reinforcement::Reinforcement() = default;

Reinforcement::Reinforcement(const Reinforcement &r) {
    this->type = r.type;
}

Reinforcement &Reinforcement::operator=(const Reinforcement &r) {
    if (this == &r) return *this;
    this->type = r.type;
    return *this;
}

string Reinforcement::getType() const {
    return this->type;
}

void Reinforcement::play() {

}

Card *Reinforcement::clone() {
    return new Reinforcement(*this);
}

Reinforcement::~Reinforcement() = default;

// ======================== Blockade class ========================

Blockade::Blockade() = default;

Blockade::Blockade(const Blockade &blockade) {
    this->type = blockade.type;
}

Blockade &Blockade::operator=(const Blockade &blockade) {
    if (this == &blockade) return *this;
    this->type = blockade.type;
    return *this;
}

string Blockade::getType() const {
    return this->type;
}

void Blockade::play() {

}

Card *Blockade::clone() {
    return new Blockade(*this);
}

Blockade::~Blockade() = default;

// ======================== Airlift class ========================

Airlift::Airlift() = default;

Airlift::Airlift(const Airlift &airlift) {
    this->type = airlift.type;
}

Airlift &Airlift::operator=(const Airlift &airlift) {
    if (this == &airlift) return *this;
    this->type = airlift.type;
    return *this;
}

string Airlift::getType() const {
    return this->type;
}

void Airlift::play() {

}

Card *Airlift::clone() {
    return new Airlift(*this);
}

Airlift::~Airlift() = default;

// ======================== Diplomacy class ========================

Diplomacy::Diplomacy() = default;

Diplomacy::Diplomacy(const Diplomacy &diplomacy) {
    this->type = diplomacy.type;
}

Diplomacy &Diplomacy::operator=(const Diplomacy &diplomacy) {
    if (this == &diplomacy) return *this;
    this->type = diplomacy.type;
    return *this;
}

string Diplomacy::getType() const {
    return this->type;
}

void Diplomacy::play() {

}

Card *Diplomacy::clone() {
    return new Diplomacy(*this);
}

Diplomacy::~Diplomacy() = default;

