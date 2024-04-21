#include"matching.h"

bool Check_cell(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2)
{
	if (matrix[posx1][posy1] == matrix[posx2][posy2])
	{
		return true;
	}
	else return false;
}

//I matching

bool I_check_vertical(string** matrix, int& posx1, int& posx2, int& posy)
{
	if (posx1 > posx2)
	{
		for (int i = posx1 - 1; i > posx2; i--)
		{
			if (matrix[i][posy] != " ")
				return false;
		}
		return true;
	}

	if (posx1 < posx2)
	{
		for (int i = posx1 + 1; i < posx2; i++)
		{
			if (matrix[i][posy] != " ")
				return false;
		}
		return true;
	}

	return false;
}

bool I_check_horizontal(string** matrix, int& posx, int& posy1, int& posy2)
{
	if (posy1 > posy2)
	{
		for (int i = posy1 - 1; i > posy2; i--)
		{
			if (matrix[posx][i] != " ")
				return false;
		}
		return true;
	}

	if (posy1 < posy2)
	{
		for (int i = posy1 + 1; i < posy2; i++)
		{
			if (matrix[posx][i] != " ")
				return false;
		}
		return true;
	}
	return false;
}

//L matching

bool L_check(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2)
{
	if(posx2 == posx1 + 1)
	{
		if (posy2 == posy1 + 1)
		{
			if (matrix[posx1 + 1][posy1] == " ")
				return true;
			if (matrix[posx1][posy1 + 1] == " ")
				return true;

			return false;
		}

		if (posy2 == posy1 - 1)
		{
			if (matrix[posx1 + 1][posy1] == " ")
				return true;
			if (matrix[posx1][posy1 - 1] == " ")
				return true;

			return false;
		}
	}

	if (posx2 == posx1 - 1)
	{
		if (posy2 == posy1 + 1)
		{
			if (matrix[posx1 - 1][posy1] == " ")
				return true;
			if (matrix[posx1][posy1 + 1] == " ")
				return true;

			return false;
		}

		if (posy2 == posy1 - 1)
		{
			if (matrix[posx1 - 1][posy1] == " ")
				return true;
			if (matrix[posx1][posy1 - 1] == " ")
				return true;

			return false;
		}
	}

	if (I_check_vertical(matrix, posx1, posx2, posy1) == true)
	{
		if (I_check_horizontal(matrix, posx2, posy1, posy2) == true)
		{
			return true;
		}
	}	

	if (I_check_horizontal(matrix, posx1, posy1, posy2) == true)
	{
		if (I_check_vertical(matrix, posx1, posx2, posy2) == true)
		{
			return true;
		}
	}
	return false;
}

//U matching

bool U_check_vertical(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2, int& row)
{
		if (posy1 < posy2)
		{
			for (int i = posx2 + 1; i < row; i++)
			{
				if (matrix[i][posy2] == " ")
				{
					if (matrix[i][posy2 - 1] == " ")
					{
						if (matrix[i][posy1] == " ")
						{
							if (L_check(matrix, i, posx1, posy2, posy1) == true)
							{
								return true;
							}
						}
					}
				}
				else break;
			}

			for (int i = posx1 - 1; i >= 0; i--)
			{
				if (matrix[i][posy1] == " ")
				{
					if (matrix[i][posy1 + 1] == " ")
					{
						if (matrix[i][posy2] == " ")
						{
							if (L_check(matrix, i, posx2, posy1, posy2) == true)
							{
								return true;
							}
						}
					}
				}
				else break;
			}
		}

		if (posy1 > posy2)
		{
			for (int i = posx2 + 1; i < row; i++)
			{
				if (matrix[i][posy2] == " ")
				{
					if (matrix[i][posy2 + 1] == " ")
					{
						if (matrix[i][posy1] == " ")
						{
							if (L_check(matrix, i, posx1, posy2, posy1) == true)
							{
								return true;
							}
						}
					}
				}
				else break;
			}

			for (int i = posx1 - 1; i >= 0; i--)
			{
				if (matrix[i][posy1] == " ")
				{
					if (matrix[i][posy1 - 1] == " ")
					{
						if (matrix[i][posy2] == " ")
						{
							if (L_check(matrix, i, posx2, posy1, posy2) == true)
							{
								return true;
							}
						}
					}
				}
				else break;
			}
		}
		return false;
}

