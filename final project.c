/*
GROUP MEMBERS 
IRAKIZA JEAN DE LA PAIX 24394
GATERA BOSCO            24416
SAFARI GIHOZO PATIENCE  24456
RWAKIGARAMA REGIS       24458 

*/
#include<stdio.h>
/////////////////////////////////////////STRUCTURE//////////////////////////////////////////////////
 struct medecine{
 	int batch_number;
 	char med_name[20];
 	char manfact_name[20];
 	char med_type[15];
 	char expire_date[20];
 	int quantity;

 } med;
 /////////////////////////////////////RECORD FUCTION///////////////////////////////////////////////
 void record(){
 //printf("WELECOME TO GIHOZO PHARMACY MANAGMENT SYSTEM \n");
 printf("\t\t\t\tMEDECINE REGISTRATION FOARM \n\t\t\t\t -----------------------------\n");
 FILE * p;
 printf("\t\t\t\tBATCH NUMBER:..\n");
  printf("\t\t\t\t ");
 scanf("%d",&med.batch_number);
  printf("\t\t\t\tMEDCINE NAME:..\n");
   printf("\t\t\t\t ");
 scanf("%s",med.med_name);
  printf("\t\t\t\tMANFACTUAL NAME:..\n");
   printf("\t\t\t\t ");
 scanf("%s",med.manfact_name);
  printf("\t\t\t\tMEDECINE TYPE:..\n");
   printf("\t\t\t\t ");
 scanf("%s",med.med_type);
  printf("\t\t\t\tEXPIRED DATE:..\n");
   printf("\t\t\t\t ");
 scanf("%s",med.expire_date);
  printf("\t\t\t\tQUANTITY:..\n");
   printf("\t\t\t\t ");
 scanf("%d",&med.quantity);
 p=fopen("medecinelist.txt","a");
 fprintf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,med.quantity);
 fclose(p);

 }
////////////////////////////////////////////////SELING RECORDING FUNCTION //////////////////////////////////////////////
 void selling(){
// printf("WELECOME TO GIHOZO PHARMACY MANAGMENT SYSTEM \n");
 printf("\t\t\t\tSELLING MEDECINE  REGISTRATION FOARM \n\t\t\t\t --------------------------\n");
 FILE * pp;
 printf("\t\t\t\tBATCH NUMBER:..\n");
  printf("\t\t\t\t ");
 scanf("%d",&med.batch_number);
  printf("\t\t\t\tMEDCINE NAME:..\n");
   printf("\t\t\t\t ");
 scanf("%s",med.med_name);
  printf("\t\t\t\tMANFACTUAL NAME:..\n");
   printf("\t\t\t\t ");
 scanf("%s",med.manfact_name);
  printf("\t\t\t\tMEDECINE TYPE:..\n");
   printf("\t\t\t\t ");
 scanf("%s",med.med_type);
  printf("\t\t\t\tEXPIRED DATE:DD/MM/YYYY\n");
   printf("\t\t\t\t ");
 scanf("%s",med.expire_date);
  printf("\t\t\t\tQUANTITY:..\n");
   printf("\t\t\t\t ");
 scanf("%d",&med.quantity);
 pp=fopen("selling.txt","a");
 fprintf(pp,"%d\t%s\t%s\t%s\t%s\t%d\t\n",med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,med.quantity);
 fclose(pp);
 }
