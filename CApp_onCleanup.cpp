#include "CApp.h"

void CApp::onCleanup()
{
    for (int i = 1; i <= NMAX; i++)
         for (int j = 1; j <= NMAX; j++)
              SDL_FreeSurface(surfaces[i][j]);

    SDL_FreeSurface(surf_test);
    SDL_FreeSurface(surf_display);
    SDL_Quit();
}
