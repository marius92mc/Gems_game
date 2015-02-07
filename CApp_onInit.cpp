#include "CApp.h"
#include "CGem.h"
#include <cstdlib>
#include <ctime>

bool CApp::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    if ((surf_display = SDL_SetVideoMode(755, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
        return false;
    if ((surf_test = CSurface::onLoad("BackGround.jpg")) == NULL)
        return false;

    srand(time(NULL));                          // important for randomness

                        // Initialize matrix of gems on the background
    for (int i = 1; i <= NMAX; i++)
        for (int j = 1; j <= NMAX; j++)
        {
            a[i][j]->setX(365 + (j - 1) * 35);
            a[i][j]->setY(130 + (i - 1) * 36);

                                                  // random step
            a[i][j]->setId(rand() % 5 + 1);

                                            // we make sure that we haven't generated already a configuration that needs collapse

            if (i >= 3 && j >= 3)
                do
                    a[i][j]->setId(rand() % 5 + 1);
                while (a[i-2][j]->getId() == a[i][j]->getId() || a[i][j-2]->getId() == a[i][j]->getId());

            if (i >= 3 && j < 3)
                do
                    a[i][j]->setId(rand() % 5 + 1);
                while (a[i-2][j]->getId() == a[i][j]->getId());

            if (j >= 3 && i < 3)
                do
                    a[i][j]->setId(rand() % 5 + 1);
                while (a[i][j-2]->getId() == a[i][j]->getId());

                                            // from here we make the connection between id and the actual name of gem picture
            putGem(i, j);
        }

    return true;
}
