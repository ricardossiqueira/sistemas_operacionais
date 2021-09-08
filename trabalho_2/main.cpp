#include <iostream>
#include <vector>
#include <unistd.h>
#include <mutex>
#include <thread>

using namespace std;

const unsigned totalChairs = 4;
unsigned usingChairs = 0;
mutex mtx;

auto haircut = []()
{
  if (totalChairs - usingChairs > 0)
  {
    mtx.lock();
    usingChairs++;
    mtx.unlock();

    usleep(1);
    cout << "Cortando cabelo...\n";

    mtx.lock();
    usingChairs--;
    mtx.unlock();
  }
  else
    cout << "Salao cheio, saindo...\n";
};

int main(int argc, char *argv[])
{
  vector<thread> queue;

  for (int i = 0; i < 10; i++)
    new thread(haircut);

  return 0;
}
