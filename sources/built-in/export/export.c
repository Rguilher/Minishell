
#include "minishell.h"

static void	update_env(char **token, int j)
{
	int	i;

	if (check_if_exists_exp(token, j))
		return ;
	i = dup_env();
	g_ms.env[i] = ft_strdup(token[j]);
}

void	export(char **token)
{
	int	i;

	g_ms.exit_status = 0;
	check_only_export(token);
	i = 1;
	while (token[i])
	{
		if (!check_isname_exp(token[i]))
			print_error("sh: export: ",
				token[1], "not a valid identifier", 1);
		else
			update_env(token, i);
		i++;
	}
}
