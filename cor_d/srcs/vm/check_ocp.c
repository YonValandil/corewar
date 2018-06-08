/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ocp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:45:10 by lchety            #+#    #+#             */
/*   Updated: 2018/06/08 20:23:08 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//ocp_chunk valeur du morceaux recup par le mask
int		arg_available(int ocp_chunk, int opcode, int num_arg)//est appelé pour chaque argument, check la value
{
	if (ocp_chunk < 1 || ocp_chunk > 3)
		return (0);
	if (ocp_chunk == 3)
		ocp_chunk += 1;//voir define t_ind +1 pour le mask binaire 0100 a la place de 11
	if (ocp_chunk & g_op_tab[opcode - 1].ocp[num_arg])//
		return (1);
	return (0);
}

int		check_ocp(int ocp, int opcode)
{
	int		nb_arg;

	nb_arg = g_op_tab[opcode - 1].nb_arg;

	// arg_available, le dernier param: 0 = 1er arg, 1 = 2em arg, 2 = 3em arg
	if (nb_arg >= 1 && !arg_available((ocp & 0xC0) >> 6, opcode, 0))//prend que la value necessaire et l'envoi a droite
		return (0);
	if (nb_arg >= 2 && !arg_available((ocp & 0x30) >> 4, opcode, 1))
		return (0);
	if (nb_arg >= 3 && !arg_available((ocp & 0xC) >> 2, opcode, 2))
		return (0);
	return (1);
}
