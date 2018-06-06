/******************************************************************************* 
Autor: Leandro Pereira Sampaio 
Componente Curricular: Algoritmos I 
Concluido em: 09/06/2014 
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum 
trecho de código de outro colega ou de outro autor, tais como provindos de livros e 
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código 
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte 
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação. 
******************************************************************************************/

//Declaração das bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaração de todas os protótipos das funções existentes no programa.
int numvalidos(int numero); //A função chamada de (numvalidos), tem como parâmetro uma variavel inteira, chamada (numero).
void maiorcoluna(int n, int somacoluna[6]); //A função chamada de (maiorcoluna), é do tipo void, pois retornará apenas um vetor(somacoluna),
//e o mesmo é considerado um ponteiro. Essa função recebe uma variável do tipo inteira, e um vetor (somacoluna[6], também inteiro.
void maiorlinha(int n, int somalinha[6]); //A função chamada de (maiorlinha), é do tipo void, pois retornará apenas um vetor(somalinha), 
//e o mesmo é considerado um ponteiro. Essa função recebe uma variável do tipo inteira, e um vetor (somalinha[6], também inteiro.
int numdiferentes(int numero, int matriz[7][7], int linha, int coluna, int dificuldade, int modo, int j); //A função chamada de (numdiferentes), recebe variáveis
//inteiras e uma matriz, também inteira.
void zerarmatriz(int matriz[7][7], int dificuldade); //A função chamada de (zerarmatriz), recebe uma matriz do tipo inteira e uma variável também inteira.
int jogadoraleatorio(int numero, int j); //A função chamada de (jogadoraleatorio), recebe duas variáveis do tipo inteira.

