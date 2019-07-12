/*
** EPITECH PROJECT, 2018
** mapping
** File description:
** mapping.hpp mapping.cpp
*/

#include "common.h"

/*!
* Open the file given in argument check if it can open and close it
* to place it in a buffer with "mmap".
* @param [out] map
* @param [in] filename
* @return return the "perror" return and the "FAILURE" code if an error
* 	  occur while the target opening or return the "file_size" of
* 	  the file.
*/

int	map_my_file(void **map, const char *filename)
{
	int 		fd = 0;
	struct stat	file_infos;
	void		*addr;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(filename), FAILURE);
	if (stat(filename, &file_infos) == -1)
		return (perror(filename), FAILURE);
	addr = mmap(NULL, file_infos.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED)
		return (FAILURE);
	(*map) = addr;
	if (close(fd) == -1)
		return (perror(filename), FAILURE);
	return ((int)file_infos.st_size);
}
