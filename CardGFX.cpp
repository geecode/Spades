#include "stdafx.h"
#include "CardGFX.h"
#include "VisibleObject.h"

namespace GFX
{
    CardGFX::CardGFX( std::string filename, std::string cardName )
        : _cardName( cardName )
    {
        load( filename );
        scaleSprite( 0.125f, 0.125f );
    }

    CardGFX::~CardGFX()
    {
    }

    std::string CardGFX::cardName() const
    {
        return _cardName;
    }
}
