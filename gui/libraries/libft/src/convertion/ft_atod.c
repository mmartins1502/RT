#include "libft.h"

double	ft_atod(char *str)
{
	double	d;
	double	decimal;
	int		len;
	int		neg;

	neg = (str[0] == '-');
	d = ft_atoll(str);
	decimal = 0;
	str = ft_strchr(str, '.');
	if (str && *str + 1)
	{
		str++;
		len = (int)ft_strlen(str);
		decimal = ft_atoll(str);
		while (len--)
			decimal /= 10;
		if (neg)
			decimal *= -1;
	}
	return (d + decimal);
}
