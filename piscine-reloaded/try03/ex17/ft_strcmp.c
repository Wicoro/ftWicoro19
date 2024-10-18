/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:46:52 by norban            #+#    #+#             */
/*   Updated: 2024/10/08 09:32:44 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}
/*int main()
{
	char *str1 = "abcdewww";
	char *str2 = "alpha";
	int a = ft_strcmp(str1, str2);
	int b = strcmp(str1, str2);
	printf("%d\n", a);
	printf("%d\n", b);
}*/
