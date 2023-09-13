
#include "minishell.h"

int	ft_isfile(char *token_cmd)
{
	if (*token_cmd == '.')
		token_cmd++;
	if (*token_cmd == '.')
		token_cmd++;
	if (*token_cmd == '/')
		return (1);
	return (0);
}

int	ft_isdirectory(char *token_cmd)
{
	struct stat	statbuf;

	statbuf = (struct stat){0};
	if (stat(token_cmd, &statbuf))
		return (0);
	if (S_ISDIR(statbuf.st_mode))
	{
		if (*token_cmd == '.')
			token_cmd++;
		if (*token_cmd == '.')
			token_cmd++;
		if (*token_cmd == '/')
			return (1);
	}
	return (0);
}
