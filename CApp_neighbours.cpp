#include "CApp.h"

bool CApp::neighbours(COORDS a, COORDS b)
{
    int a_position_in_matrix_C = ((a.x - 365) / 35) + 1; // first gem's column number in matrix
    int a_position_in_matrix_R = ((a.y - 130) / 36) + 1; // first gem's row number in matrix

    int b_position_in_matrix_C = ((b.x - 365) / 35) + 1;  // second gem's column number in matrix
    int b_position_in_matrix_R = ((b.y - 130) / 36) + 1;  // second gem's row number in matrix

                // first we have to make sure that positions are real, aka >= 1 and <= 8

    if (a_position_in_matrix_R < 1 || a_position_in_matrix_R > 8 ||
        a_position_in_matrix_C < 1 || a_position_in_matrix_C > 8 ||
        b_position_in_matrix_R < 1 || b_position_in_matrix_R > 8 ||
        b_position_in_matrix_C < 1 || b_position_in_matrix_C > 8)

        return false;

    if (a_position_in_matrix_R == b_position_in_matrix_R &&             // neighbours on the same row
        abs(a_position_in_matrix_C - b_position_in_matrix_C) == 1)
    {
        neighbour1.x = a_position_in_matrix_R;
        neighbour1.y = a_position_in_matrix_C;
        neighbour2.x = b_position_in_matrix_R;
        neighbour2.y = b_position_in_matrix_C;
        return true;
    }

    if (a_position_in_matrix_C == b_position_in_matrix_C &&              // neighbours on the same column
        abs(a_position_in_matrix_R - b_position_in_matrix_R) == 1)
    {
        neighbour1.x = a_position_in_matrix_R;
        neighbour1.y = a_position_in_matrix_C;
        neighbour2.x = b_position_in_matrix_R;
        neighbour2.y = b_position_in_matrix_C;
        return true;
    }
        
    return false;
}
