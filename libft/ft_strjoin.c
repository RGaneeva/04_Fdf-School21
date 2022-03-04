/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:30:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/05/07 12:35:27 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefstr, char const *sufstr)
{
	char	*addstr;
	size_t	lenght;
	char	*result;

	if (!prefstr)
		return (0);
	lenght = 0;
	if (!prefstr && sufstr)
		lenght = ft_strlen(prefstr) + 1;
	else if (prefstr && sufstr)
		lenght = ft_strlen(prefstr) + ft_strlen(sufstr) + 1;
	addstr = (char *) malloc(sizeof(char) * lenght);
	if (!addstr)
		return (0);
	result = addstr;
	if (prefstr)
		while (*prefstr)
			*addstr++ = *prefstr++;
	if (sufstr)
		while (*sufstr)
			*addstr++ = *sufstr++;
	*addstr = '\0';
	return (result);
}
/* joins two strings and allocates memory to it*/
