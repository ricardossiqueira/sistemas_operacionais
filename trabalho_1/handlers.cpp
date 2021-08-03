#include "handlers.h"

// Maior numero possivel '100' (3 chars de 1 byte cada) + EOL
#define MSG_SIZE 4
#define PATH_TO_PING "/bin/ping"

int comandoParaExecutar = 0;

void handle_SIGUSR1(int)
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
    comandoParaExecutar = atoi(inbuf);
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

void handle_SIGUSR2(int)
{
  int pfd[2];
  char inbuf[MSG_SIZE];

  // Cria pipe e em caso de erro encerra com codigo 1
  if (pipe(pfd) < 0)
    exit(1);

  // Criando processo filho
  int child = fork();

  if (child > 0) // Se no processo pai
  {
    char strComandoParaExecutar[MSG_SIZE];
    sprintf(strComandoParaExecutar, "%d", comandoParaExecutar);
    write(pfd[1], strComandoParaExecutar, MSG_SIZE);
  }
  else if (child == 0) // Se no processo filho
  {
    read(pfd[0], inbuf, MSG_SIZE);
    if (atoi(inbuf) == 0)
      cout << "Nao ha comando a executar" << endl;
    else if (atoi(inbuf) % 2 == 0)
      execlp(PATH_TO_PING, "ping", "8.8.8.8", "-c", "5", NULL);
    else
      execlp(PATH_TO_PING, "ping", "paris.testdebit.info", "-c", "5", "-i", "2", NULL);
  }

  // Encerrando pipe (tanto pai quanto filho executam)
  close(pfd[0]);
}

void handle_SIGTERM(int)
{
  cout << "Finalizando o disparador..." << endl;
  exit(0);
}