// Client  Application

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
void main()
{
	int sid,bd,lis,con,rd,sd,n;
	struct sockaddr_in sin;
	char buf[100];
	char buf1[100];
	socklen_t len;
	sid=socket(PF_INET,SOCK_STREAM,0);
	if(sid==-1)
	{
		 printf("\n Error in creating socket\n");
		 exit(-1);
	}
	printf("\nSocket is created successfully\n");
	memset(&sin,0,sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_port=htons(2113);
	sin.sin_addr.s_addr=htonl(INADDR_ANY);
	con=connect(sid,(struct sockaddr*)&sin,sizeof(sin));
	if(con<0)
	{
	       	printf("\n Connection failed\n");
		exit(-1);
	}
	printf("\nConnection established");

        printf("\n Menu");
        printf("\n 1. Chat Application");
        printf("\n 2. Dictornary Application");
        printf("\n 3. Telephone Directory");
        printf("\n Enter your Option:");
        scanf("%d",&n);

	  // Converting option value integer data into string
	sprintf(buf,"%d",n);
	  // printf("%s",buf);
        sd=send(sid,buf,10,0);

       switch(n)
       {
       case 1:
       // Chat Application between Server and Client
       // Type STOP to quit fro Chat Applcation

       do
	{
	 printf("\n Enter the string to be sent to Server:");
	 scanf("%s",buf);
	 sd=send(sid,buf,50,0);
	 if(sd<0)
	 {
	    printf("\n Error in sending data\n");
	    exit(-1);
	 }
	 rd=read(sid,buf1,50);
	 if(rd<0)
	    {
	        printf("\nError in reading data\n");
		exit(-1);
	    }
	 printf("\n The content recieved from sender is: %s\n",buf1);
	}     while(strcasecmp(buf1,"STOP")!=0);

	break;
       
      case 2:
	 // Dictonary Application

        printf("\n Enter the word(Meaning to be searched):");
 	scanf("%s",buf);
// Send the word to client to search the meaning of word
  	sd=send(sid,buf,15,0);
  	if(sd<0)
	{
	printf("\nerror in sending data\n");
 	exit(-1);
	}
	rd=read(sid,buf1,10);
	if(rd<0)
	{
		printf("\nError in reading data\n");
                 exit(-1);
 	}
 	printf("\n The Meaning for the given word %s is: %s \n",buf,buf1);
  	
       break;
      case 3:
            // telephone Directory
     printf("\n Enter the Designation:(whose phone number is required): ");
        scanf("%s",buf);
        sd=send(sid,buf,15,0);
        if(sd<0)
        {
            printf("\nerror in sending data\n");
            exit(-1);
        }
	do
	{ 
		// Reading the data from the Server
	 rd=read(sid,buf1,100);
         if(rd<0)
          {
                printf("\nError in reading data\n");
                exit(-1);
          }
         printf("\n Recieved data from file %s\n", buf1);
	}
	while(strcasecmp(buf1,"end")!=0);
	break;
  }
        shutdown(sid,2);
        close(sid);

}
