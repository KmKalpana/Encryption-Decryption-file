#include<stdio.h>
#include<conio.h>
int main()
{
    char fname[20],decrypt[20], ch;
    FILE *f1, *f2;
    printf("Enter the any file name for decrypting the data: ");
    gets(fname);  //temp file.
    printf("Enter the file name which you want to be decrypted: ");
    gets(decrypt);   //original file.
    f1 = fopen(fname, "w");
    if(f1== NULL)
        return 0;
    f2 = fopen(decrypt, "r");
    if(f2 == NULL)
        return 0;

   int count=-1;
    ch = fgetc(f2);
    while(1)
  {
  ++count;
  if(ch==EOF)
  {
  break;
  }
  if(count%2==0)
  {
    ch=ch-3;
    fputc(ch,f1);
    ch=fgetc(f2);
  }
  else
  {
    ch=ch+2;
    fputc(ch,f1);
    ch=fgetc(f2);
    }
  }
    fclose(f1);
    fclose(f2);
    //You can copy the decrypted data in original file.
    f1=fopen(fname,"r");
    f2=fopen(decrypt,"w");
    ch=fgetc(f1);
    while(ch!=EOF)
    {
      fputc(ch,f2);
      ch=fgetc(f1);
    }
  fclose(f1);
  fclose(f2);
    printf("\nFile %s Decrypted Successfully!", decrypt);
    return 0;
}