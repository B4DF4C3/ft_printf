/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <sgendry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:15:05 by sgendry           #+#    #+#             */
/*   Updated: 2019/04/13 17:28:21 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlendel(char const *s, char c)
{
	int	i;
	int	res;

	i = -1;
	if (!s || c == '\0')
		return (0);
	while (s[++i] && s[i] == c)
		;
	res = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		res++;
	}
	return (res);
}

static	void	ft_freeall(char ***res)
{
	int	i;

	if (!res || !(*res))
		return ;
	i = -1;
	while ((*res)[++i])
		free((*res)[i]);
	free(*res);
	*res = NULL;
}

static void		ft_movenext(char **now, char c, char ***res, int j)
{
	if (!((*res)[j] = ft_strsub(*now, 0, ft_strlendel(*now, c))))
		ft_freeall(res);
	*now = ft_nextword(*now, c);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*now;
	int		i;
	int		j;
	int		len;

	if (!s || c == '\0')
		return (NULL);
	len = ft_wordcount(s, c);
	if (!(res = (char **)malloc((len + 1) * sizeof(char *))))
		return (NULL);
	res[len] = NULL;
	i = -1;
	while (s[++i] && s[i] == c)
		;
	now = (char *)s + i;
	j = -1;
	while (++j < len)
	{
		ft_movenext(&now, c, &res, j);
		if (!res)
			return (NULL);
	}
	return (res);
}
