/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:41:26 by samajat           #+#    #+#             */
/*   Updated: 2022/04/22 23:51:27 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <fcntl.h>

int main ()
{
    int fd;

    fd = open("./Users/samajat/temp/.temp", O_CREAT);
}