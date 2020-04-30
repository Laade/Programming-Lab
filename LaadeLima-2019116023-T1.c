
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de An�lise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laborat�rio de Programa��o
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orienta��es gerais -----
//  Descri��o: esse arquivo deve conter as quest�es do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as quest�es do trabalho

//  ----- Dados do Aluno -----
//  Nome: Laade da Costa Lima Modesto
//  email: laade09@gmail.com
//  Matr�cula: 2019116023
//  Semestre: 2�

//  Copyright � 2016 Renato Novais. All rights reserved.
// �ltima atualiza��o: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/*
## fun��o utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y){
  int soma = 0;
  soma = x + y;
  return soma;
}

/*
## fun��o utilizada para testes  ##
 fatorial = fatorial de um n�mero
@objetivo
    calcular o fatorial de um n�mero
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //fun��o utilizada para testes
  int fat = 1;
  return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = m�s, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inv�lida
    1 -> se data v�lida
 */

int q1(char *data){

    char dia[3], mes[3], ano[5];
    int idia, imes, iano, i, j;
    int datavalida = 1;

    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);

    //QUEBRA DE STRING DATA
	for(i=0; data[i] != '/'; i++)
		dia[i] = data[i];
	for(i=i+1, j=0; data[i] != '/'; i++, j++)
		mes[j] = data[i];
	for(i=i+1, j=0; data[i] != '\0'; i++, j++)
		ano[j] = data[i];

	//Converte CHAR PARA INTEIRO
		idia= atoi(dia);
		imes= atoi(mes);
		iano= atoi(ano);

   if(iano>0000  && iano<=9999)   {
        if(imes>0 && imes<13)
            switch(imes){
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                if(idia<1||idia>31 && imes==1 || imes==3 || imes==5 || imes==7 || imes==8 || imes==0 || imes==12)
                    datavalida = 0;
                break;
                case 4:
                case 6:
                case 9:
                case 11:
                if(idia<1||idia>30 && imes == 4 || imes == 6 || imes == 9 || imes == 11)
                    datavalida = 0;
                break;

                case 2:
                if(!(iano % 400)||(!(iano % 4)&&(iano % 100))){
                    if(idia<1 || idia>29)
                        datavalida=0;
                } else
                if(idia<1 || idia>28)
                    datavalida=0;
                break;
        }
        else datavalida = 0;
    }//else datavalida = 0;
    if (datavalida)
        return 1;
    else
        return 0;
}

/*
 Q2 = diferen�a entre duas datas
 @objetivo
    Calcular a diferen�a em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Al�m disso, a fun��o tem tr�s par�metros qtdDias, qtdMeses e qtdAnos. Esses tr�s par�metros devem ser utilizados para guardar os resultados dos c�lculos. Na chamada da fun��o deve passar o valor -1 para os tr�s
 @saida
    1 -> c�lculo de diferen�a realizado com sucesso
    2 -> datainicial inv�lida
    3 -> datafinal inv�lida
    4 -> datainicial > datafinal
 */

