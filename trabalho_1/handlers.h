#include <iostream>
#include <csignal>
#include <string>

#ifdef __unix__
#include <unistd.h>

// Assunmindo que o codigo destina-se apenas a ambientes unix, conforme
// enunciado do trabalho, deixarei a concional para WIN32 comentada

// #elif defined _WIN32
// #include <windows.h>
// #define sleep(x) Sleep(1000 * (x))

#endif

using namespace std;

void handle_SIGUSR1(int);
void handle_SIGUSR2(int);
void handle_SIGTERM(int);