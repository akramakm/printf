/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-akma <ael-akma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:23:18 by ael-akma          #+#    #+#             */
/*   Updated: 2023/01/16 04:42:35 by ael-akma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

// int ft_strlen(char *str)
// {
//     int i = 0 ;
//     while(str[i])
//     {
//         i++;
//     }
//     return(i);
// }

void	ft_putchar(char c)
{
	write (1, &c, 1);
}


void	ft_putstr_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}



void	ft_putnbr(int n)
{
	long int	i;
	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
	{
		ft_putchar(i % 10 + '0');
	}
}


int sume(char *str , ...)
{
    va_list akram;
    int i = 0; 
    va_start(akram,str);
    while(str[i])
    {
        
        if(str[i] == '%')
        {
            i++;
                if(str[i] == 'd')
            {
                int str0 = va_arg(akram,int);
                ft_putnbr(str0);
             }
             else if(str[i] == 's')
             {
             char* str1 = va_arg(akram,char*);
             printf("%s ",str1);
             }
            else if (str[i] == 'c')
            {
            char str2 = va_arg(akram,int);
            printf("%c ",str2);
            }
            else if(str[i] == '%')
            {
                printf("%%");
            }
        }
        else
        {
            ft_putchar(str[i]);
        }
        i++;
    }
    va_end(akram);
    return(0);
}





int main()
{
    // sume("%d %s %c && %%",4,"akram",'c');
    printf("%X",244);
}