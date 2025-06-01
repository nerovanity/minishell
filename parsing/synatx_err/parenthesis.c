/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihamani <ihamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:21:13 by moel-oua          #+#    #+#             */
/*   Updated: 2025/06/01 11:19:45 by ihamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	parenthesis(char *line, int i)
{
	while (line[i] != '\0')
	{
		if (ft_chrstr(line[i], "()"))
			return (false);
		i++;
	}
	return (true);
}
