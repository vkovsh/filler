/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:11:18 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/17 17:38:37 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	t_pfargs	pf;
	char		*first_spec;
	t_list		*tmp;

	first_spec = NULL;
	pf.length = 0;
	pf.fd = 1;
	if (!(first_spec = ft_strchr(format, '%')))
		return (ft_output(pf.fd, format, &(pf.length)));
	init_list(format, &(pf.t), &(pf.output));
	va_start(pf.argptr, format);
	tmp = pf.t;
	while (pf.t)
	{
		set_spec(&pf);
		check_asterisk(&pf);
		set_value(&pf);
		pf.t = (pf.t)->next;
	}
	va_end(pf.argptr);
	ft_output(pf.fd, pf.output, &(pf.length));
	ft_strdel(&(pf.output));
	ft_lstdel(&tmp, &del_one);
	return (pf.length);
}
