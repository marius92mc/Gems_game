#include "CApp.h"

void CApp::onLoop()
{
    if (selected_gems.size() == 2)
    {
        if (neighbours(selected_gems[0], selected_gems[1]))
        {
            if (collapseCase())
                verifyAllMatrix();
        }

        selected_gems.erase(selected_gems.begin(), selected_gems.end()); // erase the vector, so we could fill it
    }                                            // again with the coordinates of two points, given from the user
}
