#include <stdio.h>

int main(void) {
  printf("Hello World\n");
    printf("\n    AES Algorithm Encryption Implementation   \n\n\n");
    char s[17],s1[17],c1, c2;
    int i[4][4],k[4][4],x,y,y1,t1,z,h,t,j,a[4],a1[4],b[2],l,p,q,c[4]={0},f1=0,g;
    int l1,m, gh, round;

  //      S-box Intialization
	int s_box[16][16]={{99,124,119,123,242,107,111,197,48,1,103,43,254,215,171,118},
			{202,130,201,125,250,89,71,240,173,212,162,175,156,164,114,192},
			{183,253,147,38,54,63,247,204,52,165,229,241,113,216,49,21},
			{4,199,35,195,24,150,5,154,7,18,128,226,235,39,178,117},
			{9,131,44,26,27,110,90,160,82,59,214,179,41,227,47,132},
			{83,209,0,237,32,252,177,91,106,203,190,57,74,76,88,207},
			{208,239,170,251,67,77,51,133,69,249,2,127,80,60,159,168},
			{81,163,64,143,146,157,56,245,188,182,218,33,16,255,243,210},
			{205,12,19,236,95,151,68,23,196,167,126,61,100,93,25,115},
			{96,129,79,220,34,42,144,136,70,238,184,20,222,94,11,219},
			{224,50,58,10,73,6,36,92,194,211,172,98,145,149,228,121},
			{231,200,55,109,141,213,78,169,108,86,244,234,101,122,174,8},
			{186,120,37,46,28,166,180,198,232,221,116,31,75,189,139,138},
			{112,62,181,102,72,3,246,14,97,53,87,185,134,193,29,158},
			{225,248,152,17,105,217,142,148,155,30,135,233,206,85,40,223},
			{140,161,137,13,191,230,66,104,65,153,45,15,176,84,187,22}};

  //   round constant Initialization
	int rc[5][11]={{1,2,4,8,16,32,64,128,27,54},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}};

// Getting the Text input
	printf("\nEnter the text to be encrypted  :");
 	f1=0;
  while(f1 !=16)
  {
    c1=getchar();
    s[f1]=c1;
    f1++;
  }
  s[f1]='\0';
  printf("\n \n The Give Text :%s",s);
  
  c1=getchar();

 // Getting the Key input
  printf("\n \n  Enter the key   :");
  f1=0;
  while(f1 !=16)
  {
    c1=getchar();
    s1[f1++]=c1;
  }
  s1[f1]='\0';
  printf("%s",s1);

//Storing  input string in 2D ARRAY
	z=0;
	for(x=0;x<4;x++)
		for(y=0;y<4;y++)
		{
			i[y][x]=s[z];
			z++;
		}

  //Storing  the Key in 2D ARRAY
	z=0;
	for(x=0;x<4;x++)
		for(y=0;y<4;y++)
		{
			k[y][x]=s1[z];
			z++;
		}

   printf("\n Initial KEY Matrix \n");
   for(x=0;x<4;x++)
		{
      for(y=0;y<4;y++)
			   printf("\t%x",k[x][y]);
		  printf("\n");	
		}

   printf("\n Text:State Matrix \n");
   for(x=0;x<4;x++)
		{
      for(y=0;y<4;y++)
		    	printf("\t%x",i[x][y]);
		  printf("\n");	
		}
 
// Printing S-box 
printf("\n S Box \n");
   for(x=0;x<16;x++)
		{
    	 for(y=0;y<16;y++)
			    printf("\t %x",s_box[x][y]);
	     printf("\n");	
		}

