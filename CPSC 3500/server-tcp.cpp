#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>

using namespace std;

#define MAXBUF 1000000


struct sockaddr_in sockme, newsockme;
int s, childs;
char *hostnum;
int type;
int portnum;

char bufout[1000];
char bufin[MAXBUF+1];
int result;
char c, *cp;
int n;



int main(int argc, char *argv[])
{
   // Get the port number from the command-line arguments
   if (argc == 2)
   {
      portnum = atoi(argv[1]);
   }
   else {
      cout << "usage: server-tcp <portnum>" << endl;
      exit(-1);
   }

    sockme.sin_family = AF_INET;
    sockme.sin_addr.s_addr = INADDR_ANY;
    sockme.sin_port = htons(portnum);




    s = socket(PF_INET, SOCK_STREAM, 0);

    bind(s, (struct sockaddr *) &sockme, sizeof(sockme));


// Queue up to 20 incoming requests
    result = listen(s, 20);
   
   
   
   
   cout << "Server started" << endl;
   cout << "Listening on port " << portnum << endl;
   
   
   while (1)
   {         // servers never sleep...

       socklen_t alen = sizeof(newsockme);
       childs = accept(s, (struct sockaddr *) &newsockme, &alen);
      
      
      
      char *bp = bufin;
      int cnt = MAXBUF;
      while ( (n = recv (childs, bp, cnt, 0)) > 0 ) {
         bp += n;
         cnt = MAXBUF - (bp - bufin);
      }
      *bp = '\0';
      
      
      cout << "Received: " << bufin << endl;



       // Just echo what was sent
       result = send (childs, bufin, strlen(bufin), 0);
       result = close(childs);
      
   
   }
   
   
   // Close the socket
   close (s);
   
   return 0;
}