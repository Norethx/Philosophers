/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:59:48 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/10/28 12:29:59 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t	panela_livre;
pthread_mutex_t	fogao_livre;
pthread_mutex_t	colher_livre;
pthread_mutex_t	print_cook_mtx;

void			print_cook(int cook, int type);
void			*cook_main(void *cook);

int	main(void)
{
	pthread_t	cook[3];
	int			i;

	i = 0;
	printf("%d",1%5);
	usleep(100000);
	pthread_mutex_init(&panela_livre, NULL);
	pthread_mutex_init(&fogao_livre, NULL);
	pthread_mutex_init(&colher_livre, NULL);
	pthread_mutex_init(&print_cook_mtx, NULL);
	while (i < 3)
	{
		pthread_create(&cook[i], NULL, cook_main, (void *)(long long)i);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		pthread_join(cook[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&panela_livre);
	pthread_mutex_destroy(&fogao_livre);
	pthread_mutex_destroy(&colher_livre);
	pthread_mutex_destroy(&print_cook_mtx);
}

void	print_cook(int cook, int type)
{
	pthread_mutex_lock(&print_cook_mtx);
	if (cook == 0 && type == 0)
		printf("massas está cozinhando:\n");
	if (cook == 1 && type == 0)
		printf("sopa está cozinhando:\n");
	if (cook == 2 && type == 0)
		printf("assado está cozinhando:\n");
	if (cook == 0 && type == 1)
		printf("massas está esperando:\n");
	if (cook == 1 && type == 1)
		printf("sopa está esperando:\n");
	if (cook == 2 && type == 1)
		printf("assado está esperando:\n");
	if (cook == 0 && type == 2)
		printf("massas está pronto! cozinha liberada!\n");
	if (cook == 1 && type == 2)
		printf("sopa está pronto! cozinha liberada!\n");
	if (cook == 2 && type == 2)
		printf("assado está pronto! cozinha liberada!\n");
	pthread_mutex_unlock(&print_cook_mtx);
}

void	*cook_main(void *cook)
{
	while (1)
	{
		print_cook((long long)cook, 1);
		if ((long long)cook == 0)
		{
			pthread_mutex_lock(&panela_livre);
			printf("massas pegou panela\n");
			pthread_mutex_lock(&fogao_livre);
			printf("massas esta ocupando o fogao\n");
		}
		if ((long long)cook == 1)
		{
			usleep(1000);
			pthread_mutex_lock(&fogao_livre);
			printf("sopa esta ocupando o fogao\n");
			pthread_mutex_lock(&colher_livre);
			printf("sopa esta usando a colher\n");
		}
		if ((long long)cook == 2)
		{
			pthread_mutex_lock(&colher_livre);
			printf("assado esta usando a colher\n");
			pthread_mutex_lock(&panela_livre);
			printf("assado pegou panela\n");
		}
		print_cook((long long)cook, 0);
		usleep(1000000);
		print_cook((long long)cook, 2);
		if ((long long)cook == 0)
		{
			pthread_mutex_unlock(&panela_livre);
			pthread_mutex_unlock(&fogao_livre);
		}
		if ((long long)cook == 1)
		{
			pthread_mutex_unlock(&fogao_livre);
			pthread_mutex_unlock(&colher_livre);
		}
		if ((long long)cook == 2)
		{
			pthread_mutex_unlock(&colher_livre);
			pthread_mutex_unlock(&panela_livre);
		}
		usleep(1000);
	}
	return (NULL);
}
