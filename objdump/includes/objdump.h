/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** objdump.h
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <elf.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "common.h"

/*
** 	functions in "objdump.c"
*/

void	s_argument(t_elf *elf);
void	look_for_section(t_elf *elf);
int	objdump(const char *arg, const char *bin);

/*
** 	functions in "display.c"
*/

void	display_sec_name(t_elf *elf, int i);
void	display_all_infos(t_elf *elf, int i);
void 	display_hexa_info(int size, uint8_t *data);
int	check_valid_section_name(char *section_name);

#endif /* !OBJDUMP_H_ */
