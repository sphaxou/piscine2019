/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:00:16 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 19:49:23 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	if (!(new = (t_btree*)malloc(sizeof(t_btree))))
		return (0);
	new->item = item;
	new->left = 0;
	new->right = 0;
	return (new);
}
