/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:25:35 by anshimiy          #+#    #+#             */
/*   Updated: 2023/08/31 14:14:58 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief		Close possibly used file descriptors by dup() function
/// @details Closes all file descriptors from 3 to 200 since dup()
///				allocate an fd from the smallest available
void	ft_close_fd(void)
{
	int	i;

	i = 2;
	while (++i < 50)
	{
		close(i);
	}
}

void	ft_check_exit(t_state *state)
{
	ft_close_fd();
	ft_free_all(state);
}
