/******************************************************************************* 
Autor: Leandro Pereira Sampaio 
Componente Curricular: Algoritmos I 
Concluido em: 09/06/2014 
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum 
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e 
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo 
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte 
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o. 
******************************************************************************************/

//Declara��o das bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declara��o de todas os prot�tipos das fun��es existentes no programa.
int numvalidos(int numero); //A fun��o chamada de (numvalidos), tem como par�metro uma variavel inteira, chamada (numero).
void maiorcoluna(int n, int somacoluna[6]); //A fun��o chamada de (maiorcoluna), � do tipo void, pois retornar� apenas um vetor(somacoluna),
//e o mesmo � considerado um ponteiro. Essa fun��o recebe uma vari�vel do tipo inteira, e um vetor (somacoluna[6], tamb�m inteiro.
void maiorlinha(int n, int somalinha[6]); //A fun��o chamada de (maiorlinha), � do tipo void, pois retornar� apenas um vetor(somalinha), 
//e o mesmo � considerado um ponteiro. Essa fun��o recebe uma vari�vel do tipo inteira, e um vetor (somalinha[6], tamb�m inteiro.
int numdiferentes(int numero, int matriz[7][7], int linha, int coluna, int dificuldade, int modo, int j); //A fun��o chamada de (numdiferentes), recebe vari�veis
//inteiras e uma matriz, tamb�m inteira.
void zerarmatriz(int matriz[7][7], int dificuldade); //A fun��o chamada de (zerarmatriz), recebe uma matriz do tipo inteira e uma vari�vel tamb�m inteira.
int jogadoraleatorio(int numero, int j); //A fun��o chamada de (jogadoraleatorio), recebe duas vari�veis do tipo inteira.

