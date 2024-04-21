/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:00:27 by mwojtcza          #+#    #+#             */
/*   Updated: 2024/03/09 20:51:37 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

static int	ft_word_countv2(char const *s, char c)
{
	int	count;
	int	inword;

	inword = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !inword)
		{
			count++;
			inword = 1;
		}
		else if (*s == c)
			inword = 0;
		s++;
	}
	return (count);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**list;
	const char	*tmp;
	int			i;
	int			lenword;

	lenword = ft_word_countv2(s, c);
	list = (char **)malloc((lenword + 1) * sizeof(char *));
	if (!list)
		return (0);
	i = 0;
	while (i < lenword)
	{
		while (*s == c && *s)
			s++;
		tmp = s;
		while (*s && *s != c)
			s++;
		list[i] = ft_substr(tmp, 0, s - tmp);
		if (!list[i])
			return (ft_free(list, i));
		i++;
	}
	list[i] = NULL;
	return (list);
}

/*
#include <stdio.h> // for printf
#include <stdlib.h> // for free

int main(void)
{
    char const *s = "   asdf asdf     ";
    char c = 'x';
    char **result = ft_split(s, c);
    
    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("%s\n", result[i]);
            free(result[i]); // Free memory allocated for each word
        }
        free(result); // Free memory allocated for the array of pointers
    }
    
    return 0;
}
*/
