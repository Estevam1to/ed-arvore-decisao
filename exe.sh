#!/bin/bash

exe() {
    if [ "$#" -eq 1 ]; then
        clear && g++ -Wall -Wextra -Werror -O2 -std=c++20 "$1" && ./a.out < entrada
    elif [ "$#" -eq 2 ]; then
        clear && g++ -Wall -Wextra -Werror -O2 -std=c++20 "$1" && ./a.out < "$2"
    elif [ "$#" -eq 3 ]; then
        clear && g++ -Wall -Wextra -Werror -O2 -std=c++20 "$1" && ./a.out < "$2" > "$3"
    else
        echo "Uso incorreto: exe <arquivo.cpp> [entrada.txt] [saida.txt]"
    fi
}

# Validate the number of arguments
if [ "$#" -gt 3 ]; then
    echo "Erro: número de parâmetros inválido"
    echo "Uso correto: exe <arquivo.cpp> [entrada.txt] [saida.txt]"
else
    # Call the exe() function with the appropriate arguments
    exe "$@"
fi
