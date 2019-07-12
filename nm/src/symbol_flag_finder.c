/*
** EPITECH PROJECT, 2018
** symbole_flag_finder
** File description:
** symbole_flag_finder.hpp symbole_flag_finder.cpp
*/

#include "nm.h"

char	find_flag_type(char *result, Elf64_Sym sym, t_elf *elf)
{
	if (elf->shdr[sym.st_shndx].sh_type == SHT_PROGBITS
		&& elf->shdr[sym.st_shndx].sh_flags == (SHF_ALLOC
							| SHF_WRITE))
		(*result) = 'D';
	else if (elf->shdr[sym.st_shndx].sh_type == SHT_PROGBITS
		&& elf->shdr[sym.st_shndx].sh_flags == (SHF_ALLOC
							| SHF_EXECINSTR))
		(*result) = 'T';
	else
	{
		if (elf->shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
			(*result) = 'D';
		else
			(*result) = (!elf->shdr->sh_type
					&& elf->ehdr->e_type == ET_REL
					? 'N' : 'T');
	}
	return (*result);
}

char	find_flag_index(char *result, Elf64_Sym sym, t_elf *elf)
{
	if (sym.st_shndx == SHN_ABS)
		(*result) = 'A';
	else if (sym.st_shndx == SHN_COMMON)
		(*result) = 'C';
	else
	{
		if (elf->shdr[sym.st_shndx].sh_type == SHT_NOBITS
			&& elf->shdr[sym.st_shndx].sh_flags == (SHF_ALLOC
								| SHF_WRITE))
			(*result) = 'B';
		else if (elf->shdr[sym.st_shndx].sh_type == SHT_PROGBITS
			&& elf->shdr[sym.st_shndx].sh_flags == (SHF_ALLOC))
			(*result) = 'R';
	}
	return (*result);
}

char	find_flag_info(char *result, Elf64_Sym sym)
{
	if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE)
		(*result) = 'u';
	else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK)
		(*result) = (sym.st_shndx == SHN_UNDEF ? 'w' : 'W');
	else {
		if (ELF64_ST_BIND(sym.st_info) == STB_WEAK
			&& ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
			(*result) = (sym.st_shndx == SHN_UNDEF ? 'v' : 'V');
		else if (sym.st_shndx == SHN_UNDEF)
			(*result) = 'U';
	}
	return (*result);
}

char	find_sym_flag(char *result, Elf64_Sym sym, t_elf *elf)
{
	(*result) = '?';

	(*result) = find_flag_info(result, sym);
	if ((*result) == '?')
		(*result) = find_flag_index(result, sym, elf);
	if ((*result) == '?')
		(*result) = find_flag_type(result, sym, elf);
	if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && (*result) != '?')
		(*result) += 32;
	return (*result);
}
