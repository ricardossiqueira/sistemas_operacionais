/** Trabalho 1 - Sistemas Operacionais
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: handlers.hpp
 *  Descricao: Arquivo com as implementacoes das funcoes para lidar com cada
 *             sinal recebido pela funcao main
 */

#include "handlers.hpp"

int
    comandoParaExecutar = 0,
    listening = 1; // Enquanto 1 o programa escuta os sinais enviados

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
    // char *randomNumber recebe o numero aleatorio gerado
    sprintf(randomNumber, "%d", rand() % 100 + 1);

    cout << "Enviado o numero " << randomNumber << " via pipe!" << endl;

    // Escrevendo no pipe
    write(pfd[1], randomNumber, MSG_SIZE);
  }

  // Encerrando pipe (tanto pai quanto filho executam)
  close(pfd[0]);
}

void handle_SIGUSR2(int)
{
  // Criando processo filho
  int child = fork();

  if (child == 0) // Se no processo filho
  {
    if (comandoParaExecutar == 0)
      cout << "Nao ha comando a executar" << endl;
    else if (comandoParaExecutar % 2 == 0)
      execlp(PATH_TO_PING, "ping", "8.8.8.8", "-c", "5", NULL);
    else
      execlp(PATH_TO_PING,
             "ping",
             "paris.testdebit.info",
             "-c",
             "5",
             "-i",
             "2",
             NULL);
  }
}

void handle_SIGTERM(int)
{
  cout << "Finalizando o disparador..." << endl;
  listening = 0;
}

int getListening() { return listening; }