bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

int  prime[5761500],cnt=1;
int status[3125500];bitset<100000009>store;

void sieve()
{
	 int i, j, sqrtN;
     sqrtN = int( sqrt( mxx ) );
     store.set();



     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <= mxx; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }
	 prime[0]=2;j=1;store[2]=false;
	 for(i=3;i<=mxx;i+=2)
     {
         if( Check(status[i>>5],i&31)==0)prime[j++]=i,cnt++,store[i]=false;
     }
     printf("%d\n",cnt);
}
