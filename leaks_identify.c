#include "leaks_identify.h"

t_mem	mem_info[N];

void	leaks_identify_init(void)
{
	size_t	i;

	i = 0;
	while (i < N)
	{
		mem_info[i].ptr = NULL;
		mem_info[i].size = 0;
		mem_info[i].file = NULL;
		mem_info[i].line = 0;
		i++;
	}
}

void	*leaks_identify_malloc(size_t size, const char *file, unsigned int line)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (i < N)
	{
		if (mem_info[i].ptr == NULL)
		{
			mem_info[i].ptr = ptr;
			mem_info[i].size = size;
			mem_info[i].file = file;
			mem_info[i].line = line;
			break;
		}
		i++;
	}
	return (ptr);
}

void	leaks_identify_free(void *ptr)
{
	size_t	i;

	i = 0;
	while (i < N)
	{
		if (mem_info[i].ptr == ptr)
		{
			mem_info[i].ptr = NULL;
			mem_info[i].size = 0;
			mem_info[i].file = NULL;
			mem_info[i].line = 0;
			break;
		}
		i++;
	}
	free(ptr);
}

void	leaks_identify_check(void)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (i < N)
	{
		if (mem_info[i].ptr != NULL)
		{
			printf("****--memory leaks!!--****\n");
			printf("  address: %p\n", mem_info[i].ptr);
			printf("     size: %zu\n", mem_info[i].size);
			printf("file&line: %s : %u\n", mem_info[i].file, mem_info[i].line);
			printf("\n");
			cnt++;
		}
		i++;
	}
	printf("****--total leaks : %zu", cnt);
}