#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.



// Estrutura que representa uma "carta" do jogo
typedef struct card{
    float area;            // área da cidade (ex: km²)
    float PIB;             // PIB da cidade
    int population;        // população (inteiro)
    int num_tour_points;   // número de pontos turísticos (inteiro)

    // UF do estado com 2 letras + '\0' (terminador de string)
    // Ex: "CE" + '\0' => precisa de 3 posições
    char state[3];

    // código com até 3 caracteres + '\0'
    // OBS: se você digitar 2222, ele vai guardar só "222"
    char code[4];

    // nome da cidade com até 19 caracteres + '\0'
    // OBS: scanf("%19s") NÃO aceita espaços (ex: "RIO BRANCO" vira só "RIO")
    char city_name[20];
} card_t;

// Função para preencher (popular) uma carta recebida por ponteiro
static void populate_card(card_t *card){
    // Lê a UF (2 letras). %2s garante que no máximo 2 caracteres vão ser lidos.
    // Como state é char[3], sobra 1 espaço pro '\0' automático do scanf.
    printf("Set state (UF ex: CE): ");
    scanf("%2s", card->state);

    // Debug: mostra o que foi lido
    printf("DEBUG state='%s'\n", card->state);

    // Lê o nome da cidade (uma palavra apenas, sem espaços)
    printf("Set city name: ");
    scanf("%19s", card->city_name);

    // Lê a área (float). O & pega o endereço da variável para o scanf preencher.
    printf("Set Area: ");
    scanf("%f", &card->area);

    // Lê o código (até 3 caracteres)
    printf("Set code: ");
    scanf("%3s", card->code);

    // Lê a população (int)
    printf("Set Population: ");
    scanf("%d", &card->population);

    // Lê o PIB (float)
    printf("Set PIB: ");
    scanf("%f", &card->PIB);

    // Lê o número de pontos turísticos (int)
    printf("Set Number of touristic points: ");
    scanf("%d", &card->num_tour_points);
}

// Função para imprimir uma carta (apenas leitura, por isso const)
static void print_card(const card_t *carta){
    // Como state agora é string (char[3]), tem que imprimir com %s (não %c)
    printf("Estado: %s\n", carta->state);

    // %3s imprime a string com "largura mínima" 3 (não limita o que foi guardado)
    // Quem limita é o scanf("%3s")
    printf("Código: %3s\n", carta->code);

    printf("Nome da Cidade: %s\n", carta->city_name);
    printf("Área: %.2f km²\n", carta->area);   // %.2f -> duas casas decimais
    printf("PIB: %.2f\n", carta->PIB);
    printf("População: %d habitantes\n", carta->population);
    printf("Número de Pontos Turísticos: %d\n", carta->num_tour_points);
    printf("\n");
}

int main()
{
    // Duas cartas locais (uma para cada jogador)
    card_t card_1, card_2;

    printf("* * * * * START GAME!! * * * * *\n\n");

    // Preenche a carta do Player 1
    printf("===== Register Player 1 Cards =====\n");
    populate_card(&card_1);

    printf("\n\n");

    // Preenche a carta do Player 2
    printf("===== Register Player 2 Cards =====\n");
    populate_card(&card_2);

    // Só imprime no final (depois de preencher as duas)
    printf("\n===== RESULTADOS FINAIS =====\n\n");

    printf("---- Player 1 ----\n");
    print_card(&card_1);

    printf("\n\n");

    printf("---- Player 2 ----\n");
    print_card(&card_2);

    return 0; // encerra o programa com sucesso
}
