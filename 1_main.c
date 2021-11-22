/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:52:12 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/22 14:49:34 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_empty(char **argv)
{
	int	i;
	int	j;
	int	cd;

	i = -1;
	while (argv[++i])
	{
		if (argv[i][0] == '\0')
			return (0);
	}
	i = 0;
	while (argv[++i])
	{
		cd = 0;
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				cd++;
		if (!cd)
			return (0);
	}
	return (1);
}

static int	ft_check_char(char *s, int j)
{
	if (s[j] <= 31 || (s[j] >= '!' && s[j] <= '*') || s[j] == ','
		|| s[j] == '.' || s[j] == '/' || s[j] >= ':' || s[0] == '\0')
		return (1);
	if ((s[j] == '-' || s[j] == '+') && (s[j + 1] == '-' || s[j + 1] == '+'))
		return (1);
	if ((s[j] == '-' || s[j] == '+') && (s[j + 1] == ' ' || s[j + 1] == '\0'))
		return (1);
	return (0);
}

static int	ft_check_arg(char *s, t_arg *arg, int j)
{
	while (s[j] != '\0')
	{
		if (ft_check_char(s, j))
		{
			write(2, "Error\n", 6);
			free(s);
			return (0);
		}
		else
			j++;
	}
	arg->av = (char **)ft_split(s, ' ');
	if (arg->av == NULL)
	{
		write(2, "Error\n", 6);
		ft_free_split(arg->av);
		return (0);
	}
	free(s);
	return (1);
}

int	ft_rows(t_arg *arg)
{
	int	i;

	i = 0;
	while (arg->av[i])
		i++;
	arg->ac = i + 1;
	return (i);
}

int	main(int argc, char **argv)
{
	t_arg	arg;
	t_var	var;
	char	*s;

	arg.ac = argc;
	arg.av = argv;
	if (argc <= 1)
		return (1);
	s = ft_strjoin(argc - 1, &argv[1], " ");
	if (s == NULL || !ft_check_empty(argv))
	{
		write(2, "Error\n", 6);
		if (s)
			free(s);
		return (1);
	}
	if (!(ft_check_arg(s, &arg, 0)) || !(ft_check_dupl(&arg)))
		return (1);
	var = ft_init_var(ft_rows(&arg));
	if (!(ft_check_minmax(&arg, 0)))
		return (1);
	if (!(ft_create_stack(&arg, &var)))
		return (1);
	return (0);
}
