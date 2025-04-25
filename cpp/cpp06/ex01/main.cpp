/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:37:01 by mrocher           #+#    #+#             */
/*   Updated: 2024/12/02 13:27:42 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() 
{
    Data data;
    std::cout << "Original Data obj: " << data.obj << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data obj: " << deserialized->obj << std::endl;

    return 0;
}