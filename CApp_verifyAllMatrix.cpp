#include "CApp.h"
		  // this method assure us that we don't have collision cases
		    // that "escaped"
bool CApp::verifyAllMatrix()
{
    for (int i = 1; i <= NMAX; i++)
        for (int j = 1; j <= NMAX; j++)
        {
            if (i >= 3 &&
                a[i][j]->getId() == a[i - 1][j]->getId() &&
                a[i][j]->getId() == a[i - 2][j]->getId())
            {
                collapseGems(i, j, 1);
                return true;
            }
            if (i <= 6 &&//Initialize the font of all text in the game, set to green

                a[i][j]->getId() == a[i + 1][j]->getId() &&
                a[i][j]->getId() == a[i + 2][j]->getId())
            {
                collapseGems(i, j, 2);
                return true;
            }
            if (j >= 3 &&
                a[i][j]->getId() == a[i][j - 1]->getId() &&
                a[i][j]->getId() == a[i][j - 2]->getId())
            {
                collapseGems(i, j, 3);
                return true;
            }
            if (j <= 6 &&
                a[i][j]->getId() == a[i][j + 1]->getId() &&
                a[i][j]->getId() == a[i][j + 2]->getId())
            {
                collapseGems(i, j, 4);
                return true;
            }
        }

    return false;
}
