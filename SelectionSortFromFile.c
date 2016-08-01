#include <stdio.h>
#define DATA_SIZE 100

int COMPARE_COUNT=0;

int Swap(int X[], int n, int m){
      int tmp;

      tmp  = X[n];
      X[n] = X[m];
      X[m] = tmp;
      return 0;

}

int Selection_Sort(int X[], int num){
      int i,j,max;
      for(i=num-1; i > 0; i--)
      {
            max=0;
            for(j=1; j<=i ; j++)
            {
                  COMPARE_COUNT++;
                   //仮の最大値より、大きい値が見つかったら、インデックスを設定し直す
                  if(X[max] < X[j]) max=j;
            }
            Swap(X,i,max);
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
      if(fp==NULL) return 1;
      
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

      rc = Selection_Sort(Data,n);
      
      printf("After: \n");
      for(i=0; i<n ; i++) printf("%d \t", Data[i]);
      printf("\nComparing: %d tmes \n", COMPARE_COUNT);
      
      return 0;

}
