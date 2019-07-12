/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm.hpp nm.cpp
*/

#include "nm.h"
#include "common.h"

/*!
* Mother function which check if the arguments used are correct
* make a buffer in "map_my_file" with "mmap". Assign the generals
* ELF infos in the structure "sym_chain" and then, assign the symbol
* by various manipulation.
* @param [in] arg
* @return an "ERROR" code if during one of the previous steps a
* 	   problem occur or "SUCCESS"
*/

int	nm(const char *arg, const char *bin)
{
	void		*map = NULL;
	t_sym		*sym_chain = NULL;
	t_elf		elf;

	if (check_argument_file(arg, bin) == FAILURE)
		return (ERROR);
	map_my_file(&map, arg);
	if (assign_elf_struct(&elf, &map, arg, bin) == FAILURE)
		return (ERROR);
	if (symbol_manipulation(&elf, &sym_chain) == FAILURE)
		return (ERROR);
	return (SUCCESS);
}
