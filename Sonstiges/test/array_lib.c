#include <stdio.h>

typedef struct
{
    int    x;
    int    y;
    int    z;
    int    ***array;
} s_array3d;

s_array3d    array3d_init(int x, int y, int z, int ***array)
{
    s_array3d    result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.array = array;
    return result;
}

void    array3d_print(s_array3d *array)
{
    int    x = 0;
    int    y = 0;
    int    z = 0;
    int    ***ary = array->array;
    int   *pary;

    printf("[[[");

    while (y < array->y)
    {
        pary = ary[y];
        while (z < array->z)
        {
            printf("%i, ", *pary++);
            z++;
        }

        z = 0;
        x++;

        if (x < array->x)
        {
            printf("]],\n[[");
        }
        else
        {
            printf("]]]\n");
            y++;
            x = 0;
            ary++;
        }
    }
}

int main() {
    int    array[4][3][3] =
    {
        {{1,2,3}, {4,5,6}, {7,8,9}},
        {{10,11,12}, {13,14,15}, {16,17,18}},
        {{19,20,21}, {22,23,24}, {25,26,27}},
        {{28,29,30}, {31,32,33}, {34,35,36}},
    };

    s_array3d    array_struct = array3d_init(4, 3, 3, array);
    array3d_print(&array_struct);

    return 0;
}
