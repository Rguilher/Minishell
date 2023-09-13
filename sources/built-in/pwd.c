

#include "minishell.h"

void	pwd(void)
{
	char	*pwd;

	g_ms.exit_status = 0;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		print_error("sh: pwd: ", pwd, strerror(errno), 1);
	else
	{
		ft_putstr_fd(pwd, 1);
		ft_putstr_fd("\n", 1);
	}
	free(pwd);
}
