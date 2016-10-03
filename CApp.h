#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL/SDL.h>
#include <iostream>
#include <cmath>
#include <vector>
#include "CSurface.h"
#include "CGem.h"
#include "CEvent.h"

using namespace std;

const int NMAX = 8;

class CApp : public CEvent
{                   // variables are private by default
    bool running;
    long int points;

    SDL_Surface* surf_display;

    SDL_Surface* surf_test;

    CGem* a[NMAX + 1][NMAX + 1];

    SDL_Surface* surfaces[NMAX + 1][NMAX + 1];

    COORDS click_coords, neighbour1, neighbour2; // click_coords are the coords on the map
                                       // neighbour1, neoghbour2 are the positions in the matrix of the two neighbour gems
    vector<COORDS> selected_gems;

    public:
        CApp();             // constructor
        ~CApp();            // destructor
        int onExecute();

        bool onInit();
        COORDS onEvent(SDL_Event*);
        void onLoop();
        bool onRender();
        void onCleanup();

        void onExit();

        bool putGem(int, int);

        bool neighbours(COORDS, COORDS);

        bool collapseCase();

        bool makeSwitchGems();

        bool collapseGems(int, int, int); // x, y, z, where z is 1 for up, 2 for down, 3 for left, 4 for right

        bool verifyAllMatrix();
};

#endif
