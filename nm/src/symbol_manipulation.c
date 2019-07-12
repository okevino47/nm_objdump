/*
** EPITECH PROJECT, 2018
** symbole_manipulation
** File description:
** symbole_manipulation.hpp symbole_manipulation.cpp
*/

#include "nm.h"

/*!
* Mother function of every function working with the
* symbol link list. Stock the symbols information,
* display the symbols information and free them.
* @param [in] elf
* @param [in] sym_chain
* @return "FAILURE" if the chain list of symbols is empty
*         or "SUCCESS"
*/

int	symbol_manipulation(t_elf *elf, t_sym **sym_chain)
{
	look_for_strtab_symtab(elf, sym_chain);
	if (!elf->symtab)
	{
		fprintf(stderr, "nm: aucun symbole pour ce fichier");
		return (FAILURE);
	}
	display_symbol(*sym_chain);
	free_everything(sym_chain);
	return (SUCCESS);
}

/*!
* Try to find with the good offset index, the string table
* in the ELF header, if not found increment the counter to
* continue looking for until the last table.
* @param [in] elf
* @param [in] sym_chain
*/

void	look_for_strtab_symtab(t_elf *elf, t_sym **sym_chain)
{
	int i = 0;

	elf->shdrtab = &elf->shdr[elf->ehdr->e_shstrndx];
	while (i < elf->ehdr->e_shnum)
	{
		if (elf->ehdr->e_shstrndx != SHN_UNDEF
			&& elf->shdr[i].sh_name != SHN_UNDEF)
			assign_function(elf, sym_chain, i);
		i += 1;
	};
}

/*!
* Move to the correct offset to find all the symbols in the
* symtab and check if the name of the symbol exist.
* @param [in] elf
* @param [in] sym
*/

void	find_all_symbol_info(t_elf *elf, t_sym **sym)
{
	unsigned int 	i = 0;
	Elf64_Sym	*symbole = (Elf64_Sym*)
		(elf->addr + elf->symtab->sh_offset);

	while (i < elf->symtab->sh_size / elf->symtab->sh_entsize)
	{
		if (symbole[i].st_info != STT_FILE && \
			symbole[i].st_name != STN_UNDEF)
			stock_sym_info(sym, symbole[i], elf, i);
		i += 1;
	}
}

/*!
* Assign in the chain list the name, the value of
* of the symbol and call the function which choose
* the right flag to set.
* @param [in] sym_chain
* @param [in] sym
* @param [in] elf
* @param [in/out] i
*/

void	stock_sym_info(t_sym **sym_chain, Elf64_Sym sym, t_elf *elf, int i)
{
	t_sym		*tmp = find_right_link(sym_chain);
	char 		flag_symbole = '\0';
	char		*strtab = elf->addr +
				(elf->shdr[elf->symtab->sh_link].sh_offset);
	Elf64_Sym	*symtable = (Elf64_Sym*)
				(elf->addr + elf->symtab->sh_offset);

	if (sym.st_value != 0000000000000000)
		sprintf(tmp->value, "%016x", (unsigned int)sym.st_value);
	else
		sprintf(tmp->value, "%16c", ' ');
	tmp->name = malloc(sizeof(char) * (strlen(strtab +
				symtable[i].st_name)) + 1);
	sprintf(tmp->name, "%s", strtab + symtable[i].st_name);
	tmp->flag = find_sym_flag(&flag_symbole, sym, elf);
}

/*!
* Look for the last link of the chain link. Create the chain link
* if it does not exist anymore.
* @param [in] sym_chain
* @return the last link of the chain.
*/

t_sym	*find_right_link(t_sym **sym_chain)
{
	t_sym	*tmp = NULL;

	if (*sym_chain == NULL)
	{
		(*sym_chain) = malloc(sizeof(t_sym));
		init_sym_link(*sym_chain);
		return (*sym_chain);
	}
	else
	{
		tmp = (*sym_chain);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_sym));
		init_sym_link(tmp->next);
		return (tmp->next);
	}
}