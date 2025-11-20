/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall-reborn.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:52:30 by acennadi          #+#    #+#             */
/*   Updated: 2025/05/30 15:56:08 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSCALL_REBORN_h
#define SYSCALL_REBORN_h

//includes
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

//functions parametre
int ft_dup2(int oldfd, int newfd);
int ft_dup(int oldfd);

#endif