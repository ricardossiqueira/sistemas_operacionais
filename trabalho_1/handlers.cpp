#include "handlers.h"

// Maior numero possivel '100' (3 chars de 1 byte cada) + EOL
#define MSG_SIZE 4

void handle_SIGTERM(int signum)
{
  // pfd = Pipe File Descriptor
  int pfd[2];
  char inbuf[MSG_SIZE];

  srand(time(NULL));

  // Cria pipe e em caso de erro encerra com codigo 1
  if (pipe(pfd) < 0)
    exit(1);

  // Criando processo filho
  int child = fork();

  if (child > 0) // Se no processo pai
  {
    // Lendo do pipe
    read(pfd[0], inbuf, MSG_SIZE);
    cout << "Recebido: " << atoi(inbuf) << endl;
  }
  else if (child == 0) // Se no processo filho
  {
    char randomNumber[MSG_SIZE];
    // int randomNumber -> char *randomNumber
    sprintf(randomNumber, "%d", rand() % 100 + 1);

    cout << "Enviando o numero " << randomNumber << " via pipe!" << endl;

    // Escrevendo no pipe
    write(pfd[1], randomNumber, MSG_SIZE);
  }

  // Encerrando pipe (tanto pai quanto filho executam)
  close(pfd[0]);
}