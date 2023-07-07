#!/bin/bash

exe() {
    if [ "$#" -eq 1 ]; then
        g++ -Wall -Wextra -Werror -O2 -std=c++20 "$1" && ./a.out
    elif [ "$#" -eq 2 ]; then
        g++ -Wall -Wextra -Werror -O2 -std=c++20 "$1" && ./a.out < "$2"
    elif [ "$#" -eq 3 ]; then
        g++ -Wall -Wextra -Werror -O2 -std=c++20 "$1" && ./a.out < "$2" > "$3"
    else
        echo "Uso incorreto: exe <arquivo.cpp> [entrada.txt] [saida.txt]"
    fi
}

# Chame a função exe() com os argumentos adequados
exe "$@"