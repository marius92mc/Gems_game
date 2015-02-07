#include "CApp.h"
                                    // this method actually makes the connection
bool CApp::putGem(int i, int j)  // between id and actual name of the gem picture
{
    if (a[i][j]->getId() == 1)
    {
        if ((surfaces[i][j] = a[i][j]->onLoad("Blue.png")) == NULL)
            return false;
    }

    if (a[i][j]->getId() == 2)
    {
        if ((surfaces[i][j] = a[i][j]->onLoad("Green.png")) == NULL)
            return false;
    }

    if (a[i][j]->getId() == 3)
    {
        if ((surfaces[i][j] = a[i][j]->onLoad("Purple.png")) == NULL)
            return false;
    }

    if (a[i][j]->getId() == 4)
    {
        if ((surfaces[i][j] = a[i][j]->onLoad("Red.png")) == NULL)
            return false;
    }

    if (a[i][j]->getId() == 5)
    {
        if ((surfaces[i][j] = a[i][j]->onLoad("Yellow.png")) == NULL)
            return false;
    }

    return true;
}
