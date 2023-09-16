/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:20:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/16 19:14:27 by yokitaga         ###   ########.fr       */
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
    if (init_data(all_info, argc, argv) == false)
        return (free_all(all_info));
    //mutexの初期化
    if (init_mutex(all_info) == false)
        return (free_all(all_info));
    //哲学者の初期化
    //if (init_philo(all_info) == false)
        //return (free_all(all_info));
    printf("start\n");
    //スレッド生成
    
    //スレッドの終了待ち

    //スレッドの破棄
    
    return (0);
}