// class definition for card graphics image

#ifndef CARDGFX_H
#define CARDGFX_H

#include "stdafx.h"
#include "VisibleObject.h"

namespace GFX
{
    class CardGFX : public VisibleObject
    {
    public:
        CardGFX( std::string filename, std::string cardName );
        ~CardGFX();
        std::string cardName() const;
    private:
        std::string _cardName;
    };
}

#endif