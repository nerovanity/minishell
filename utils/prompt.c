/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:02:42 by ihamani           #+#    #+#             */
/*   Updated: 2025/06/02 10:25:52 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*prompt(t_c *c)
{
	char	*username;
	char	*pwd;
	char	*pro;

	username = ft_getenv("USER", c->ft_env);
	if (!username[0])
		username = ft_strdup("Minishell", c->garbage);
	pwd = ft_getenv("PWD", c->ft_env);
	if (!pwd[0])
	{
		pwd = getcwd(NULL, 0);
		ft_add_gc(c->garbage, ft_new_gc_node(pwd));
	}
	pro = ft_strjoin("\033[0;32m", username, c->garbage);
	pro = ft_strjoin(pro, "\033[0m:", c->garbage);
	pro = ft_strjoin(pro, pwd, c->garbage);
	pro = ft_strjoin(pro, "$ ", c->garbage);
	return (pro);
}