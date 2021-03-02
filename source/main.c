/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:01:06 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/02 14:44:58 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

#include "carbon.h"

int
	main(void)
{
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		line = msh_prompt();
		if (!str_cmp(line, "exit\n"))
		{
			status = 0;
			fmt_print(line);
		}
		else
		{
			fmt_print("input: ");
			fmt_print(line);
		}
	}
	return (0);
}
