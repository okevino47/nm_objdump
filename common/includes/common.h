/*
** EPITECH PROJECT, 2018
** common
** File description:
** common.hpp common.cpp
*/

#ifndef COMMON_H_
#define COMMON_H_

#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define	UNSUP_ELF	("Unsupported ELF file byte order.")

enum	e_return_value
{
	ERROR 	= 84, \
	SUCCESS = 0, \
	FAILURE = -1
};

typedef struct s_all_elf_structs
{
	void		*addr;
	Elf64_Ehdr	*ehdr;
	Elf64_Shdr	*shdr;
	Elf64_Shdr	*shdrtab;
	Elf64_Shdr	*symtab;
	Elf64_Shdr	*strtab;
}			t_elf;

/*
** Function of the "check.c" file
*/

int 	check_argument_file(const char *filename, const char *bin);
int	check_file_type(Elf64_Half type, const char *filename, \
						const char *bin);
int 	check_byte_order(unsigned char *e, const char *filename, \
						const char *bin);
int 	launch_check_in_ehdr(Elf64_Ehdr *elf, const char *filename, \
						const char *bin);
int 	check_elf_format(unsigned char *magic_number, const char *filename, \
						const char *bin);

/*
** Function of the "mapping.c" file
*/

int	map_my_file(void **map, const char *filename);

/*
** Function of the "assignation.c" file
*/

int	assign_elf_struct(t_elf *elf, void **map, const char *arg, const char *bin);

#endif /* !COMMON_H_ */
