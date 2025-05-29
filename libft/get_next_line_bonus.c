/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:22:53 by bnespoli          #+#    #+#             */
/*   Updated: 2024/09/02 20:41:52 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_make_line(t_vars *lst)
{
	t_listg		*tmp;
	char		*line;
	int			count;

	line = (char *)malloc((lst->len + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	count = 0;
	tmp = NULL;
	while (lst->list)
	{
		tmp = lst->list->next;
		line[count] = lst->list->content;
		free(lst->list);
		lst->list = tmp;
		count++;
	}
	line[count] = '\0';
	return (line);
}

char	*ft_read_line(t_vars *lst)
{
	lst->len = 0;
	while (lst->read_bytes > 0)
	{
		ft_lstadd_backgnl(&lst->list, ft_lstnewgnl(lst->buffer[lst->index]));
		if (!(lst->buffer[lst->index]) || lst->buffer[lst->index] == '\n')
			break ;
		lst->index++;
		lst->len++;
		if (lst->index >= lst->read_bytes)
		{
			lst->index = 0;
			lst->read_bytes = read(lst->fd, lst->buffer, BUFFER_SIZE);
			if (lst->read_bytes == -1)
				return (ft_lstcleargnl(&(lst->list)));
		}
	}
	lst->index++;
	lst->len++;
	return (ft_make_line(lst));
}

char	*get_next_line(int fd)
{
	static t_vars	str[1024];

	if (fd < 0 || fd > 1024)
		return (NULL);
	if (str[fd].index >= str[fd].read_bytes || str[fd].index == 0)
	{
		str[fd].index = 0;
		str[fd].fd = fd;
		str[fd].len = 0;
		str[fd].list = NULL;
		while (str[fd].index < BUFFER_SIZE)
			str[fd].buffer[str[fd].index++] = '\0';
		str[fd].read_bytes = read(fd, str[fd].buffer, BUFFER_SIZE);
		if (str[fd].read_bytes == -1)
			return (ft_lstcleargnl(&str[fd].list));
		str[fd].index = 0;
	}
	if (str[fd].read_bytes <= 0 || str[fd].buffer[str[fd].index] == '\0')
	{
		if (str[fd].read_bytes < 0 && str[fd].list)
			ft_lstcleargnl(&str[fd].list);
		return (NULL);
	}
	return (ft_read_line(&str[fd]));
}
