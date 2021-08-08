// Server application

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>

// For storing the Telephone Directory information
struct person
{
    char name[20];
    char designation[20];
    long int phone;
};
void main()
{
	int sid,bd,lis,acptd,rd,sd;
	struct sockaddr_in sin;
	char buf[100];     // For reading the Data
	char buf1[100];    // For Writing the Data
	socklen_t len;

// Socket Creation	
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

// Socket Binding 
	bd=bind(sid,(struct sockaddr*)&sin,sizeof(sin));
	if(bd < 0)
	{
		printf("\n Binding failed\n");
		exit(-1);
	}
	printf("\n Binding completed\n");

// Server is Listening for Client Application
	lis=listen(sid,5);
	if(lis < 0)
	{	
		printf("\n Error in listening\n");
		exit(-1);
	}
	printf("\nlistening is completed\n");
	len=sizeof(sin);

// Accepting the Client
	acptd=accept(sid,(struct sockaddr*)&sin,&len);
	if(acptd < 0)
	{
		printf("\n Error in accepting\n");
		exit(-1);
	}
	printf("\n Client is accepted\n");

//Reading the Option data(1/2/3) from the Client and Store into 'buf' 
	rd=read(acptd,buf,50);
        if(rd<0)
        {
                 printf("Error in receiving\n");
                 exit(-1);
        }
        int a=atoi(buf);    // Convert into the integer(option)
	
        printf("Option is: %d",a);
        if(a==1)
	{
	  do
	  {
	       rd=read(acptd,buf,50);  // Read the data form client
        	if(rd<0)
	        { 
		 printf("Error in receiving\n");
		 exit(-1);
        	}

	     printf("\n Message received from client:%s:",buf);
            printf("\n Enter the string to Client:");
	    scanf("%s",buf1);
	    sd=send(acptd,buf1,50,0);
	    if(sd<0)
	    { 
	      printf("\n Error in sending data\n");
	      exit(-1);
	     }
	   } while(strcasecmp(buf1,"STOP")!=0);
	 
	}
	
	else if(a==2)
	{

// Dictonary Application Get the word from Client and send the meaning to Client

        rd=read(acptd,buf,50); 
	if(rd<0)  
	{   
		printf("Error in receiving\n"); 
 		 exit(-1); 
	} 
        FILE *fptr;     // For reading the meaning from File
        char name[20],mean[20]; 
	fptr = (fopen("sample.txt", "r"));
        if(fptr == NULL)
        {
      	   printf("Error!");
      	    exit(1);
     	}
        printf("\n Word received from client:%s:\n",buf);
  	while(fscanf(fptr,"%s", name)!=EOF)   // searching the word in the file
     	 {
          if((strcmp(name,buf))==0)
	   {
	    fscanf(fptr,"%s", mean);    // Read the meaning from the file
	    sd=send(acptd,mean,40,0); 
 	    if(sd<0)
		{   
 		 printf("\nError in sending data\n");  
 		 exit(-1); 
 		 }
	     break;  // once found come out of searching 
           }
         }

      }  
       else if(a==3)
       {
	        // Telephone Directory- Option 3
	   rd=read(acptd,buf,40);
           printf("%s",buf);
           if(rd<0)
            {
                printf("Error in receiving\n");
                 exit(-1);
            }

	       FILE *infile;
    		struct person input;

    // Open person.dat for reading
    		infile = fopen ("person.dat","rb");
    		if (infile == NULL)
    		{
       		   fprintf(stderr, "\nError opening file\n");
        	   exit (1);
    		}
     while(fread(&input, sizeof(struct person), 1, infile))
     {
        if(strcmp(buf,input.designation)==0)
	{
           
	sprintf(buf1,"%s %s %ld",input.name, input.designation, input.phone);
	printf("\n Data  is: %s\n",buf1);
        sd=send(acptd,buf1,sizeof(buf1),0);
        if(sd<0)
             {
                printf("\nError in sending data\n");
                 exit(-1);
             }
       }
    }   // End of While

    send(acptd,"End",sizeof("end"),0); //indicate the end of data search in file
    
     fclose (infile);        // close the file
  }
   shutdown(sid,2);
   close(sid);
}


