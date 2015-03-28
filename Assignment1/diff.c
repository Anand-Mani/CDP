#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

using namespace std;

/********************

Function : diff
(for diff of two files)

This function says only that this files are same or not.

**********************/

void diff(FILE *fp1, FILE *fp2)
{
    int ch1, ch2;
    ch1 = getc(fp1);
    ch2 = getc(fp2);

    while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
         ch1 = getc(fp1);
         ch2 = getc(fp2);

    }
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    if (ch1 == ch2)
        printf("----- Files are identical. -----\n");
    else if(ch1!=ch2)
        printf("----- Files are Not identical -----\n");

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
    fclose(fp1);
    fclose(fp2);
}

/********************

Function : diffp
(for diff of two files by persentage-wise)

this gives How much % of file-2 is different from file-1

**********************/

void diffp(FILE *f1, FILE *f2)
{
    char c1[1000],c2[1000];
    //fgets(c1, 1000, f1);
	//fgets(c2, 1000, f2);
	int j=0;
	char s[1000][1000];
	while((fgets(c1,1000,f1)!= NULL))
    {
        strcpy(s[j],c1);
        j++;
    }
    //printf("1%s2%s3%s", s[0], s[1], s[2]);
    int n[j]={0};
    //printf("%d %d", n[0],n[1]);
    int pcnt = 0;
    int ncnt = 0;

    int k=0;
    bool flag = false;
    //int count = 0;
    while(fgets(c2,1000,f2)!= NULL)
    {
        k=0;
        flag = false;
        while(k<j)
        {
            if( strcmp(c2,s[k])==0 && n[k] == 0 )
            {
                pcnt++;
                n[k]++;
                flag = true;
                break;
            }
            k++;
        }


        if(flag==false)
            ncnt++;
    }

    int ans = (pcnt*100)/(pcnt+ncnt);
    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("File-2 is -- %d persentage-- matching with file-1\n",ans);
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

	fclose(f1);
    fclose(f2);
}

/********************

Function : diffl
(for diff of two files by linewise)

**********************/


void diffl(FILE *f1, FILE *f2)
{
    char c1[1000],c2[1000];
    fgets(c1, 1000, f1);
	fgets(c2, 1000, f2);
	int j=0;

	while((fgets(c1,1000,f1)!= NULL) && (fgets(c2,1000,f2)!= NULL))
	{
		j++;
		if( strcmp(c1,c2) != 0 )
		{
			printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("file1 - line: %d\n",j);
			printf( "   %s\n",c1);
			printf( "-----------------------------------------------------\n");
			printf( "file2 - line: %d\n",j);
			printf( "   %s\n", c2);
			printf( ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		}
	}
    fclose(f1);
    fclose(f2);
}

/***************************
******************************
        Main Function
******************************
******************************/

int main()
{
    FILE *fl1, *fl2;

    char s[10];
    bool flag=true;
    while(flag==true)
    {
        printf("CMD >> ");
        scanf("%s",s);
        if(strcmp(s,"quit")==0)
        {
            flag = false;
        }

        /************* For Batchfile operation *********************/
        else if(strcmp(s,"batchfile")==0)
        {
                //cout<<"NO"<<endl;
                FILE *f;
                f = fopen("batchfile","r");
                if(f==NULL)
                    printf("batchfile is not there or error in opening it.");
                else
                {
                    char buf[256];
                    char c1[16], c2[16];
                    while (fgets (buf, 256, f))
                    {
                        //char cmd[256];
                        //strcpy(cmd,buf);
                        fgets (c1, 16, f);
                        fgets (c2, 16, f);
                        //cout<<"YES"<<endl;
                        char c11[16];
                        char c22[16];
                        int a=0;
                        while(c1[a]!='\n')
                        {
                            c11[a]=c1[a];
                            a++;
                        }
                        while(a<16)
                        {
                            c11[a]='\0';
                            a++;
                        }
                        a=0;
                        while(c2[a]!='\n')
                        {
                            c22[a]=c2[a];
                            a++;
                        }
                        while(a<16)
                        {
                            c22[a]='\0';
                            a++;
                        }
                        fl1 = fopen(c11,"r");
                        fl2 = fopen(c22,"r");

                        printf("CMD > %sFile -1 : %sFile -2 : %s",buf, c11, c22);
                        if(fl2==NULL)
                        {
                            printf("Error in File-2.\n");
                        }
                        else if(fl1==NULL)
                        {
                            printf("Error in File-1.\n");
                        }
                        else
                        {
                            if(strcmp(buf,"diff-p\n")==0)
                            {
                                diffp(fl1,fl2);
                            }
                            else if(strcmp(buf,"diff\n")==0)
                            {
                                diff(fl1,fl2);
                            }
                            else if(strcmp(buf,"diff-l\n")==0)
                            {
                                diffl(fl1,fl2);
                            }
                            else
                            {
                                cout<<"Your Command is not valid."<<endl;
                            }
                        }
                    }
                    fclose(f);
                }

        }

        /******** For Various Diff commands *******/
        else
        {
            char c1[16], c2[16];
            cout<<"File-1:";
            scanf("%s",c1);
            cout<<"File-2:";
            scanf("%s",c2);
            fl1 = fopen(c1,"r");
            fl2 = fopen(c2,"r");

            if(fl1==NULL)
            {
                printf("Error in 1 given files.\n");
            }
            else if(fl2==NULL)
            {
                printf("Error in 2 given files.\n");
            }
            else
            {
                //printf("s\n");

                if(strcmp(s,"diff")==0)
                {
                    diff(fl1,fl2);
                }
                else if(strcmp(s,"diff-p")==0)
                {
                    diffp(fl1,fl2);
                }
                else if(strcmp(s,"diff-l")==0)
                {
                    diffl(fl1,fl2);
                }
                else
                {
                    cout<<"Your Command is not valid."<<endl;
                }
            }
        }
    }
    return 0;
}
