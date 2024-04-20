 #include"all.h"
char buffer[200];
    int i;

int wifi(int i)
{
	if(i==1)
	{
  transmit_outsting("AT\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	km_mdelay(400);
				while(!(STK_CTRL&(0x01<<16)))
				{
					;
				}		
	
	 if(i==2)
	{
		transmit_outsting("AT+CWMODE=3\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }	
	
	
	 if(i==3)
	{
		transmit_outsting("AT+CWJAP=\"KM-2.4G4F\",\"9963111084\"\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }

 if(i==4)
	{
		transmit_outsting("AT+CIFSR\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	
	
	if(i==5)
	{
		transmit_outsting("AT+CIPMUX=0\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	
	if(i==6)
	{
		transmit_outsting("AT+CIPMODE=0\r\n");
	if(receive_outchar()!=0)
	{
		return -1;
	}
	 return 0;
  }
	return 0;
}




	int receive_outchar()
	 {
		for(i=0;i<200;i++)
		{
			buffer[i]=receive_char();
			if(buffer[i]=='K' && buffer[i-1]=='O')
			{
				return 0;
			}
		}
		return -1;
 	}
		

	