int main() //Fun��o principal.
{
srand(time(NULL)); // Trecho do programa que faz parte do gerador de n�meros alet�rios, e possui como semente o hor�rio atual.
int j=0, i=0 , matriz[7] [7], somalinha[6]= {0,0,0,0,0,0}, somacoluna[6]={0,0,0,0,0,0}, jogador, numero, linha, coluna, dificuldade, a, b, modo=0, cont;
//Nessa parte do software, ser�o declaradas as vari�veis da fun��o (main).	
	
printf("\n               ********** BEM VINDO AO JOGO DA SOMA ********** \n");
printf("________________________________________________________________________________\n");
printf("\n     A TABELA PODE SER: [Facil = 2x2] [Media = 4x4] [Dificil = 6x6]\n");
printf("________________________________________________________________________________\n");
printf("\nDIGITE O NIVEL DO JOGO: [1]Facil [2]Medio [3]Dificil: ");
scanf("%d", &dificuldade);
printf("________________________________________________________________________________\n");
printf("\nESCOLHA O MODO A SER JOGADO: [1]Manual [2]Aleatorio: ");
scanf("%d", &modo);
printf("________________________________________________________________________________\n");
system("cls");
	
switch(dificuldade) //Ap�s o usu�rio escolher a dificuldade do jogo, ele ir� rodar as atividades escolhidas, para o tal n�mero digitado.
{
	case 1: a=2; b=3; 
	printf("\n             ** VOCE ACABA DE ESCOLHER A TABELA FACIL( 2x2 ) **\n\n");  //Caso o usu�rio digite (1)=f�cil, ele escolher� o tabuleiro (2x2).
	printf("________________________________________________________________________________\n"); break; 
	
	case 2: a=4; b=5; 
	printf("\n             ** VOCE ACABA DE ESCOLHER A TABELA MEDIA( 4x4 ) **\n\n"); 
	printf("________________________________________________________________________________\n"); break; //Caso o usu�rio digite (2)=m�dio, ele escolher� o tabuleiro (4x4).
	
	case 3: a=6; b=7; 
	printf("\n             ** VOCE ACABA DE ESCOLHER A TABELA DIFICIL( 6x6 ) **\n\n"); 
	printf("________________________________________________________________________________\n"); break; //Caso o usu�rio digite (1)=dificil, ele escolher� o tabuleiro (6x6).
//A vari�vel (a), significa a quantidade de linhas ou colunas escolhidas pelo usu�rio, quando digitado a dificuldade do jogo.
//A vari�vel (b), � a quantidade de linhas ou colunas, somados ao n�mero (1), pois o programa come�ar� a contar apartir do (1), n�o possuindo assim, 
//a linha nem coluna na posi��o (0). Facilitando assim, a jogabilidade.
}

zerarmatriz(matriz, dificuldade); //Chamada da fun��o que ir� zerar todas as posi��es da matriz: matriz[7] [7].

	for(i=0; i<a; i++) //Esse trecho apenas, tomar� como base a quantidade de linhas, para rodar a quantidade de vezes necess�rias para completar todas as posi��es da matriz.
	{
		for(j=0; j<a; j++) //Esse trecho apenas, tomar� como base a quantidade de colunas, para rodar a quantidade de vezes necess�rias para completar todas as posicoes da matriz.
		{
			if(j%2==0) //Nessa parte, ser� escolhido a vez do jogador, se o resto da divis�o der 0, ser� a vez do primeiro jogador, ou seja, ser� intercalado o jogador 1 com o jogador 2.
			jogador=1; 
			else jogador=2;
			
			for(cont=1; cont<2; cont++) //Esse for comanda, para ver se existe a linha e coluna escolhida pelo jogador.
			{
				if(modo==2) //Se o modo escolhido for aleat�rio(2), ser� escrito na tela a seguinte frase.
				printf("\n\n        JOGADOR 1 = [linhas] --- JOGADOR 2 = [colunas]     \n\n");
				else //Se o modo for manual(1), aparecer� na tela as seguintes informa��es.
				printf("\n   **** JOGADOR 1 = SOMA DAS LINHAS --- JOGADOR 2 = SOMA DAS COLUNAS ****\n");
				printf("________________________________________________________________________________\n");
				printf("\nJOGADOR %d, digite uma LINHA que esteja no intervalo de %d - %d : ", jogador, 1, b-1);
				scanf("%d", &linha); 
				printf("________________________________________________________________________________\n");
				printf("\nJOGADOR %d, digite uma COLUNA que esteja no intervalo de %d - %d : ", jogador, 1, b-1);
				scanf("%d", &coluna);
				
				if(linha<=a & coluna<=a) cont++; //Nessa parte o programa ir� controlar se a linha e coluna s�o v�lidas.
				else cont--; //Se a linha e a coluna n�o forem v�lidas ele diminuir� 1, e retornar� a fazer as perguntas. 
			}
			
			if(modo==1) //Se o usu�rio escolher a op��o manual, ele realizar� as a��es do bloco.
			{
				printf("________________________________________________________________________________\n");
				printf("\nDigite um numero: ");
				scanf("%d", &numero);
			}
			else { //Se o n�mero digitado for diferente de (1), isto �, o modo seja o aleat�rio, ele entrar� nesse bloco de a��es.
			      numero = jogadoraleatorio(numero, j); //Chamada da fun��o (jogadoraleatorio), a qual possui como argumentos as vari�veis (numero) e (j).
				 }
			
			for(cont=0; cont<3; cont++) //For criado para que se usu�rio, coloque um n�mero repetido e na sequ�ncia coloque um n�mero maior que 100. 
			{	
				numero = numdiferentes(numero, matriz, linha, coluna, dificuldade, modo, j); //Chamada da fun��o, que verifica se os n�meros digitados s�o diferentes.
				numero = numvalidos(numero); //Chamada da fun��o (numvalidos), a qual possui como argumento a vari�vel (numero).
			}
			system("cls"); //Comando para limpar a tela.
			
			//Nesse trecho de c�digo ele verificar� se a posi��o desejada pelo usu�rio j� possui um n�mero inserido. Se no local escolhido possuir um n�mero
			//na posi��o escolhida, o programa rejeitar�, e ir� pedir ao usu�rio que digite novamente uma posi��o v�lida.
			
			if(matriz[linha] [coluna] == 0) //Se a posi��o for v�lida, o n�mero � inserido na matriz.
			matriz[linha] [coluna]=numero;
			else{
			printf("\n * Jah existe um numero nessa posicao, por gentiliza digite novamente! *\n\n");
			j--; //Diminuir� um, pois o usu�rio ir� que digitar novamente uma posi��o. E o (for), ter� que rodar novamente.
			}
			
			//Este bloco � indispens�vel pois, ele printar� na tela o tabuleiro com todos os seus n�mero inseridos e na posi��o adequada.
			for(linha=1; linha<b; linha++) //Esse for iniciar� com 0 e quando for iniciado novamente, adicionar� 1 na linha, para que todas as posi��es da matriz sejam lidas.
			{
				if(linha==1) { //Linha 1, para repetir, apenas 1 vez no for, e n�o todas as vezes que o for se repetir.
				printf("\n________________________******* TABELA %dx%d *******______________________________\n\n",a , a);
				printf("                              ____COLUNAS____ \n\n");
				}
				somalinha[linha] = 0;
					for(coluna=1; coluna<b; coluna++) //Esse for iniciar� com 0 e quando for iniciado novamente, adicionar� 1 na coluna, para que todas as posi��es da matriz sejam lidas.
					{	
						if(coluna==1)
						printf("LINHA(%d):", linha);
						printf("   %3d    ", matriz[linha] [coluna]);
						somalinha[linha] = somalinha[linha] + matriz[linha] [coluna]; //Para fazer a soma das linhas, � necess�rio passar por todas as colunas, para posteriormente somar os valores da pr�xima linha.
					}
				printf("  =  (%3d) ", somalinha[linha]);
				printf("\n\n");
			}
			
			for(coluna=1; coluna<b; coluna++) //Essa estrutura de repeti��o, realiza a soma das colunas de acordo, com os valores inseridos no tabuleiro.
			{
				somacoluna[coluna] = 0;
				for(linha=1; linha<b; linha++){
				somacoluna[coluna] = somacoluna[coluna] + matriz[linha] [coluna]; //Para fazer a soma das colunas, � necess�rio passar por todas as linhas, para posteriormente somar os valores da pr�xima coluna.
				}
			if(coluna==1)
			printf("SOMA: ");
			
			printf("     (%3d)", somacoluna[coluna]);
			}
		printf("\n");
		}
	}
maiorlinha(6, somalinha);
printf("\n\n       * A maior linha e ( %d )  ", somalinha[5]); //Com este trecho, aparecer� na tela a maior soma das linhas, como existem no m�ximo 6 linhas, 
//e a ordena��o est� decrescente, a maior linha estar� na quinta posi��o do vetor. Pois, a primeira posi��o do vetor � 0.

maiorcoluna(6, somacoluna);
printf("----  A maior coluna e ( %d ) * \n", somacoluna[5]); //Com este trecho, aparecer� na tela a maior soma das colunas, como existem no m�ximo 6 colunas, 
//e a ordena��o est� decrescente, a maior coluna estar� na quinta posi��o do vetor. Pois, a primeira posi��o do vetor � 0.

for(cont=5; cont>=0; cont--) //Esse for serve para passar por todas as somas de linhas e colunas poss�veis, at� que se descubra o vencedor. Se n�o haver vencedor, o jogo ficar� no empate.
{
	if(somacoluna[cont] < somalinha[cont]){
		printf("________________________________________________________________________________\n");
		printf("\n           * PARABENS, VENCEDOR JOGADOR 1! *     SOMA: ( %d )    \n", somalinha[cont]);
		cont=cont-5;
	}
	
	else if(somacoluna[cont] > somalinha[cont]){
		printf("________________________________________________________________________________\n");
		printf("\n           * PARABENS, VENCEDOR JOGADOR 2! *     SOMA: ( %d )    \n", somacoluna[cont]);
		cont=cont-5;
	}
	
	else if(somacoluna[cont] == somalinha[cont]){
		if(cont==0)
			printf(" \n              EMPATE!!!  \n");
	}
}
printf("________________________________________________________________________________\n");
printf(" \n                       * OBRIGADO, FIM DE JOGO! *            \n");
printf("________________________________________________________________________________\n");

}


