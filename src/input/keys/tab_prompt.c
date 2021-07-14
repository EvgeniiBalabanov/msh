/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telron <telron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:59:02 by telron            #+#    #+#             */
/*   Updated: 2021/06/10 12:51:14 by telron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_line	*ft_create_line_before(t_shell *config, t_cmd_line *cmd_line)
{
	t_line		*line_before;
	size_t		counter;
	char		chr;
	t_command	*command;

	command = ft_inp_command_get(config);
	line_before = ft_line_create_str("");
	if (line_before)
	{
		counter = command->xx_cursor;
		while (counter--)
		{
			chr = cmd_line->line->string[counter];
			if (!chr || !(ft_isalnum(chr) || ft_strchr("./_-", chr)))
				break ;
			ft_line_insert_chr(line_before, chr, 0);
		}
	}
	return (line_before);
}

static void	ft_has_prompt(\
						t_shell *config, \
						t_dlist *prompt_dlist, \
						t_line *line_before)
{
	size_t		counter;
	t_line		*tail;
	t_command	*command;
	t_cmd_line	*cmd_line;

	cmd_line = ft_inp_cmd_line_get(config);
	command = ft_inp_command_get(config);
	if ((prompt_dlist->right || prompt_dlist->left) && \
		!ft_choice_make(config, prompt_dlist))
	{
		config->view.mode = MODE_CHOICE;
		ft_input(config);
		tail = config->view.mode_choice.choice.cmd_line->line;
	}
	else
		tail = prompt_dlist->content;
	counter = 0;
	while (line_before->length--)
		ft_line_del_chr(cmd_line->line, command->xx_cursor-- - 1);
	while (tail->string[counter])
		ft_line_insert_chr(cmd_line->line, tail->string[counter++], \
													command->xx_cursor++);
}

void	ft_inp_keys_tab_prompt(t_shell *config)
{
	t_cmd_line	*cmd_line;
	t_line		*line_before;
	t_dlist		*prompt_dlist;

	cmd_line = ft_inp_cmd_line_get(config);
	ft_inp_cursor_sync(config);
	line_before = ft_create_line_before(config, cmd_line);
	if (!line_before)
		return ;
	prompt_dlist = ft_prompt(config, line_before);
	if (prompt_dlist)
		ft_has_prompt(config, prompt_dlist, line_before);
	ft_dlstclear(&prompt_dlist, (void (*)(void *))ft_line_del);
	ft_line_del(line_before);
}
