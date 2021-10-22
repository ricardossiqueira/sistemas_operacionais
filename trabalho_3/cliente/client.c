/*
EEL770 - Universidade Federal do Rio de Janeiro
O código foi desenvolvido pelo monitor Felipe Schreiber Fernandes e modificado pelo professor Rodrigo de Souza Couto para os objetivos da disciplina.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define SERVERIP "3.135.248.67"
#define PORT 8080
#define NUMEROENVIADO 122
#define DELIM "|" //define o caractere delimitador das mensagens
char *clientMessageParsed[3];

void parse(char *buff)
{
	char *copy, *p;
	int cnt = 0;
	copy = strdup(buff);
	while ((p = strsep(&copy, DELIM)))
	{
		clientMessageParsed[cnt] = strdup(p);
		cnt++;
	}
	free(copy);
}

int Connect()
{
	int sock = 0;
	struct sockaddr_in serv_addr;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, SERVERIP, &serv_addr.sin_addr) <= 0)
	{
		printf("\n Endereco invalido \n");
		return -1;
	}

	while ((connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0))
	{
		printf("\n Conexao Falhou \n");
	}
	return sock;
}

int request(char *buff, char *str_PID, int sock)
{
	int valread;
	strncpy(buff, "1|\0", 1024);
	strcat(buff, str_PID);
	printf("Enviando mensagem %s\n", buff);
	send(sock, buff, 1024, 0);
	valread = read(sock, buff, 1024);
	if (valread == 0)
	{
		printf("A PROBLEM HAS OCCURRED\n");
	}
	parse(buff);
	if (strcmp(clientMessageParsed[0], "2") == 0)
	{
		return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int ok;
	char dreString[1024];
	char buffer[1024] = {0};
	sprintf(dreString, "%u|", NUMEROENVIADO);
	int sock = Connect();
	ok = request(buffer, dreString, sock);
	if (ok)
	{
		unsigned int sum = atoi(clientMessageParsed[1]);
		printf("Numero enviado: %u\n", NUMEROENVIADO);
		printf("O resultado eh: %u\n", sum);
		strncpy(buffer, "3|\0", 1024);
		strcat(buffer, dreString);
		printf("Enviando mensagem %s\n", buffer);
		send(sock, buffer, 1024, 0);
	}
	close(sock);
	return 0;
}
