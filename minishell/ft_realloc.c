/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeson <hyeson@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 04:07:44 by hyeson            #+#    #+#             */
/*   Updated: 2025/05/17 18:14:56 by hyeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	ft_bzero(tmp, size);
	ft_memcpy(tmp, ptr, size);
	free(ptr);
	return (tmp);
}
