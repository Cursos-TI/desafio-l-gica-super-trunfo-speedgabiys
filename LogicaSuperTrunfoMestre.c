#include <stdio.h> // Biblioteca para entrada e saída (printf, scanf).
#include <stdlib.h> // Biblioteca para funções gerais como exit().
#include <string.h> // Biblioteca para manipulação de strings.

// Função que calcula a densidade demográfica.
float calcularDensidadeDemografica(unsigned long int populacao, float area) {
    return populacao / area;
}

// Função que obtém o valor do atributo escolhido.
float obterValor(int atributo, unsigned long int populacao, float area, float pib, int pontos_turisticos, float densidade, int carta) {
    switch (atributo) {
        case 1: // População
        return (float)populacao;
        case 2: // Área
        return area;
        case 3: // PIB
        return pib;
        case 4: // Pontos turísticos
        return (float)pontos_turisticos;
        case 5: // Densidade demográfica
        return -densidade; // Regra invertida: menor vence, então invertemos o sinal
        default:
        return 0;
    }
}

// Função que inicia o jogo.
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

    densidade1 = calcularDensidadeDemografica(populacao1, area1); 
    densidade2 = calcularDensidadeDemografica(populacao2, area2);

    // Exibição do menu de atributos.

    printf("\nAtributos disponíveis para comparação:\n"); // Exibe os atributos disponíveis.
    printf("1. População\n2. Área\n3. PIB\n4. Pontos turísticos\n5. Densidade demográfica (vence o menor valor)\n");

    int atributo1, atributo2;

    // Jogador escolhe 2 atributos diferentes para comparação.

    printf("\nEscolha o primeiro atributo (1 a 5): \n");
    scanf("%d", &atributo1); // Lê o primeiro atributo escolhido.

    // Valida a entrada do primeiro atributo.
    do {
        printf("\nEscolha o segundo atributo (1 a 5): \n");
        scanf("%d", &atributo2);
        if (atributo1 == atributo2) {
            printf("\nOs atributos devem ser diferentes. Tente novamente.\n");
        }
    } while (atributo1 == atributo2);

    // Obtém valore dos atributos para cada carta.
    float valor1_atributo1 = obterValor(atributo1, populacao1, area1, pib1, pontos_turisticos1, densidade1, 1);
    float valor1_atributo2 = obterValor(atributo2, populacao1, area1, pib1, pontos_turisticos1, densidade1, 1);
    float valor2_atributo1 = obterValor(atributo1, populacao2, area2, pib2, pontos_turisticos2, densidade2, 2);
    float valor2_atributo2 = obterValor(atributo2, populacao2, area2, pib2, pontos_turisticos2, densidade2, 2);

    float  soma1 = valor1_atributo1 + valor1_atributo2; 
    float soma2 = valor2_atributo1 + valor2_atributo2;

    // Exibe as comparações detalhadas
printf("\n====== COMPARAÇÃO DAS CARTAS ======\n");

// Exibe os detalhes da carta 1
printf("\nCarta 1\nPaís: %s\n", Pais1);
printf("(Atributo 1): ");
if (atributo1 == 1) printf("População\nPopulação: %.2f\n", valor1_atributo1);
else if (atributo1 == 2) printf("Área\nÁrea: %.2f\n", valor1_atributo1);
else if (atributo1 == 3) printf("PIB\nPIB: %.2f\n", valor1_atributo1);
else if (atributo1 == 4) printf("Pontos Turísticos\nPontos Turísticos: %.2f\n", valor1_atributo1);
else if (atributo1 == 5) printf("Densidade\nDensidade: %.2f\n", densidade1);

printf("(Atributo 2): ");
if (atributo2 == 1) printf("População\nPopulação: %.2f\n", valor1_atributo2);
else if (atributo2 == 2) printf("Área\nÁrea: %.2f\n", valor1_atributo2);
else if (atributo2 == 3) printf("PIB\nPIB: %.2f\n", valor1_atributo2);
else if (atributo2 == 4) printf("Pontos Turísticos\nPontos Turísticos: %.2f\n", valor1_atributo2);
else if (atributo2 == 5) printf("Densidade\nDensidade: %.2f\n", densidade1);