int numvalidos(int numero){ //Esse trecho de c�digo consiste na implementa��o da fun��o (numvalidos). A fun��o possui como par�metro a vari�vel (numero).

int validar;
	for(validar=1; validar<2; validar++) //Estrutura de repeti��o (for), utilizada para verificar se os n�meros digitados pelo usu�rio est�o no intervalo de 1 � 100.
	{	
		if(numero>100)
		{
			printf("\n * Digite um numero entre 1-100: ");
			scanf("%d", &numero);
			validar--;
		}
		else numero=numero;	
	}
return numero;
}


void maiorcoluna(int n, int somacoluna[6]) //Esse trecho de c�digo consiste na implementa��o da fun��o (maiorcoluna). Essa fun��o possui como par�metros um vetor (somacoluna[6]) e o tamanho do vetor (n).
{
int i, j, aux;
	for (i = 0; i < n-1; i++) //Ordena��o de vetores, em ordem decrescente. Compara o elemento da posi��o i com os elementos das posi��es de i + 1 at� n-1. 
//Se achar um elemento menor troca-o com o elemento da posi��o i.
	{
		for (j = i + 1; j < n; j++)
		{
			if (somacoluna[j] < somacoluna[i])
	      	{
				aux = somacoluna[i];
				somacoluna[i] = somacoluna[j];
				somacoluna[j] = aux;
	    	}
		}
    }
}


