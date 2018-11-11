void flush_in_std(){ 
   int ch; while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}
