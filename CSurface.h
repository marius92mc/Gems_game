#ifndef _CSURFACE_H_INCLUDED_
    #define _CSURFACE_H_INCLUDED_

#include <SDL/SDL.h>
#include "SDL_image.h"

class CSurface
{
    public:
        CSurface();

        static SDL_Surface* onLoad(char*);
        static bool onDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};



#endif // _CSURFACE_H_INCLUDED_
