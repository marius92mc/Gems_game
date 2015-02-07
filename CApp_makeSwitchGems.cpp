#include "CApp.h"

bool CApp::makeSwitchGems()
{
   int aux;

    aux = a[neighbour1.x][neighbour1.y]->getId();
    a[neighbour1.x][neighbour1.y]->setId(a[neighbour2.x][neighbour2.y]->getId());
    a[neighbour2.x][neighbour2.y]->setId(aux);

    putGem(neighbour1.x, neighbour1.y);
    putGem(neighbour2.y, neighbour2.y);

    return true;
}
