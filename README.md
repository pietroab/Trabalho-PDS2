# CARDGAME TRUNFO DE CARROS

Este será o jogo escolhido para o trabalho da disciplina de PDS2. Como dito anteriormente o jogo será o Trunfo com a temática de carros. A ideia inicial será de que o jogo se inicia após a distribuição das cartas para os jogadores. Cada jogador irá começar com 7 cartas na mão onde cada carta receberá um id para identificação e 5 atributos associados a ela. Uma vez escolhida a carta pelo o id, o jogador terá que escolher um dos 5 atributos para ser comparado a carta do adversário. Após a comparação, o jogador que obtiver a vitória receberá a carta do adversário. Em caso de empate, uma nova rodada se inicia até que se obtenha um vencedor. O jogo termina quando um jogador obtiver todas as cartas em sua mão.





# INTEGRANTES:

Pietro Urcine de Abreu

Jose Tarcisio Prata Junior




# USER STORIES:


### Iniciar jogo:

Eu, enquanto jogador, gostaria de iniciar um jogo com um deck embaralhado divido por 2.


### Terminar jogo:

Eu, enquanto jogador, gostaria que o jogo terminasse quando o objetivo for atingido por um jogador.


### Selecionar baralho:

Eu, enquanto jogador, quero escolher um baralho para começar um novo jogo.


### Escolher atributo da carta:

Eu, enquanto jogador, quero selecionar um atributo da carta para ser comparado com o do outro jogador.


### Receber carta do oponente:

Eu, enquanto jogador, quero receber a carta de meu oponente se eu ganhar.


### Selecionar numero de jogadores:

Eu, enquanto jogador, quero escolher o numero de jogadores que quero jogar contra.

# ⚠️ Pré-requisitos

- Ter o MinGW instalado.
- Possuir um compilador para C++
- É recomendável utilizar um ambiente linux

# ⚠️ ATENÇÃO: O Jogo possui 2 modos.

- O Jogo se inicia no modo DEBUG, caso queira sair do modo DEBUG, altere a linha 14 do arquivo main da pasta src mudando #define para false.

# 📁 Acesso 

- Faça o Download da Pasta src
- Entre no diretório da pasta
- Para compilar o projeto digite o comando: g++ -o jogo *.cpp 
- Para executar o projeto digite o comando: jogo.exe

