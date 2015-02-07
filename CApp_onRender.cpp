#include "CApp.h"

bool CApp::onRender()
{
    if (CSurface::onDraw(surf_display, surf_test, 0, 0) == NULL) // last 2 params represent the coordinates
        return false;



    for (int i = 1; i <= NMAX; i++)
        for (int j = 1; j <= NMAX; j++)
            if (a[i][j]->onDraw(surf_display, surfaces[i][j], a[i][j]->getX(), a[i][j]->getY()) == NULL)
               return false;



    SDL_Flip(surf_display);

    return true;
}
