/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** main.c
*/

#include "objdump.h"
#include "../includes/objdump.h"

/*!
* Mother function of the objdump program which call
* every function necessary to copy the real "objdump"
* program behavior.
* @param [in] ac
* @param [in] av
* @return "SUCCESS" if any error occur whuile the
* 	   program execution or "ERROR" if a 'FAILURE"
* 	   is return somewhere in the program
*/

int	main(int ac, char **av)
{
	int	loop = 1;
	char 	*bin;
	int 	return_value = SUCCESS;

	bin = (strstr(av[0], "objdump") == NULL ? "nm" : "objdump");
	if (ac <= 2)
		return (objdump(ac == 1 ? "a.out" : av[loop], bin));
	while (av[loop])
	{
		printf("\n%s:\n\n", av[loop]);
		if (objdump(av[loop++], bin) != SUCCESS)
			return_value = ERROR;
	}
	return (return_value);
}