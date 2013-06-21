// Member function definitions for class DeckOfCards

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Card.h"
#include "DeckOfCards.h"

namespace Spades
{
    DeckOfCards::DeckOfCards()
    {
        for ( int i = Card::HEARTS; i <= Card::SPADES; ++i )
	    {
		    for ( int j = Card::TWO; j <= Card::ACE; ++j )
		    {            
			    _deck.push_back( Card( j, i ) );
		    }
	    }
    }

    void DeckOfCards::shuffle()
    {
	    for ( int i = 0; i < 3; ++i )
        {
            srand( unsigned (time ( 0 ) ) );

	        for ( unsigned int k = 0; k < _deck.size(); ++k )
	        {
		        int key = rand() % 52;
		        std::swap( _deck[ k ], _deck[ key ] );
	        }
        }
    }

    Card DeckOfCards::dealCard()
    {
        Card nextCard = _deck.front();
        _deck.erase( _deck.begin() );    
        return nextCard;     
    }

    bool DeckOfCards::moreCards()
    {
        if ( !_deck.empty() )
            return true;
        else
            return false;
    }

    void DeckOfCards::showDeck() const
    {
        int i = 1;
        for ( std::vector< Card >::const_iterator it = _deck.begin();
              it != _deck.end(); ++it )
        {
              Card card = *it;
              std::cout << i << "  " << card.cardName() << std::endl;
              ++i;
        }
    }

}    
    
