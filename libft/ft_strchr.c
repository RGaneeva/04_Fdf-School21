/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:36:16 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 13:39:19 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int sym)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	while ((i + 1) > 0)
	{
		if (string[i] == (char)sym)
			return ((char *)string + i);
		i--;
	}
	return (0);
}
