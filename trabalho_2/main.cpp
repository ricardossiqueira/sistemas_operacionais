#include <iostream> // std::cout
#include <vector>   // std::vector
#include <unistd.h> // std::usleep
#include <mutex>    // std::mutex
#include <thread>   // std::thread

// Numero de clientes que tentarao cortar o cabelo simultaneamente
#define CLIENTS 10

using namespace std;

const unsigned totalChairs = 4;
unsigned usingChairs = 0;
mutex mtx;

// Lambda function (dessa forma args pode ser vazio)
auto haircut = [](/* args */)
{
  if (totalChairs - usingChairs > 0) // Caso haja uma cadeira disponivel
  {
    // Lock para operacao na variavel "compartilhada" entre as threads
    mtx.lock();
    usingChairs++;
    mtx.unlock();

    usleep(2); // 2 microsegundos
    cout << "Cortando cabelo...\n";

    // Lock para operacao na variavel "compartilhada" entre as threads
    mtx.lock();
    usingChairs--;
    mtx.unlock();
  }
  // Caso todas as cadeiras estejam ocupadas
  else
    cout << "Salao cheio, saindo...\n";
};

int main(int argc, char *argv[])
{
  vector<thread> queue; // Vector de threads (clientes)

  // Cria todos os clientes no vetor sem esperar a conclusao das threads
  for (int i = 0; i < CLIENTS; i++)
    queue.push_back(thread(haircut));

  // Join em todas as threads criadas
  for (thread &t_ : queue)
    t_.join();

  return 0;
}
