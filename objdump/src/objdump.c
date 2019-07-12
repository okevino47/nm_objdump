/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** objdump.hpp objdump.cpp
*/

#include <elf.h>
#include "objdump.h"

/*!
* Mother function calling every function to complete
* an objdump basic with the "-f" and "-s" flags.
* Check basic at the begining, load a buffer to
* stock the ELF information and finally print
* specifics information.
* @param [in] arg
* @return "FAILURE" if an error occur while the
* 	   program execution or "SUCCESS" instead.
*/

int	objdump(const char *arg, const char *bin)
{
	void	*map = NULL;
	t_elf	elf;

	if (check_argument_file(arg, bin) == FAILURE)
		return (ERROR);
	map_my_file(&map, arg);
	if (assign_elf_struct(&elf, &map, arg, bin) == FAILURE)
		return (ERROR);
	look_for_section(&elf);
	return (SUCCESS);
}

/*!
* Call alternately the "-f" objdump argument and
* after the "-s" argument of objdump.
* @param [in] elf
*/

void	look_for_section(t_elf *elf)
{
	s_argument(elf);
}

/*!
* Simulate the "-s" argument of the objdump
* @param [in/out] elf
*/

void	s_argument(t_elf *elf)
{
	int 	i = 0;

	elf->shdrtab = &elf->shdr[elf->ehdr->e_shstrndx];
	while (i < elf->ehdr->e_shnum)
	{
		if (elf->ehdr->e_shstrndx != SHN_UNDEF
			&& elf->shdr[i].sh_name != SHN_UNDEF)
			display_sec_name(elf, i);
		i += 1;
	}
}