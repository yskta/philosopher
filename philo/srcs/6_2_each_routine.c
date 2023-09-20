/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_2_each_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:31:52 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/19 22:20:42 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	take_fork_routine(t_each_philo *philo, t_info *all_info)
{
	pthread_mutex_lock(philo->right_fork);
	print_time_and_routine(all_info, philo->id, NUM_TAKE_FORK);
	pthread_mutex_lock(philo->left_fork);
	print_time_and_routine(all_info, philo->id, NUM_TAKE_FORK);
}

void	eat_count_check(t_each_philo *philo, t_info *all_info)
{
	//monitorスレッドもアクセスするので、ロックする
	pthread_mutex_lock(&all_info->end_flag);
	if (philo->eat_times == all_info->finish_eating_count)
		all_info->num_of_philo_finish_eating++;
	if (all_info->num_of_philo_finish_eating == all_info->num_of_philo)
		all_info->can_continue = false;
	pthread_mutex_unlock(&all_info->end_flag);
}

void	eat_routine(t_each_philo *philo, t_info *all_info)
{
	//monitorスレッドも死んだかどうかを判定するためにphilo->last_eat_timeにアクセスするので、ロックする
	pthread_mutex_lock(philo->time);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(philo->time);
	//食事を始めたことを表示
	print_time_and_routine(all_info, philo->id, NUM_EAT);

	//食事した回数をカウント&終わったかどうかを確認
	if (all_info->need_to_count)
	{
		philo->eat_times++;
		eat_count_check(philo, all_info);//全員が食事を終えたかどうかを確認
	}
	//この辺から
	// if (philo->ideal_time != 0)//偶数番目の哲学者 あるいは奇数番目の哲学者の最後の人
	// 	lag = philo->ideal_time - get_elapsed_time(info);
	// philo->ideal_time = philo->ideal_time + info->time_to_eat;
	//この辺までの処理は、よくわからない
	wait_time(all_info->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	sleep_routine(t_each_philo *philo, t_info *all_info)
{
	//size_t	lag;

	print_time_and_routine(all_info, philo->id, NUM_SLEEP);
	//lag = philo->ideal_time - get_elapsed_time(info);
	//philo->ideal_time = philo->ideal_time + time_to_sleep;
	wait_time(all_info->time_to_sleep);
}

void	think_routine(t_each_philo *philo, t_info *all_info)
{
	//size_t	lag;
	//size_t	wait_time;

	//wait_time = 0;
	// if (info->sum_of_philo % 2 && info->time_to_sleep < info->time_to_eat * 2)
	// 	wait_time = info->time_to_eat * 3 - (info->time_to_eat + info->time_to_sleep);
	print_time_and_routine(all_info, philo->id, NUM_THINK);
	//lag = philo->ideal_time - get_elapsed_time(info);
	//philo->ideal_time = philo->ideal_time + wait_time;
	//wait_time(all_info->time_to_sleep + lag, info);
}