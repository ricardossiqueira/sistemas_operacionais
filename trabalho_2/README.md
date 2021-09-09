# Trabalho 2 - Sistemas Operacionais
### [FIFO Barbershop](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf)

**Aluno:** Ricardo Santos Siqueira

**DRE:** 118167558

**Período:** 2021.1

## Ambiente de desenvolvimento

**OS:** Manjaro Linux x86_64

**Kernel:** 5.13.12-1-MANJARO

**Shell:** fish 3.3.1

## Compilação

Compilando a todos os arquivos
```console
make all
```

Limpando todos os arquivos gerados
```console
make clean
```

Compilação, 10 execuções e limpeza
```console
make test 

# make -s all;
# for i in {1..10}; do
#   ./trabalho_2;
#   echo ----$i----;
# done;
# make -s clean
```

## Referências externas

 - [Multithreading in C++](https://www.geeksforgeeks.org/multithreading-in-cpp/)

 - [Multithreading in C](https://www.geeksforgeeks.org/multithreading-c-2/)

 - [Condition Varaibles in C++11](https://thispointer.com/c11-multithreading-part-7-condition-variables-explained/)

 - [Race Condition in C++](https://thispointer.com//c11-multithreading-part-4-data-sharing-and-race-conditions/)

 - [Using mutex to fix race conditins in C++11](https://thispointer.com/c11-multithreading-part-5-using-mutex-to-fix-race-conditions/)

 - [FIFO barbershop in process synchronization](https://www.geeksforgeeks.org/fifo-barbershop-in-process-synchronization/)