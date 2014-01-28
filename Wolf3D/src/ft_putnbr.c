/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:51:01 by ibakayok          #+#    #+#             */
/*   Updated: 2013/12/29 20:04:06 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);
int		ft_putstr(char *str);

int		ft_putnbr(int n)
{
	int		l;

	l = 1;
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			l++;
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
		{
			l += ft_putnbr(n / 10);
			l += ft_putnbr(n % 10);
		}
		else
			ft_putchar(48 + n);
	}
	return (l);
}