void maiorlinha(int n, int somalinha[6]) //Esse trecho de c�digo consiste na implementa��o da fun��o (maiorlinha). Essa fun��o possui como par�metros um vetor (somalinha) e o tamanho do vetor (n).
{
int i, j, aux;
		for (i = 0; i < n-1; i++)//Ordena��o do vetor (somalinha[6]), em ordem decrescente. Compara o elemento da posi��o i com os elementos das posi��es de i + 1 at� n-1. 
//Se achar um elemento menor troca-o com o elemento da posi��o i.
	{
		for (j = i + 1; j < n; j++)
		{
			if (somalinha[j] < somalinha[i])
	      	{
				aux = somalinha[i]; 
				somalinha[i] = somalinha[j]; 
				somalinha[j] = aux;
	    	}
		}
    }
}


int numdiferentes(int numero, int matriz[7][7], int linha, int coluna, int dificuldade, int modo, int j) //Esse trecho de c�digo consiste na implementa��o da 
//fun��o (numdiferentes). Essa fun��o possui como par�metros as vari�veis: numero, dificuldade, modo, j, coluna, linha e a matriz[7] [7].
{

int validar, a, b;
	
switch(dificuldade)
{
	case 1: a=2; b=3; break;
	case 2: a=4; b=5; break;
	case 3: a=6; b=7; break;
}	

for(validar=1; validar<2; validar++)
{	
	for(linha=1; linha<b; linha++) //Com esses for utilizados, a matriz ser� totalmente pecorrida e se existir uma n�mero igual, o usu�rio ter� que digitar 
//outro n�mero, at� que o n�mero seja diferentes de todos os inseridos anteriormente.
		for(coluna=1; coluna<b; coluna++)
		{
			if(modo==1){
				if(numero==matriz[linha][coluna]) 
				{
					printf("________________________________________________________________________________\n");
					printf("\n *Digite outro numero, por favor: ");
					scanf("%d", &numero);
					validar--;
				}
			}
			else if(modo==2)
				if(numero==matriz[linha][coluna])
				{
			 		//Caso o gerador de n�meros aleat�rios gere algum n�mero igual, o gerador sortiar� outro n�mero at� que o mesmo, seja diferente de todos n�meros do tabuleiro.
					numero=(rand()%100)+1;
					validar--;
				}
		}
	}
return numero; //A fun��o retornar� o valor proviniente da vari�vel (numero).
}


void zerarmatriz(int matriz[7][7], int dificuldade) //Esse trecho de c�digo consiste na implementa��o da fun��o (zerarmatriz). Essa fun��o possui como par�metros
//uma vari�vel (dificuldade) e uma matriz: matriz[7] [7].
{
int b, linha, coluna;
	
	switch(dificuldade)
	{
	case 1: b=3; break;
	case 2: b=5; break;
	case 3: b=7; break;
	}

for(linha=1; linha<b; linha++)
	for(coluna=1; coluna<b; coluna++)
	{
		matriz[linha][coluna]=0; //Ser�o zeradas todas as casas da matriz, de acordo com o tamanho do tabuleiro escolhido pelo usu�rio.
	}
}


int jogadoraleatorio(int numero, int j) //Esse trecho de c�digo consiste na implementa��o da fun��o (jogadoraleatorio). Essa fun��o possui como par�metros
//duas vari�veis do tipo inteira: (numero) e (j).
{ 
	numero=(rand()%100)+1; 
return numero;	
}

