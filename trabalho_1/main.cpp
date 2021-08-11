/** Trabalho 1 - Sistemas Operacionais
 *  Periodo: 2021.1
 *  Autor: Ricardo Santos Siqueira
 *  DRE: 118167558
 *  Arquivo: main.cpp
 *  Descricao: Implementacao da funcao main do programa
 */

// Importacoes feitas em handlers.h
#include "handlers.hpp"

int main()
{
  int pid = getpid();

  cout << "PID do processo: " << pid << endl;

  // listeners e handlers dos sinais
  signal(SIGUSR1, handle_SIGUSR1);
  signal(SIGUSR2, handle_SIGUSR2);
  signal(SIGTERM, handle_SIGTERM);

  while (getListening())
  {
    sleep(1);
  }

  return 0;
}