////////////////////////////////////////////////MEDCINE DISPLAY FUNCTION //////////////////////////////////////////////
void display(){
FILE *p;
p=fopen("medecinelist.txt","r");
//printf("WELECOME TO GIHOZO PHARMACY MANAGMENT SYSTEM \n");
printf("\t\t\t\tMEDICINE LIST \n\t\t\t\t----------------------------------\n");
printf("\t\t\t\tPATCH\tMEDECINE\tMANFACTURE\tTYPE\tEX-DATE\t QUANTITY\n\t\t\t\t=====\t========\t========\t====\t======\t =======\n");
while (!feof(p))
{
	fscanf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,&med.quantity);
	printf("\t\t\t\t%d\t%s\t\t%s\t\t%s\t%s\t%d\t\n",med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,med.quantity);
	}
}
/////////////////////////////////////DISLPAY SELING FUNCTION////////////////////////////////////////////////////////
 void display_selling(){
FILE *pp;
pp=fopen("selling.txt","r");
//printf("WELECOME TO GIHOZO PHARMACY MANAGMENT SYSTEM \n");
printf("\t\t\t\t\t\t MEDICINE LIST \n \n\t\t\t\t\t\t -----------------------------\n");
printf("\t\t\t\tPATCH\tMEDECINE\tMANFACTURE\tTYPE\tEX-DATE\t QUANTITY\n\t\t\t\t=====\t========\t========\t====\t======\t =======\n");
while (!feof(pp))
{
	fscanf(pp,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,&med.quantity);
	printf("\t\t\t\t%d\t%s\t\t%s\t\t%s\t%s\t%d\t\n",med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,med.quantity);
	}
}
///////////////////////////////////////////////SORTING FUCTION ///////////////////////////////////////////////////////
 void sort(){
 	FILE *p;
 	struct medecine m[100],temp;
 	int i,j,c=0,min,max;
 	p=fopen("medecinelist.txt","r");
 	while(!feof(p))
 	{
 		fscanf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&m[c].batch_number,m[c].med_name,m[c].manfact_name,m[c].med_type,m[c].expire_date,&m[c].quantity);
 		c++;

	 }
	 for(i=0;i<c-1;i++)
	 {

	 	min=m[i].batch_number;
	 	max=i;
	 	for(j=i+1;j<c;j++){
	 		if (m[j].batch_number<min)
	 		{
	 			min=m[j].batch_number;
	 			max=j;
			 }
		 }
		 temp=m[max];
		 m[max]=m[i];
		 m[i]=temp;
	 }
	 printf("\t\t\t\tPATCH\tMEDECINE\tMANFACTURE\tTYPE\tEX-DATE\t QUANTITY\n\t\t\t\t=====\t========\t========\t====\t======\t =======\n");
	 for (i=0;i<c;i++){
	 printf("\t\t\t\t%d\t%s\t\t%s\t\t%s\t%s\t%d\t\n",m[i].batch_number,m[i].med_name,m[i].manfact_name,m[i].med_type,m[i].expire_date,m[i].quantity);
	 fclose(p);
	 }
 }
 /////////////////////////////////////////REPORT FUNCTION /////////////////////////////////////////////////////////////////
 void report(){
 	printf("\t\t@@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@  @@\n");
 	printf("\t\t@@                                                                       @@\n");
 	printf("\t\t@@                       IGIHOZO PHARMACY FULL REPORT                    @@\n");
 	printf("\t\t@@                       =============================                   @@\n");
 	printf("\t\t@@                                                                       @@\n");
 	FILE *p;
p=fopen("medecinelist.txt","r");
    printf("\t\t@@                        STORED MEDICINE  LIST                          @@ \n");
    printf("\t\t@@                       =============================                   @@\n");
    printf("\t\t@@                                                                       @@\n");
    printf("\t\t@@     PATCH  MEDECINE  MANFACTURE  TYPE  EX-DATE  QUANTITY              @@\n");
    printf("\t\t@@     =====  ========  ==========  ====  ======    =======              @@\n");
while (!feof(p))
{
	fscanf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,&med.quantity);
	printf("\t\t@@     %d\t%s\t%s\t%s\t%s\t%d \n",med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,med.quantity);
	}
	printf("\t\t@@                                                                       @@\n");
	printf("\t\t@@                          SOLD MEDICINE  LIST                          @@ \n");
    printf("\t\t@@                       =============================                   @@\n");
    printf("\t\t@@                                                                       @@\n");
    printf("\t\t@@     PATCH  MEDECINE  MANFACTURE  TYPE  EX-DATE  QUANTITY              @@\n");
    printf("\t\t@@     =====  ========  ==========  ====  ======    =======              @@\n");
	
	FILE *pp;
