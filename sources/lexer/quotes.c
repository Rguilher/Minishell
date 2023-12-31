
#include "minishell.h"

void	mark_metachar_inside_quotes(char *prompt)
{
	int		i;
	char	c;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\"' || prompt[i] == '\'')
		{
			c = prompt[i];
			i++;
			while (prompt[i] && prompt[i] != c)
			{
				if (prompt[i] == '|')
					prompt[i] = PIPE_QUOTES;
				else if (prompt[i] == '<')
					prompt[i] = L_RDCT_QUOTES;
				else if (prompt[i] == '>')
					prompt[i] = R_RDCT_QUOTES;
				i++;
			}
		}
		if (prompt[i] != '\0')
			i++;
	}
}

static void	mark_metachar_dollar_and_tilde(char *prompt, int i)
{
	if (prompt[i] == '$' && prompt[i + 1] != '$'
		&& prompt[i + 1] && !ft_iswhitespace(prompt[i + 1]))
		prompt[i] = DOLLAR_VAR;
	else if (prompt[i] == '~' && (i == 0 || ft_iswhitespace(prompt[i - 1])
			|| prompt[i - 1] == '=') && (ft_iswhitespace(prompt[i + 1])
			|| !prompt[i + 1] || prompt[i + 1] == '/' || prompt[i + 1] == ':'))
		prompt[i] = TILDE_VAR;
}

static void	mark_metachar_dollar(char *prompt, int i)
{
	if (prompt[i] == '$' && prompt[i + 1] != '$' && prompt[i + 1]
		&& !ft_iswhitespace(prompt[i + 1]) && prompt[i + 1] != '\"')
		prompt[i] = DOLLAR_VAR;
}

void	find_metachar(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\'')
		{
			i++;
			while (prompt[i] && prompt[i] != '\'')
				i++;
		}
		else if (prompt[i] == '\"')
		{
			i++;
			while (prompt[i] && prompt[i] != '\"')
			{
				mark_metachar_dollar(prompt, i);
				i++;
			}
		}
		else
			mark_metachar_dollar_and_tilde(prompt, i);
		if (prompt[i] != '\0')
			i++;
	}
}

void	change_metachar_back(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == PIPE_QUOTES)
			prompt[i] = '|';
		else if (prompt[i] == L_RDCT_QUOTES)
			prompt[i] = '<';
		else if (prompt[i] == R_RDCT_QUOTES)
			prompt[i] = '>';
		i++;
	}
}
