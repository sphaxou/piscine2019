/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 05:24:54 by vgallois          #+#    #+#             */
/*   Updated: 2019/06/24 19:47:10 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*f)(void*))
{
	if (!(root))
		return ;
	btree_apply_infix(root->left, f);
	f(root->item);
	btree_apply_infix(root->right, f);
}
