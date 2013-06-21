/*
    Author:   Juan P. Alvarado
    
    Date:     June 16, 2013          
    
    Description:  Game class - runs game loop

    Changes:

*/

#ifndef CARDGAME_H
#define CARDGAME_H

#include "stdafx.h"
#include "DeckOfCards.h"
#include "Player.h"
#include "ObjectManager.h"
#include "PlayerHand.h"

//namespace Spades
//{
    class CardGame
    {
    public:
        /*const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;*/
   
        static void start();
        //static sf::RenderWindow getWindow();
    private:
        static bool isExiting();
        static void gameLoop();

        static void showSplashScreen();
        static void showMenu();

        enum GameState { 
            UNINITIALIZED, SHOWING_SPLASH, PAUSED,
            SHOWING_MENU, PLAYING, EXITING };

        static GameState _gameState;
        static sf::RenderWindow _window;
        static GFX::ObjectManager _objectManager;
        //static sf::Music _music;
        static Spades::DeckOfCards _deck;
        //static Spades::PlayerHand _playerHand1;
        /*static Player _player1;
        static Player _player2;
        static Player _player3;
        static Player _player4;*/
    };
//}
        
#endif