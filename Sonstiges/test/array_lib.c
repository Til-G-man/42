#include <stdio.h>


typedef struct
{
	int	x;
	int	y;
	int	z;
	int	***array;
} s_array3d;

s_array3d	array3d_init(int x, int y, int z, int ***array)
{
	s_array3d    result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.array = array;
	return result;
}

//void array3d_print_recursive(s_array3d *array, int i, int j, int k)
//{
//	if (k < array->z)
//	{
//        printf("%i ", *(array->array)[i][j][k]);
//		array3d_print_recursive(array, i, j, k + 1);
//	}
//	else if (j < array->y - 1)
//	{
//		printf("\n");
//		array3d_print_recursive(array, i, j + 1, 0);
//	}
//	else if (i < array->x - 1)
//	{
//		printf("\n\n");
//		array3d_print_recursive(array, i + 1, 0, 0);
//	}
//}

void	array3d_print(s_array3d *array)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	printf("[[[");
	while (array->array[x][y][z])
	{
		printf("%i, ", array->array[x][y][z]);
        z++;
        if (z == array->z)
        {
            z = 0;
            x++;
            if (x == array->x)
            {
                printf("]],\n[[");
				x = 0;
                y++;
            }
			else
				printf("], [");
        }
	}
	printf("]]]\n");
}
int	main()
{
	int	array[4][3][3] =
	{
		{{1,2,3}, {4,5,6}, {7,8,9}},
		{{10,11,12}, {13,14,15}, {16,17,18}},
		{{19,20,21}, {22,23,24}, {25,26,27}},
		{{28,29,30}, {31,32,33}, {34,35,36}},
	};
	s_array3d	array_struct = array3d_init(4, 3, 3, array);

	printf("x: %i, y: %i, z: %i\n", array_struct.x, array_struct.y, array_struct.z);
	printf("arra_struct->array[0][0][0]: '%ls'", array_struct.array[0][0][0]);
	//array3d_print(&array_struct);
	return (0);
}