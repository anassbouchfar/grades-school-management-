#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct matiere{
	
                                            //S1
/*1*/ char anglais[5], /*2*/francais[5], /*3*/langage_C1[5], /*4*/circuite_assembleur[5], /*5*/analyse[5], /*6*/algebre[5],/*7*/ langage_C2[5]
                                            //S2
	 ,/*8*/base_donnee[5], /*9*/php[5], /*10*/droit[5], /*11*/economie[5], /*12*/organisation[5], /*13*/linux_reseau[5] ;
}libellematiere;


typedef struct etudiant{
	char nom[20],prenom[20],cin[20],cne[11],date_naissance[11],password[20];
	int semestre;

}etudiant;

typedef struct professeur{
		char nom[20],prenom[20],cin[20],date_naissance[11],password[20];
		int matiere;
	
}professeur;
typedef struct administrateur{
	char password[20];
}admin;




void majiscule(char phrase[]);

void ajouter_etudiant();
void supprimer_etudiant();
void modifier_etudiant();
void rechercher_etudiant();
void afficher_etudiant();
void inscription_semestre();
void gestion_etudiant();

void ajouter_professeur();
void supprimer_professeur();
void modifier_professeur();
void rechercher_professeur();
void gestion_professeur();
void noter(int matiere);

void menu_administrateur();
void menu_principal();
void menu_etudiant(char cne[]);
void menu_professeur(char cin[]);
//void semestre1(char cne[],char nom, char prenom[]);
int main(){
	menu_principal();
	return 0;
}






int password(char code[]){
	int i=-1;
	printf("mot de passe : ");
  char    *T=(char *) malloc(1*sizeof(char));
			 do{
		           if(i!=-1) T=(char *) realloc(T,1*sizeof(char));
			 	i++;
			 	    *(T+i)=getch();
			        if(T[i]!='\r') printf("*");
			 }while(*(T+i)!='\r');
		
		T[i]='\0';	 
    int res;
	res=strcmp(code,T);
	free(T);    
	return res;
}
void majiscule(char phrase[]){
	int i;
	for (i=0;i<strlen(phrase);i++){
		if(phrase[i]>='a'&& phrase[i]<='z') phrase[i]-=32;
	}
	
}

