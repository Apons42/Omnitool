/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmanip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:43:28 by apons             #+#    #+#             */
/*   Updated: 2019/05/24 10:56:07 by apons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**ft_tabcpy(char **dst, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (!(dst[i] = ft_strnew(ft_strlen(tab[i]))))
			return (NULL);
		dst[i] = ft_strcpy(dst[i], tab[i]);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
