/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:51:10 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/09/03 14:29:27 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_printf_digit(void *v_print, char c);
static unsigned int	ft_putstr_lst(void *s);
static void			ft_aux_printf(t_ext_list **new, va_list args,
						const char *str, void *ls_va);

int	ft_printf(const char *str, ...)
{
	t_ext_list		*n_ext;
	void			*ls_va;
	va_list			args;
	unsigned int	len_printf;

	n_ext = ft_calloc(1, sizeof(t_ext_list));
	va_start(args, str);
	ls_va = va_arg(args, void *);
	ft_aux_printf(&n_ext, args, str, ls_va);
	len_printf = ft_lstiter(n_ext->head, &ft_putstr_lst);
	ft_lstclear(&n_ext, &free);
	va_end(args);
	return (len_printf);
}

static void	ft_aux_printf(t_ext_list **new, va_list args, const char *str,
		void *ls_va)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i++] == '%' && str[i] != 0)
		{
			if (flag > 0)
				ft_lstadd_back(new, ft_lstnew(ft_substr(str, i - 1 - flag,
							flag)));
			if (ft_strchr("cdiuxXps%", str[i]) && str[i] != 0)
				ft_lstadd_back(new, ft_lstnew(ft_printf_digit(ls_va, str[i])));
			if (ft_strchr("cdiuxXps", str[i++]) && str[i] != 0)
				ls_va = va_arg(args, void *);
			flag = -1;
		}
		flag++;
	}
	if (flag > 0)
		ft_lstadd_back(new, ft_lstnew(ft_substr(str, i - flag, flag)));
}

static unsigned int	ft_putstr_lst(void *s)
{
	int	len;

	len = 0;
	if (((char *)s)[0] == 0)
		len += write(1, &((char *)s)[0], 1);
	else
		len += ft_putstr_fd((char *)s, 1);
	return (len);
}

static char	*ft_printf_digit(void *v_print, char c)
{
	if (c == 'd')
		return (ft_itoa((int)(long long)v_print));
	if (c == 'i')
		return (ft_itoa((int)(long long)v_print));
	if (c == 'u')
		return (ft_uitoa_base((long long)v_print, "0123456789"));
	if (c == 'x')
		return (ft_uitoa_base((long long)v_print, "0123456789abcdef"));
	if (c == 'X')
		return (ft_uitoa_base((long long)v_print, "0123456789ABCDEF"));
	if (c == 'p' && v_print)
		return (ft_memtoa_base((long long)v_print, "0123456789abcdef"));
	if (c == 'p' && !v_print)
		return (ft_strdup("(nil)"));
	if (c == 's' && v_print == ((void *)0))
		return (ft_strdup("(null)"));
	if (c == 's' && ((char *)v_print)[0] == '\0')
		return ((void *)0);
	if (c == 's')
		return (ft_strdup(v_print));
	if (c == 'c')
		return ((char *)ft_memset(ft_calloc(2, 1), (unsigned long)v_print, 1));
	if (c == '%')
		return (ft_strdup("%"));
	return (ft_strdup(""));
}
