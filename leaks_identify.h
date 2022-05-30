#ifndef LEAKS_IDENTIFY_H
# define LEAKS_IDENTIFY_H

# include <stdio.h>
# include <stdlib.h>

# define N 100

typedef struct s_mem
{
	void			*ptr;
	size_t			size;
	const char		*file;
	unsigned int	line;
}	t_mem;

void	leaks_identify_init(void);
void	*leaks_identify_malloc(size_t size, const char *file, unsigned int line);
void	leaks_identify_free(void *ptr);
void	leaks_identify_check(void);

#endif