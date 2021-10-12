#include <stdio.h>
#include <stdlib.h>
int main()
{
  char filename[20], tempfile[20],  ch;
  FILE *f1, *f2;
  printf("Enter the file name which you want to be encrypted: ");
  scanf("%s",filename);
  f1=fopen(filename,"r");
  if(f1==NULL)
  {
  printf("error to open the file.\n");
  exit(1);
  }
  // create a temporary file.
  f2=fopen("temp.txt","w");
  if(f2==NULL)
  {
  printf("Error to creating new file.\n");
  exit(1);
  }
  //logic for encrypt any file.
  int count=-1;
  ch=fgetc(f1);
  do
  {
    ++count;
    //encryption keys.
    if(count%2==0)
  {
    fputc(ch+3,f2);
    ch=fgetc(f1);
  }
  else
   {
    fputc(ch-2,f2);
    ch=fgetc(f1);
  }
  } while (ch!=EOF);
  
  fclose(f1);
  fclose(f2);

    f1 = fopen(filename, "w");
    if(f1 == NULL)
        return 0;
    f2 = fopen("temp.txt", "r");
    if(f2 == NULL)
        return 0;
  ch=fgetc(f2);
  while(ch!=EOF)
  {
    fputc(ch,f1);
    ch= fgetc(f2);
  }
  fclose(f1);
  fclose(f2);
  printf("\nfile is encrypted successfully!");
}
