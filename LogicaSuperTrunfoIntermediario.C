#include <stdio.h>   // Biblioteca para entrada e saída (printf, scanf).
#include <stdlib.h>  // Biblioteca para funções gerais como exit().

// Função que inicia  o jogo

void iniciarJogo() {

    printf("\n    Iniciando o Jogo...    \n");

    // Declarações de variáveis para armazenar informações das  duas cartas(países).

     char Pais1[100], Pais2[100]; // Nome do país.
    char Estado1[100], Estado2[100]; // Variável Estado será identificada pelas letras de A a H.
    char Cidade1[100], Cidade2[100]; // Variável da cidade será númerada de 1 a 4.

     unsigned long int populacao1, populacao2; // Número de habitantes.
    float area1, area2; // Área da cidade em quilometros quadrados.
    float pib1, pib2; // O produto interno da cidade.
    int pontos_turisticos1, pontos_turisticos2;  // Número de pontos turisticos.
    float densidade1, densidade2; // Densidade demográfica da cidade.

    // Coletando informações da carta 1

    printf("\n    Carta 1:    \n");
    printf("Digite o nome do país:\n");
    scanf(" %[^\n]", Pais1); //espaço antes do %c para consumir o '\n' pendente
    
    printf("Digite a População:\n");
    scanf("%lu", &populacao1);

    printf("Digite a Área:\n");
    scanf("%f", &area1);

    printf("Digite o PIB:\n");
    scanf("%f", &pib1);
    
    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &pontos_turisticos1);

    // Coletando informações da carta 2

    printf("\n    Carta 2:    \n");
    printf("Digite o nome do país:\n");
    scanf(" %[^\n]", Pais2); // espaço antes do %c para consumir o '\n' pendente.

    printf("Digite a População:\n");
    scanf("%lu", &populacao2);

    printf("Digite a Área:\n");
    scanf("%f", &area2);

    printf("Digite o PIB:\n");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &pontos_turisticos2);

    // Cálculo da densidade demográfica (população / área).

    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    // Exibi menu de atributos para o jogador escolher.
    int opcao;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    printf("\nResultado da comparação:\n");

    // Compara os atributos escolhidos.

    switch (opcao) {

        case 1:
         printf("Atributo: População\n");
         printf("%s: %lu habitantes\n", Pais1, populacao1);
         printf("%s: %lu habitantes\n", Pais2, populacao2);
        if (populacao1 > populacao2) {
            printf("A carta 1 venceu!\n");
        } else if (populacao1 < populacao2) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        break;

    case 2:
        printf("Atributo: Área\n");
        printf("%s: %.2f km²\n", Pais1, area1);
        printf("%s: %.2f km²\n", Pais2, area2);
        if (area1 > area2) {
            printf("A carta 1 venceu!\n");
        } else if (area1 < area2) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        break;

        case 3:
        printf("Atributo: PIB\n");
        printf("%s: %.2f bilhões\n", Pais1, pib1);
        printf("%s: %.2f bilhões\n", Pais2, pib2);
        if (pib1 > pib2) {
            printf("A carta 1 venceu!\n");
        } else if (pib1 < pib2) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        break;

        case 4:
        printf("Atributo: Pontos Turísticos\n");
        printf("%s: %d pontos turísticos\n", Pais1, pontos_turisticos1);
        printf("%s: %d pontos turisticos\n", Pais2, pontos_turisticos2);
        if (pontos_turisticos1 > pontos_turisticos2) {
            printf("A carta 1 venceu!\n");
        } else if (pontos_turisticos1 < pontos_turisticos2) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        break;

        case 5:
        printf("Atributo: Densidade Demográfica\n");
        printf("%s: %.2f habitantes/km²\n", Pais1, densidade1);
        printf("%s: %.2f habitantes/km²\n", Pais2, densidade2);
        if (densidade1 < densidade2) {
            printf("A carta 1 venceu!\n");
        } else if (densidade1 > densidade2) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
        break;
        default:
        printf("Opção inválida!\n");

    }
   
}

// Função principal com o menu do jogo.

int main() {
    int menu;

   do {

    // Menu interativo.

     printf("\n    MENU PRINCIPAL    \n");
     printf("1. Iniciar Jogo\n");
     printf("2. Ver regras\n");
     printf("3. Sair\n");
     printf("Escolha uma opção: ");
     scanf("%d", &menu);
     getchar(); // Limpa o buffer de entrada

     // Processa a opção escolhida pelo jogador.

     switch (menu) {
        case 1:
        iniciarJogo();  // Chama a função para iniciar o jogo.
        break;
        case 2:
        // Exibe as regras do jogo.
        printf("\n    REGRAS DO JOGO    \n");
        printf("1. Cada jogador escolhe uma carta representando um país.\n");
        printf("2. Um atributo é escolhido para comparar as duas cartas.\n");
        printf("3. Vence a carta com o MAIOR valor no atributo escolhido.\n");
        printf("4. EXCEÇÃO: Para Densidade Demográfica, vence a carta com o MENOR valor.\n");
        printf("5. Em caso de empate, o resultado é considerado empate.\n");
        break;
        case 3:
        printf("\n    Saindo do jogo...    \n");
        exit(0);  // Encerra o progrma.
    default:
printf("Opção invalida! Tente novamente.\n");    
}
} while (menu != 3);  // Repete o menu até o jogador escolher sair.

return 0;
}
// Fim do código.