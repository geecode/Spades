// DeckOfCards.h - class definition for class DeckOfCards

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <vector>

namespace Spades
{
    class DeckOfCards 
    {
    public:
	    DeckOfCards();
	    void shuffle();
	    Card dealCard();
	    bool moreCards();
        void showDeck() const;
        void showNextCard();

    private:
	    std::vector< Card > _deck;
	    int currentCard;
    };

}

#endif