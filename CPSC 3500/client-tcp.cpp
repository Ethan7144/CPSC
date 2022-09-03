/************************* INCLUDES **************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>

using namespace std;


/************************* MACROS ****************************/
#define MAXBUF 1000000
#define FALSE 0
#define TRUE 1


/************************* VARIABLES ****************************/
struct sockaddr_in sockme;
int s;
int type;
int portnum;
char *hostnum;


char bufout[MAXBUF+1];
char bufin[MAXBUF+1];
char c, *cp;
char filename[100];

int result;
int n;


int main(int argc, char *argv[])
{
   
   // Get the port number and dotted decimal address of server
   // from the command-line arguments
   if (argc == 3)
   {
      hostnum = argv[1];
      portnum = atoi(argv[2]);
   }
   else
   {
      cout << "usage: client-tcp <hostnum> <portnum>" << endl;
      exit(-1);
   }



    sockme.sin_family = AF_INET;

    if ((sockme.sin_addr.s_addr = inet_addr(hostnum)) == INADDR_NONE)
    {
        cout << "Invalid dotted decimal address" << endl;

        exit(-1);
    }






    sockme.sin_port = htons(portnum);
   
   
   
   
   //   Get message from user, send to server
   char message[100] = "";
   
   
   // Run indefinitely, until the user enters the /QUIT command
   while(true)
   {
       s = socket(PF_INET, SOCK_STREAM, 0);

       if ((result = connect (s, (struct sockaddr *) &sockme, sizeof(sockme))))
       {
           perror("Connect failed\n");
           close (s);
           exit(-1);
       };
      
      
      cout << "--------------------------------------" << endl;
      cout << "Connected to server at IP address = " << hostnum;
      cout << " and Port = " << portnum << endl;
      
      cout << "Input your request (99 characters max). Enter /QUIT when finished:" << endl;
      
      
      // Read a message from the standard input
      string msg;

      getline (cin, msg);
      
      
      
      if (msg == "/QUIT")
      {
         // Close the socket
         close(s);
         
         break;
      }

      
      // Send the message
      int total_characters = msg.length();
      
      cout << "Message: " << msg << endl;
      cout << "Message size: " << total_characters << endl;


       result = send (s, msg.c_str(), total_characters, 0);

       if (result == -1)
       {
           perror("Send failed");
           exit(-1);
       }
      
      
      
      
      
      // Now half close the connection so the server knows
      // the request is complete
      result = shutdown(s, 1);
      
   
      
      // Read response from the server, send to standard output
      char *bp = bufin;
      int cnt = MAXBUF;


       while ( (n = recv (s, bp, cnt, 0)) > 0 )
       {
           bp += n;
           cnt = MAXBUF - (bp - bufin);
       }


      
      if (n != -1)
      {
         *bp = '\0';
         cout << "Response was: " << bufin << endl;
      }
      else
      {
         perror("recv failed");
         exit(-1);
      }
      
      
      // Close the socket
      close(s);
      
   }
   
   

   return 0;
}
