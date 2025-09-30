/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:54:16 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/30 15:54:16 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrchr(const char *s, int c);

char    *ft_strrchr(const char *s, int c)
{
    char                *occ;
    unsigned long long  i;

    occ = (void *) 0; //Puede que esto no se detecte como NULL
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            occ = s[i];
        i++;
    }
    return (occ);
}