// Printing Round constant 
printf("\n RC Matrix \n");
   for(x=0;x<5;x++)
		{
    	 for(y=0;y<10;y++)
			   printf("\t %x",rc[x][y]);
		   printf("\n");	
		}
  printf("\n\n Round : 0 ");
  // Intial Add Round Operation
   for(x=0;x<4;x++)
	{
		for(y=0;y<4;y++)
		{
			i[y][x]=i[y][x]^k[y][x];
		}
	}
  printf("\n \n \n AEs Output after AddRoundKey Round 0");
     for(x=0;x<4;x++)
		{
    	for(y=0;y<4;y++)
			   printf("\t %x",i[y][x]);
		
		}
    // Ten Rounds for 128 bit Text input
 for( round=0; round<10; round++)
{
      printf("\n AES Example Round %d",round+1);       
  // Generation of key for Round:	
    printf("\n Generation of key for Round : %d\n",round+1);
	  j=3;
    // Row Selection
	 for(x=0;x<4;x++)
	  {
		  a[x]=k[x][j];
  	}
   // Row Shifting
    j=a[0];
	 for(x=0;x<3;x++)
	  {
		  a[x]=a[x+1];
	  }
	  a[3]=j;
    // S Box Replacement
	 for(x=0;x<4;x++)
	   {
		   int b[3]={0};
		   j=1;
     	 while(a[x]!=0)
		   {
			  l=a[x]%16;
			  b[j]=l;
			  j--;
			  a[x]=a[x]/16;
		   }
		   a[x]=s_box[b[0]][b[1]];
     }
    for(x=0;x<4;x++)
	     {
		   a[x]=rc[x][round]^a[x];
	     }
       // First column XOR
	  for(x=0;x<4;x++)
	   {
		   k[x][0]=a[x]^k[x][0];
	   }
    // Second column XOR
  	for(x=0;x<4;x++)
	   {
		  k[x][1]=k[x][0]^k[x][1];
     }
	  // Third column XOR
	   for(x=0;x<4;x++)
	    {
	      k[x][2]=k[x][1]^k[x][2];
	    }
	  // Fourth column XOR
     for(x=0;x<4;x++)
	    {
	     	k[x][3]=k[x][2]^k[x][3];
	     }
     printf("KEY Matrix \n");
       for(x=0;x<4;x++)
	     {
        for(y=0;y<4;y++)
	      	printf("\t%x",k[x][y]);
	      printf("\n");	
	     }

  // Sub Byte Module- S Box Replacement in State Matrix     
   printf("\n SUB BYTES");
	 for(y=0;y<4;y++)
	 {
		 for(x=0;x<4;x++)
		 {
			int b[3]={0};
			j=1;
			while(i[x][y]!=0)
			{
				l=i[x][y]%16;
				b[j]=l;
				j--;
				i[x][y]=i[x][y]/16;
				b[j]=i[x][y];
			}
			i[x][y]=s_box[b[0]][b[1]];
		}
	}  
  printf("\n State Matrix \n");
   for(x=0;x<4;x++)
	 {
        for(y=0;y<4;y++)
		       printf("\t%x",i[x][y]);
	      printf("\n");	
   }
// Shifting Rows in State Matrix 
  printf("\n Shifting Rows:");
//  one  Left Shift on 2nd row:
	l=i[1][0];
	for(x=0;x<3;x++)
	{
		i[1][x]=i[1][x+1];
	}
	  i[1][3]=l;
//  Two  Left Shift on 3rd row:
	  l=i[2][0];
	  p=i[2][1];
	for(x=0;x<2;x++)
	{
		i[2][x]=i[2][x+2];
	}
	  i[2][2]=l;
	  i[2][3]=p;
// Three Left Shift on  4th row
	  l=i[3][0];
	  p=i[3][1];
	  q=i[3][2];
	  i[3][0]=i[3][3];
	  i[3][1]=l;
	  i[3][2]=p;
	  i[3][3]=q;

printf("\n State Matrix \n");
   for(x=0;x<4;x++)
	{
    for(y=0;y<4;y++)
		   printf("\t%x",i[x][y]);
	   printf("\n");	
	}
    printf("\n");

  //  Mixing columns:
 if (round !=9)
  {
    // Mixing Columns for all Rounds Except last round

	int flag[4][4]={{2,3,1,1},{1,2,3,1,},{1,1,2,3},{3,1,1,2}};
	for(x=0;x<4;x++)
	{
		for(y=0;y<4;y++)
		{
			a[y]=i[y][x];
			a1[y]=i[y][x];
		}
    for(y=0;y<4;y++)
		{  
     	for(z=0;z<4;z++)
			{  
       	t=a[z];t1=a[z];
				if(flag[y][z]==2 && ((t>>7) & 1))
        {
          // Flag bit is 2 and the leftmost significat bit is 1.
					a1[z]=((a[z]<<1)^27);
          a1[z]=a1[z]& 255;
				}
				else if(flag[y][z]==2)
				{
					a1[z]=a[z]<<1;
				}
				else if(flag[y][z]==1)
				{
					a1[z]=a[z];
				}
				else if(flag[y][z]==3 && (t>>7 & 1))
				{
          // Flag bit is 3 and the leftmost significat bit is 1.
					a1[z]=(((t1<<1)^27)^a[z]);
          a1[z]=a1[z]& 255;
				}
				else
				{
					a1[z]=((t1<<1)^a[z]);
				}
      }
  // Xor Operation on all the four values.  
        c[y]=a1[0]^a1[1]^a1[2]^a1[3];	
      
		}	
  // Placing into the State Matrix Columns:		
		for(y=0;y<4;y++)
		{
			i[y][x]=c[y];
		}
  }
    printf("Mix Columns:");
    printf("\n State Matrix \n");
   	for(l1=0;l1<4;l1++)
		{
     	for(m=0;m<4;m++)
			    printf("\t%x",i[l1][m]);
	  	printf("\n");	
		}	
 }
// AddRound key Operation:
// XOR Operation Between State Matrix and Key Matrix
	for(x=0;x<4;x++)
	{
		for(y=0;y<4;y++)
		{
			i[x][y]=i[x][y]^k[x][y];
		}
	}
  printf("\n Add round Key:");
    printf("\n State Matrix \n");
  for(l1=0;l1<4;l1++)
		{
     	for(m=0;m<4;m++)
			    printf("\t%x",i[l1][m]);
		  printf("\n");	
		}	
    // One Round Operation is Over.
  printf("\n AEs Output after AddRoundKey Round %d\n", round+1);
  printf("\n CipherText:\n");
  for(x=0;x<4;x++)
		{
    	for(y=0;y<4;y++)
			   printf("\t %x",i[y][x]);
		}
    printf("\n\n");
 }
