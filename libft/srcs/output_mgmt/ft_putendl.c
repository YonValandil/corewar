/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:18:17 by pde-rent          #+#    #+#             */
/*   Updated: 2017/11/25 21:21:30 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_mgmt.h"

void	ft_putendl(const char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
