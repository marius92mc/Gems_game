#include "CApp.h"

COORDS CApp::onEvent(SDL_Event* event)
{
    return CEvent::onEvent(event);
}

void CApp::onExit()
{
    running = false;
    cout << "\n\n\t/*************************/\n";
    cout <<"\t *                       *\n";
    cout <<"\t *                       *\n";

    cout << "\t    Total Score : " << points << " .    \n";

    cout <<"\t *                       *\n";
    cout <<"\t *                       *\n";
    cout << "\t/*************************/\n\n\n";
}
