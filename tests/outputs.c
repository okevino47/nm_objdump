/*
** EPITECH PROJECT, 2018
** outputs
** File description:
** outputs.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>
#include "../nm/includes/nm.h"
#include "../common/includes/common.h"

TestSuite(redirect, .timeout = 1);

Test(nm_on_directory, stdout_)
{
	cr_assert(map_my_file(NULL, "directory_test/") == -1,
		"Crashed at \"map_my_file\"");
}

Test(no_right, stdout_)
{
	cr_assert(check_argument_file("no_right", "nm") == -1,
		"Crashed at \"map_my_file\"");
}

Test(no_read_write, stdout_)
{
	cr_assert(check_argument_file("no_read_right", "nm") == -1,
		"Crashed at \"map_my_file\"");
}

Test(no_elf_file, stdout_)
{
	void 		*map = NULL;
	Elf64_Ehdr	*ehdr = NULL;

	map_my_file(&map, "no_elf.c");
	ehdr = (Elf64_Ehdr*)(map);
	cr_assert(check_elf_format(ehdr->e_ident, "no_elf.c", "nm") == -1,
		"Crashed at \"map_my_file\"");
}

