char N_[9],W_[20];
main()
{
	read(0,N_,9);
	int N=0;
	for(int i=0;N_[i]>='0';i++)N=N*10+N_[i]-'0';
	long ans=0;
	int i=1;
	while(i<=N)
	{
		long j=N/(N/i)+1;
		ans+=(j-i)*(i+j-1)*(N/i)*(N/i+1)/4;
		i=j;
	}
	i=20;
	do{W_[--i]=ans%10+'0';}while(ans/=10);
	write(1,W_+i,20-i);
}