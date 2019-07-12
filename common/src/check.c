/*
** EPITECH PROJECT, 2018
** check
** File description:
** check.hpp check.cpp
*/

#include "common.h"

/*!
* Mother function calling all the pre-check functions
* @param [in] filename
* @return Following the behavior of the program "SUCCESS" or
*         "FAILURE"
*/

int 	launch_check_in_ehdr(Elf64_Ehdr *ehdr, const char *filename, \
						const char *bin)
{
	if (check_elf_format(ehdr->e_ident, filename, bin) == FAILURE)
		return (FAILURE);
	if (check_byte_order(ehdr->e_ident, filename, bin) == FAILURE)
		return (FAILURE);
	if (check_file_type(ehdr->e_type, filename, bin) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/*!
* Check the file rights to verify if we can scan the
* ELF header.
* @param [in] filename
* @return "Failure" code with an error explication or a
* 	  "SUCCESS" code.
*/

int 	check_argument_file(const char *filename, const char *bin)
{
	if (access(filename, F_OK ) != 0)
	{
		fprintf(stderr, "%s: \'%s\': No such file\n", bin, filename);
		return (FAILURE);
	}
	if (access(filename, R_OK ) != 0)
	{
		fprintf(stderr, "%s: %s: Permission denied\n", bin, filename);
		return (FAILURE);
	}
	return (SUCCESS);
}

/*!
* Check if the file given as argument is in ELF format by checking
* the 4 first bytes of the binary.
* Check then if the file is in 64 BITS format to continue or
* send an error.
* @param [in] e
* @param [in] filename
* @return "SUCCESS" if no error occur or "FAILURE"
*/

int 	check_elf_format(unsigned char *e, const char *filename, \
						const char *bin)
{
	if (!e)
	{
		fprintf(stderr, "%s: %s: File format not recognized\n", \
			bin, filename);
		return (FAILURE);
	}
	if (e[EI_MAG0] != 0x7f || e[EI_MAG1] != 'E' || e[EI_MAG2] != 'L'
						|| e[EI_MAG3] != 'F')
	{
		fprintf(stderr, "%s: %s: File format not recognized\n", \
			bin, filename);
		return (FAILURE);
	}
	if (e[EI_CLASS] != ELFCLASS64)
	{
		fprintf(stderr, "%s: %s: Unsupported ELF File Class.\n", \
			bin, filename);
		return FAILURE;
	}
	return (SUCCESS);
}

/*!
* Check the encoding file index to verify if the byte encoding
* is correct.
* @param [in] e
* @param [in] filename
* @return "Failure" code with an error explication or a
* 	  "SUCCESS" code.
*/

int 	check_byte_order(unsigned char *e, const char *filename, \
					const char *bin)
{
	if (e[EI_DATA] == ELFDATANONE)
	{
		fprintf(stderr, "%s: %s: %s\n", \
			bin, filename, UNSUP_ELF);
		return FAILURE;
	}
	if (e[EI_VERSION] != EV_CURRENT)
	{
		fprintf(stderr, "%s: %s: %s\n", \
			bin, filename, UNSUP_ELF);
		return FAILURE;
	}
	return (SUCCESS);
}

/*!
* Check in te ELF structure if the type of the file is a
* a object file, an executable, a core file or a library.
* @param [in] type
* @param [in] filename
*  @return "Failure" code with an error explication or a
* 	   "SUCCESS" code.
*/

int	check_file_type(Elf64_Half type, const char *filename, \
					const char *bin)
{
	if (type == ET_NONE)
	{
		fprintf(stderr, "%s: %s: File format not recognized\n", \
			bin, filename);
		return (FAILURE);
	}
	return (SUCCESS);
}
