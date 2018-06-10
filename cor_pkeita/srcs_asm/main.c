/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:41:32 by overetou          #+#    #+#             */
/*   Updated: 2018/06/10 13:07:03 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void	ft_asm(t_champ *champ)
{
	champ->name = NULL;
	champ->comment = NULL;
	champ->cmd = NULL;
	champ->label = NULL;
	champ->comment_char[0] = ';';
	champ->comment_char[1] = COMMENT_CHAR;
	champ->comment_char[2] = '\0';
	store_header(champ);
	parse_args(champ);
	if (!champ->cmd)
		ft_error(champ, "No params");
	valid_labels(champ);
}

void	read_file(t_champ *champ, char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)//si on a resussi a ouvrir le fichier
		ft_error(champ, "BUG OPEN FILE");
	if (!(champ->file_len = lseek(fd, 0, SEEK_END)))//si il est pas vide (lseek?)
		ft_error(champ, "Empty file");
	if (!(champ->file = ft_strnew(champ->file_len)))//on malloc champ->file de la taille du fichier (check si malloc ok)
		ft_error(champ, "MALLOC FAIL");
	lseek(fd, 0, SEEK_SET);//on remet lseek a zero
	if (read(fd, champ->file, champ->file_len) < 0)//on read le file (check si read ok)
		ft_error(champ, "READ FAIL");
	if (close(fd) < 0)//close le fichier (check si close ok)
		ft_error(champ, "CLOSE FAIL");
}

int		main(int argc, char **argv)
{
	t_champ	champ;
	int		arg;
	int		len;

	arg = 0;
	if (argc < 2)
	{
		ft_printf("Usage : ./asm *.s ...\n");
		return (0);
	}
	while (++arg < argc)//on fait l'assemblage pour chaque champion entré en param (while counter < argc)
	{
		len = ft_strlen(argv[arg]) - 1;
		if (len > 1 && argv[arg][len] == 's' && argv[arg][len - 1] == '.') //si le format du fichier est bon
		{
			ft_bzero(&champ, sizeof(champ));//initialisation de toute la structure a zero
			read_file(&champ, argv[arg]);//on ouvre on lit, on fill le res dans la structure, on check
			ft_asm(&champ);//assignation des bonne values dans la structure (store_header(), parse_args(), valid_labels())
			file_creation(&champ, argv[arg]);//
			free_champ(&champ);//tous les free du champion
		}
		else//sinon file invalid
			ft_printf("File %d is invalid\n", arg);
	}
	return (0);
}