int main() //Função principal.
{
srand(time(NULL)); // Trecho do programa que faz parte do gerador de números aletórios, e possui como semente o horário atual.
int j=0, i=0 , matriz[7] [7], somalinha[6]= {0,0,0,0,0,0}, somacoluna[6]={0,0,0,0,0,0}, jogador, numero, linha, coluna, dificuldade, a, b, modo=0, cont;
//Nessa parte do software, serão declaradas as variáveis da função (main).	
	
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
	
switch(dificuldade) //Após o usuário escolher a dificuldade do jogo, ele irá rodar as atividades escolhidas, para o tal número digitado.
{
	case 1: a=2; b=3; 
	printf("\n             ** VOCE ACABA DE ESCOLHER A TABELA FACIL( 2x2 ) **\n\n");  //Caso o usuário digite (1)=fácil, ele escolherá o tabuleiro (2x2).
	printf("________________________________________________________________________________\n"); break; 
	
	case 2: a=4; b=5; 
	printf("\n             ** VOCE ACABA DE ESCOLHER A TABELA MEDIA( 4x4 ) **\n\n"); 
	printf("________________________________________________________________________________\n"); break; //Caso o usuário digite (2)=médio, ele escolherá o tabuleiro (4x4).
	
	case 3: a=6; b=7; 
	printf("\n             ** VOCE ACABA DE ESCOLHER A TABELA DIFICIL( 6x6 ) **\n\n"); 
	printf("________________________________________________________________________________\n"); break; //Caso o usuário digite (1)=dificil, ele escolherá o tabuleiro (6x6).
//A variável (a), significa a quantidade de linhas ou colunas escolhidas pelo usuário, quando digitado a dificuldade do jogo.
//A variável (b), é a quantidade de linhas ou colunas, somados ao número (1), pois o programa começará a contar apartir do (1), não possuindo assim, 
//a linha nem coluna na posição (0). Facilitando assim, a jogabilidade.
}

zerarmatriz(matriz, dificuldade); //Chamada da função que irá zerar todas as posições da matriz: matriz[7] [7].

	for(i=0; i<a; i++) //Esse trecho apenas, tomará como base a quantidade de linhas, para rodar a quantidade de vezes necessárias para completar todas as posições da matriz.
	{
		for(j=0; j<a; j++) //Esse trecho apenas, tomará como base a quantidade de colunas, para rodar a quantidade de vezes necessárias para completar todas as posicoes da matriz.
		{
			if(j%2==0) //Nessa parte, será escolhido a vez do jogador, se o resto da divisão der 0, será a vez do primeiro jogador, ou seja, será intercalado o jogador 1 com o jogador 2.
			jogador=1; 
			else jogador=2;
			
			for(cont=1; cont<2; cont++) //Esse for comanda, para ver se existe a linha e coluna escolhida pelo jogador.
			{
				if(modo==2) //Se o modo escolhido for aleatório(2), será escrito na tela a seguinte frase.
				printf("\n\n        JOGADOR 1 = [linhas] --- JOGADOR 2 = [colunas]     \n\n");
				else //Se o modo for manual(1), aparecerá na tela as seguintes informações.
				printf("\n   **** JOGADOR 1 = SOMA DAS LINHAS --- JOGADOR 2 = SOMA DAS COLUNAS ****\n");
				printf("________________________________________________________________________________\n");
				printf("\nJOGADOR %d, digite uma LINHA que esteja no intervalo de %d - %d : ", jogador, 1, b-1);
				scanf("%d", &linha); 
				printf("________________________________________________________________________________\n");
				printf("\nJOGADOR %d, digite uma COLUNA que esteja no intervalo de %d - %d : ", jogador, 1, b-1);
				scanf("%d", &coluna);
				
				if(linha<=a & coluna<=a) cont++; //Nessa parte o programa irá controlar se a linha e coluna são válidas.
				else cont--; //Se a linha e a coluna não forem válidas ele diminuirá 1, e retornará a fazer as perguntas. 
			}
			
			if(modo==1) //Se o usuário escolher a opção manual, ele realizará as ações do bloco.
			{
				printf("________________________________________________________________________________\n");
				printf("\nDigite um numero: ");
				scanf("%d", &numero);
			}
			else { //Se o número digitado for diferente de (1), isto é, o modo seja o aleatório, ele entrará nesse bloco de ações.
			      numero = jogadoraleatorio(numero, j); //Chamada da função (jogadoraleatorio), a qual possui como argumentos as variáveis (numero) e (j).
				 }
			
			for(cont=0; cont<3; cont++) //For criado para que se usuário, coloque um número repetido e na sequência coloque um número maior que 100. 
			{	
				numero = numdiferentes(numero, matriz, linha, coluna, dificuldade, modo, j); //Chamada da função, que verifica se os números digitados são diferentes.
				numero = numvalidos(numero); //Chamada da função (numvalidos), a qual possui como argumento a variável (numero).
			}
			system("cls"); //Comando para limpar a tela.
			
			//Nesse trecho de código ele verificará se a posição desejada pelo usuário já possui um número inserido. Se no local escolhido possuir um número
			//na posição escolhida, o programa rejeitará, e irá pedir ao usuário que digite novamente uma posição válida.
			
			if(matriz[linha] [coluna] == 0) //Se a posição for válida, o número é inserido na matriz.
			matriz[linha] [coluna]=numero;
			else{
			printf("\n * Jah existe um numero nessa posicao, por gentiliza digite novamente! *\n\n");
			j--; //Diminuirá um, pois o usuário irá que digitar novamente uma posição. E o (for), terá que rodar novamente.
			}
			
			//Este bloco é indispensável pois, ele printará na tela o tabuleiro com todos os seus número inseridos e na posição adequada.
			for(linha=1; linha<b; linha++) //Esse for iniciará com 0 e quando for iniciado novamente, adicionará 1 na linha, para que todas as posições da matriz sejam lidas.
			{
				if(linha==1) { //Linha 1, para repetir, apenas 1 vez no for, e não todas as vezes que o for se repetir.
				printf("\n________________________******* TABELA %dx%d *******______________________________\n\n",a , a);
				printf("                              ____COLUNAS____ \n\n");
				}
				somalinha[linha] = 0;
					for(coluna=1; coluna<b; coluna++) //Esse for iniciará com 0 e quando for iniciado novamente, adicionará 1 na coluna, para que todas as posições da matriz sejam lidas.
					{	
						if(coluna==1)
						printf("LINHA(%d):", linha);
						printf("   %3d    ", matriz[linha] [coluna]);
						somalinha[linha] = somalinha[linha] + matriz[linha] [coluna]; //Para fazer a soma das linhas, é necessário passar por todas as colunas, para posteriormente somar os valores da próxima linha.
					}
				printf("  =  (%3d) ", somalinha[linha]);
				printf("\n\n");
			}
			
			for(coluna=1; coluna<b; coluna++) //Essa estrutura de repetição, realiza a soma das colunas de acordo, com os valores inseridos no tabuleiro.
			{
				somacoluna[coluna] = 0;
				for(linha=1; linha<b; linha++){
				somacoluna[coluna] = somacoluna[coluna] + matriz[linha] [coluna]; //Para fazer a soma das colunas, é necessário passar por todas as linhas, para posteriormente somar os valores da próxima coluna.
				}
			if(coluna==1)
			printf("SOMA: ");
			
			printf("     (%3d)", somacoluna[coluna]);
			}
		printf("\n");
		}
	}
maiorlinha(6, somalinha);
printf("\n\n       * A maior linha e ( %d )  ", somalinha[5]); //Com este trecho, aparecerá na tela a maior soma das linhas, como existem no máximo 6 linhas, 
//e a ordenação está decrescente, a maior linha estará na quinta posição do vetor. Pois, a primeira posição do vetor é 0.

maiorcoluna(6, somacoluna);
printf("----  A maior coluna e ( %d ) * \n", somacoluna[5]); //Com este trecho, aparecerá na tela a maior soma das colunas, como existem no máximo 6 colunas, 
//e a ordenação está decrescente, a maior coluna estará na quinta posição do vetor. Pois, a primeira posição do vetor é 0.

for(cont=5; cont>=0; cont--) //Esse for serve para passar por todas as somas de linhas e colunas possíveis, até que se descubra o vencedor. Se não haver vencedor, o jogo ficará no empate.
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


int numvalidos(int numero){ //Esse trecho de código consiste na implementação da função (numvalidos). A função possui como parâmetro a variável (numero).

int validar;
	for(validar=1; validar<2; validar++) //Estrutura de repetição (for), utilizada para verificar se os números digitados pelo usuário estão no intervalo de 1 à 100.
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


void maiorcoluna(int n, int somacoluna[6]) //Esse trecho de código consiste na implementação da função (maiorcoluna). Essa função possui como parâmetros um vetor (somacoluna[6]) e o tamanho do vetor (n).
{
int i, j, aux;
	for (i = 0; i < n-1; i++) //Ordenação de vetores, em ordem decrescente. Compara o elemento da posição i com os elementos das posições de i + 1 até n-1. 
//Se achar um elemento menor troca-o com o elemento da posição i.
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


void maiorlinha(int n, int somalinha[6]) //Esse trecho de código consiste na implementação da função (maiorlinha). Essa função possui como parâmetros um vetor (somalinha) e o tamanho do vetor (n).
{
int i, j, aux;
		for (i = 0; i < n-1; i++)//Ordenação do vetor (somalinha[6]), em ordem decrescente. Compara o elemento da posição i com os elementos das posições de i + 1 até n-1. 
//Se achar um elemento menor troca-o com o elemento da posição i.
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


int numdiferentes(int numero, int matriz[7][7], int linha, int coluna, int dificuldade, int modo, int j) //Esse trecho de código consiste na implementação da 
//função (numdiferentes). Essa função possui como parâmetros as variáveis: numero, dificuldade, modo, j, coluna, linha e a matriz[7] [7].
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
	for(linha=1; linha<b; linha++) //Com esses for utilizados, a matriz será totalmente pecorrida e se existir uma número igual, o usuário terá que digitar 
//outro número, até que o número seja diferentes de todos os inseridos anteriormente.
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
			 		//Caso o gerador de números aleatórios gere algum número igual, o gerador sortiará outro número até que o mesmo, seja diferente de todos números do tabuleiro.
					numero=(rand()%100)+1;
					validar--;
				}
		}
	}
return numero; //A função retornará o valor proviniente da variável (numero).
}


void zerarmatriz(int matriz[7][7], int dificuldade) //Esse trecho de código consiste na implementação da função (zerarmatriz). Essa função possui como parâmetros
//uma variável (dificuldade) e uma matriz: matriz[7] [7].
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
		matriz[linha][coluna]=0; //Serão zeradas todas as casas da matriz, de acordo com o tamanho do tabuleiro escolhido pelo usuário.
	}
}


int jogadoraleatorio(int numero, int j) //Esse trecho de código consiste na implementação da função (jogadoraleatorio). Essa função possui como parâmetros
//duas variáveis do tipo inteira: (numero) e (j).
{ 
	numero=(rand()%100)+1; 
return numero;	
}

