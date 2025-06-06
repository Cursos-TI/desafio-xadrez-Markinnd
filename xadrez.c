#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

//Comentando o código referente aos desafios Iniciante e Aventureiro
/*
int main() {

    printf("Desafio Xadrez\n");
    printf("\n"); //Pulando uma linha apenas para melhor visualização
    
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.
    // Movimento da Torre (usando for)
    printf("--- Movimento da Torre ---\n");
    for (int i = 1; i <= 5; i++) {
        printf("Casa %d: Direita\n", i);
    }
    printf("\n");
    
    
    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.
    // Movimento do Bispo (usando while)
    printf("--- Movimento do Bispo ---\n");
    int casaBispo = 1;
    while (casaBispo <= 5) {
        printf("Casa %d: Cima, Direita\n", casaBispo);
        casaBispo++;
    }
    printf("\n");

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.
    // Movimento da Rainha (usando do-while)
    printf("--- Movimento da Rainha ---\n");
    int casaRainha = 1;
    do {
        printf("Casa %d: Esquerda\n", casaRainha);
        casaRainha++;
    } while (casaRainha <= 8);
    printf("\n");

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.
    printf("--- Movimento do Cavalo ---\n");
    int movimentoCavalo = 1; //controle do movimento do cavalo

    //loop externo (while)
    while (movimentoCavalo--)
    {
        //loop interno (for)
        for (int i = 0; i < 2; i++)
        {
            printf("Casa %d: Baixo\n", i); //imprime a direção 2 vezes
        }
        
        printf("Casa 3: Esquerda");
    }
    
    printf("\n");

    */

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    // --- Funções Recursivas para Torre, Bispo e Rainha ---

// Função recursiva para movimentação da Torre
// A Torre se move em linha reta.
void moverTorreRecursivo(int casaAtual, int limite, const char *direcao) {
    if (casaAtual <= limite) {
        printf("Casa %d: %s\n", casaAtual, direcao);
        moverTorreRecursivo(casaAtual + 1, limite, direcao); // Chama a si mesma para a próxima casa
    }
}

// Função recursiva para movimentação do Bispo (agora também com loops aninhados para simulação)
// O Bispo se move em diagonal (Cima, Direita).
void moverBispoRecursivoAninhado(int passoVertical, int passoHorizontal, int limitePassos) {
    // Loop externo (recursão): simula o movimento vertical
    if (passoVertical <= limitePassos) {
        printf("  Diagonal: Passo Vertical %d\n", passoVertical);

        // Loop interno (while): simula o movimento horizontal para a mesma diagonal
        int i = 1;
        while (i <= passoHorizontal) { // Para cada passo vertical, faz 1 passo horizontal
            printf("    Movendo para a Direita (Parte Horizontal).\n");
            i++;
        }
        
        // Chamada recursiva para o próximo passo vertical
        moverBispoRecursivoAninhado(passoVertical + 1, passoHorizontal, limitePassos);
    }
}


// Função recursiva para movimentação da Rainha
// A Rainha pode se mover em qualquer direção.
void moverRainhaRecursivo(int casaAtual, int limite, const char *direcao) {
    if (casaAtual <= limite) {
        printf("Casa %d: %s\n", casaAtual, direcao);
        moverRainhaRecursivo(casaAtual + 1, limite, direcao); // Chama a si mesma para a próxima casa
    }
}


int main() {

    printf("Desafio Xadrez\n");
    printf("\n"); //Pulando uma linha apenas para melhor visualização
    
    // Nível Novato - Movimentação das Peças
    
    // Implementação de Movimentação da Torre (com Recursividade)
    printf("--- Movimento da Torre (Recursivo) ---\n");
    moverTorreRecursivo(1, 5, "Direita");
    printf("\n");
    
    // Implementação de Movimentação do Bispo (com Recursividade e Loops Aninhados)
    printf("--- Movimento do Bispo (Recursivo com Loops Aninhados) ---\n");
    // Simulando 5 "casas" diagonais, cada uma com um "passo horizontal" de 1
    moverBispoRecursivoAninhado(1, 1, 5); 
    printf("\n");

    // Implementação de Movimentação da Rainha (com Recursividade)
    printf("--- Movimento da Rainha (Recursivo) ---\n");
    moverRainhaRecursivo(1, 8, "Esquerda");
    printf("\n");

    // --- Nível Intermediário - Movimentação do Cavalo (Loops Aninhados Complexos) ---
    // O Cavalo se move em "L": duas casas em uma direção (horizontal ou vertical) e uma casa na direção perpendicular.
    // Agora: 2 casas para cima e 1 casa para a direita.

    printf("--- Movimento do Cavalo (Loops Aninhados Complexos) ---\n");
    printf("Simulando movimento em L: 2 casas para cima e ENTAO 1 casa para a direita.\n");

    int casasVerticaisPercorridas = 0; // Contador para as casas verticais
    int casasHorizontaisAlvo = 1;      // Alvo de casas horizontais para o movimento
    
    // Loop externo (for): para a parte vertical (2 casas para cima)
    for (int i = 1; i <= 2; i++) { // Itera 2 vezes para as 2 casas para cima
        printf("  Subindo... (Casa %d de 2)\n", i);
        casasVerticaisPercorridas++;

        // Loop interno (while ou do-while, usaremos while aqui): para a parte horizontal
        // Este loop será executado apenas uma vez, e apenas após as casas verticais serem completadas.
        int j = 0; // Contador para a casa horizontal
        while (j < casasHorizontaisAlvo) {
            // Usamos 'continue' para pular a execução do corpo do loop interno
            // se ainda não chegamos ao final do movimento vertical.
            if (casasVerticaisPercorridas < 2) {
                j++; // Incrementa j para evitar loop infinito, mas não faz o movimento horizontal
                continue; 
            }
            
            // Se chegamos aqui, as 2 casas verticais foram percorridas
            printf("    Agora movendo para a direita (Casa %d de 1).\n", j + 1);
            j++; // Incrementa para sair do loop interno (já que só move 1 casa)
            
            // Usamos 'break' para sair do loop interno assim que o movimento horizontal for feito
            break; 
        }
    }
    printf("\n");

    return 0;
}
