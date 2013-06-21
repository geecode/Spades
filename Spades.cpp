#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <SFML\Audio.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "Card.h"
#include "DeckOfCards.h"
#include "Player.h"
#include "headers.h"
#include "CardGame.h"
using namespace std;

int main()
{
    
  CardGame::start();
             
	system( "pause" );

    return EXIT_SUCCESS;
}

