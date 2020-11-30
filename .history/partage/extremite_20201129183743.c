#include "extremite.h"


/*  
    Crée un serveur écoutant sur le port 123
    redirige les données recues sur la sortie standard
 */
void extout() {
    // char * port = "123";

    // // Descripteurs de sockets
    // int s,n;

    // // Utilitaires
    // int len, on = 1;
    // struct sockaddr_in client;

    // struct addrinfo * resol; 

    struct addrinfo indic = {
        AI_PASSIVE,              
        PF_INET6,
        SOCK_STREAM,
        0,
        0,
        NULL,
        NULL,
        NULL
    };

    // int err = getaddrinfo(NULL,port,&indic,&resol); 
    // if (err<0){
    //     fprintf(stderr,"Résolution: %s\n",gai_strerror(err));
    //     exit(2);
    // }

    // /* Création de la socket, de type TCP / IP */
    // if ((s=socket(resol->ai_family,resol->ai_socktype,resol->ai_protocol))<0) {
    //     perror("allocation de socket");
    //     exit(3);
    // }
    // fprintf(stderr,"le n° de la socket est : %i\n",s);

    // /* On rend le port réutilisable rapidement /!\ */
    // if (setsockopt(s,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0) {
    //     perror("option socket");
    //     exit(4);
    // }
    // fprintf(stderr,"Option(s) OK!\n");

    // /* Association de la socket s à l'adresse obtenue par résolution */
    // if (bind(s,resol->ai_addr,sizeof(struct sockaddr_in6))<0) {
    //     perror("bind");
    //     exit(5);
    // }
    // freeaddrinfo(resol); /* /!\ Libération mémoire */
    // fprintf(stderr,"bind!\n");

    // /* la socket est prête à recevoir */
    // if (listen(s,SOMAXCONN)<0) {
    //     perror("listen");
    //     exit(6);
    // }
    // fprintf(stderr,"listen!\n");

    // while(1) {
    //     /* attendre et gérer indéfiniment les connexions entrantes */
    //     len=sizeof(struct sockaddr_in);
    //     if( (n=accept(s,(struct sockaddr *)&client,(socklen_t*)&len)) < 0 ) {
    //         perror("accept");
    //         exit(7);
    //     }

    //     /* Nom réseau du client */
    //     char hotec[NI_MAXHOST], portc[NI_MAXSERV];  

    //     err = getnameinfo((struct sockaddr*)&client,len,hotec,NI_MAXHOST,portc,NI_MAXSERV,0);
    //     if (err < 0 ){
    //         fprintf(stderr,"résolution client (%i): %s\n",n,gai_strerror(err));
    //     }else{ 
    //         fprintf(stderr,"accept! (%i) ip=%s port=%s\n",n,hotec,portc);
    //     }
    //     /* traitement */
    //     writeSrcInDst(n, 1);
    // }
}

void main()
{
    extout();
}

void extin() {

}
