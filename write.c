


/* Write in the File */
   fp = fopen(filename,"w");
   for(i=0;i<num;i++) fprintf( fp, "%d\t%d\t%d\n",
       Data[0][Index[i]],Data[1][Index[i]],Data[2][Index[i]]);
   fclose(fp);
   
   
   
   