/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:04:52 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/22 17:16:54 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_22_for_two(int **m, int pos_alt);
void	continue_cases_three(int **m, int pos_alt);
void	continue_cases_two(int **m, int pos_alt);

void	cases_four(int **m, int pos_alt)
{
	if (m[pos_alt][5] == 1)
		m[pos_alt][4] = 4;
	else if (m[pos_alt][0] == 1)
		m[pos_alt][1] = 4;
	else if (m[pos_alt][5] == 3)
		m[pos_alt][2] = 4;
	else if (m[pos_alt][0] == 3)
		m[pos_alt][3] = 4;
	else
	{
		m[pos_alt][2] = -4;
		m[pos_alt][3] = -4;
	}
	return ;
}

void	cases_three(int **m, int pos_alt)
{
	if (m[pos_alt][5] == 4)
		m[pos_alt][2] = 3;
	else if (m[pos_alt][0] == 4)
		m[pos_alt][3] = 3;
	else if (m[pos_alt][0] == 1 && m[pos_alt][5] == 2)
		m[pos_alt][4] = 3;
	else if (m[pos_alt][0] == 2 && m[pos_alt][5] == 1)
		m[pos_alt][1] = 3;
	else if ((m[pos_alt][0] == 1 && m[pos_alt][5] == 3)
		|| (m[pos_alt][0] == 3 && m[pos_alt][5] == 1))
	{
		m[pos_alt][2] = -3;
		m[pos_alt][3] = -3;
	}
	else if (m[pos_alt][0] == 3 && m[pos_alt][5] == 2)
	{
		m[pos_alt][2] = -3;
		m[pos_alt][4] = -3;
	}
	else
		continue_cases_three(m, pos_alt);
	return ;
}

void	continue_cases_three(int **m, int pos_alt)
{
	if (m[pos_alt][0] == 2 && m[pos_alt][5] == 3)
	{
		m[pos_alt][1] = -3;
		m[pos_alt][3] = -3;
	}
	else
	{
		m[pos_alt][1] = -3;
		m[pos_alt][4] = -3;
	}
	return ;
}

void	cases_two(int **m, int pos_alt)
{
	if (m[pos_alt][0] == 4)
		m[pos_alt][2] = 2;
	else if (m[pos_alt][0] == 2 && m[pos_alt][5] == 3)
	{
		if (m[pos_alt][1] == 3)
			m[pos_alt][3] = 2;
		else
		{
			m[pos_alt][1] = -2;
			m[pos_alt][4] = -2;
		}
	}
	else if (m[pos_alt][5] == 2 && m[pos_alt][0] == 3)
	{
		if (m[pos_alt][4] == 3)
			m[pos_alt][2] = 2;
		else
		{
			m[pos_alt][1] = -2;
			m[pos_alt][4] = -2;
		}
	}
	else
		continue_cases_two(m, pos_alt);
	return ;
}

void	continue_cases_two(int **m, int pos_alt)
{
	if (m[pos_alt][5] == 4)
		m[pos_alt][3] = 2;
	else if ((m[pos_alt][0] == 1 && m[pos_alt][5] == 2)
		|| (m[pos_alt][0] == 2 && m[pos_alt][5] == 1))
	{
		m[pos_alt][2] = -2;
		m[pos_alt][3] = -2;
	}
	else if (m[pos_alt][0] == 1 && m[pos_alt][5] == 3)
	{
		m[pos_alt][4] = -2;
		m[pos_alt][3] = -2;
	}
	else if (m[pos_alt][0] == 3 && m[pos_alt][5] == 1)
	{
		m[pos_alt][1] = -2;
		m[pos_alt][2] = -2;
	}
	else
		check_22_for_two(m, pos_alt);
	return ;
}
