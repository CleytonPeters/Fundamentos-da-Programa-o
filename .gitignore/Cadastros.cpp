#include  <stdio.h>
#include  <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void chamaswitch ();
void finalizar ();
void menu ();
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int MENU=0;

//  variavel  global 
typedef struct ficha_de_aluno
  { 
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
	float media;
  } ficha_de_aluno;
  
  int count = 0;	
  int valor = 1;
  int z;
  int arrayAUX[100];
  //int cadastrados = 0;
  ficha_de_aluno aluno;
  ficha_de_aluno turma[100];
  int posicao_que_encontrou_na_turma_o_aluno;
//------------caixa-----------------//  
  char sidetop_left    = 218;
  char sidetop_right   = 191;
  char center          = 196;
  char side            = 179;
  char sidebase_left   = 192;
  char sidebase_right  = 217;
  char acentoc         = 128;
  char cedilhaminu     = 135;
  char acentoA         = 198;
//-------------caixa----------------//  
int main (void)
{   
  for (int zerar = 0; zerar <= 100; zerar++) {
  	turma[zerar].matricula = 0;
  }  
  menu ();
  return 0;
}
void menu () {	
	while(MENU!=5){
		int centro=40, contador=0;
		system("cls");
 		printf("%c", sidetop_left);
 		while(contador<centro){
			printf("%c",center);
			contador++;
		}
		printf("%c\n", sidetop_right);
		printf("%c          ALUNOS CADASTRADOS: %d         %c\n", side, count,side);
		printf("%c                                        %c\n", side,side);
		printf("%c                                        %c\n", side,side);
		printf("%c            1. INCLUIR ALUNO            %c\n", side,side);
		printf("%c            2. EXCLUIR ALUNO            %c\n", side,side);
		printf("%c            3. LISTAR ALUNOS            %c\n", side,side);
		printf("%c            4. LAN%cAR NOTA              %c\n", side,acentoc,side);
		printf("%c            5. SAIR                     %c\n", side,side);
		printf("%c                                        %c\n", side,side);
		printf("%c        Digite a op%c%co desejada: [   ]  %c\n", side,cedilhaminu,acentoA,side);		
		printf("%c                                        %c\n", side,side);
		centro=40, contador=0;
		printf("%c", sidebase_left);
 		while(contador<centro){
			printf("%c",center);
			contador++;
		}
		printf("%c\n", sidebase_right);
		gotoxy(35,10);
		scanf("%d", &valor);
		fflush(stdin);
		system("cls");
		chamaswitch ();
	}	
}
void incluir() {
	int nexiste = 0;
	int numerodigitado = 1;
  	int incluircancelar, excluircancelar;
	while( numerodigitado == 1) {
		do {
	    	nexiste = 0; 
	    	int espcentro=40, contador=0;
			system("cls");
 			printf("%c", sidetop_left);
 			while(contador<espcentro){
				printf("%c",center);
				contador++;
			}
			printf("%c\n", sidetop_right);
	    	printf("%c I N C L U I R   A L U N O : %d Cadastros%c\n", side, count, side);
  			espcentro=40, contador=0;
			printf("%c", sidebase_left);
 			while(contador<espcentro){
				printf("%c",center);
				contador++;
			}
			printf("%c\n", sidebase_right);	  
	  		//----------------------------------------------------- 
	    	printf(" Digite Matricula: ");
  	    	scanf("%i", &aluno.matricula);
  	    	fflush(stdin);
  	  		for (int c = 0; c <= 100; c++){ //TESTE PARA VER SE EXISTE
  	 	    	if (aluno.matricula == turma[c].matricula){
  		        	system ("cls");
  		   	    	printf ("\nATENCAO, MATRICULA '%d' JA EXISTE, DIGITE OUTRA\n", aluno.matricula);
  		        	system ("pause");
  		        	posicao_que_encontrou_na_turma_o_aluno = c;
  		        	c = 100;
  		        	nexiste++;  			
  		    	}		
  	    	}
  	    }while (nexiste != 0);
	    printf(" Nome do Aluno: ");
   	    fgets(aluno.nome, 50, stdin);
   	    fflush(stdin);
   	    
        printf(" Informe a 1a. nota: ");
        scanf("%f", &aluno.nota1);
   	    fflush(stdin);
   	  
	    printf(" Informe a 2a. nota: ");
  	    scanf("%f", &aluno.nota2);
  	    fflush(stdin);

	    aluno.media = (aluno.nota1 + aluno.nota2)/2;
  	    printf(" Media das Notas: %.2f\n" , aluno.media);
  	    printf("__________________________________________\n");
	  
	    printf(" INCLUIR (1) CANCELAR (2): ");
  	    scanf ("%d", &incluircancelar);
  	    fflush(stdin);
  	    system ("cls");
      	if(incluircancelar == 1){
  		    turma[aluno.matricula].matricula = aluno.matricula;
  		    turma[aluno.matricula].nota1 = aluno.nota1;
  	        turma[aluno.matricula].nota2 = aluno.nota2;
  		    turma[aluno.matricula].media =  aluno.media;
  		    strncpy(turma[aluno.matricula].nome, aluno.nome, 50); 
  		    count++;
  				
  		    printf(" DESEJA INCLUIR MAIS ALUNOS?\n(1) SIM (2) NAO: ");
  		    scanf("%d",&numerodigitado);
  		    fflush(stdin);  			
  		}else { 
			menu ();
  		}
  		system ("cls");  				
	} while( numerodigitado == 1);	
} 

