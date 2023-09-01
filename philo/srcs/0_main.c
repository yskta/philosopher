/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:20:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/09/01 16:15:39 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    check_input(int argc, char **argv)
{
    //引数のエラー処理
    
    return (true);
}

void    set_init_data(int argc, char **argv)
{
    //引数を構造体に格納(データの初期設定)
}

int main(int argc, char **argv)
{
    
    //引数チェック
    if (argc < 5 || argc > 6)
		return (1);
    if (check_and_input(argc, argv) == false)
        return (1);
    //引数を構造体に格納(データの初期設定)
    set_init_data(int argc, char **argv);
    //スレッド生成
    
    //スレッドの終了待ち

    //スレッドの破棄
    
    return (0);
}