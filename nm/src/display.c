/*
** EPITECH PROJECT, 2018
** display
** File description:
** display.hpp display.cpp
*/

#include "nm.h"

/*!
* Loop until the end of the struct list and print
* every value of the symbol stored in the struct.
* @param [in] sym
*/

void	display_symbol(t_sym *sym)
{
	t_sym	*tmp = NULL;

	sym = sort_chain_sym(sym);
	tmp = sym;
	while (tmp)
	{
		printf("%s %c %s\n", tmp->value, tmp->flag, tmp->name);
		tmp = tmp->next;
	}
}

/*!
* Epur he string given in parameter by removing spaces
* set minus char in capslock.
* @param [in] str
* @return the chain transformed
*/

char	*epur_str(char *str)
{
	char 	*result = strdup(str);
	char 	*result1 = malloc(sizeof(char) * strlen(str) + 1);
	int	i = 0;
	int 	j = 0;

	memset(result1, '\0', sizeof(char) * strlen(str) + 1);
	while (result[i++])
		if (result[i] >= 'A' && result[i] <= 'Z')
			result[i] = result[i] + 32;
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] >= 'a' && result[i] <= 'z')
			result1[j++] = result[i];
		i += 1;
	}
	free(result);
	return (result1);
}

/*!
* Sort every link with the name of the flag by
* alphabetical order sorted by a bubble method.
* @param [in/out] sym
* @return the begin of the chain list
*/

t_sym	*sort_chain_sym(t_sym *sym)
{
	t_sym	*tmp = sym;

	while (tmp && tmp->next)
	{
		char *a = epur_str(tmp->name);
		char *b = epur_str(tmp->next->name);
		if ((strcoll(a, b)) > 0 || (((strcoll(a, b)) == 0)
					&& (tmp->flag > tmp->next->flag)))
		{
			str_bubble_sort(&tmp->name, &tmp->next->name);
			str_bubble_sort(&tmp->value, &tmp->next->value);
			char_bubble_sort(&tmp->flag, &tmp->next->flag);
			tmp = sym;
		}
		else
			tmp = tmp->next;
		free(a);
		free(b);
	}
	return (sym);
}

/*!
* Bubble sort function specialized for string
* @param [out] a
* @param [out] b
*/

void	str_bubble_sort(char **a, char **b)
{
	char *tmp = NULL;

	tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

/*!
* Bubble sort function specialized for char
* @param [out] a
* @param [out] b
*/

void	char_bubble_sort(char *a, char *b)
{
	char tmp;

	tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}
