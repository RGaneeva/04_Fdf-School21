/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_module.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarmeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:09:37 by pcarmeli          #+#    #+#             */
/*   Updated: 2021/12/26 13:33:10 by pcarmeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_module(float i)
{
	if (i < 0)
		return (i * (-1));
	else
		return (i);
}