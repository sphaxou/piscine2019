/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:45:30 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 19:52:54 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left;
	int right;

	if (!root)
		return (0);
	left = 1 + btree_level_count(root->left);
	right = 1 + btree_level_count(root->right);
	return (left > right ? left : right);
}