// Exibe os detalhes da carta 2
printf("\nCarta 2\nPaís: %s\n", Pais2);
printf("(Atributo 1): ");
if (atributo1 == 1) printf("População\nPopulação: %.2f\n", valor2_atributo1);
else if (atributo1 == 2) printf("Área\nÁrea: %.2f\n", valor2_atributo1);
else if (atributo1 == 3) printf("PIB\nPIB: %.2f\n", valor2_atributo1);
else if (atributo1 == 4) printf("Pontos Turísticos\nPontos Turísticos: %.2f\n", valor2_atributo1);
else if (atributo1 == 5) printf("Densidade\nDensidade: %.2f\n", densidade2);

printf("(Atributo 2): ");
if (atributo2 == 1) printf("População\nPopulação: %.2f\n", valor2_atributo2);
else if (atributo2 == 2) printf("Área\nÁrea: %.2f\n", valor2_atributo2);
else if (atributo2 == 3) printf("PIB\nPIB: %.2f\n", valor2_atributo2);
else if (atributo2 == 4) printf("Pontos Turísticos\nPontos Turísticos: %.2f\n", valor2_atributo2);
else if (atributo2 == 5) printf("Densidade\nDensidade: %.2f\n", densidade2);

// Comparação de cada atributo

// Exibe os detalhes da comparação.
printf("\n%s\n%s\n", Pais1, atributo1 == 5 ? "Densidade" : atributo1 == 1 ? "População" : atributo1 == 2 ? "Área" : atributo1 == 3 ? "PIB" : "Pontos Turísticos");
printf("%s\n%s\n", Pais2, atributo1 == 5 ? "Densidade" : atributo1 == 1 ? "População" : atributo1 == 2 ? "Área" : atributo1 == 3 ? "PIB" : "Pontos Turísticos");

// Compara os valores dos atributos escolhidos.
if (valor1_atributo1 > valor2_atributo1)
    printf("%s venceu no atributo (%s)\n", Pais1, atributo1 == 5 ? "Densidade" : atributo1 == 1 ? "População" : atributo1 == 2 ? "Área" : atributo1 == 3 ? "PIB" : "Pontos Turísticos");
else if (valor1_atributo1 < valor2_atributo1)
    printf("%s venceu no atributo (%s)\n", Pais2, atributo1 == 5 ? "Densidade" : atributo1 == 1 ? "População" : atributo1 == 2 ? "Área" : atributo1 == 3 ? "PIB" : "Pontos Turísticos");
else
    printf("Empate no atributo (%s)\n", atributo1 == 5 ? "Densidade" : atributo1 == 1 ? "População" : atributo1 == 2 ? "Área" : atributo1 == 3 ? "PIB" : "Pontos Turísticos");

printf("\n%s\n%s\n", Pais1, atributo2 == 5 ? "Densidade" : atributo2 == 1 ? "População" : atributo2 == 2 ? "Área" : atributo2 == 3 ? "PIB" : "Pontos Turísticos");
printf("%s\n%s\n", Pais2, atributo2 == 5 ? "Densidade" : atributo2 == 1 ? "População" : atributo2 == 2 ? "Área" : atributo2 == 3 ? "PIB" : "Pontos Turísticos");

if (valor1_atributo2 > valor2_atributo2)
    printf("%s venceu no atributo (%s)\n", Pais1, atributo2 == 5 ? "Densidade" : atributo2 == 1 ? "População" : atributo2 == 2 ? "Área" : atributo2 == 3 ? "PIB" : "Pontos Turísticos");
else if (valor1_atributo2 < valor2_atributo2)
    printf("%s venceu no atributo (%s)\n", Pais2, atributo2 == 5 ? "Densidade" : atributo2 == 1 ? "População" : atributo2 == 2 ? "Área" : atributo2 == 3 ? "PIB" : "Pontos Turísticos");
else
    printf("Empate no atributo (%s)\n", atributo2 == 5 ? "Densidade" : atributo2 == 1 ? "População" : atributo2 == 2 ? "Área" : atributo2 == 3 ? "PIB" : "Pontos Turísticos");

// Resultado final

// Exibe o resultado final da comparação.
printf("\n====== SOMA DOS ATRIBUTOS ======\n");
printf("Carta 1\n%s\n", Pais1);
printf("População: %.2f + Densidade: %.2f\n", valor1_atributo1, valor1_atributo2);
printf("Carta 2\n%s\n", Pais2);
printf("População: %.2f + Densidade: %.2f\n", valor2_atributo1, valor2_atributo2);

if (soma1 > soma2)
    printf("\nResultado final: Carta 1 (%s) venceu!\n", Pais1);
else if (soma1 < soma2)
    printf("\nResultado final: Carta 2 (%s) venceu!\n", Pais2);
else
    printf("\nResultado final: Empate!\n");

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
// Fim do código.