/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:47:34 by lmahlang          #+#    #+#             */
/*   Updated: 2018/01/18 15:53:02 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int						ft_save_to_line(char **line, char **reserve)
{
	char				*tmp;
	char				*tmp2;
	size_t				len;

	if (ft_strchr(*reserve, '\n'))
	{
		len = ft_strchr(*reserve, '\n') - *reserve;
		tmp = ft_strsub(*reserve, 0, len);
		tmp2 = *line;
		*line = ft_strjoin(*line, tmp);
		ft_strdel(&tmp2);
		ft_strdel(&tmp);
		tmp = *reserve;
		*reserve = ft_strsub(*reserve, len + 1, ft_strlen(tmp));
		ft_strdel(&tmp);
		return (1);
	}
	tmp = *line;
	*line = ft_strjoin(*line, *reserve);
	ft_strdel(&tmp);
	ft_strdel(&*reserve);
	return (0);
}

int						get_next_line(int fd, char **line)
{
	static char			*rsv = NULL;
	int					ret;
	char				*tmp;

	if (fd <= -1 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (!rsv && (rsv = ft_strnew(BUFF_SIZE)))
		if ((ret = read(fd, rsv, BUFF_SIZE)) == -1)
			return (-1);
	*line = ft_strnew(1);
	while (1)
	{
		if ((ft_save_to_line(line, &rsv)) || !(rsv = ft_strnew(BUFF_SIZE)))
			return (1);
		if ((ret = read(fd, rsv, BUFF_SIZE)) == -1)
			return (-1);
		else if (!ret)
		{
			if (ft_strlen(*line) == 0)
				return (0);
			tmp = rsv;
			rsv = ft_strjoin(rsv, "\n");
			ft_strdel(&tmp);
		}
	}
}