void ajouter_etudiant(){
	etudiant E;
	FILE *p_fichier=fopen("etudiant.txt","a+");
	
	printf("Nom : "); scanf("%s",E.nom);majiscule(E.nom);
	printf("Prenom : ");scanf("%s",E.prenom);majiscule(E.prenom);
	printf("CIN : ");scanf("%s",E.cin);majiscule(E.cin);
	printf("CNE : ");scanf("%s",E.cne);majiscule(E.cne);
	printf("Date de naissance : ");scanf("%s",E.date_naissance);
	printf("password : ");scanf("%s",E.password);
	printf("Semestre : ");scanf("%d",&E.semestre);
	fprintf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,E.semestre);
    fclose(p_fichier);
}
void supprimer_etudiant(){
    char cne[11];int a=0;
    etudiant E;
	
	FILE *p_fichier=fopen("etudiant.txt","r");
	printf("entrer le cne de l'etudiant a supprimer : ");scanf("%s",cne);majiscule(cne);
	while(!feof(p_fichier)){ 
	fscanf(p_fichier,"%s\n",E.cne);
	if(strcmp(E.cne,cne)==0) a++;
	 }
	 if(a==0) printf("\nCe etudiant n'existe pas \n");
	 else {
	 fseek(p_fichier,0,SEEK_SET);	
      FILE *p_fichiersupp=fopen("etudiantsupp.txt","w");
	while(!feof(p_fichier)){
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
		if(strcmp(E.cne,cne)!=0){
		
			fprintf(p_fichiersupp,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,E.semestre);
		}
	}
	fclose(p_fichier);
	fclose(p_fichiersupp);
	int supp=remove("etudiant.txt");
	int renom=rename("etudiantsupp.txt","etudiant.txt");
	printf("\nEtudiant supprime \n") ;
		 }
		fclose(p_fichier);
}
void modifier_etudiant(){
char cne[11];int a=0;
    etudiant E;
	etudiant N;
	FILE *p_fichier=fopen("etudiant.txt","r");
	printf("entrer le cne de l'etudiant a modifier : ");scanf("%s",cne);
	majiscule(cne);
	while(!feof(p_fichier)){ 
	fscanf(p_fichier,"%s\n",E.cne);
	if(strcmp(E.cne,cne)==0) a++;
	 }
	 if(a==0) printf("\nCe etudiant n'existe pas \n");
	 else {
	 	printf("\nentrer le nouveau Nom : ");scanf("%s",N.nom);majiscule(N.nom);
	 	printf("\nentrer le nouveau Prenom : ");scanf("%s",N.prenom);majiscule(E.prenom);
	 	printf("\nentrer le nouveau Cin : ");scanf("%s",N.cin);majiscule(N.cin);
	 	printf("\nentrer le nouveau Cne : ");scanf("%s",N.cne);majiscule(N.cne);
	 	printf("\nentrer la nouvelle date de naissance : ");scanf("%s",N.date_naissance);
	 	printf("\nentrer le nouveau mot de passe :");scanf("%s",N.password);
      FILE *p_fichiermod=fopen("etudiantmod.txt","w");
      fseek(p_fichier,0,SEEK_SET);
	while(!feof(p_fichier)){
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
		if(strcmp(E.cne,cne)!=0){
			
			fprintf(p_fichiermod,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,E.semestre);
		}
		else fprintf(p_fichiermod,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",N.nom,N.prenom,N.cin,N.cne,N.date_naissance,N.password,E.semestre);
	}
	fclose(p_fichier);
	fclose(p_fichiermod);
	int supp=remove("etudiant.txt");
	int renom=rename("etudiantmod.txt","etudiant.txt");
	printf("\nEtudiant modifie \n") ;
		 }
		 fclose(p_fichier);
}
void rechercher_etudiant(){
   int choix;
	printf("\n[1] Rechercher par CNE\n[2] Rechercher Par NOM \n");
    printf("entrer votre choix : ");scanf("%d",&choix);
    switch (choix){
    	case 1:system("cls");{int a=0; etudiant E ;char cne[20]; printf("\nentrer le cne de l'etudiant a rechercher : ");scanf("%s",cne);
    	    majiscule(cne);
    		FILE *p_fichier=fopen("etudiant.txt","r");
    		while(!feof(p_fichier)){
    			fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,E.semestre);
    			if(strcmp(E.cne,cne)==0){
    				printf(" les information de l'etudiant : \n");
    				printf("Nom : %s\n",E.nom); 
	                printf("Prenom : %s\n",E.prenom);
	                printf("CIN : %s\n",E.cin);
	                printf("CNE : %s\n",E.cne);
	                printf("Date de naissance : %s\n",E.date_naissance);
	                printf("password : %s\n",E.password);
	                printf("password : %d\n",E.semestre);
	                a++;break;
    			}
    		
    		}
    		fclose(p_fichier);
    			if(a==0) printf("Ce etudiant n'existe pas ! \n");
    	} break;
    	case 2:system("cls");{ int a=0;etudiant E ;char nom[20]; printf("\nentrer le nom de l'etudiant a rechercher : ");scanf("%s",nom);
    	  majiscule(nom);
    		FILE *p_fichier=fopen("etudiant.txt","r");
    		while(!feof(p_fichier)){
    			fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,E.semestre);
    			if(strcmp(E.nom,nom)==0){
    				printf(" les information de l'etudiant : \n");
    				printf("Nom : %s\n",E.nom); 
	                printf("Prenom : %s\n",E.prenom);
	                printf("CIN : %s\n",E.cin);
	                printf("CNE : %s\n",E.cne);
	                printf("Date de naissance : %s\n",E.date_naissance);
	                printf("password : %s\n",E.password);
	                 printf("password : %d\n",E.semestre);
	                a++;break;
    			}
    			
    		}
    		fclose(p_fichier);
    		if(a==0) printf("Ce etudiant n'existe pas ! \n");
    	} break;
    }
	
}
void afficher_etudiant(){
int choix;
	printf("[1] Genie Informatique (GI)CC)\n[2] menu principal\n");
	printf("\n           entrer le filiere : ");scanf("%d",&choix);
	switch (choix){
		case 1:system("cls"); 
		int choix2;
			printf("[1] Semestre 1\n[2] Semestre 2\n[3] Semestre 3\n[4] Semestre 4\n");
			printf("\n           entrer le semestre : "); scanf("%d",&choix2);
			etudiant E ;int var=0;
			FILE *p_fichier=fopen("etudiant.txt","r");
			switch (choix2) {
			    case 1:	
				 while(!feof(p_fichier)){
						fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
						if(E.semestre==1){ var=1;
							printf("****************************************************\n");
							printf(" Nom : %s\n",E.nom); 
	                        printf(" Prenom : %s\n",E.prenom);
	                        printf(" CIN : %s\n",E.cin);
	                        printf(" CNE : %s\n",E.cne);
	                        printf(" Date de naissance : %s\n",E.date_naissance);
	                        printf("****************************************************\n");
						}
						
					}
					fclose(p_fichier);if(var==0) printf("\naucun etudiant inscrit au 1er Semestre\n");
					break;
					
				     
								
				case 2:
				
					while(!feof(p_fichier)){
						fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
						if(E.semestre==2){var=1;
							printf("****************************************************\n");
							printf(" Nom : %s\n",E.nom); 
	                        printf(" Prenom : %s\n",E.prenom);
	                        printf(" CIN : %s\n",E.cin);
	                        printf(" CNE : %s\n",E.cne);
	                        printf(" Date de naissance : %s\n",E.date_naissance);
	                        printf("****************************************************\n");
						}
					}
								fclose(p_fichier);if(var==0) printf("\naucun etudiant inscrit au 2eme Semestre\n");
					
				 break;
				case 3:
				 
					while(!feof(p_fichier)){
						fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
						if(E.semestre==3){ var=1;
							printf("****************************************************\n");
							printf(" Nom : %s\n",E.nom); 
	                        printf(" Prenom : %s\n",E.prenom);
	                        printf(" CIN : %s\n",E.cin);
	                        printf(" CNE : %s\n",E.cne);
	                        printf(" Date de naissance : %s\n",E.date_naissance);
	                        printf("****************************************************\n");
						}
					}
								fclose(p_fichier);if(var==0) printf("\naucun etudiant inscrit au 3eme Semestre\n");
	
				
				 break;
				 case 4:
				 
					while(!feof(p_fichier)){
						fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
						if(E.semestre==4){ var=1;
							printf("****************************************************\n");
							printf(" Nom : %s\n",E.nom); 
	                        printf(" Prenom : %s\n",E.prenom);
	                        printf(" CIN : %s\n",E.cin);
	                        printf(" CNE : %s\n",E.cne);
	                        printf(" Date de naissance : %s\n",E.date_naissance);
	                        printf("****************************************************\n");
						}
					}
								fclose(p_fichier);if(var==0) printf("\naucun etudiant inscrit au 4eme Semestre\n");
				break;
				}
					
				break;
			
		
		
		case 2:system("cls");gestion_etudiant();break;
		
		}
	
	if(choix !=5) afficher_etudiant();
}
void inscription_semestre(){ 
     char cne[15]; etudiant E; int temp=0,sem;
	printf( "CNE : "); scanf("%s",cne);
	FILE *p_fichier=fopen("etudiant.txt","r");
	while(!feof(p_fichier)){
	fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
    if(strcmp(cne,E.cne)==0) {
    	temp=1;break;
    }
	}
	if(temp==1){
		printf("\nentrer le nouveau semestre  : ");scanf("%d",&sem);
		FILE *p_fichiermod=fopen("etudiantmod.txt","w");
      fseek(p_fichier,0,SEEK_SET);
	while(!feof(p_fichier)){
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
		if(strcmp(E.cne,cne)!=0){
			
			fprintf(p_fichiermod,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,E.semestre);
		}
		else fprintf(p_fichiermod,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,sem);
	}
	fclose(p_fichier);
	fclose(p_fichiermod);
	int supp=remove("etudiant.txt");
	int renom=rename("etudiantmod.txt","etudiant.txt");
	
		 
		 
	}
	else {
		printf("cne n'existe pas !!");
		inscription_semestre();
	}
	gestion_etudiant();
}
void gestion_etudiant(){
 int choix;
printf("---------------MENU GESTION ETUDIANT-----------------\n");
printf("[1] Ajouter un Etudiant\n");
printf("[2] Modifier un Etudiant\n");
printf("[3] Supprimer un Etudiant\n");
printf("[4] Rechercher un Etudiant\n");
printf("[5] Afficher les etudiants\n");
printf("[6] inscription dans un semestre\n");
printf("[7] Menu Principal \n");

do {
	printf("\n\n          Tapez votre choix : ");scanf("%d",&choix); 
}while(choix<1&&choix>7);

switch (choix) {
	case 1 :system("cls"); ajouter_etudiant();printf("\nEtudiant ajoute \n") ;break;

	case 2 :system("cls"); modifier_etudiant();break;
	case 3 :system("cls"); supprimer_etudiant();break;
   	case 4 :system("cls"); rechercher_etudiant();break;
   	case 5 : system("cls");afficher_etudiant();break;
   	case 6 : system("cls");inscription_semestre();break;
    case 7 :system("cls") ; menu_administrateur();break;
    
   
}

if(choix!=7 && choix!=5) { system("cls");
 gestion_etudiant(); }
}

