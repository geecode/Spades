// member function definitions for Player class
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Card.h"
#include "CardGame.h"

namespace Spades
{
    Player::Player( std::string playerName, int playerNumber )
        : _booksMade( 0 ),
          _bid( 0 ),
          _hearts( 0 ),
          _clubs( 0 ),
          _diamonds( 0 ),
          _spades( 0 ),
          _playerName( playerName ),
          _playerNumber( playerNumber )
    {
    }

    Player::~Player()
    {
    }

    void Player::takeNextCard( Card &c )
    {
    
        _playerHand.push_back( c );
    }

    void Player::sortSuits()
    {   
        int index = 0;

        // place hearts together
        for ( int i = 0; i < _playerHand.size(); ++i )
        {       
            if ( _playerHand[ i ].suit() == "Hearts" )
            {
            
                std::swap( _playerHand[ i ], _playerHand[ index ] ); 
                ++index;
                ++_hearts;
            }        
        }
    
        // place clubs together
        for ( int j = index; j < _playerHand.size(); ++j )
        {       
            if ( _playerHand[ j ].suit() == "Clubs" )
            {
            
                std::swap( _playerHand[ j ], _playerHand[ index ] ); 
                ++index;
                ++_clubs;
            }        
        }

        // place diamonds together
        for ( int k = index; k< _playerHand.size(); ++k )
        {       
            if ( _playerHand[ k ].suit() == "Diamonds" )
            {
            
                std::swap( _playerHand[ k ], _playerHand[ index ] ); 
                ++index;
                ++_diamonds;
            }        
        }

        // place spades together
        for ( int l = 0; l < _playerHand.size(); ++l )
        {       
            if ( _playerHand[ l ].suit() == "Spades" )
            {
            
                std::swap( _playerHand[ l ], _playerHand[ index ] ); 
                ++index;
                ++_spades;
            }        
        }
    }

    void Player::sortHand()
    {
        this->sortSuits();
        int size = _hearts;
        int index = _hearts;
    
        // sort hearts
        for ( int i = 0; i < size; ++i )
        {
            while ( size )
            {            
                for ( int counter = 1; counter < index; ++counter )
                {
                    if ( _playerHand[ counter ].faceValue() 
                        <  _playerHand[ counter - 1 ].faceValue() )
                    {
                    
                        std::swap( _playerHand[ counter ], _playerHand[ counter - 1 ] );
                    }
                }
                --size;
            }
        }

        int begin = _hearts;
        size = _clubs;
        index += _clubs;
    
        // sort clubs
        for ( int j = begin; j < begin + size; ++j )
        {
            while ( size )
            {            
                for ( int counter = begin + 1; counter < index; ++counter )
                {
                    if ( _playerHand[ counter ].faceValue() 
                        <  _playerHand[ counter - 1 ].faceValue() )
                    {
                    
                        std::swap( _playerHand[ counter ], _playerHand[ counter - 1 ] );
                    }
                }
                --size;
            }
        }

        begin += _clubs;
        size = _diamonds;
        index += _diamonds;

        // sort diamonds
        for ( int k = begin; k < begin + size; ++k )
        {       
            while ( size )
            {            
                for ( int counter = begin + 1; counter < index; ++counter )
                { 
                    if ( _playerHand[ counter ].faceValue() 
                        <  _playerHand[ counter - 1 ].faceValue() )
                    {
                    
                        std::swap( _playerHand[ counter ], _playerHand[ counter - 1 ] );
                    }
                }
                --size;
            }
        }

        begin += _diamonds;
        size = _spades;
        index += _spades;
    
        // sort spades
        for ( int l = begin; l < begin + size; ++l )
        {       
            while ( size )
            {
            
                for ( int counter = begin + 1; counter < index; ++counter )
                { 
                    if ( _playerHand[ counter ].faceValue() 
                        <  _playerHand[ counter - 1 ].faceValue() )
                    {
                    
                        std::swap( _playerHand[ counter ], _playerHand[ counter - 1 ] );
                    }
                }
                --size;
            }
        }
    }

    std::vector< Card > Player::playerHand() const
    {
        return _playerHand;
    }

    int Player::playerNumber() const
    {
        return _playerNumber;
    }
}