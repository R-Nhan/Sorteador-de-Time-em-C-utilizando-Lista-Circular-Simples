🎲 Sorteador de Pessoas e Times — em C

Um programa em C que permite cadastrar pessoas, visualizar a lista, remover nomes e realizar sorteios tanto de pessoas quanto de times.
Feito para ser rápido, simples e funcional — rodando direto no terminal.
🚀 Funcionalidades
Adicionar pessoas a uma lista encadeada circular
Visualizar todas as pessoas cadastradas
Remover um nome específico
Sortear 1 pessoa com efeito visual de rotação
Sortear times completos a partir da lista
Organização automática dos grupos pelo tamanho escolhido
Utiliza rand(), srand(), listas encadeadas e manipulação de strings
🧠 Como funciona?
O programa usa duas listas:
Lista principal (circular) → armazena todas as pessoas
Lista auxiliar de times → recebe os nomes já sorteados
Os sorteios funcionam avançando um número aleatório de passos por nome, simulando um "giro" antes de escolher o sorteado.
📂 Arquivos do projeto
main.c        → Menu principal e fluxo do programa
sorteio.c     → Lógica de lista, sorteio e montagem dos times
sorteio.h     → Estrutura e cabeçalhos
▶️ Como compilar e executar
No terminal:
gcc main.c sorteio.c -o sorteador
./sorteador
📋 Exemplo do menu
1 - Adicionar na lista
2 - Mostrar lista
3 - Tirar Pessoa
4 - Sortear Pessoa
5 - Sortear Time
6 - Sair
🛠️ Tecnologias
Linguagem C
stdio.h
stdlib.h
time.h
unistd.h
Manipulação de listas encadeadas circulares
🧑‍💻 Autor
Desenvolvido por Ian 👨‍💻
Um projeto para aprendizado e diversão com lógica de programação.
