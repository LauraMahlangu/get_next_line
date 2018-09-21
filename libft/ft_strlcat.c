/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 05:07:51 by lmahlang          #+#    #+#             */
/*   Updated: 2017/09/29 05:08:02 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*cr;
	char		*redr;
	size_t		l;

	cr = (char *)ft_memchr(dst, '\0', size);
	if (cr == NULL)
		return (size + ft_strlen(src));
	redr = (char *)src;
	l = (size_t)(cr - dst) + ft_strlen(redr);
	while ((size_t)(cr - dst) < size - 1 && *redr != '\0')
	{
		*cr = *redr;
		cr++;
		redr++;
	}
	*cr = '\0';
	return (l);
}
