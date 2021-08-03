// Importacoes feitas em handlers.h
#include "handlers.h"

int main()
{
  int pid = getpid();

  cout << "PID do processo: " << pid << endl;

  signal(SIGUSR1, handle_SIGUSR1);
  signal(SIGUSR2, handle_SIGUSR2);
  signal(SIGTERM, handle_SIGTERM);

  while (1)
  {
    sleep(1);
  }

  return 0;
}