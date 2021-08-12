# Trabalho 1 - Sistemas Operacionais

**Aluno:** Ricardo Santos Siqueira

**DRE:** 118167558

**Período:** 2021.1 

## Ambiente de desenvolvimento

OS: Ubuntu 20.04.2 LTS on Windows 10 x86_64

Kernel: 5.4.72-microsoft-standard-WSL2

Shell: zsh 5.8

## Compilação

  Compilando a partir do diretório raiz
  ```console
  make all
  ```

  Limpando todos os arquivos gerados
  ```console
  make clean
  ```

## Teste

  Testando sinal SIGUSR1
  ```console
  kill -USR1 <PID>
  ```

  Testando sinal SIGUSR2
  ```console
  kill -USR2 <PID>
  ```

  Testando sinal SIGTERM
  ```console
  kill -TERM <PID>
  ```

## Referências

- [srand](http://www.inf.ufsc.br/~bosco.sobral/ensino/ine5201-02202A/Gerando_Numeros_Aleatorios_em_C.pdf)
- [pipe](https://www.geeksforgeeks.org/pipe-system-call/)
- [fork](https://www.geeksforgeeks.org/creating-multiple-process-using-fork/)
- [csiganal](https://www.tutorialspoint.com/cplusplus/cpp_signal_handling.htm)
- [close](https://stackoverflow.com/questions/37159008/close-function-with-wrtie-read-function-for-pipe-c)
- [SIGUSR1 & SIGUSR2](https://stackoverflow.com/questions/6168636/how-to-trigger-sigusr1-and-sigusr2)
- [getenv](https://stackoverflow.com/questions/27822022/linux-c-detect-user-shell-csh-bash-etc)
- [exec](https://www.dca.ufrn.br/~adelardo/cursos/DCA409/node39.html)
- [makefile](https://earthly.dev/blog/g++-makefile/)