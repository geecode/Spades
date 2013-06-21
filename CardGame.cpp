/*
    Author:  Juan P. Alvarado
    
    Date: 
    
    Description:

    Changes:

*/

#include "stdafx.h"
#include "CardGame.h"
#include "headers.h"
#include "ObjectManager.h"
#include "PlayerHand.h"
#include "HandGFX.h"
#include "GFX.h"

//namespace Spades
//{
    void CardGame::start()
    {
        if ( _gameState != UNINITIALIZED )
            return;
 
        _window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 ), "Spades" );

        /*_deckOfCards *_deck = &__deck;*/

        _deck.shuffle();

        Spades::Player *player1 = new Spades::Player( "player1", 1 );
        Spades::Player *player2 = new Spades::Player( "player2", 2 );
        Spades::Player *player3 = new Spades::Player( "player3", 3 );
        Spades::Player *player4 = new Spades::Player( "player4", 4 );

        while ( _deck.moreCards() )
        {
            player1->takeNextCard( _deck.dealCard() );
            player2->takeNextCard( _deck.dealCard() );
            player3->takeNextCard( _deck.dealCard() );
            player4->takeNextCard( _deck.dealCard() );
        }

        player1->sortHand();
        player2->sortHand();
        player3->sortHand();
        player4->sortHand();

        GFX::HandGFX *playerHand1 = new GFX::HandGFX( player1->playerHand(), player1->playerNumber() );
        GFX::HandGFX *playerHand2 = new GFX::HandGFX( player2->playerHand(), player2->playerNumber() );
        GFX::HandGFX *playerHand3 = new GFX::HandGFX( player3->playerHand(), player3->playerNumber() );
        GFX::HandGFX *playerHand4 = new GFX::HandGFX( player4->playerHand(), player4->playerNumber() );


        _objectManager.Add( playerHand1->hand() );

        _gameState = SHOWING_SPLASH;
   

        while ( !isExiting() )
        {
            gameLoop();
        }   
        delete player1;
        delete player2;
        delete player3;
        delete player4;
        _window.close();
    }

    //sf::RenderWindow CardGame::getWindow()
    //{
    //    return _window;
    //}

    bool CardGame::isExiting()
    {
        if ( _gameState == CardGame::EXITING )
            return true;
        else
            return false;
    }

    void CardGame::gameLoop()
    {
    
        sf::Event currentEvent;
        _window.pollEvent( currentEvent );
    
            switch( _gameState )
            {
            case CardGame::SHOWING_SPLASH:
                {
                    showSplashScreen();
                    break;
                }
            case CardGame::SHOWING_MENU:
                {
                    showMenu();
                    break;
                }
            case CardGame::PLAYING:
                {
                    _window.clear( sf::Color( 30, 120, 20 ) );

                    _objectManager.DrawAll( _window );

                    _window.display();
        
                    if ( currentEvent.type == sf::Event::Closed )
                    {
                        _gameState = CardGame::EXITING;
                        //_music.stop();
                    }
                
                    if ( currentEvent.type == sf::Event::KeyPressed )
                    {
                        if ( currentEvent.key.code == sf::Keyboard::Escape )
                        {
                            //_music.pause();
                            showMenu();
                   
                        }
                    } 
           
                break;
            }
        }
    }

    void CardGame::showSplashScreen()
    {
        GFX::SplashScreen splashScreen;
        splashScreen.show( _window );
        _gameState = CardGame::SHOWING_MENU;
    }

    void CardGame::showMenu()
    {
        GFX::MainMenu menu;
        GFX::MainMenu::MenuResult result = menu.show( _window );
        switch ( result )
        {
        case GFX::MainMenu::EXIT:
            _gameState = EXITING;
            //_music.stop();
            break;
        case GFX::MainMenu::PLAY:
            _gameState = PLAYING;
           // _music.play();
            break;
        }
    }
//}
    CardGame::GameState CardGame::_gameState = UNINITIALIZED;
    sf::RenderWindow CardGame::_window;
    GFX::ObjectManager CardGame::_objectManager;
    Spades::DeckOfCards CardGame::_deck;
    //PlayerHand CardGame::_playerHand1;
    //Player CardGame::_player1;
    //Player CardGame::_player2;
    //Player CardGame::_player3;
    //Player CardGame::_player4;
    /*Player *player1 = new Player( "player1", 1 );
    Player *player2 = new Player( "player2", 2 );
    Player *player3 = new Player( "player3", 3 );
    Player *player4 = new Player( "player4", 4 );

    _deck.shuffle();

    

    player1->sortHand();
    player2->sortHand();
    player3->sortHand();
    player4->sortHand();

    PlayerHand *pPlayer1_Hand = new PlayerHand( player1->playerHand(), player1->playerNumber() );
    PlayerHand *pPlayer2_Hand = new PlayerHand( player2->playerHand(), player2->playerNumber() );
    PlayerHand *pPlayer3_Hand = new PlayerHand( player3->playerHand(), player3->playerNumber() );
    PlayerHand *pPlayer4_Hand = new PlayerHand( player4->playerHand(), player4->playerNumber() );

    _playerHand1 = *pPlayer1_Hand;
    
    _objectManager.Add( "player1", pPlayer1_Hand );
    _objectManager.Add( "player2", pPlayer2_Hand );
    _objectManager.Add( "player3", pPlayer3_Hand );
    _objectManager.Add( "player4", pPlayer4_Hand );*/