/*
** EPITECH PROJECT, 2018
** main
** File description:
** main.hpp main.cpp
*/

#include "nm.h"
#include "../includes/nm.h"

/*!
* Mother function of the programm which call
* every function to read an ELF file
* @param [in] ac
* @param [in] av
* @return a code "ERROR" if an error occur during the program
* 	  or "SUCCESS" if not.
*/

int main(int ac, char **av)
{
	int 	loop 		= 1;
	int 	return_value 	= SUCCESS;
	char	*bin;

	bin = (strstr(av[0], "objdump") == NULL ? "nm" : "objdump");
	if (ac <= 2)
		return (nm(ac == 1 ? "a.out" : av[1], bin));
	while (av[loop])
	{
		printf("\n%s:\n", av[loop]);
		if (nm(av[loop++], bin) != SUCCESS)
			return_value = ERROR;
	}
	return (return_value);
}
