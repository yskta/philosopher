/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:20:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/17 15:49:27 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int main(int argc, char **argv)
{
    t_info  *all_info;

    all_info = (t_info *)malloc(sizeof(t_info));
    if (!all_info)
        return (error_msg("main:malloc error"));
    //引数 1つ目：哲学者の人数 2つ目：死ぬまでの時間 3つ目:食事を終えるまでの時間 4つ目:睡眠を終えるまでの時間 + 5つ目:食事しないといけない回数(任意)
    if (check_input(argc, argv) == false)
        return (0);
    //引数を構造体に格納(データの初期設定)
    if (init_info(all_info, argc, argv) == false)
        return (free_all(all_info));
    //mutexの初期化
    if (init_mutex(all_info) == false)
        return (free_and_destroy_all(all_info));
    //哲学者の初期化
    init_each_philo(all_info);
    //スレッド生成、終了待ち、リソース解放
    if (all_thread_create(all_info) == false)
        return (free_and_destroy_all(all_info));
    freeand_destroy_all(all_info);
    return (0);
}