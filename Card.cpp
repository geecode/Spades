// Member function definitions for class Card

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Card.h"

namespace Spades
{
    const std::string Card::_faces[ 13 ] = 
	      { "two", "three", "four", "five","six", "seven",
	         "eight", "nine", "ten", "jack", "queen","king", "ace" };
    const std::string Card::_suits[ 4 ] = 
	      { "Hearts", "Clubs", "Diamonds", "Spades" };

    Card::Card()
    {
    }

    Card::Card( int f, int s )
    {
	    _face = f;
	    _suit = s;
        _filename = "images\\" + _faces[ _face ] + "Of" + _suits[ _suit ] + ".png";

        _cardName = _faces[ _face ] + " Of " + _suits[ _suit ];
        _cardName.front() = toupper( _cardName.front() );

    }
    Card::~Card()
    {
    }

    int Card::faceValue() const
    {
        return _face;
    }

    std::string Card::filename() const
    {
        return _filename;
    }

    std::string Card::cardName() const
    {
        return _cardName;
    }

    std::string Card::face() const
    {
       return _faces[ _face ];
    }

    std::string Card::suit() const
    {
       return _suits[ _suit ];
    }
}
