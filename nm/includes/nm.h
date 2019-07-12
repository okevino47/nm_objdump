/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm.hpp nm.cpp
*/

#ifndef NM_H_
#define NM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

struct s_sym
{
	char		*name;
	char		*value;
	char 		flag;
	struct s_sym 	*next;
};

typedef struct s_sym	t_sym;

/*
** Function of the "assignation.c" file
*/

void	init_sym_link(t_sym *link);
void	free_everything(t_sym **sym);
void	assign_function(t_elf *elf, t_sym **sym_chain, int i);
int	assign_elf_struct(t_elf *elf, void **map, \
				const char *arg, const char *bin);

/*
** Function of the "display.c" file
*/

void	display_symbol(t_sym *sym);
void	char_bubble_sort(char *a, char *b);
void	str_bubble_sort(char **a, char **b);
char	*epur_str(char *str);
t_sym	*sort_chain_sym(t_sym *sym);

/*
** Function of the "nm.c" file
*/

int 	nm(const char *arg, const char *bin);

/*
** Function of the "symbol_flag_finder.c" file
*/

char	find_flag_info(char *result, Elf64_Sym sym);
char	find_sym_flag(char *flag, Elf64_Sym sym, t_elf *elf);
char	find_flag_type(char *result, Elf64_Sym sym, t_elf *elf);
char	find_flag_index(char *result, Elf64_Sym sym, t_elf *elf);

/*
** Function of the "symbol_manipulation.c" file
*/

void	find_all_symbol_info(t_elf *elf, t_sym **sym);
void	look_for_strtab_symtab(t_elf *elf, t_sym **sym_chain);
void	stock_sym_info(t_sym **sym_chain, Elf64_Sym sym, t_elf *elf, int i);
int	symbol_manipulation(t_elf *elf, t_sym **sym_chain);
t_sym	*find_right_link(t_sym **sym_chain);

#endif /* !NM_H_ */