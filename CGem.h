#ifndef _CGEM_H_INCLUDED_
    #define _CGEM_H_INCLUDED_

#include <SDL/SDL.h>
#include "SDL_image.h"

class CGem
{
    int id; // 1 = Blue, 2 = Green, 3 = Purple, 4 = Red, 5 = Yellow
    int x, y;

    public:
        CGem();

        SDL_Surface* onLoad(char*);
        bool onDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

        bool setId(int);
        int getId();

        bool setX(int);
        int getX();

        bool setY(int);
        int getY();

};





#endif // _CGEM_H_INCLUDED_
