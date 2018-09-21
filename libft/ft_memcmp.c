/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 04:40:03 by lmahlang          #+#    #+#             */
/*   Updated: 2017/09/29 04:40:18 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*te;
	char	*tem;
	size_t	i;

	te = (char *)s1;
	tem = (char *)s2;
	i = 0;
	while (i < n && te[i] == tem[i])
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)te[i] - (unsigned char)tem[i]);
}
