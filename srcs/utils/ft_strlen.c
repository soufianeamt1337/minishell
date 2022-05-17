/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelmoham <eelmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:01:41 by samajat           #+#    #+#             */
/*   Updated: 2022/05/17 20:02:28 by eelmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    if (!str || !str[0])
        return (0);
    while (str[i])
        i++;
    return (i);    
}