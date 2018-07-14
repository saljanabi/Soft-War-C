#include "../../../include/c/zhelpers.h"
#include <unistd.h>


int main (int argc, char ** argv)
{
    ///////////////////////////////////////
    //Variable/////////////////////////////
    //logfile Fichier de log
    //cycle   Nombre de milliseconde par cycle
    //size    Taille de la map
    //pport   Port envoi notife client
    //rport   Port recoi les commandes
    //verboses       mode verbose
    char *logfile;
    int cycle = 100000;
    int size = 5;
    int verbose  = 0;
    
    char *rport = malloc(4 * sizeof(char));
    rport = "4242";
    
    char *pport = malloc(4 * sizeof(char));
    pport = "4243";
    
    logfile = malloc(10 * sizeof(char));
    logfile = "server.log";


    //////////////////////////////////////
    //Gestion des arguments
    // --rep-port  == rport
    // --pub-port  == pport
    // --cycle     == cycle
    // -v          == verbose
    // --log       == logfile
    // --size      == size
    // --help -h --usage == affiche le usage
    int i = 0;
    
    
    while (i < argc)
    {
        //////////////////////////
        //USAGE///////////////////
        //////////////////////////
        if(strcmp(argv[i], "--usage") == 0 || strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "?") == 0 )
        {
            printf("---------------------------------------------\n");
            printf("          Usage        \n");
            printf("---------------------------------------------\n");
            printf("--rep-port [port utilisé pour recevoir les commandes des clients et répondre]\n");
            printf("--pub-port [port utilisé pour envoyer les notifications aux clients]\n");
            printf("--cycle [nombre en microsecondes correspondant à un cycle (> 0)]\n");
            printf("-v (active le mode verbose (loglevel INFO))\n");
            printf("--log [fichier de log]\n");
            printf("--size [taille de la map]\n");
            exit(0);
        }

        if(strcmp(argv[i], "--log") == 0)
        {
            logfile = malloc(strlen(argv[++i]) * sizeof(char));
            logfile = argv[i];
        }

        if(strcmp(argv[i], "--cycle") == 0)
        {
             cycle = atoi(argv[++i]);
        }
        if(strcmp(argv[i], "--req-port") == 0)
        {
            rport = argv[++i];
        }
        if (strcmp(argv[i], "--pub-port") == 0)
        {
            pport = argv[++i];
        }
        
        if (strcmp(argv[i], "-v") ==  0)
        {
            verbose = 1;
        }
        
        if (strcmp(argv[i], "--size") == 0)
        {
            size = atoi(argv[++i]);
        }
        i++;
    }

    printf ("Fichier de log : %s\n", logfile);
    printf ("Nombre de milliseconde par cycle : %d\n", cycle);
    printf ("Port socket req : %s\n", rport);
    printf ("Port socket pub : %s\n", pport);
    printf ("Taille de la map : %d\n", size);
    printf ("Mode verbose : %d\n", verbose);
    printf ("Lancement du serveur\n");
    printf ("Listen tcp://*\n");
    printf ("En attente\n");
    
    ///////////////////////////////////////////////////
    //Partie Socket///////////////////////////////////
    /////////////////////////////////////////////////
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    void *publisher = zmq_socket (context, ZMQ_PUB);
    int rc = zmq_bind (responder, "tcp://*:4242");
    int pub = zmq_bind (publisher, "tcp://*:4243");
    assert (pub == 0);
    assert (rc == 0);
    while (1) {
        char buffer [10];
//      memset(buffer,0,10);
        zmq_recv (responder, buffer, 10, 0);
        if (strcmp(buffer, "left") == 1)
        {
            s_sendmore(publisher, "A");
            s_send (publisher, "move left");
        }
        else if (strcmp(buffer, "right") == 1)
        s_sendmore(publisher, "B");
        s_send (publisher, buffer);
        sleep (1);
    }
    zmq_close (publisher);
    zmq_close (responder);
    zmq_ctx_destroy (context);
    return 0;
}
