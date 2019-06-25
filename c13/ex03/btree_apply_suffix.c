/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:28:58 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 19:47:42 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, f);
	btree_apply_suffix(root->right, f);
	f(root->item);
}
