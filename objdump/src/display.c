/*
** EPITECH PROJECT, 2018
** display
** File description:
** display.hpp display.cpp
*/

#include <elf.h>
#include "objdump.h"

/*!
* Function which display the name of the section designed
* by the "i" index given in parameter.
* @param [in] elf
* @param [in] i
*/

void	display_sec_name(t_elf *elf, int i)
{
	char *str_section = elf->addr + elf->shdrtab->sh_offset;
	size_t strtab_position = elf->shdr[i].sh_name;
	char *section_name = str_section + strtab_position;

	if (check_valid_section_name(section_name) == SUCCESS) {
		printf("Contents of section %s:\n", section_name);
		display_all_infos(elf, i);
	}
}

/*!
* Display every section line information, with the begining
* address, then the infos in hexa and then the infos themselves
* @param [in] elf
* @param [in/out] i
*/

void	display_all_infos(t_elf *elf, int i)
{
	int	size;
	uint8_t	*data;

	for (unsigned int j = (unsigned int)elf->shdr[i].sh_offset;
		j < (uint)(elf->shdr[i].sh_offset + elf->shdr[i].sh_size);
		j += 16)
	{
		data = (unsigned char *)(elf->addr + j);
		size = (int)(elf->shdr[i].sh_offset + elf->shdr[i].sh_size - j);
		printf(" %04x ", (int)(elf->shdr[i].sh_addr + j - elf->shdr[i].sh_offset));
		display_hexa_info(size, data);
		printf("%s", " \n");
	}
}

/*!
* Print every informations in hexa and in ASCII
* after that.
* @param [in] size
* @param [in] data
*/

void 	display_hexa_info(int size, uint8_t *data)
{
	for (int i = 0; i < 16; i += 1)
	{
		if (i < size)
			printf("%02x", data[i]);
		else
			printf("%s", "  ");
		if (!((i + 1) % 4))
			printf("%s", " ");
	}
	printf("%s", " ");
	for (int i = 0; i < 16; i += 1)
		if (i < size && isprint(data[i]))
			printf("%c", data[i]);
		else if (i < size)
			printf("%s", ".");
		else
			printf("%s", " ");

}

/*!
* Check if the section name given in parameter
* correspond to a section name that do not have
* to be displayed
* @param [in] section_name
* @return "SUCCESS" if the name does not correspond
* 	   to a section name to avoid or "FAILURE".
*/

int	check_valid_section_name(char *section_name)
{
	char	*invalid[] = {
		".bss", \
		".tbss", \
		".shstrtab", \
		".symtab", \
		".strtab", \
		".rela.text", \
		".rela.eh_frame", \
		".rela.debug_info", \
		".rela.debug_line", \
		".rela.debug_aranges", \
		NULL
	};

	for (int i = 0; invalid[i] != NULL; i += 1)
		if (strcmp(invalid[i], section_name) == 0)
			return (FAILURE);
	return (SUCCESS);
}