#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das funções
void iniciarJogo(int *pontuacao, int dificuldade);
void pausarJogo();
void reiniciarJogo(int *pontuacao, int *dificuldade);
void sairJogo();
int gerarNumeroAleatorio(int dificuldade);
void mostrarMenu();
void limparBuffer();
void escolherDificuldade(int *dificuldade);

int main() {
    int escolha;
    int pontuacao = 0; // Variável para armazenar a pontuação do jogador
    int dificuldade = 1; // Variável para armazenar o nível de dificuldade

    // Loop principal do jogo
    while (1) {
        // Mostra o menu de opções
        mostrarMenu();
        // Lê a escolha do usuário
        scanf("%d", &escolha);
        // Limpa o buffer de entrada
        limparBuffer();
        // Switch para lidar com as opções do menu
        switch (escolha) {
            case 1:
                // Inicia o jogo, passando a pontuação e a dificuldade como ponteiros
                iniciarJogo(&pontuacao, dificuldade);
                break;
            case 2:
                // Pausa o jogo
                pausarJogo();
                break;
            case 3:
                // Reinicia o jogo, resetando a pontuação e a dificuldade
                reiniciarJogo(&pontuacao, &dificuldade);
                break;
            case 4:
                // Sai do jogo
                sairJogo();
                break;
            case 5:
                // Permite ao jogador escolher a dificuldade do jogo
                escolherDificuldade(&dificuldade);
                break;
            default:
                // Mensagem de erro para escolhas inválidas
                printf("Escolha invalida! Tente novamente.\n");
        }
    }
    return 0;
}

// Função para mostrar o menu
void mostrarMenu() {
    printf("\n=== Menu Principal ===\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Pausar Jogo\n");
    printf("3. Reiniciar Jogo\n");
    printf("4. Sair\n");
    printf("5. Escolher Dificuldade\n");
    printf("Escolha uma opcao: ");
}

// Função para iniciar o jogo
void iniciarJogo(int *pontuacao, int dificuldade) {
    int numero, tentativa, tentativas = 0;
    // Gera um número aleatório com base na dificuldade
    numero = gerarNumeroAleatorio(dificuldade);
    printf("Jogo iniciado! Adivinhe o numero entre 1 e %d:\n", dificuldade * 10);

    // Loop principal do jogo (3 tentativas)
    while (tentativas < 3) {
        printf("Sua tentativa (%d/3): ", tentativas + 1);
        scanf("%d", &tentativa);
        limparBuffer();
        tentativas++;
        // Verifica se o palpite está correto
        if (tentativa == numero) {
            printf("Parabens! Voce adivinhou o numero em %d tentativas.\n", tentativas);
            // Atualiza a pontuação do jogador
            *pontuacao += 10 * dificuldade;
            printf("Sua pontuacao acumulada: %d\n", *pontuacao);
            return;
        } else if (tentativa < numero) {
            printf("Muito baixo! Tente novamente.\n");
        } else {
            printf("Muito alto! Tente novamente.\n");
        }
    }

    // Mensagem de game over quando o jogador excede o número de tentativas
    printf("Game over! O numero secreto era %d.\n", numero);
}

// Função para pausar o jogo
void pausarJogo() {
    printf("Jogo pausado. Pressione Enter para continuar...\n");
    getchar();
}

// Função para reiniciar o jogo
void reiniciarJogo(int *pontuacao, int *dificuldade) {
    // Reseta a pontuação e a dificuldade
    *pontuacao = 0;
    *dificuldade = 1;
    printf("Jogo reiniciado. Pontuacao e dificuldade resetadas.\n");
}

// Função para sair do jogo
void sairJogo() {
    printf("Saindo do jogo. Ate logo!\n");
    exit(0);
}

// Função para gerar um número aleatório com base na dificuldade
int gerarNumeroAleatorio(int dificuldade) {
    srand(time(NULL));
    return rand() % (dificuldade * 10) + 1;
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para escolher a dificuldade do jogo
void escolherDificuldade(int *dificuldade) {
    int escolha;
    printf("\n=== Escolher Dificuldade ===\n");
    printf("1. Facil (1-10)\n");
    printf("2. Medio (1-20)\n");
    printf("3. Dificil (1-30)\n");
    printf("Escolha uma dificuldade: ");
    scanf("%d", &escolha);
    limparBuffer();
    // Verifica se a escolha está dentro do intervalo válido (1 a 3)
    if (escolha >= 1 && escolha <= 3) {
        // Atualiza a dificuldade com o valor escolhido pelo jogador
        *dificuldade = escolha;
        printf("Dificuldade ajustada para %d\n", *dificuldade);
    } else {
        // Mensagem de erro para escolhas inválidas
        printf("Escolha invalida! Dificuldade padrao (Facil) mantida.\n");
        *dificuldade = 1; // Define a dificuldade padrão como Fácil
    }
}
