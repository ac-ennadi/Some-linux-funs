/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acennadi <acennadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:41:47 by acennadi          #+#    #+#             */
/*   Updated: 2025/11/20 14:58:17 by acennadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//F_DUPFD : Duplicate the file descriptor to greater than or equal to arg (newfd)
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

 int ft_dup2(int oldfd, int newfd)
 {
    int new_fd;

    if (oldfd == newfd)
        return (oldfd);
    close(newfd);
    new_fd = fcntl(oldfd, F_DUPFD, newfd);
    if (new_fd)
        return (-1);
    return (new_fd);
 }
 
