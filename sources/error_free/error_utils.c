
#include "minishell.h"

void	print_error(char *str1, char *str2, char *str3, int exit_status)
{
	int	backup_fd;

	if (g_ms.on_fork)
	{
		backup_fd = dup(1);
		dup2(2, 1);
		printf("%s%s: %s\n", str1, str2, str3);
		dup2(backup_fd, 1);
		close(backup_fd);
	}
	else
	{
		ft_putstr_fd(str1, 2);
		ft_putstr_fd(str2, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str3, 2);
		ft_putstr_fd("\n", 2);
	}
	g_ms.exit_status = exit_status;
}

void	print_error_heredoc(char *prompt, char *dlmt)
{
	int	backup_fd;

	if (!prompt)
	{
		backup_fd = dup(1);
		dup2(2, 1);
		printf("sh: warning: here-document delimited ");
		printf("by end-of-file (wanted '%s')\n", dlmt);
		dup2(backup_fd, 1);
		close(backup_fd);
	}
}
