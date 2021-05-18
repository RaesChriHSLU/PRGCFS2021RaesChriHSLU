#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_recs 1940


//Hochschule Luzern, Maschinenbau, Programmieren in C, FS2021, Testat, Christoph Raess
//------------------------------------------------------------------------------------------------------
	//Struktur soll genau gleich definiert werden wie die Sturktur der Aufnahmen
	
	
	struct rec {
	
	
				long long time;
				int pressure;
				char system;
				char alarm;
	
	
		
	};
	
	
	
	//Hauptprogramm----------------------------------------------------------------------------------
	
		int main()
		{
		
			//Lies die Daten aus dem binfile
		
		
			struct rec Reaktor_Aufnahme[max_recs];
			int c;
		
		
			FILE *ptr_binfile;
			ptr_binfile=fopen("pressureSpike.bin", "rb");
		
		
			
			if(!ptr_binfile)
		
		
			{
			printf("Unable to opten file!");
			return 1;
			}
		
		
		
			fseek(ptr_binfile, sizeof(struct rec), SEEK_SET);
			rewind(ptr_binfile);
		
			for(c= 1; c < max_recs; c++) 
			
			
			//Auflistung: Zeit, Druck, Systemstatus, Alarmsignal
			{
			fread(&Reaktor_Aufnahme[c] .time, sizeof(long long), 1, ptr_binfile);
			fread(&Reaktor_Aufnahme[c] .pressure, sizeof(int), 1, ptr_binfile);	
			fread(&Reaktor_Aufnahme[c] .system, sizeof(char), 1, ptr_binfile);
			fread(&Reaktor_Aufnahme[c] .alarm, sizeof(long long), 1, ptr_binfile);	
			}
		
	
		
			for(c=1; c < max_recs; c++) 
			{
			printf("Time: %lld\n" , Reaktor_Aufnahme[c] .time);
			printf("Pressure: %d\n" , Reaktor_Aufnahme[c] .pressure);
			printf("System State: %d\n" , Reaktor_Aufnahme[c] .system);
			printf("Alarm State: %d\n" , Reaktor_Aufnahme[c] .alarm);	
				
			printf("\n");
			}
			
		
			fclose(ptr_binfile);
		
		
		
		
	//CSV-File--------------------------------------------------------------------------------------
			// Ab hier oeffne das CSV-FILE und schreibe die Daten hinein
		
			FILE *fp = NULL;
			fp = fopen("reactorlogs.csv","a");
		
			if(fp==NULL)
			
			
			{
			printf("Error in creating the file\n");
			exit(1);
			}
		
		
		
			for(c=1; c< max_recs; c++)  {
		
			fprintf(fp, "%lld;%d,%d,%d\n", 
			Reaktor_Aufnahme[c] .time, 
			Reaktor_Aufnahme[c].pressure, 
			Reaktor_Aufnahme[c].system, 
			Reaktor_Aufnahme[c].alarm);
			}
		
		
		
			fclose(fp);
		
		
			return 0;
		
		
		}
	
	