void ajouter_professeur(){
	professeur E;int matiere;
	FILE *p_fichier=fopen("professeur.txt","a+");
	printf("Nom : "); scanf("%s",E.nom);majiscule(E.nom);
	printf("Prenom : ");scanf("%s",E.prenom);majiscule(E.prenom);
	printf("CIN : ");scanf("%s",E.cin);majiscule(E.cin);
	printf("Date de naissance : ");scanf("%s",E.date_naissance);
	printf("password : ");scanf("%s",E.password);
	printf("matiere :\n\n[1] anglais [2] francais [3] langage_C1 [4] circuite_assembleur [5] analyse [6] algebre\n");

	printf(" [7] langage_C2 [8] base_donnee [9] php [10] droit [11] economie [12] organisation [13] linux_reseau\n      ");
	scanf("%d",&matiere);
	E.matiere=matiere;
	fprintf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,E.matiere);
    fclose(p_fichier);
}
void supprimer_professeur(){
    char cin[11];int a=0;
    professeur E;
	
	FILE *p_fichier=fopen("professeur.txt","r");
	printf("entrer le cin du professeur a supprimer : ");scanf("%s",cin);majiscule(cin);
	while(!feof(p_fichier)){ 
	fscanf(p_fichier,"%s\n",E.cin);
	if(strcmp(E.cin,cin)==0) a++;
	 }
	 if(a==0) printf("\nCe professeur n'existe pas \n");
	 else {
	 fseek(p_fichier,0,SEEK_SET);	
      FILE *p_fichiersupp=fopen("professeursupp.txt","w");
	while(!feof(p_fichier)){
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,&E.matiere);
		if(strcmp(E.cin,cin)!=0){
		
			fprintf(p_fichiersupp,"%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,E.matiere);
		}
	}
	fclose(p_fichier);
	fclose(p_fichiersupp);
	int supp=remove("professeur.txt");
	int renom=rename("professeursupp.txt","professeur.txt");
	printf("\nPrefesseur supprime \n") ;
		 }
		fclose(p_fichier);
}
void modifier_professeur(){int matiere;
char cin[11];int a=0;
    professeur E;
	professeur N;
	FILE *p_fichier=fopen("professeur.txt","r");
	printf("entrer le cin du professeur a modifier : ");scanf("%s",cin);
	majiscule(cin);
	while(!feof(p_fichier)){ 
	fscanf(p_fichier,"%s\n",E.cin);
	if(strcmp(E.cin,cin)==0) a++;
	 }
	 if(a==0) printf("\nCe professeur n'existe pas \n");
	 else {
	 	printf("\nentrer le nouveau Nom : ");scanf("%s",N.nom);majiscule(N.nom);
	 	printf("\nentrer le nouveau Prenom : ");scanf("%s",N.prenom);majiscule(E.prenom);
	 	printf("\nentrer le nouveau Cin : ");scanf("%s",N.cin);majiscule(N.cin);
	 	printf("\nentrer la nouvelle date de naissance : ");scanf("%s",N.date_naissance);
	 	printf("\nentrer le nouveau mot de passe :");scanf("%s",N.password);
	 	printf("matiere :\n\n[1] anglais [2] francais [3] langage_C1 [4] circuite_assembleur [5] analyse [6] algebre\n");

	printf(" [7] langage_C2 [8] base_donnee [9] php [10] droit [11] economie [12] organisation [13] linux_reseau\n      ");
	scanf("%d",&matiere);
      FILE *p_fichiermod=fopen("professeurmod.txt","w");
      fseek(p_fichier,0,SEEK_SET);
	while(!feof(p_fichier)){
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,&E.matiere);
		if(strcmp(E.cin,cin)!=0){
			//printf("\n1\n");
			fprintf(p_fichiermod,"%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,E.matiere);
		}
		else fprintf(p_fichiermod,"%s\n%s\n%s\n%s\n%s\n%d\n",N.nom,N.prenom,N.cin,N.date_naissance,N.password,matiere);
	}
	fclose(p_fichier);
	fclose(p_fichiermod);
	int supp=remove("professeur.txt");
	int renom=rename("professeur.txt","professeur.txt");
	printf("\nProfesseur modifie \n") ;
		 }
		 fclose(p_fichier);
}
void rechercher_professeur(){
   int choix;
	printf("\n[1] Rechercher par CIN\n[2] Rechercher Par NOM \n");
    printf("entrer votre choix : ");scanf("%d",&choix);
    switch (choix){
    	case 1:system("cls");{int a=0; professeur E ;char cin[20]; printf("\nentrer le cin du professeur a rechercher : ");scanf("%s",cin);
    	    majiscule(cin);
    		FILE *p_fichier=fopen("professeur.txt","r");
    		while(!feof(p_fichier)){
    			fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,E.matiere);
    			if(strcmp(E.cin,cin)==0){
    				printf(" les information du professeur : \n");
    				printf("Nom : %s\n",E.nom); 
	                printf("Prenom : %s\n",E.prenom);
	                printf("CIN : %s\n",E.cin);
	                printf("Date de naissance : %s\n",E.date_naissance);
	                printf("password : %s\n",E.password);
	                printf("num matiere : %d",E.matiere);
	                a++;break;
    			}
    		
    		}
    		fclose(p_fichier);
    			if(a==0) printf("Ce professeur n'existe pas ! \n");
    	} break;
    	case 2:system("cls");{ int a=0;professeur E ;char nom[20]; printf("\nentrer le nom de l'etudiant a rechercher : ");scanf("%s",nom);
    	  majiscule(nom);
    		FILE *p_fichier=fopen("professeur.txt","r");
    		while(!feof(p_fichier)){
    			fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password);
    			if(strcmp(E.nom,nom)==0){
    				printf(" les information du professeur : \n");
    				printf("Nom : %s\n",E.nom); 
	                printf("Prenom : %s\n",E.prenom);
	                printf("CIN : %s\n",E.cin);
	                printf("Date de naissance : %s\n",E.date_naissance);
	                printf("password : %s\n",E.password);
	                a++;break;
    			}
    			
    		}
    		fclose(p_fichier);
    		if(a==0) printf("Ce professeur n'existe pas ! \n");
    	} break;
    }
	
}
void gestion_professeur(){
int choix;
printf("---------------MENU GESTION PROFSSEUR-----------------\n");
printf("[1] Ajouter un Professeur\n");
printf("[2] Modifier un Professeur\n");
printf("[3] Supprimer un Professeur\n");
printf("[4] Rechercher un Professeur\n");
printf("[5] Menu Principal \n");

do {
	printf("\n\n          Tapez votre choix : ");scanf("%d",&choix); 
}while(choix<1&&choix>5);

switch (choix) {
	case 1 :system("cls"); ajouter_professeur();printf("\nProfesseur ajoute \n") ;break;
	case 2 :system("cls"); modifier_professeur();break;
	case 3 :system("cls"); supprimer_professeur();break;
   	case 4 :system("cls"); rechercher_professeur();break;
    case 5 :system("cls"); menu_administrateur();break;
}

if(choix!=5) gestion_professeur();


}

