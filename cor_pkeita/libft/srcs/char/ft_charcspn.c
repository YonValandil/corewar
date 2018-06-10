/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcspn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysingaye <ysingaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:38:46 by ysingaye          #+#    #+#             */
/*   Updated: 2018/03/22 14:40:22 by ysingaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_charcspn(const char *str1, char c)
{
	int i;

	i = 0;
	while (str1[i] && c != str1[i])
		i++;
	return (i);
}
