#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <ctype.h>

char *get_ip(char *host)
{
    struct hostent *ip;

    ip = gethostbyname(host);
    if(ip == NULL)
    {
        printf("[INFO] Endereço nao encontrado!");
    }
    return inet_ntoa(*((struct in_addr *)ip->h_addr_list[0]));
}



int main(int argc, char *argv[])
{
    char *endereco;
    int err;
    int sockfd;

    int portmin = atoi(argv[2]);
    int portmax = atoi(argv[3]);
    if(argc < 4){
        printf("[INFO] Ocorreu um erro!\nUse: %s <Endereço IP> <Porta inicio> <Porta final\n", argv[0]);
        return 1;
    }
    if(isdigit(endereco[0] == 0))
        endereco = get_ip(argv[1]);

    endereco = argv[1];

    struct sockaddr_in host = {
        host.sin_addr.s_addr = inet_addr("192.168.0.103"),
        host.sin_family = AF_INET,
    };

    for(int i = portmin;i < portmax;i++)
    {

        if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("[INFO] Erro ao criar o socket!");
            return 1;
        }
        host.sin_port = htons(i);
        err = connect(sockfd,(struct sockaddr *)&host,sizeof host);
        if(err == 0)
        {
            fprintf(stdout, "[INFO] PORTA %d ABERTA\n", i);
            close(sockfd);
        }else
            close(sockfd);
        
        
    }
    
}

