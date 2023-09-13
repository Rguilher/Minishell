
#include "minishell.h"

void	update_token(char **token)
{
	int	i;
	int	j;

	i = 0;
	while (token[i])
	{
		if ((token[i][0] == '>' && (!token[i][1] || (token[i][1] == '>'
			&& !token[i][2]))) || (token[i][0] == '<' && (!token[i][1]
			|| (token[i][1] == '<' && !token[i][2]))))
		{
			free(token[i]);
			free(token[i + 1]);
			token[i] = NULL;
			token[i + 1] = NULL;
			j = i + 2;
			while (token[j])
			{
				token[j - 2] = ft_strdup(token[j]);
				free(token[j]);
				token[j++] = NULL;
			}
			i--;
		}
		i++;
	}
}
