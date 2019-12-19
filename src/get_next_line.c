/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fculator <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:57:24 by fculator          #+#    #+#             */
/*   Updated: 2019/09/18 15:10:53 by fculator         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			check_line(char **stack)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp[i] != '\n')
		if ((tmp[i++]) == '\0')
			return (0);
	return (1);
}

int			add_line(char **stack, char **line, int fd, int ret)
{
	int				len;
	char			*curr;

	len = 0;
	while (stack[fd][len] != '\n' && stack[fd][len] != '\0')
		len++;
	if (check_line(&stack[fd]))
	{
		*line = ft_strsub(stack[fd], 0, len);
		curr = ft_strdup(stack[fd] + len + 1);
		free(stack[fd]);
		stack[fd] = curr;
		if (stack[fd][0] == '\0')
			ft_strdel(&stack[fd]);
	}
	else if (stack[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(stack[fd]);
		ft_strdel(&stack[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	static char		*stack[FD_MAX];
	char			*tmp;

	if (read(fd, buffer, 0) < 0 || fd < 0 ||
		FD_MAX > 255 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (stack[fd] == NULL)
			stack[fd] = ft_strnew(1);
		tmp = ft_strjoin(stack[fd], buffer);
		free(stack[fd]);
		stack[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ft_bzero(buffer, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	if (ret == 0 && (stack[fd] == NULL || stack[fd] == '\0'))
		return (0);
	return (add_line(stack, line, fd, ret));
}
