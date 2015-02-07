#include "CApp.h"

bool CApp::collapseGems(int x, int y, int direction)
{
    int number_of_new_gems;

    srand(time(NULL)); 				// we make sure that the random-ness is not influenced

    if (direction == 1)
    {
        int max_length_to_erase = 3;  // find how much gems are the same
        for (int i = x - 3; i >= 1; i--)
            if (a[x][y]->getId() == a[i][y]->getId())
                max_length_to_erase++;
            else
                break;

        for (int i = x; i - max_length_to_erase >= 1; i--)  // move the remaining gems after collapse-ing of max_length_to_erase_gems
        {
            a[i][y]->setId(a[i - max_length_to_erase][y]->getId());
            putGem(i, y);
        }

         // put random gems on the remaining positions
        number_of_new_gems = max_length_to_erase;

                // find the configuration of number_of_new_gems gems that are not in collapse case already
        int configuration[number_of_new_gems + 1]; // indexed from 1 to number_of_new_gems, that's why we need the additional space
        if (number_of_new_gems >= 3)          // to make it easier, I've indexed them from 1, and not from 0, altough from 0 is better
        {
            configuration[1] = rand() % 5 + 1;
            configuration[2] = rand() % 5 + 1;
            for (int i = 3; i <= number_of_new_gems; i++)  // we have to make sure that the configuration of new pieces are
                do                                           // not in collapse case, which is >= 3 same gems
                    configuration[i] = rand() % 5 + 1;
                while (configuration[i] == configuration[i - 1] || configuration[i] == configuration[i - 2]);
        }
        else
            if (number_of_new_gems == 2)
            {
                configuration[1] = rand() % 5 + 1;
                configuration[2] = rand() % 5 + 1;
            }
            else
                configuration[1] = rand() % 5 + 1;

                        // modify the gems' id
        for (int i = 1; i <= number_of_new_gems; i++)
        {
            a[i][y]->setId(configuration[i]);
            putGem(i, y);
        }
    }
    else
        if (direction == 2)
        {
            int max_length_to_erase = 3;  // find how much gems are the same
            for (int i = x + 3; i <= 8; i++)
                if (a[x][y]->getId() == a[i][y]->getId())
                    max_length_to_erase++;
                else
                    break;

            for (int i = x; i + max_length_to_erase <= 8; i++)  // move the remaining gems after collapse-ing of max_length_to_erase_gems
                {
                    a[i][y]->setId(a[i + max_length_to_erase][y]->getId());
                    putGem(i, y);
                }

            // put random gems on the remaining positions
            number_of_new_gems = max_length_to_erase;

                    // find the configuration of number_of_new_gems gems that are not in collapse case already
            int configuration[number_of_new_gems + 1]; // indexed from 1 to number_of_new_gems
            if (number_of_new_gems >= 3)
            {
                configuration[1] = rand() % 5 + 1;
                configuration[2] = rand() % 5 + 1;
                for (int i = 3; i <= number_of_new_gems; i++)
                    do
                        configuration[i] = rand() % 5 + 1;
                    while (configuration[i] == configuration[i - 1] || configuration[i] == configuration[i - 2]);
            }
            else
                if (number_of_new_gems == 2)
                {
                    configuration[1] = rand() % 5 + 1;
                    configuration[2] = rand() % 5 + 1;
                }
                else
                    configuration[1] = rand() % 5 + 1;

                        // modify the gems' id
            for (int i = 1; i <= number_of_new_gems; i++)
            {
                a[9 - i][y]->setId(configuration[i]);
                putGem(9 - i, y);
            }
        }
        else
            if (direction == 3)
            {
                int max_length_to_erase = 3;  // find how much gems are the same
                for (int i = y - 3; i >= 1; i--)
                    if (a[x][y]->getId() == a[x][i]->getId())
                        max_length_to_erase++;
                    else
                        break;

                for (int i = y; i - max_length_to_erase >= 1; i--)  // move the remaining gems after collapse-ing of max_length_to_erase_gems
                {
                    a[x][i]->setId(a[x][i - max_length_to_erase]->getId());
                    putGem(x, i);
                }

                    // put random gems on the remaining positions
                number_of_new_gems = max_length_to_erase;

                        // find the configuration of number_of_new_gems gems that are not in collapse case already
                int configuration[number_of_new_gems + 1]; // indexed from 1 to number_of_new_gems
                if (number_of_new_gems >= 3)
                {
                    configuration[1] = rand() % 5 + 1;
                    configuration[2] = rand() % 5 + 1;
                    for (int i = 3; i <= number_of_new_gems; i++)
                        do
                            configuration[i] = rand() % 5 + 1;
                        while (configuration[i] == configuration[i - 1] || configuration[i] == configuration[i - 2]);
                }
                else
                    if (number_of_new_gems == 2)
                    {
                        configuration[1] = rand() % 5 + 1;
                        configuration[2] = rand() % 5 + 1;
                    }
                    else
                        configuration[1] = rand() % 5 + 1;

                            // modify the gems' id
                for (int i = 1; i <= number_of_new_gems; i++)
                {
                    a[x][i]->setId(configuration[i]);
                    putGem(x, i);
                }
            }
            else
                if (direction == 4)
                {
                    int max_length_to_erase = 3;  // find how much gems are the same
                    for (int i = y + 3; i <= 8; i++)
                        if (a[x][y]->getId() == a[x][i]->getId())
                            max_length_to_erase++;
                        else
                            break;

                    for (int i = y; i + max_length_to_erase <= 8; i++)  // move the remaining gems after collapse-ing of max_length_to_erase_gems
                    {
                        a[x][i]->setId(a[x][i + max_length_to_erase]->getId());
                        putGem(x, i);
                    }

                        // put random gems on the remaining positions
                    number_of_new_gems = max_length_to_erase;

                            // find the configuration of number_of_new_gems gems that are not in collapse case already
                    int configuration[number_of_new_gems + 1]; // indexed from 1 to number_of_new_gems
                    if (number_of_new_gems >= 3)
                    {
                        configuration[1] = rand() % 5 + 1;
                        configuration[2] = rand() % 5 + 1;
                        for (int i = 3; i <= number_of_new_gems; i++)
                            do
                                configuration[i] = rand() % 5 + 1;
                            while (configuration[i] == configuration[i - 1] || configuration[i] == configuration[i - 2]);
                    }
                    else
                        if (number_of_new_gems == 2)
                        {
                            configuration[1] = rand() % 5 + 1;
                            configuration[2] = rand() % 5 + 1;
                        }
                        else
                            configuration[1] = rand() % 5 + 1;

                                // modify the gems' id
                    for (int i = 1; i <= number_of_new_gems; i++)
                    {
                        a[x][9 - i]->setId(configuration[i]);
                        putGem(x, 9 - i);
                    }
                }
                else
                    if (direction == 5)
                    {
                        int max_length_to_erase = 0;  // find how much gems are the same
                        int copy_of_x = x; // first index in the same gem area

                        while (copy_of_x - 1 >= 1 && a[x][y]->getId() == a[copy_of_x - 1][y]->getId())
                            copy_of_x--;

                        for (int i = copy_of_x; a[x][y]->getId() == a[i][y]->getId(); i++)
                            max_length_to_erase++;


                        for (int i = copy_of_x; i + max_length_to_erase <= 8; i++)  // move the remaining gems after collapse-ing of max_length_to_erase_gems
                        {
                            a[i][y]->setId(a[i + max_length_to_erase][y]->getId());
                            putGem(i, y);
                        }

                            // put random gems on the remaining positions
                        number_of_new_gems = max_length_to_erase;

                                // find the configuration of number_of_new_gems gems that are not in collapse case already
                        int configuration[number_of_new_gems + 1]; // indexed from 1 to number_of_new_gems
                        if (number_of_new_gems >= 3)
                        {
                            configuration[1] = rand() % 5 + 1;
                            configuration[2] = rand() % 5 + 1;
                            for (int i = 3; i <= number_of_new_gems; i++)
                                do
                                    configuration[i] = rand() % 5 + 1;
                                while (configuration[i] == configuration[i - 1] || configuration[i] == configuration[i - 2]);
                        }
                        else
                            if (number_of_new_gems == 2)
                            {
                                configuration[1] = rand() % 5 + 1;
                                configuration[2] = rand() % 5 + 1;
                            }
                            else
                                configuration[1] = rand() % 5 + 1;

                                // modify the gems' id
                        for (int i = copy_of_x + number_of_new_gems + 1; i <= 8; i++)
                        {
                            a[i][y]->setId(configuration[i - copy_of_x - number_of_new_gems]);
                            putGem(i, y);
                        }
                    }
                    else
                        if (direction == 6)
                        {
                            int max_length_to_erase = 0;  // find how much gems are the same
                            int copy_of_y = y; // first index in the same gem area

                            while (copy_of_y - 1 >= 1 && a[x][y]->getId() == a[x][copy_of_y - 1]->getId())
                                copy_of_y--;

                            for (int i = copy_of_y; a[x][y]->getId() == a[x][i]->getId(); i++)
                                max_length_to_erase++;


                            for (int i = copy_of_y; i + max_length_to_erase <= 8; i++)  // move the remaining gems after collapse-ing of max_length_to_erase_gems
                            {
                                a[x][i]->setId(a[x][i + max_length_to_erase]->getId());
                                putGem(x, i);
                            }

                                // put random gems on the remaining positions
                            number_of_new_gems = max_length_to_erase;

                                    // find the configuration of number_of_new_gems gems that are not in collapse case already
                            int configuration[number_of_new_gems + 1]; // indexed from 1 to number_of_new_gems
                            if (number_of_new_gems >= 3)
                            {
                                configuration[1] = rand() % 5 + 1;
                                configuration[2] = rand() % 5 + 1;
                                for (int i = 3; i <= number_of_new_gems; i++)
                                    do
                                        configuration[i] = rand() % 5 + 1;
                                    while (configuration[i] == configuration[i - 1] || configuration[i] == configuration[i - 2]);
                            }
                            else
                                if (number_of_new_gems == 2)
                                {
                                    configuration[1] = rand() % 5 + 1;
                                    configuration[2] = rand() % 5 + 1;
                                }
                                else
                                    configuration[1] = rand() % 5 + 1;

                                    // modify the gems' id
                            for (int i = copy_of_y + number_of_new_gems + 1; i <= 8; i++)
                            {
                                a[x][i]->setId(configuration[i - copy_of_y - number_of_new_gems]);
                                putGem(x, i);
                            }
                        }



    while (verifyAllMatrix())
        verifyAllMatrix();

    points += number_of_new_gems * 10; // increase the number of points earned by the player

    return true;
}