return 0;
}



OUTPUT:


clang version 7.0.0-3~ubuntu0.18.04.1 (tags/RELEASE_700/final)
? clang-7 -pthread -lm -o main main.c
? ./main


    AES Algorithm Encryption Implementation



Enter the text to be encrypted  :Two One Nine Two


 The Give Text :Two One Nine Two

  Enter the key   :Thats my Kung Fu
Thats my Kung Fu
 Initial KEY Matrix
    54  73  20  67
    68  20  4b  20
    61  6d  75  46
    74  79  6e  75

 Text:State Matrix
    54  4f  4e  20
    77  6e  69  54
    6f  65  6e  77
    20  20  65  6f

 S Box
     63  7c  77  7b  f2  6b  6f  c5  30  1   67  2b  fe  d7  ab  76
     ca  82  c9  7d  fa  59  47  f0  ad  d4  a2  af  9c  a4  72  c0
     b7  fd  93  26  36  3f  f7  cc  34  a5  e5  f1  71  d8  31  15
     4   c7  23  c3  18  96  5   9a  7   12  80  e2  eb  27  b2  75
     9   83  2c  1a  1b  6e  5a  a0  52  3b  d6  b3  29  e3  2f  84
     53  d1  0   ed  20  fc  b1  5b  6a  cb  be  39  4a  4c  58  cf
     d0  ef  aa  fb  43  4d  33  85  45  f9  2   7f  50  3c  9f  a8
     51  a3  40  8f  92  9d  38  f5  bc  b6  da  21  10  ff  f3  d2
     cd  c   13  ec  5f  97  44  17  c4  a7  7e  3d  64  5d  19  73
     60  81  4f  dc  22  2a  90  88  46  ee  b8  14  de  5e  b   db
     e0  32  3a  a   49  6   24  5c  c2  d3  ac  62  91  95  e4  79
     e7  c8  37  6d  8d  d5  4e  a9  6c  56  f4  ea  65  7a  ae  8
     ba  78  25  2e  1c  a6  b4  c6  e8  dd  74  1f  4b  bd  8b  8a
     70  3e  b5  66  48  3   f6  e   61  35  57  b9  86  c1  1d  9e
     e1  f8  98  11  69  d9  8e  94  9b  1e  87  e9  ce  55  28  df
     8c  a1  89  d   bf  e6  42  68  41  99  2d  f   b0  54  bb  16

 RC Matrix
     1   2   4   8   10  20  40  80  1b  36
     0   0   0   0   0   0   0   0   0   0
     0   0   0   0   0   0   0   0   0   0
     0   0   0   0   0   0   0   0   0   0
     0   0   0   0   0   0   0   0   0   0


 Round : 0


 AEs Output after AddRoundKey Round 0    0   1f  e   54  3c  4e  8   59  6e  221b   b   47  74  31  1a
 AES Example Round 1
 Generation of key for Round : 1
KEY Matrix
    e2  91  b1  d6
    32  12  59  79
    fc  91  e4  a2
    f1  88  e6  93

 SUB BYTES
 State Matrix
    63  eb  9f  a0
    c0  2f  93  92
    ab  30  af  c7
    20  cb  2b  a2

 Shifting Rows:
 State Matrix
    63  eb  9f  a0
    2f  93  92  c0
    af  c7  ab  30
    a2  20  cb  2b

