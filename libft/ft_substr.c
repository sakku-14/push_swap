/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:55:46 by ysakuma           #+#    #+#             */
/*   Updated: 2021/04/28 15:29:43 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*ret_c;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	*ret = '\0';
	if (ft_strlen(s) <= start)
		return (ret);
	while (start-- && *s)
		s++;
	ret_c = ret;
	while (*s && len--)
		*ret_c++ = *s++;
	*ret_c = '\0';
	return (ret);
}
