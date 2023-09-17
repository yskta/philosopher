/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_each_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:16:55 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/17 15:00:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

//要注意。あとで修正必要かも。
void    set_ideal_time(t_each_philo *philo, t_info *all_info, size_t i)
{
	if (i % 2)//iが奇数の場合。すなわち哲学者の番号がi + 1なので偶数
		philo->ideal_time = all_info->time_to_eat;
	else//iが偶数の場合
		philo->ideal_time = 0;
	if (all_info->num_of_philo % 2 && i + 1 == all_info->num_of_philo)//哲学者の人数が奇数の場合、最後の哲学者は食事を終えるまでの時間を2倍にする。なぜなら左どなりが1番だから、1番の食事後、ようやく食べられる。詳しくはnafukaさんの説明を参照
		philo->ideal_time = all_info->time_to_eat * 2;
}

void    init_each_philo(t_info *all_info)
{
	size_t i;
	t_each_philo *philos;

	philos = all_info->all_philos;
	i = 0;
	while (i < all_info->num_of_philo)
	{
		philos[i].id = i + 1; //哲学者の番号
		philos[i].eat_times = 0; //食事を終えた回数
		philos[i].last_eat_time = 0; //最後に食事をした時間
		philos[i].right_fork = &(all_info->fork[i]);
		philos[i].right_fork = &(all_info->fork[(i + 1) % all_info->num_of_philo]); //左のフォーク
		philos[i].time = &(all_info->time[i]); //時間
		philos[i].info = (void *)all_info; //構造体のアドレス
		philos[i].can_continue = &(all_info->can_continue); //続けられるかどうか
		philos[i].ideal_time = 0; //食事を終えるまでの時間
		set_ideal_time(&philos[i], all_info, i);
		i++;
	}
}