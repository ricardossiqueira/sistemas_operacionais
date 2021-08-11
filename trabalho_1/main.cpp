// Importacoes feitas em handlers.h
#include "handlers.hpp"

int main()
{
  int pid = getpid();

  cout << "PID do processo: " << pid << endl;

  signal(SIGUSR1, handle_SIGUSR1);
  signal(SIGUSR2, handle_SIGUSR2);
  signal(SIGTERM, handle_SIGTERM);

  while (getListening())
  {
    sleep(1);
  }

  return 0;
}