bool U_check_horizontal(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2, int& col)
{
	if (posx1 < posx2)
	{
		for (int i = posy2 + 1; i < col; i++)
		{
			if (matrix[posx2][i] == " ")
			{
				if (matrix[posx2 - 1][i] == " ")
				{
					if (matrix[posx1][i] == " ")
					{
						if (L_check(matrix, posx2, posx1, posy1, i) == true)
						{
							return true;
						}
					}
				}
			}
			else break;
		}

		for (int i = posy1 - 1; i >= 0; i--)
		{
			if (matrix[posx1][i] == " ")
			{
				if (matrix[posx1 + 1][i] == " ")
				{
					if (matrix[posx2][i] == " ")
					{
						if (L_check(matrix, posx1, posx2, i, posy2) == true)
						{
							return true;
						}
					}
				}
			}
			else break;
		}
	}

	if (posx1 > posx2)
	{
		for (int i = posy2 + 1; i < col; i++)
		{
			if (matrix[posx2][i] == " ")
			{
				if (matrix[posx2 + 1][i] == " ")
				{
					if (matrix[posx1][i] == " ")
					{
						if (L_check(matrix, posx2, posx1, i, posy1) == true)
						{
							return true;
						}
						else return false;
					}
				}
			}
			else break;
		}

		for (int i = posy1 - 1; i >= 0; i--)
		{
			if (matrix[posx1][i] == " ")
			{
				if (matrix[posx1 - 1][i] == " ")
				{
					if (matrix[posx2][i] == " ")
					{
						if (L_check(matrix, posx1, posx2, i, posy2) == true)
						{
							return true;
						}
					}
				}
			}
			else break;
		}
	}
	return false;
}

//Z matching

bool Z_check_vertical(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2)
{
	if (posx1 > posx2) //The second pokemon is over the first pokemon
	{
		for (int i = posx1 - 1; i > posx2; i--)
		{
			if (matrix[i][posy1] == " ")
			{
				if (matrix[i][posy2] == " ")
				{
					if (L_check(matrix, i, posx2, posy1, posy2) == true)
					{
						return true;
					}
				}
			}
			else break;
		}
	}

	if (posx1 < posx2) //The second pokemon is under the first pokemon
	{
		for (int i = posx1 + 1; i < posx2; i++)
		{
			if (matrix[i][posy1] == " ")
			{
				if (matrix[i][posy2] == " ")
				{
					if (L_check(matrix, i, posx2, posy1, posy2) == true)
					{
						return true;
					}
					return false;
				}
			}
			else break;
		}
	}
	return false;
}

bool Z_check_horizontal(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2)
{
	if (posy1 < posy2) //The second pokemon is on the right of the first pokemon
	{
		for (int i = posy1 + 1; i < posy2; i++)
		{
			if (matrix[posx1][i] == " ")
			{
				if (matrix[posx2][i] == " ")
				{
					if (L_check(matrix, posx1, posx2, i, posy2) == true)
					{
						return true;
					}
				}
			}
			else break;
		}
	}

	if (posy1 > posy2) //The second pokemon is on the left of the first pokemon
	{
		for (int i = posy1 - 1; i > posy2; i--)
		{
			if (matrix[posx1][i] == " ")
			{
				if (matrix[posx2][i] == " ")
				{
					if (L_check(matrix, posx1, posx2, i, posy2) == true)
					{
						return true;
					}
				}
			}
			else break;
		}
	}
	return false;
}

//main matching

/*Steps:
* 1: Check if selected pokemons are the same. Return false if they are not the same. Execute the following steps if true.
* 2: Check if pokemons are on the same row. Return true if they are. Execute the next step if false.
* 3: Check if pokemons are on the same column. Return true if they are. Execute the next step if false.
* 4: Check if pokemons' position satisfy L algorithm. Return true is they do. Execute the next step if false.
* 5: Check if pokemons' position satisfy Z algorithm. Return true is they do. Execute the next step if false.
* 6: Check if pokemons' position satisfy U algorithm. Return true is they do. If not, return false.
*/
bool Matching(string** matrix, int& posx1, int& posx2, int& posy1, int& posy2, int& row, int& col)
{
	if (Check_cell(matrix, posx1, posx2, posy1, posy2) == true)
	{
		if (posx1 == posx2 && (posy1 - 1 == posy2 || posy1 + 1 == posy2))
		{
			return true;
		}

		if (posy1 == posy2 && (posx1 - 1 == posx2 || posx1 + 1 == posx2))
		{
			return true;
		}

		if (posx1 == posx2 && posy1 != posy2)
		{
			if (I_check_horizontal(matrix, posx1, posy1, posy2) == true)
				return true;
		}
		if (posy1 == posy2 && posx1 != posx2)
		{
			if (I_check_vertical(matrix, posx1, posx2, posy1) == true)
				return true;
		}

		if (L_check(matrix, posx1, posx2, posy1, posy2) == true)
			return true;

		if (Z_check_horizontal(matrix, posx1, posx2, posy1, posy2) == true)
			return true;
		else if (Z_check_vertical(matrix, posx1, posx2, posy1, posy2) == true)
			return true;

		if (U_check_horizontal(matrix, posx1, posx2, posy1, posy2, col) == true)
			return true;
		else
		{
			if (U_check_vertical(matrix, posx1, posx2, posy1, posy2, row) == true)
				return true;
			else return false;
		}
		return false;
	}
	else return false;
}