pp=fopen("selling.txt","r");
while (!feof(pp))
{
	fscanf(pp,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,&med.quantity);
	printf("\t\t@@    %d\t%s\t%s\t%s\t%s\t%d\t\n",med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,med.quantity);
	}
	printf("\t\t@@                                                                       @@\n");
	printf("\t\t@@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@  @@\n");
	printf("\n\n\n");
	
	
	
 }
  /////////////////////////////////////////DELETE FUNCTION /////////////////////////////////////////////////////////////////
 void delet(){
 FILE *p;
 FILE *pp;
 int batch, found=0;
 struct medecine m;
 p=fopen("medecinelist.txt","r");
 printf("\t\t\t ENTER ABATCH NUMBER OF MEDECINE YOUWONT TO DELETE:..\n");
 printf("\t\t\t\t ");
 scanf("%d",&batch);
 pp=fopen("delete.txt","w");
 while (!feof(p)){
 	fscanf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,&m.quantity);
 	if(m.batch_number==batch)
 	{
 		found=1;
	 } else{
	 	fprintf(pp,"%d\t%s\t%s\t%s\t%s\t%d\t\n",m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,m.quantity);
	 	
	 }
}
	 fclose(p);
	 fclose(pp);
	 if (found){
	 	pp=fopen("delete.txt","r");
	 	p=fopen("medecinelist.txt","w");
	 	while(!feof(pp)){
	 		fscanf(pp,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,&m.quantity);
		    fprintf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,m.quantity);
		 }
		 fclose(p);
		 fclose(pp);
		 printf("\n\n");
		 printf("\t\t\t\t DELETE SUCCESSFULL\n\n");
	 }else if(found==0){
	 	printf("\n\n");
		 printf("\t\t\t\t BATCH NUMBER NOT FOUND\n\n");
	 }
	 
	 
 }
	////////////////////////////////////////SEARCHING FUNCTIO ///////////////////////////////////////////////////////////////
 void search(){

 	FILE *p;
 	int find;
 	printf("\t\t\t\tENTER THE BATCH-NUMBER TO SEARCH:\n");
 	printf("\t\t\t\t ...");
 	scanf("%d",&find);
 	p=fopen("medecinelist.txt","r");
 	while (!feof(p)){
 		fscanf(p,"%d \t %s \t %s \t %s \t %s \t %d \t \n",&med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,&med.quantity);
 		if(med.batch_number==find)
 		{
 		printf("\t\t\t\tPATCH\tMEDECINE\tMANFACTURE\tTYPE\tEX-DATE\t QUANTITY\n\t\t\t\t=====\t========\t========\t====\t======\t =======\n");
		printf("\t\t\t\t%d\t%s\t\t%s\t\t%s\t%s\t%d\t\n",med.batch_number,med.med_name,med.manfact_name,med.med_type,med.expire_date,med.quantity);
	 fclose(p);
	 return;
		 }
	 }
 	printf("batch number not found !!!!\n");
    fclose(p);
    
 }
 /////////////////////////////////update function //////////////////
 void update(){
 	struct medecine m;
 	struct medecine mup;
 	FILE *p;
 	FILE *pp;
 	p=fopen("medecinelist.txt","r");
 	printf("\t\t\t ENTE THE BATCH NUMBER YOUWONT TO UPDATE\n");
 	printf("\t\t\t");
 	int batch, found=0;
 	scanf("%d",&batch);
 	pp=fopen("update.txt","w");
 	while (!feof(p)){
 		fscanf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,&m.quantity);
 		if(m.batch_number!=batch){
 			fprintf(pp,"%d\t%s\t%s\t%s\t%s\t%d\t\n",m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,m.quantity);
		 }
		 else{
		 	found=1;
		 }
	 }
	 fclose(p);
	 fclose(pp);
	 if (found==1){
	 pp=fopen("update.txt","r");
	 p=fopen("medecinelist.txt","w");
	 while(!feof(pp))
	 {
	 	fscanf(pp,"%d\t%s\t%s\t%s\t%s\t%d\t\n",&m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,&m.quantity);
		fprintf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",m.batch_number,m.med_name,m.manfact_name,m.med_type,m.expire_date,m.quantity);
		 }
		 fclose(p);
		 fclose(pp);
		 	
	 }
	  
	  p=fopen("medecinelist.txt","a");
	  printf("\t\t\t\tMEDECINE UPDATE FOARM \n\t\t\t\t -----------------------------\n");
 printf("\t\t\t\t NEW BATCH NUMBER:..\n");
  printf("\t\t\t\t ");
 scanf("%d",&mup.batch_number);
  printf("\t\t\t\t NEW MEDCINE NAME:..\n");
   printf("\t\t\t\t ");
 scanf("%s",mup.med_name);
  printf("\t\t\t\t NEW MANFACTUAL NAME:..\n");
   printf("\t\t\t\t ");
 scanf("%s",mup.manfact_name);
  printf("\t\t\t\t NEW MEDECINE TYPE:..\n");
   printf("\t\t\t\t ");
 scanf("%s",mup.med_type);
  printf("\t\t\t\t NEW EXPIRED DATE:..\n");
   printf("\t\t\t\t ");
 scanf("%s",mup.expire_date);
  printf("\t\t\t\tNEW QUANTITY:..\n");
   printf("\t\t\t\t ");
 scanf("%d",&mup.quantity);
 fprintf(p,"%d\t%s\t%s\t%s\t%s\t%d\t\n",mup.batch_number,mup.med_name,mup.manfact_name,mup.med_type,mup.expire_date,mup.quantity);
 	printf("\n \n");
 	printf("\t\t\t PRODUCT UPDETED SUCCESSFULLY !!!\n\n");
 	fclose(p);
 }
 //////////////////////////////////////////////////MAIN FUNCTION ///////////////////////////////////////////////////////////
 int main(){
 	 printf("\n\n\n");
    printf("\t\t\t######################################################################\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t#       WELCOME TO IGIHOZO PHARMACY MANAGMENT SYSTEM (IPMS)          #\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t#                                                                    #\n");
    printf("\t\t\t######################################################################\n");
    printf("\n\n");
 	int choice,y;
 	char yy;
 	do
 	{
    printf("\t\t\t\t###########################################\n");
    printf("\t\t\t\t##                                       ##\n");
 	printf("\t\t\t\t##       DO YOU WONT TO CONTINUE ?(Y,N)  ##\n");
 	printf("\t\t\t\t##                                       ##\n");
 	printf("\t\t\t\t###########################################\n");
 	printf("\t\t\t\t ...");
    scanf("%s",&yy);
    if(yy=='y'||yy=='Y'){
    	y=1;
    		printf("\t\t\t\tPLZ ENTER YOUR CHOICE ACCORDING TO THE ACTION YOU WANT .....\n \n\t\t\t\t[1].RECORD NEW-MEDECINE \n\t\t\t\t[2].STORED-MEDECINE REPORT \n\t\t\t\t[3].SEARCH A MEDECINE IN PHARMACY \n\t\t\t\t[4].SELLING MEDECINE RECORDING\n\t\t\t\t[5].SOLD MEDECINE REPORT\n\t\t\t\t[6].SORTING STORED MEDECINE \n\t\t\t\t[7].UPDATE STORED MEDECINE \n\t\t\t\t[8].DELETE EXPIRED MEDECINE\n\t\t\t\t[9].REPORT \n\t\t\t\t[0].EXIT \n");
 	        printf("\t\t\t\t ...");
	        scanf("%d",&choice);
 	        switch (choice){

 		case 1:
 			record();
 			break;

 		case 2:
 			display();
 			break;

 		case 3:
 			search();
 			break;

 		case 4:
 			selling();
 			break;

 		case 5:
 			display_selling();
 			break;

 		case 6:
 			sort();
 			break;
 		case 7:
 			update();
 			break;
 		case 8:
 			delet();
 			break;
 		case 9:
 			report();
 			break;

 		case 0:
 			break;


 		default:

			printf("\t\t\t\tYOUR CHOICE IS WRONG!!....");
			printf("\n\n\n");
     }
	} 
	else if(yy=='n'|| yy=='N'){
		y=0;
		printf("\t\t\t\tBYE BYE !!....");
    		printf("\n\n\n");

 			break;
	} 
    	else{
    		printf("\t\t\t\t WRONG CHOICE PLZ BE SHURE ON YOUR CHOICE !!!!\n");
				printf("\n\n\n");
    		
		}
   } while(yy!=0);
}
