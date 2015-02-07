#include "CSurface.h"
#include "SDL_image.h"

CSurface::CSurface()
{
}

SDL_Surface* CSurface::onLoad(char* file)
{
    SDL_Surface* surf_temp = NULL;
    SDL_Surface* surf_return = NULL;

    if  ((surf_temp = IMG_Load(file)) == NULL)
        return NULL;

    surf_return = SDL_DisplayFormatAlpha(surf_temp);
    SDL_FreeSurface(surf_temp);

    return surf_return;
}

                // surf_dest is the surface we are going to draw on
                // surf_src is the surface we use to draw on another surface
                // X and Y are the coordinates of the surf_dest where we are drawing
bool CSurface::onDraw(SDL_Surface* surf_dest, SDL_Surface* surf_src, int X, int Y)
{
    if (surf_dest == NULL || surf_src == NULL)
        return false;

    SDL_Rect dest_r;

    dest_r.x = X;
    dest_r.y = Y;

    SDL_BlitSurface(surf_src, NULL, surf_dest, &dest_r);

    return true;
}
