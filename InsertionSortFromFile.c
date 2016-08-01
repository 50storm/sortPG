#include <stdio.h>
#define DATA_SIZE 100

int COMPARE_COUNT=0;


int Insertion_Sort(int X[], int num){
      int i,j,tmp;
      for(i=1; i < num ; i++)
      {
            tmp = X[i];
            for(j=i-1; j>=0 ; j--)
            {
                  COMPARE_COUNT++;
                  if(tmp < X[j])
                  {
                    X[j+1]=X[j];
                    if(j==0) X[0]=tmp;
                  }else{
                    X[j+1] = tmp;
                    break;
                  }
            }
      }
      return 0;

}

int main(){
      int Data[DATA_SIZE];
      char filename[20];
      int i,n, rc;
      FILE *fp;


      printf("Input filename :");
      scanf("%s", filename);
      
      fp=fopen(filename, "r");
      if(fp==NULL)
      { 
        printf("couln't read file");
        return 1;
      }else{
        printf("read file.");
      }
      n=0;
      while( n<DATA_SIZE)
      {
        rc = fscanf(fp, "%d", &Data[n]);
        if(rc == EOF) break;
        n++;
      }
      fclose(fp);

      printf("Before: \n");
      for(i=0; i<n ; i++) printf("%d \t", Data[i]);
      printf("\n");

      rc = Insertion_Sort(Data,n);
      
      printf("After: \n");
      for(i=0; i<n ; i++) printf("%d \t", Data[i]);
      printf("\nComparing: %d tmes \n", COMPARE_COUNT);
      
      return 0;

}
