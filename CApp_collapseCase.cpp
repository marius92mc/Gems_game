#include "CApp.h"

bool CApp::collapseCase()
{
            // try switch gems to see what happens
    makeSwitchGems();

            // first try collapse for first neighbour, after the above switch gems
    if (neighbour1.x >= 3 &&
        a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x-1][neighbour1.y]->getId() &&
        a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x-2][neighbour1.y]->getId())
    {
        verifyAllMatrix();
        collapseGems(neighbour1.x, neighbour1.y, 1);
        return true;
    }
    else
        if (neighbour1.x <= 6 &&
            a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x+1][neighbour1.y]->getId() &&
            a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x+2][neighbour1.y]->getId())
        {
            verifyAllMatrix();
            collapseGems(neighbour1.x, neighbour1.y, 2);
            return true;
        }
        else
            if (neighbour1.y >= 3 &&
                a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x][neighbour1.y-1]->getId() &&
                a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x][neighbour1.y-2]->getId())
            {
                verifyAllMatrix();
                collapseGems(neighbour1.x, neighbour1.y, 3);
                return true;
            }
            else
                if (neighbour1.y <= 6 &&
                    a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x][neighbour1.y+1]->getId() &&
                    a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x][neighbour1.y+2]->getId())
                {
                    verifyAllMatrix();
                    collapseGems(neighbour1.x, neighbour1.y, 4);
                    return true;
                }

                // now we try for the second neighbour

    if (neighbour2.x >= 3 &&
        a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x-1][neighbour2.y]->getId() &&
        a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x-2][neighbour2.y]->getId())
    {
        verifyAllMatrix();
        collapseGems(neighbour2.x, neighbour2.y, 1);
        return true;
    }
    else
        if (neighbour2.x <= 6 &&
            a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x+1][neighbour2.y]->getId() &&
            a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x+2][neighbour2.y]->getId())
        {
            verifyAllMatrix();
            collapseGems(neighbour2.x, neighbour2.y, 2);
            return true;
        }
        else
            if (neighbour2.y >= 3 &&
                a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x][neighbour2.y-1]->getId() &&
                a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x][neighbour2.y-2]->getId())
            {
                verifyAllMatrix();
                collapseGems(neighbour2.x, neighbour2.y, 3);
                return true;
            }
            else
                if (neighbour2.y <= 6 &&
                    a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x][neighbour2.y+1]->getId() &&
                    a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x][neighbour2.y+2]->getId())
                {
                    verifyAllMatrix();
                    collapseGems(neighbour2.x, neighbour2.y, 4);
                    return true;
                }

                            // case when the switched gem goes in the middle of the 3, minimum 3
                    // for first neighbour
    if (neighbour1.x >= 2 && neighbour1.x <= 7 &&
        a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x-1][neighbour1.y]->getId() &&
        a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x+1][neighbour1.y]->getId())
    {
        verifyAllMatrix();
        collapseGems(neighbour1.x, neighbour1.y, 5);
        return true;
    }

    if (neighbour1.y >= 2 && neighbour1.y <= 7 &&
        a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x][neighbour1.y-1]->getId() &&
        a[neighbour1.x][neighbour1.y]->getId() == a[neighbour1.x][neighbour1.y+1]->getId())
    {
        verifyAllMatrix();
        collapseGems(neighbour1.x, neighbour1.y, 6);
        return true;
    }


                // for second neighbour, last case
    if (neighbour2.x >= 2 && neighbour2.x <= 7 &&
        a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x-1][neighbour2.y]->getId() &&
        a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x+1][neighbour2.y]->getId())
    {
        verifyAllMatrix();
        collapseGems(neighbour2.x, neighbour2.y, 5);
        return true;
    }

    if (neighbour2.y >= 2 && neighbour2.y <= 7 &&
        a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x][neighbour2.y-1]->getId() &&
        a[neighbour2.x][neighbour2.y]->getId() == a[neighbour2.x][neighbour2.y+1]->getId())
    {
        verifyAllMatrix();
        collapseGems(neighbour2.x, neighbour2.y, 6);
        return true;
    }


                // revert the change made initial, because we couldn't find a collapse case
    makeSwitchGems();

    return false;
}
