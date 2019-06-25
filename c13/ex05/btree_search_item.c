/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:39:28 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/25 01:49:27 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root,
		void *data, int (*cmpf)(void *, void *))
{
	void	*res;

	if (!root)
		return (NULL);
	res = btree_search_item(root->left, data, cmpf);
	if (res)
		return (res);
	if (cmpf(data, root->item) == 0)
		return (root);
	res = btree_search_item(root->right, data, cmpf);
	return (res);
}