void menu_administrateur(){
int choix;
printf("---------------MENU ADMINISTRATEUR-----------------\n");
printf("[1] Gestion des Etudiants\n");
printf("[2] Gestion des Professeurs\n");
//printf("[3] Changer le mot de passe \n");
printf("[3] Deconnecter\n");
   do{
   
	printf("          entrer votre choix : ");scanf("%d",&choix); 	
	}while(choix<1 && choix>3);
	switch (choix){
		case 1:system("cls");gestion_etudiant();break;
		case 2:system("cls");gestion_professeur();break;
		//case 3:system("cls");break; 
		case 3:system("cls");menu_principal();break;
			
	}

}
void menu_principal(){
	printf("--------------- PLATFORME NUMERIQUE DES SERVICES   ---------------\n---------------    PEDAGOGIQUES ET ADMINISTRATIFS    ---------------\n\n                ECOLE SUPERIEUR DE TECHNOLOGIE MEKNES ");
	printf("\n\n");
	int choix;
	printf("     Tu es un :\n\n     1-ETUDIANT\n\n     2-PROFESSEUR\n\n     3-ADMINISTRATEUR\n\n");
	do{

	printf("          entrer votre choix : ");scanf("%d",&choix); 	
	}while(choix<1&&choix>3);
	int teste;
	switch (choix) {
		case 1:system("cls"); { 
		char cne[20];etudiant E;int temp=-1;
			
			
			printf("\n---------------------------------------------\n");
			do{
			FILE *p_fichier=fopen("etudiant.txt","r");
			printf("CNE : ");scanf("%s",cne);
			while(!feof(p_fichier)){
				fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
				if(strcmp(cne,E.cne)==0) {
					temp++;break;
				} 
	
	              } 
				   if(temp==-1) printf("\nCne n'existe pas ressayez !!\n"); 
				   fclose(p_fichier);
	          } while(temp==-1);
	
	
	
		printf("\n---------------------------------------------\n");
		 teste=password(E.password);
		 while(teste!=0){        
		                  	printf("\nmot de passe incorrect ressayez !!\n");
		               	 teste=password(E.password);
		            
		             printf("\n");
		
	        }
	system("cls"); menu_etudiant(E.cne);
		}break;
		case 2:system("cls"); {
		 char cin[20];professeur E;int temp=-1;
			
			
			printf("\n---------------------------------------------\n");
			do{
			FILE *p_fichier=fopen("professeur.txt","r");
			printf("CIN : ");scanf("%s",cin);
			while(!feof(p_fichier)){
				fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,&E.matiere);
				if(strcmp(cin,E.cin)==0) {
					temp++; break;
				} 
	
	              } 
				   if(temp==-1) printf("\nCIN n'existe pas ressayez !!\n"); 
				   fclose(p_fichier);
	  }while(temp==-1);
	
	
	
		printf("\n---------------------------------------------\n");
	 teste=password(E.password);
		 while(teste!=0){
		                  	printf("\nmot de passe incorrect ressayez !!\n");
		               	 teste=password(E.password);
		            
		             printf("\n");
		
	}
	system("cls"); menu_professeur(E.cin);	}break;
		
		case 3: system("cls");
			
		                    char code[]="estm18";
		                    teste=password(code);       
		                   while(teste!=0){
		                   	
		                  	printf("\nmot de passe incorrect ressayez !!\n");
		               	 	teste=password(code);
		               	 	
		            }
		         
		           
		  system("cls");menu_administrateur(); 
			
	   
	               break;
	}
}
void semestre1(char cne[],char nom[],char prenom[]){ 
   libellematiere m;
	char testcne[15];
	FILE *p_anglais=fopen("anglais.txt","r");
	while(!feof(p_anglais)){
		fscanf(p_anglais,"%s\n%s\n",testcne,m.anglais);
		if(strcmp(cne,testcne)==0) {break;
		}
	} fclose(p_anglais);

	
	
	printf("*****************************************************************************\n");	
	printf("Nom : %s   Prenom : %s CNE : %s\n",nom,prenom,cne);
	printf("*****************************************************************************\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("\nMatiere                           Moyenne\n");
	printf("Anglais");printf("                             %s",m.anglais);
	
	
	
}
void semestre2(char cne[],char nom[],char prenom[]){ 
   libellematiere m;
	char testcne[15];
	FILE *p_langagec2=fopen("langageC.txt","r");
	while(!feof(p_langagec2)){
		fscanf(p_langagec2,"%s\n%s\n",testcne,m.langage_C2);
		if(strcmp(cne,testcne)==0)  break;
		
	} fclose(p_langagec2);
	
	
	
	printf("*****************************************************************************\n");	
	printf("Nom : %s   Prenom : %s CNE : %s\n",nom,prenom,cne);
	printf("*****************************************************************************\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("\nMatiere                           Moyenne\n");
	printf("Langage C avance");printf("                             %s",m.langage_C2);


	
}
void menu_etudiant(char cne[]){ int choix;
	printf("[1] afficher les notes\n[2] Deconnecter\n\n");
	printf("                entrer votre choix : ");scanf("%d",&choix);
	switch(choix){
		
		case 1 : {
		FILE *p_fichier=fopen("etudiant.txt","r");
        etudiant E;int sem;
       while(!feof(p_fichier)){
         fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
          if(strcmp(E.cne,cne)==0) {
	
           sem=E.semestre;break ;}
         }
               fclose(p_fichier);
switch (sem){
	case 1:system("cls");semestre1(cne,E.nom,E.prenom);break;
	case 2:system("cls");semestre2(cne,E.nom,E.prenom);break;
	case 3:break;
	case 4:break;
}
printf("\n\n");
menu_etudiant(cne);	

		}break;
		
		
		
		
		case 2:system("cls");menu_principal();break;
	}


}

void noter(int matiere)  { 
	libellematiere m;
	switch (matiere) {

		case 1: {
			 
		
		FILE *p_fichier=fopen("etudiant.txt","r");
	FILE *p_anglais=fopen("anglais.txt","w");
	while(!feof(p_fichier)){
		etudiant E;
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
		if(E.semestre==1) {
		printf("*****************************************************************************\n");	
		printf("Nom : %s   Prenom : %s CNE : %s\nNote : ",E.nom,E.prenom,E.cne);
		scanf("%s",m.anglais);
		printf("*****************************************************************************\n");
		fprintf(p_anglais,"%s\n%s\n",E.cne,m.anglais);
		}
	} fclose(p_fichier); fclose(p_anglais);  break;}
	
	
	case 2: {
			
		
		FILE *p_fichier=fopen("etudiant.txt","r");
	FILE *p_francais=fopen("francais.txt","w");
	while(!feof(p_fichier)){
		etudiant E;
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
		if(E.semestre==1) {
		printf("*****************************************************************************\n");	
		printf("Nom : %s   Prenom : %s CNE : %s\nNote : ",E.nom,E.prenom,E.cne);
		scanf("%s",m.francais);
		printf("*****************************************************************************\n");
		fprintf(p_francais,"%s\n%s\n",E.cne,m.francais);
		}
	} fclose(p_fichier); fclose(p_francais);  break;}
	
	   
	
	case 7: {
		
	
	FILE *p_fichier=fopen("etudiant.txt","r");
	FILE *p_langagec2=fopen("languagec2.txt","w");
	while(!feof(p_fichier)){
		etudiant E;
		fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.cne,E.date_naissance,E.password,&E.semestre);
		if(E.semestre==2) {
		printf("*****************************************************************************\n");	
		printf("Nom : %s   Prenom : %s CNE : %s\nNote : ",E.nom,E.prenom,E.cne);
		scanf("%s",m.langage_C2);
		printf("*****************************************************************************\n");
		fprintf(p_langagec2,"%s\n%s\n",E.cne,m.langage_C2);
		}
	}      fclose(p_fichier); fclose(p_langagec2);  
	
	break;}
	
	


}

}

void menu_professeur(char cin[]){  
  int choix;
  printf("---------------MENU PROFESSEUR-----------------\n\n");
  printf("[1] entrer les notes\n[2] Deconnecter        \nentrer votre choix : ");scanf("%d",&choix);
  switch (choix){
  	case 1: {
  		int temp=0;
	FILE *p_fichier=fopen("professeur.txt","r");
	professeur E;
	while(!feof(p_fichier)){  
	fscanf(p_fichier,"%s\n%s\n%s\n%s\n%s\n%d\n",E.nom,E.prenom,E.cin,E.date_naissance,E.password,&E.matiere);
	
	if(strcmp(E.cin,cin)==0) {  temp=1; break;
	}
	
	} fclose(p_fichier);
	
	system("cls");
	noter(E.matiere);
	menu_professeur(cin);
                                   	}break;
  	
  	
  	
  	case 2:system("cls");menu_principal();break;
  }
   
}

