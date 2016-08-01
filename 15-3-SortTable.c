#include<stdio.h>
#define DATA_SIZE 100

int Swap(int X[], int i, int j)
{
    int tmp;
   
    tmp = X[i];
    X[i] = X[j];
    X[j] = tmp;
   
    return 0;
}

int Quick_Sort_Ex(int Data[], int min, int max, int Index[])
{
    int i,j,k,p;

    if(min>=max)return 1;

    p = Data[Index[(min+max)/2]];
    i = min;
    j = max;

    while(i<=j)
        {
        while(Data[Index[i]]<p) i++;
        while(Data[Index[j]]>p) j--;
        if(i>=j) break;
        Swap(Index,i,j);
        i++; j--;
        }
    Quick_Sort_Ex(Data,min,i-1,Index);
    Quick_Sort_Ex(Data,j+1,max,Index);

    return 0;
}

int main()
{
    char  filename[20];
    FILE  *fp;

    int  Data[3][DATA_SIZE];
    int  Index[DATA_SIZE];
    int  i,num,rc,id;
 
    /* Get FileName */
    printf("Input filename : ");
    scanf("%s", filename);

    /* Read File */
    fp=fopen(filename, "r");
    if(fp==NULL) return -1;
    num=0;
    while(num<DATA_SIZE)
        {
        rc=fscanf(fp,"%d%d%d",&Data[0][num],&Data[1][num],&Data[2][num]);
        if(rc == EOF)break;
        num++;
        }
    fclose(fp);

    /* Sort ID */  
    for(i=0;i<num;i++) Index[i] = i;
    //ID順
    //Quick_Sort_Ex(Data[0],0,num-1,Index);
    //English順
    //Quick_Sort_Ex(Data[1],0,num-1,Index);
    //Math順
    Quick_Sort_Ex(Data[2],0,num-1,Index);
   
    /* Display Table */
    printf("Id\tEnglish\tMath\n");
    for(i=0;i<num;i++) printf("%d\t%d\t%d\n",
        Data[0][Index[i]],Data[1][Index[i]],Data[2][Index[i]]);

   /* Get FileName */
   printf("Output filename : ");
   scanf("%s", filename);
 
   /* Write in the File */
   fp = fopen(filename,"w");
   for(i=0;i<num;i++) fprintf( fp, "%d\t%d\t%d\n",
       Data[0][Index[i]],Data[1][Index[i]],Data[2][Index[i]]);
   fclose(fp);

    return 0;
}
