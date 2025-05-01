#include <stdio.h>
#include <string.h>

int main() {

    // Declarações de variáveis

    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[100], cidade2[100];
    char abreviacao1[4], abreviacao2[4];

    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;
    float SuperPoder1, SuperPoder2;

    // Carta 1
    printf("Carta 1:\n");

    printf("Digite a letra do estado: ");
    scanf(" %c", &estado1); // espaço antes do %c para consumir o '\n' pendente

    printf("Digite o código da carta: ");
    scanf("%s", codigo1);

    getchar(); // limpa buffer antes de ler a string com espaços
    printf("Digite o nome da cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0'; // remove o '\n'

    printf("Digite a abreviação do estado: ");
    scanf("%s", abreviacao1);

    printf("Digite a população: ");
    scanf("%lu", &populacao1);

    printf("Digite a área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Carta 2
    printf("\nCarta 2:\n");

    printf("Digite a letra do estado: ");
    scanf(" %c", &estado2);

    printf("Digite o código da carta: ");
    scanf("%s", codigo2);

    getchar();
    printf("Digite o nome da cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

    printf("Digite a abreviação do estado: ");
    scanf("%s", abreviacao2);

    printf("Digite a população: ");
    scanf("%lu", &populacao2);

    printf("Digite a área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pib_per_capita1 = pib1 / populacao1;
    pib_per_capita2 = pib2 / populacao2;

    SuperPoder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1 / densidade1);
    SuperPoder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1 / densidade2);

    // Comparação

    printf("\nComparação de cartas (Atributo: População):\n");

    if (populacao1 > populacao2) {
        printf("A carta 1 venceu!\n");
    } else {
        printf("A carta 2 venceu!\n");
    } 

    printf("\nComparação de cartas (Atributo: Área):\n");

    if (area1 > area2) {
        printf("A carta 1 venceu!\n");
    } else {
        printf("A carta 2 venceu!\n");
    } 

    printf("\nComparação de cartas (Atributo: PIB):\n");

    if (pib1 > pib2) {
        printf("A carta 1 venceu!\n");
    } else {
        printf("A carta 2 venceu!\n");
    } 

    printf("\nComparação de cartas (Atributo: Densidade):\n");

    if (densidade1 < densidade2) {
        printf("A carta 1 venceu!\n");
    } else {
        printf("A carta 2 venceu!\n");
    } 

    printf("\nComparação de cartas (Atributo: PIB per capita):\n");

    if (pib_per_capita1 > pib_per_capita2) {
        printf("A carta 1 venceu!\n");
    } else {
        printf("A carta 2 venceu!\n");
    } 

    printf("\nComparação de cartas (Atributo: Super Poder):\n");

    if (SuperPoder1 > SuperPoder2) {
        printf("A carta 1 venceu!\n");
    } else {
        printf("A carta 2 venceu!\n");
    } 

    printf("\nComparação de cartas (Atributo: Pontos Turísticos):\n");

    if (pontos_turisticos1 > pontos_turisticos2) {
        printf("A carta 1 venceu!\n");
    } else {
        printf("A carta 2 venceu!\n");
    } 

    // Exibição

    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %lu \n", cidade1, abreviacao1, populacao1);
    printf("Carta 2 - %s (%s): %lu \n", cidade2, abreviacao2, populacao2);
    printf("Resultado: %s (%s) venceu!\n",  (populacao1 > populacao2) ? "Carta 1" : "Carta 2", (populacao1 > populacao2) ? cidade1 : cidade2);

    printf("\nComparação de cartas (Atributo: Área):\n");
    printf("Carta 1 - %s (%s): %.2f \n", cidade1, abreviacao1, area1);
    printf("Carta 2 - %s (%s): %.2f \n", cidade2, abreviacao2, area2);
    printf("Resultado: %s (%s) venceu!\n", (area1 > area2) ? "Carta 1" : "Carta 2", (area1 > area2) ? cidade1 : cidade2);

    printf("\nComparação de cartas (Atributo: PIB):\n");
    printf("Carta 1 - %s (%s): %.2f \n", cidade1, abreviacao1, pib1);
    printf("Carta 2 - %s (%s): %.2f \n", cidade2, abreviacao2, pib2);
    printf("Resultado: %s (%s) venceu!\n", (pib1 > pib2) ? "Carta 1" : "Carta 2", (pib1 > pib2) ? cidade1 : cidade2);

    printf("\nComparação de cartas (Atributo: densidade):\n");
    printf("Carta 1 - %s (%s): %.2f \n", cidade1, abreviacao1, densidade1);
    printf("Carta 2 - %s (%s): %.2f \n", cidade2, abreviacao2, densidade2);
    printf("Resultado: %s (%s) venceu!\n", (densidade1 > densidade2) ? "Carta 1" : "Carta 2", (densidade1 < densidade2) ? cidade1 : cidade2);

    printf("\nComparação de cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s (%s): %.2f \n", cidade1, abreviacao1, pib_per_capita1);
    printf("Carta 2 - %s (%s): %.2f \n", cidade2, abreviacao2, pib_per_capita2);
    printf("Resultado: %s (%s) venceu!\n", (pib_per_capita1 > pib_per_capita2) ? "Carta 1" : "Carta 2", (pib_per_capita1 > pib_per_capita2) ? cidade1 : cidade2);

    printf("\nComparação de cartas (Atributo: Super Poder):\n");
    printf("Carta 1 - %s (%s): %.2f \n", cidade1, abreviacao1, SuperPoder1);
    printf("Carta 2 - %s (%s): %.2f \n", cidade2, abreviacao2, SuperPoder2);
    printf("Resultado: %s (%s) venceu!\n", (SuperPoder1 > SuperPoder2) ? "Carta 1" : "Carta 2", (SuperPoder1 >  SuperPoder2) ? cidade1 : cidade2);

    printf("\nComparação de cartas (Atributo: Pontos Turísticos):\n");
    printf("Carta 1 - %s (%s): %d \n", cidade1, abreviacao1, pontos_turisticos1);
    printf("Carta 2 - %s (%s): %d \n", cidade2, abreviacao2, pontos_turisticos2);
    printf("Resultado: %s (%s) venceu!\n", (pontos_turisticos1 > pontos_turisticos2) ? "Carta 1" : "Carta 2", (pontos_turisticos1 > pontos_turisticos2) ? cidade1 : cidade2);


return 0;
}