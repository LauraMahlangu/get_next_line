/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahlang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 05:17:09 by lmahlang          #+#    #+#             */
/*   Updated: 2017/09/29 05:17:21 by lmahlang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *haystack, int c)
{
	int len;
	int i;

	len = ft_strlen(haystack) + 1;
	i = len - 1;
	while (i >= 0)
	{
		if (haystack[i] == c)
			return ((char *)(haystack + i));
		i--;
	}
	return (NULL);
}
