#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

class BarberShop
{
private:
  const unsigned _totalChairs = 4;
  unsigned _usingChairs = 0;
  mutex mtx;

public:
  void haircut();
};

void BarberShop::haircut()
{
  lock_guard<mutex> lockGuard(mtx);
  // mtx.lock();
  if (_totalChairs - _usingChairs > 0)
  {
    _usingChairs++;
    cout
        << "Cortando cabelo... <thread_id: "
        << this_thread::get_id()
        << ">"
        << endl;
    _usingChairs--;
  }
  // mtx.unlock();
}

int main(int argc, char *argv[])
{
  vector<thread> queue;
  BarberShop barberShop;

  for (int i = 0; i < 10; i++)
  {
    queue.push_back(thread(&BarberShop::haircut, &barberShop));
  }

  for (auto &t : queue)
    t.join();

  return 0;
}
