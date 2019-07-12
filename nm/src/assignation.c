/*
** EPITECH PROJECT, 2018
** assignation
** File description:
** assignation.hpp assignation.cpp
*/

#include "nm.h"

/*!
* Initialise all the variables while creating a new link structure
* @param [out] link
*/

void	init_sym_link(t_sym *link)
{
	link->name	= NULL;
	link->value	= malloc(sizeof(char) * 17);
	link->flag	= '\0';
	link->next	= NULL;
}

/*!
* Free all the space used in every variables of the structure
* "t_sym".
* @param [out] sym
*/

void	free_everything(t_sym **sym)
{
	t_sym	*tmp = NULL;

	while (*sym)
	{
		tmp = (*sym);
		(*sym) = (*sym)->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
}

/*!
* Assign in the "t_elf" structure the string table address, /
* and assign if the symbole table is found too.
* @param [in/out] elf
* @param [out] sym_chain
* @param [in/out] i
*/

void	assign_function(t_elf *elf, t_sym **sym_chain, int i)
{
	if (elf->shdr[i].sh_type == SHT_SYMTAB) {
		elf->symtab = &(elf->shdr[i]);
		find_all_symbol_info(elf, sym_chain);
	}
	else if (elf->shdr[i].sh_type == SHT_STRTAB)
		elf->strtab = &elf->shdr[i];
}
