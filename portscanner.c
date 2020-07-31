#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
int main(int argc, char *argv[]){
	char *host = argv[1];
	int msocket,conexao;
	int total = 65535;
	struct sockaddr_in alvop;
	for(int porta=0; porta<total; porta++){
				   /*DOMINIO|TIPO|PROTOCOLO*/
	/*
	AF_INET = IP
	SOCK_STREAM = CONEXAO ORIENTADA
	0 = TCP
	*/
	msocket = socket(AF_INET,SOCK_STREAM,0);
		alvop.sin_family = AF_INET;
		alvop.sin_port = htons(porta);
		alvop.sin_addr.s_addr = inet_addr(host);
		/*
		int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
		recebe o socket/estrutura/sockaddr/tamanho
		*/


		conexao = connect(msocket, (struct sockaddr *)&alvop, sizeof alvop);
		if(conexao == 0){
			printf("Conexao Sucedida PORTA [%d]\n", porta);
			close(conexao);
		}
		}
}