int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    int nDias, nMeses, nAnos;
    int diainicial,mesinicial,anoinicial;
    int diafinal,mesfinal,anofinal;
    char sDia[3], sMes[3], sAno[5];
    int i, j, contM = 0, contA = 0;
    int retorno = 1;

    if(q1(datainicial)==0)
        retorno=2;
    if(q1(datafinal)==0)
        retorno=3;

    	sscanf(datainicial, "%d/%d/%d", &diainicial, &mesinicial, &anoinicial);
    	sscanf(datafinal, "%d/%d/%d", &diafinal, &mesfinal, &anofinal);

    	// Capturando Valores da Data Inicial

    for (i = 0; datainicial[i] != '/'; i++)
        sDia[i] = datainicial[i];

    sDia[i] = '\0';
    i++;

    for (j = i, contM = 0; datainicial[j] != '/'; j++, contM++)
        sMes[contM] = datainicial[j];

    sMes[j] = '\0';
    j++;

    for (i = j, contA = 0; i < strlen(datainicial); i++, contA++)
       sAno[contA] = datainicial[i];

    sAno[contA] = '\0';

   // Convertendo String em Inteiro
    diainicial = atoi(sDia);
    mesinicial = atoi(sMes);
    anoinicial = atoi(sAno);

    // Capturando Valores da Data Final

    for (i = 0; datafinal[i] != '/'; i++)
        sDia[i] = datafinal[i];

    sDia[i] = '\0';
    i++;
    for (j = i, contM = 0; datafinal[j] != '/'; j++, contM++)
        sMes[contM] = datafinal[j];

    sMes[j] = '\0';
    j++;

    for (i = j, contA = 0; i < strlen(datafinal); i++, contA++)
       sAno[contA] = datafinal[i];

    sAno[contA] = '\0';

    // Convertendo String em Inteiro
    diafinal = atoi(sDia);
    mesfinal = atoi(sMes);
    anofinal = atoi(sAno);

    nDias = diafinal - diainicial;
    nMeses = mesfinal - mesinicial;
    nAnos = anofinal - anoinicial;

        if (nAnos<0) retorno=4;
        else if (nMeses<0 && nAnos<1) retorno=4;
        else if (nDias<0 && nMeses<1 && nAnos<1) retorno=4;
        if(nDias<0){
            nDias+=30;
            nMeses--;

        }
        if(nMeses<0) {
            nMeses+=12;
            nAnos--;

			 return 0;
        }
     /*mantenha o c�digo abaixo, para salvar os dados em
    nos par�metros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se � uma pesquisa Case Sensitive ou n�o. Se isCaseSensitive = 1, a pesquisa deve considerar diferen�as entre mai�sculos e min�sculos.
        Se isCaseSensitive != 1, a pesquisa n�o deve  considerar diferen�as entre mai�sculos e min�sculos.
 @saida
    Um n�mero n >= 0.
 */

int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;
    int i;

    for(i=0; texto[i]!='\0'; i++){
        if(isCaseSensitive==1){
            if(texto[i]== c)
                qtdOcorrencias++;
        }else if(isCaseSensitive!=1){
            if(texto[i]== c || texto[i]== c+32 || texto[i]==c-32)
                qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorr�ncias de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que ir� guardar as posi��es de in�cio e fim de cada ocorr�ncia da palavra (strBusca) no texto base (texto).
 @saida
    Um n�mero n >= 0 correspondente a quantidade de ocorr�ncias encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e sa�da correspondente. Por exemplo, se tiver uma �nica ocorr�ncia, a posi��o 0 do vetor deve ser preenchido com o �ndice de in�cio do texto, e na posi��o 1, deve ser preenchido com o �ndice de fim da ocorrencias. Se tiver duas ocorr�ncias, a segunda ocorr�ncia ser� amazenado nas posi��es 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como h� uma ocorr�ncia da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o �ndice da posi��o no texto deve come�ar ser contado a partir de 1.
        O retorno da fun��o, n, nesse caso seria 1;
 */

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;
    int i, j, p=0;

    for(i=0; strTexto[i]!='\0'; i++){
        int j=0, ini;
        if(strTexto[i] == strBusca[j])
        ini = i+1;
        while(strTexto[i+1] == strBusca[j+1] && strBusca[j+1]!='\0'){
        i++;
        j++;
}
if(strBusca[j+1]=='\0'){
posicoes[p] = ini;
p++;
posicoes[p] = i+1;
p++;
qtdOcorrencias++;
}
    }

    return qtdOcorrencias;
}


/*
 Q5 = inverte n�mero
 @objetivo
    Inverter n�mero inteiro
 @entrada
    uma int num.
 @saida
    N�mero invertido
 */

int q5(int num){

    int num_invertido=num%10;
    num/=10;

    while(num>0){
        num_invertido*=10;
        num_invertido+=num%10;
        num/=10;
    }
    return num_invertido;
}


/*
 Q6 = ocorr�ncia de um n�mero em outro
 @objetivo
    Verificar quantidade de vezes da ocorr�ncia de um n�mero em outro
 @entrada
    Um n�mero base (numerobase) e um n�mero de busca (numerobusca).
 @saida
    Quantidade de vezes que n�mero de busca ocorre em n�mero base
 */


int q6(int numerobase, int numerobusca){
    int qtdOcorrencias, qtd, aux;

for(aux=numerobusca, qtd = 0;aux>0; aux/=10)
qtd++;

    qtd = pow(10,qtd);

    while (numerobase>0){
aux=numerobase%qtd;
numerobase=numerobase/10;
if (numerobusca==aux)
qtdOcorrencias++;
    }

    return qtdOcorrencias;
}
