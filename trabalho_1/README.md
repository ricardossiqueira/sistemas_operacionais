
### Compilação

  Compilando a partir do diretório raiz
  ```console
  g++ -Wall *.cpp *.h -o main
  ```

### Teste

  Testando sinal SIGTERM
  ```console
  kill -15 <PID>
  ```

### Referências

- [srand](http://www.inf.ufsc.br/~bosco.sobral/ensino/ine5201-02202A/Gerando_Numeros_Aleatorios_em_C.pdf)
- [pipe](https://www.geeksforgeeks.org/pipe-system-call/)
- [fork](https://www.geeksforgeeks.org/creating-multiple-process-using-fork/)
- [csiganal (signal handling)](https://www.tutorialspoint.com/cplusplus/cpp_signal_handling.htm)
- [close pipe](https://stackoverflow.com/questions/37159008/close-function-with-wrtie-read-function-for-pipe-c)