void finalizar (){
	int espcentro=40, contador=0;
	system("cls");
 	printf("%c", sidetop_left);
 	while(contador<espcentro){
		printf("%c",center);
		contador++;
		}
	printf("%c\n", sidetop_right);
	printf("%c            F I N A L I Z A D O         %c\n", side,side);
  	espcentro=40, contador=0;
	printf("%c", sidebase_left);
 	while(contador<espcentro){
		printf("%c",center);
		contador++;
	}
	printf("%c\n", sidebase_right);  					
}

void chamaswitch (){     
   int incluircancelar, excluircancelar,numerodigitado;
   switch(valor){   	  
//---------------------------------------INCLUI ALUNO ------------------------------------//	
	case 1 :
		incluir();
	break; 
//---------------------------------------EXCLUI ALUNO -------------------------------------//	 
    case 2 :
    	if (count == 0) {
     	    printf("\n   ATENCAO, NAO HA ALUNOS CADASTRADOS\n");
        	system ("pause");
        } else {
     		do {     	 
			for (int nexiste = 0; nexiste == 0;){
       			system ("cls");
				int espcentro=40, contador=0;
				system("cls");
 				printf("%c", sidetop_left);
 					while(contador<espcentro){
						printf("%c",center);
						contador++;
					}
				printf("%c\n", sidetop_right);
	    		printf("%c E X C L U I R   A L U N O : %d Cadastros%c\n", side, count, side);
  				espcentro=40, contador=0;
				printf("%c", sidebase_left);
 					while(contador<espcentro){
						printf("%c",center);
						contador++;
					}
			printf("%c\n", sidebase_right);	  
	 		printf(" Digite Matricula: ");
  			scanf("%i", &aluno.matricula);
  				for (int c = 0; c <= 100; c++){ //TESTE PARA VER SE EXISTE
  					if (aluno.matricula == turma[c].matricula){
  						posicao_que_encontrou_na_turma_o_aluno = c;
  						c = 100;
  						nexiste = 1;
  					}//IF			  
  		    	}//FOR	scanf	  			
	   	    }//FOR
  			printf(" Nome do Aluno: %s\n", turma[posicao_que_encontrou_na_turma_o_aluno].nome);
  			printf (" Deseja realmente Excluir: %s? (1) SIM (2) NAO: ", turma[posicao_que_encontrou_na_turma_o_aluno].nome);
   			scanf ("%d", &excluircancelar);
   				if (excluircancelar == 1) {
   					turma[posicao_que_encontrou_na_turma_o_aluno].matricula = 0;
   					count--;
   					printf("\n DESEJA EXCLUIR MAIS ALUNOS? (1) SIM (2) NAO: ");
  					scanf("%d",&numerodigitado);  							
				}else {				
					system ("cls");
  					menu ();
			    }
				system ("cls");   			   
			}while( numerodigitado == 1);}
	break;	 
//---------------------------------------LISTA ALUNO ---------------------------------------//      
    case 3 :
     	int aux;
        z = 0;
        for (int cont3 = 0; cont3 <= 100; cont3++) {
			if (cont3 == turma[cont3].matricula && cont3 != 0) {
  			z++;
  			arrayAUX[z] = cont3;
			}
  		}
  		if (count > 1){
  			for (int a = 1; a <= count;a++){
  				for (int b = 1; b < count; b++){
  					if (turma[arrayAUX[b]].media > turma[arrayAUX[b+1]].media){
  					aux = arrayAUX[b];
  					arrayAUX[b] = arrayAUX[b+1];
  					arrayAUX[b+1] = aux;
  	       			}
				}
  			}
  		}
     	if (count == 0) {     	
        	printf("\n   ATENCAO, NAO HA ALUNOS CADASTRADOS\n");
        	system ("pause");
        }else {
			printf("__________________________________________\n\n");
  			printf("          L I S T A R   A L U N O         \n"  );  		  		 		
  			for (z = 1; z <= count;z++) {
  				printf ("__________________________________________\n\n"  );
  				printf ("\t\tMatricula: %d\n",  turma[arrayAUX[z]].matricula);
  				printf ("\t\tNome: %s\n",                  turma[arrayAUX[z]].nome );
  				printf ("\t\tNota 1: %f\n",             turma[arrayAUX[z]].nota1);
  				printf ("\t\tNota 2: %f\n",             turma[arrayAUX[z]].nota2);
  				printf ("\t\tMedia : %f\n",            turma[arrayAUX[z]].media); 
  				system ("pause");
  		   }
		   system ("cls");
   		}
    break;
//------------------------------------LANÇAR NOTA------------------------------------------//
    case 4 :
        system ("cls");
     	printf("__________________________________________\n\n");
  		printf("          L A N Ç A R   N O T A         \n"    );
  		printf("__________________________________________\n"  );  		  						
    break;
//---------------------------------------FINALIZA------------------------------------------//
    case 5 :
     	finalizar ();
       	MENU = 5;
    break;
//__________________________________________________________________________________________// 
		 
   }  // switch
   return;
}