Mix Columns:
 State Matrix
    ba  84  e8  1b
    75  a4  8d  40
    f4  8d  6   7d
    7a  32  e   5d

 Add round Key:
 State Matrix
    58  15  59  cd
    47  b6  d4  39
    8   1c  e2  df
    8b  ba  e8  ce

 AEs Output after AddRoundKey Round 1

 CipherText:
     58  47  8   8b  15  b6  1c  ba  59  d4  e2  e8  cd  39  df  ce


 AES Example Round 2
 Generation of key for Round : 2
KEY Matrix
    56  c7  76  a0
    8   1a  43  3a
    20  b1  55  f7
    7   8f  69  fa

 SUB BYTES
 State Matrix
    6a  59  cb  bd
    a0  4e  48  12
    30  9c  98  9e
    3d  f4  9b  8b

 Shifting Rows:
 State Matrix
    6a  59  cb  bd
    4e  48  12  a0
    98  9e  30  9c
    8b  3d  f4  9b

Mix Columns:
 State Matrix
    15  c9  7f  9d
    ce  4d  4b  c2
    89  71  be  88
    65  47  97  cd

 Add round Key:
 State Matrix
    43  e   9   3d
    c6  57  8   f8
    a9  c0  eb  7f
    62  c8  fe  37

 AEs Output after AddRoundKey Round 2

 CipherText:
     43  c6  a9  62  e   57  c0  c8  9   8   eb  fe  3d  f8  7f  37


 AES Example Round 3
 Generation of key for Round : 3
KEY Matrix
    d2  15  63  c3
    60  7a  39  3
    d   bc  e9  1e
    e7  68  1   fb

 SUB BYTES
 State Matrix
    1a  ab  1   27
    b4  5b  30  41
    d3  ba  e9  d2
    aa  e8  bb  9a

 Shifting Rows:
 State Matrix
    1a  ab  1   27
    5b  30  41  b4
    e9  d2  d3  ba
    9a  aa  e8  bb

Mix Columns:
 State Matrix
    aa  65  fa  88
    16  c   5   3a
    3d  c1  de  2a
    b3  4b  5a  a

 Add round Key:
 State Matrix
    78  70  99  4b
    76  76  3c  39
    30  7d  37  34
    54  23  5b  f1

 AEs Output after AddRoundKey Round 3

 CipherText:
     78  76  30  54  70  76  7d  23  99  3c  37  5b  4b  39  34  f1


 AES Example Round 4
 Generation of key for Round : 4
KEY Matrix
    a1  b4  d7  14
    12  68  51  52
    2   be  57  49
    c9  a1  a0  5b

 SUB BYTES
 State Matrix
    bc  51  ee  b3
    38  38  eb  12
    4   ff  9a  18
    20  26  39  a1

 Shifting Rows:
 State Matrix
    bc  51  ee  b3
    38  eb  12  38
    9a  18  4   ff
    a1  20  26  39

Mix Columns:
 State Matrix
    10  bc  d3  f3
    d8  94  e0  e0
    53  ea  9e  25
    24  40  73  7b

 Add round Key:
 State Matrix
    b1  8   4   e7
    ca  fc  b1  b2
    51  54  c9  6c
    ed  e1  d3  20

 AEs Output after AddRoundKey Round 4

 CipherText:
     b1  ca  51  ed  8   fc  54  e1  4   b1  c9  d3  e7  b2  6c  20


 AES Example Round 5
 Generation of key for Round : 5
KEY Matrix
    b1  5   d2  c6
    29  41  10  42
    3b  85  d2  9b
    33  92  32  69

 SUB BYTES
 State Matrix
    c8  30  f2  94
    74  b0  c8  37
    d1  20  dd  50
    55  f8  66  b7

 Shifting Rows:
 State Matrix
    c8  30  f2  94
    b0  c8  37  74
    dd  50  d1  20
    b7  55  f8  66

Mix Columns:
 State Matrix
    2a  26  8f  e9
    78  1e  c   7a
    1b  a7  6f  a
    5b  62  0   3f

 Add round Key:
 State Matrix
    9b  23  5d  2f
    51  5f  1c  38
    20  22  bd  91
    68  f0  32  56

 AEs Output after AddRoundKey Round 5

 CipherText:
     9b  51  20  68  23  5f  22  f0  5d  1c  bd  32  2f  38  91  56


 AES Example Round 6
 Generation of key for Round : 6
