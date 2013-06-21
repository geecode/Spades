#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "VisibleObject.h"
#include "CardGFX.h"

namespace GFX
{
    class ObjectManager
    {
    public:
        ObjectManager();
        ~ObjectManager();

        void Add( VisibleObject* gameObject );
        void Add( std::vector< GFX::CardGFX* > gameObjects );
        void Remove( std::string name );
        int getObjectCount() const;
        VisibleObject* Get( std::string name ) const;

        void DrawAll( sf::RenderWindow &window );
    private:
        std::vector< VisibleObject* > _gameObjects;

        struct ObjectDeallocator
        {
            void operator() ( VisibleObject* p ) const
            {
                delete p;
            }
        };
    };

}


#endif