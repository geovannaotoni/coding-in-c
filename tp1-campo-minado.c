#include <stdio.h>

int main() {
  int quant_jogos, tamanho_tabuleiro, jogadas;
  // printf("Digite o número de jogos a serem realizados: \n");
  do {
    scanf("%d", &quant_jogos);
  } while (quant_jogos < 1 || quant_jogos > 10); // número máximo de jogos é 10

  for (int jogo = 1; jogo <= quant_jogos; jogo++) {
    // printf("Digite o tamanho do tabuleiro: \n");
    do {
      scanf("%d", &tamanho_tabuleiro);
    } while (tamanho_tabuleiro < 2 || tamanho_tabuleiro > 100); // o tabuleiro deve ter tamanho entre 2 e 100

    char tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
    for(int i = 0; i < tamanho_tabuleiro; i++) {
      for(int j = 0; j < tamanho_tabuleiro; j++) {
        scanf(" %c", &tabuleiro[i][j]); // colocado um espaço em branco para não considerar os espaços digitados pelo usuário como caracteres
      }
    }

    int status_jogo = 1; // quando o jogador perder, status_jogo = 0, quando ainda faltar terminar, status_jogo = 2
    int x, y; // x = linha, y = coluna

    // printf("Digite o nº de jogadas: \n");
    scanf("%d", &jogadas);
    // verificações a cada jogada
    for (int k = 0; k < jogadas; k++) {
      scanf("%d %d", &x, &y);

      // verifica se o jogador escolheu uma posição com mina
      if(tabuleiro[x][y] == 'b') {
        status_jogo = 0;
      } else if(tabuleiro[x][y] == 'x'  && status_jogo != 0) {
        tabuleiro[x][y] = 'o'; // marcar a posição como revelada
        int bomba_perto = 0; // 0 quando falso e 1 quando verdadeiro
        // verifica se alguma das posições adjacentes tem uma mina
        for(int nx = -1; nx <= 1; nx++) {
          for(int ny = -1; ny <= 1; ny++) {
            int adjx = x + nx;
            int adjy = y + ny;

            if(adjx >= 0 && adjx < tamanho_tabuleiro && adjy >= 0 && adjy < tamanho_tabuleiro) {
              if(tabuleiro[adjx][adjy] == 'b') {
                bomba_perto = 1;
                break;
              }
            }
          }
        }
        
        if(!bomba_perto) {
          // Marcar todas as posições adjacentes como já revelada
          for(int nx = -1; nx <= 1; nx++) {
            for(int ny = -1; ny <= 1; ny++) {
              int adjx = x + nx;
              int adjy = y + ny;

              if(adjx >= 0 && adjx < tamanho_tabuleiro && adjy >= 0 && adjy < tamanho_tabuleiro) {
                tabuleiro[adjx][adjy] = 'o'; 
              }
            }
          }
        }

      }
    }

    if(status_jogo != 0) {
      for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
          if(tabuleiro[i][j] == 'x') {
            status_jogo = 2;
          }
        }
      }
    }

    if(status_jogo == 0) {
      printf("PERDEU\n");
    }

    if(status_jogo == 1) {
      printf("GANHOU\n");
    }
    
    if(status_jogo == 2) {
      printf("FALTOU TERMINAR\n");
    }

  }
  return 0;
}
