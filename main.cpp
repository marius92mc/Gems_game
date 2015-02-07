#include <iostream>
#include "CApp.h"

using namespace std;

CApp::CApp() : selected_gems()        // ": selected_gems()" not quite necessary
{
    click_coords.x = -1;
    click_coords.y = -1;

    surf_display = NULL;
    surf_test = NULL;

    points = 0;

    for (int i = 0; i < 9; i++)
         for (int j = 0; j < 9; j++)
         {
             a[i][j] = new CGem;

             surfaces[i][j] = NULL;
         }

    running = true;
}

int CApp::onExecute()
{
    if (onInit() == false)
        return -1;

    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            click_coords = onEvent(&event);
            if (click_coords.x >= 0 && click_coords.y >= 0)
            {
                selected_gems.push_back(click_coords);
            }
        }

        onLoop();

        if (onRender() == false)
            running = false;
    }

    onCleanup();

    return 0;
}

CApp::~CApp()
{
    for (int i = 0; i < 9; i++)
         for (int j = 0; j < 9; j++)
              delete a[i][j];
}

int main(int argc, char* argv[])
{
    CApp the_app;

    return the_app.onExecute();
}
