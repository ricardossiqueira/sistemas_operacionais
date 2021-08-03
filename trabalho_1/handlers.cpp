#include "handlers.h"

// Maior numero possivel '100' (3 chars de 1 byte cada) + EOL
#define MSG_SIZE 4

void handle_SIGTERM(int signum)
{
  int p[2];
  char inbuf[MSG_SIZE];

  srand(time(NULL));

  // Inicializa uma instancia do pipe
  if (pipe(p) < 0)
    exit(1);

  // Criando processo filho
  int child = fork();

  // Processo filho calcula um numero aleatorio entre 1 e 100 e envia via pipe
  if (child == 0)
  {
    char randomNumber[MSG_SIZE];

    sprintf(randomNumber, "%d", rand() % 100 + 1);

    cout << "Enviando o numero " << randomNumber << " via pipe!" << endl;
    write(p[1], randomNumber, MSG_SIZE);
  }

  // Lendo do pipe
  read(p[0], inbuf, MSG_SIZE);
  cout << "Recebido: " << inbuf << endl;
}