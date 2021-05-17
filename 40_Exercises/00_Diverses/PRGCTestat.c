#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_recs 1940




	//Define struct in the same structure as the records
	struct rec {
		long long time;
		int pressure;
		char system;
		char alarm;
		
	};
	
	int main()
	{
		//Read the data out of the binfile
		struct rec reactor_record[max_recs];
		int i;
		
		FILE *ptr_binfile;
		ptr_binfile=fopen("pressureSpike.bin", "rb");
		
		if(!ptr_binfile)
		{
			printf("Unable to opten file!");
			return 1;
		}
		
		fseek(ptr_binfile, sizeof(struct rec), SEEK_SET);
		rewind(ptr_binfile);
		
		for(i= 1; i < max_recs; i++) {
			fread(&reactor_record[i] .time, sizeof(long long), 1, ptr_binfile);
			fread(&reactor_record[i] .pressure, sizeof(int), 1, ptr_binfile);	
			fread(&reactor_record[i] .system, sizeof(char), 1, ptr_binfile);
			fread(&reactor_record[i] .alarm, sizeof(long long), 1, ptr_binfile);
			
		}
		
		
		
		for(i=1; i < max_recs; i++) {
		printf("Time: %lld\n" , reactor_record[i] .time);
		printf("Pressure: %d\n" , reactor_record[i] .pressure);
		printf("System State: %d\n" , reactor_record[i] .system);
		printf("Alarm State: %d\n" , reactor_record[i] .alarm);		
		printf("\n");
		}
		
		fclose(ptr_binfile);
		
		
		//Open a csv file and write the data in it
		
		FILE *fp = NULL;
		fp = fopen("reactorlogs.csv","a");
		
		if(fp==NULL)
		{
		printf("Error in creating the file\n");
		exit(1);
		}
		
		for(i=1; i< max_recs; i++)  {
		fprintf(fp, "%lld;%d,%d,%d\n", reactor_record[i] .time, reactor_record[i].pressure, reactor_record[i].system, reactor_record[i].alarm);
		}
		
		fclose(fp);
		
		
		return 0;
		
		
	}
	
	
/*
// fread_fwrite.c
#include <stdio.h>
#include <stdlib.h>

struct {
	long long time;
	int pressure;
	char system[4];
	char alarm[1];
}records;

void speichern(void) {
	FILE *save =fopen("pressureSpike.bin","r+b");
	if( NULL== save) {
		save = fopen("pressureSpike.bin", "w+b");
		if( NULL==save )  {
		fprintf(stderr, "Kann \"adressen.dat\" nicht öffen!\n);
		return;
		}
	}
	// FILE-Zeiger save auf das Ende der Datei setzen
	fseek(save, 0, SEEK_END);
	
	//Wir schreiben eine Adresse ans Ende von "adressen.dat".
	if(fwrite(%records, sizeof(records), 1, save)  !=1)  {
		fprintf(stderr, "Fehler bei fwrite..!!!
	}
	//Wir geben unseren FILE-Zeiger wieder frei.
	fcloese(save);
}

void ausgabe(void) {
	FILE *output = fopen("pressureSpike.bin", "r+b");
	if (NULL ==output ) {
		fprintf(stderr, "Kann \"adressen.dat\" nicht öffnen!\n")
		return;
	}
	//Wir lesen alle Adressen aus "pressureSpike.bin".
	while( fread(&records, sizeof(records), 1, output) == 1) {
	printf("time...........: %lld\n", records.time);
	printf("pressure.......: &d\n", records.pressure);
	printf("system.........: &s\n", records.system);
	printf("alarm..........: &s\n", records.alarm);
	printf("\n\n");
	
	}
	fclose(output);
}



*/



