#Apresentação

Este projeto tem como foco principal desenvolver uma versão em texto do jogo Keno, que consiste na escolha de até 15 números pelo jogador, que podem ser sorteados pela máquina, que, dependendo da probabilidade de combinação dos números, pode resultar em um retorno financeiro maior ao qual o jogador investiu na aposta.

#O que foi feito

O executável não apresentou problemas em tempo de execução durante a fase de testes, assim como durante a implementação. Logo, é possível chegar a conclusão que o código está funcional.

#O que não foi feito

Não foi possível fazer a documentação devida no doxygen, assim como não há um arquivo makefile, o que torna o processo de compilação um pouco mais complicado para o usuário.

#Compilar

Já que há ausência de um arquivo makefile, o usuário pode digitar o seguinte comando no terminal: 
"g++ -Wall -std=c++11 ./src/Keno.cpp ./src/main.cpp -I ./include/ -o ./bin/KenoGame"
É importante frizar que o seguinte comando só terá sucesso caso o usuário esteja no diretório "KenoGame", onde se encontram os subdiretórios com os arquivos de código.
Após a compilação, o usuário pode acessar o diretório bin e executar o seguinte comando "KenoGame <nome do arquivo de entrada>", onde o arquivo de entrada possui as informações a serem passadas para o programa.

#Autor

Anderson Santos de Medeiros