KEY Matrix
    bd  b8  6a  ac
    3d  7c  6c  2e
    c2  47  95  e
    87  15  27  4e

 SUB BYTES
 State Matrix
    14  26  4c  15
    d1  cf  9c  7
    b7  93  7a  81
    45  8c  23  b1

 Shifting Rows:
 State Matrix
    14  26  4c  15
    cf  9c  7   d1
    7a  81  b7  93
    b1  45  8c  23

Mix Columns:
 State Matrix
    a9  37  aa  f2
    ae  d8  c   21
    e7  6c  b1  9c
    f0  fd  67  3b

 Add round Key:
 State Matrix
    14  8f  c0  5e
    93  a4  60  f
    25  2b  24  92
    77  e8  40  75

 AEs Output after AddRoundKey Round 6

 CipherText:
     14  93  25  77  8f  a4  2b  e8  c0  60  24  40  5e  f   92  75


 AES Example Round 7
 Generation of key for Round : 7
KEY Matrix
    cc  74  1e  b2
    96  ea  86  a8
    ed  aa  3f  31
    16  3   24  6a

 SUB BYTES
 State Matrix
    fa  73  ba  58
    dc  49  d0  76
    3f  f1  36  4f
    f5  9b  9   9d

 Shifting Rows:
 State Matrix
    fa  73  ba  58
    49  d0  76  dc
    36  4f  3f  f1
    9d  f5  9b  9

Mix Columns:
 State Matrix
    9f  37  51  37
    af  ec  8c  fa
    63  39  4   66
    4b  fb  b1  d7

 Add round Key:
 State Matrix
    53  43  4f  85
    39  6   a   52
    8e  93  3b  57
    5d  f8  95  bd

 AEs Output after AddRoundKey Round 7

 CipherText:
     53  39  8e  5d  43  6   93  f8  4f  a   3b  95  85  52  57  bd


 AES Example Round 8
 Generation of key for Round : 8
KEY Matrix
    8e  fa  e4  56
    51  bb  3d  95
    ef  45  7a  4b
    21  22  6   6c

 SUB BYTES
 State Matrix
    ed  1a  84  97
    12  6f  67  0
    19  dc  e2  5b
    4c  41  2a  7a

 Shifting Rows:
 State Matrix
    ed  1a  84  97
    6f  67  0   12
    e2  5b  19  dc
    7a  4c  41  2a

Mix Columns:
 State Matrix
    e8  8a  4b  f5
    74  75  ee  e6
    d3  1f  75  58
    55  8a  c   38

 Add round Key:
 State Matrix
    66  70  af  a3
    25  ce  d3  73
    3c  5a  f   13
    74  a8  a   54

 AEs Output after AddRoundKey Round 8

 CipherText:
     66  25  3c  74  70  ce  5a  a8  af  d3  f   a   a3  73  13  54


 AES Example Round 9
 Generation of key for Round : 9
KEY Matrix
    bf  45  a1  f7
    e2  59  64  f1
    bf  fa  80  cb
    90  b2  b4  d8

 SUB BYTES
 State Matrix
    33  51  79  a
    3f  8b  66  8f
    eb  be  76  7d
    92  c2  67  20

 Shifting Rows:
 State Matrix
    33  51  79  a
    8b  66  8f  3f
    76  7d  eb  be
    20  92  c2  67

Mix Columns:
 State Matrix
    b6  e7  51  8c
    84  88  98  ca
    34  60  66  fb
    e8  d7  70  51

 Add round Key:
 State Matrix
    9   a2  f0  7b
    66  d1  fc  3b
    8b  9a  e6  30
    78  65  c4  89

 AEs Output after AddRoundKey Round 9

 CipherText:
     9   66  8b  78  a2  d1  9a  65  f0  fc  e6  c4  7b  3b  30  89


 AES Example Round 10
 Generation of key for Round : 10
KEY Matrix
    28  6d  cc  3b
    fd  a4  c0  31
    de  24  a4  6f
    f8  4a  fe  26

 SUB BYTES
 State Matrix
    1   3a  8c  21
    33  3e  b0  e2
    3d  b8  8e  4
    bc  4d  1c  a7

 Shifting Rows:
 State Matrix
    1   3a  8c  21
    3e  b0  e2  33
    8e  4   3d  b8
    a7  bc  4d  1c


 Add round Key:
 State Matrix
    29  57  40  1a
    c3  14  22  2
    50  20  99  d7
    5f  f6  b3  3a

 AEs Output after AddRoundKey Round 10

 CipherText:
     29  c3  50  5f  57  14  20  f6  40  22  99  b3  1a  2   d7  3a
}