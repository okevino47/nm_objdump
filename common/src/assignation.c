/*
** EPITECH PROJECT, 2018
** assignation
** File description:
** assignation.hpp assignation.cpp
*/

#include "common.h"

/*!
* Assign every variables of the structure "t_elf" by calling various
* functions.
* @param [out] elf
* @param [in] map
* @param [in] arg
* @return "SUCCESS" if the function end normaly after various
* 	   functions calling or "FAILURE" if not.
*/

int	assign_elf_struct(t_elf *elf, void **map, const char *arg, \
				const char *bin)
{
	elf->addr = (*map);
	elf->ehdr = (Elf64_Ehdr*)(*map);
	if (launch_check_in_ehdr(elf->ehdr, arg, bin) == FAILURE)
		return (FAILURE);
	elf->shdr = (Elf64_Shdr *)((char *)elf->ehdr + elf->ehdr->e_shoff);
	elf->symtab = (NULL);
	elf->strtab = NULL;
	return (SUCCESS);
}
