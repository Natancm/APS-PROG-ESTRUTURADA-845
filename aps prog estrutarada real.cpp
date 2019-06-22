// bibliotecas

#include <stdio.h>
#include <stdlib.h>

// bibliotecas

// constantes simbolicas

#define POSITIVOS 1
#define ARQUIVO "produtos.dat"

// constantes simbolicas

// variaveis globais

struct produtos{
				int codigo;
                char produto[20+1];
                float preco;
                char descricao[50+1]; 
                }estoque,*salvo;

int tamanho = 0 ; 

int primary_key = 1;

// variaveis globais

// prototipo das funcoes

void salvar();
void inicializar();
void realocar();
int cadastro();
void leitura();
void maior();
void mostrar();

// prototipo das funcoes


//tamanho inicial do meu ponteiro para estrutura

void inicializar(){
    salvo = (struct produtos *) malloc(sizeof(struct produtos));
}

//tamanho inicial do meu ponteiro para estrutura

//tamanho final do meu ponteiro para estrutura

void realocar(){
    salvo = (struct produtos *) realloc(salvo,tamanho*sizeof(struct produtos));
}

//tamanho final do meu ponteiro para estrutura

// funcao recursiva para cadastro dos produtos

int cadastro(){
    printf("codigo: ");     scanf("%d",&estoque.codigo);				getchar();

    if(tamanho == 0 && estoque.codigo < POSITIVOS){
        fprintf(stderr,"\nnada sera salvo no arquivo.\n");
        exit(0);
    }
    else{
    	
        if(estoque.codigo < POSITIVOS){
			realocar();
            leitura();
            maior();
            mostrar();

            exit(0);
        }
        
        else{
        	
          printf("produto: ");      fgets(estoque.produto,20,stdin);
          printf("preco: ");        scanf("%f",&estoque.preco);			getchar();
          printf("descricao: ");    fgets(estoque.descricao,50,stdin);

		  estoque.codigo = primary_key;

          tamanho++;
          primary_key++;

          salvar();

          return cadastro();
        }
    }
}

// funcao recursiva para cadastro dos produtos

// salvar estrutura no arquivo

void salvar(){
	FILE *arquivo;

    if(tamanho == 1){
        arquivo = fopen(ARQUIVO,"wb");
        
    }
    
    else{
        arquivo = fopen(ARQUIVO,"ab");
        
    }
    
    if(arquivo == NULL){
        fprintf(stderr,"impossivel abrir arquivo.");
        
    }
    
	fwrite(&estoque,sizeof(struct produtos),1,arquivo);
    fclose(arquivo);

}

// salvar estrutura no arquivo

// ler estrutura do arquivo e salvar em um ponteiro para estrutura

void leitura(){
	FILE *arquivo;

	arquivo = fopen(ARQUIVO,"rb");

	if(arquivo == NULL){
		printf("impossivel abrir arquivo. ");
		
	}
	
	else{
		
		fread(salvo,tamanho,sizeof(struct produtos),arquivo);
	}
	
	fclose(arquivo);

}

// ler estrutura do arquivo e salvar em um ponteiro para estrutura

// mostrar itens salvo no ponteiro para estrutura / vetor lido arquivo

void mostrar(){
	int contador;
	
	printf("segue abaixo os itens salvos no arquivo \n\n");

	for(contador = 0; contador < tamanho; contador++){
		
		printf("codigo[%d]: %d \n",contador,salvo[contador].codigo);
		printf("produto[%d]: %s",contador,salvo[contador].produto);
		printf("preco[%d]: %.2f \n",contador,salvo[contador].preco);
		printf("descricao[%d]: %s \n",contador,salvo[contador].descricao);

		putchar('\n');

		free(salvo);
	}
}

// mostrar itens salvo no ponteiro para estrutura / vetor lido arquivo

// determinar e mostrar o produto com o maior preco

void maior()
{
	int contador;
	float maior_preco = salvo[0].preco;

	for(contador = 0; contador < tamanho; contador++)
	{

		if(salvo[contador].preco > maior_preco)
		{
			maior_preco = salvo[contador].preco;
		}

		else
		{
			continue;
		}

	}

	printf("\n\no(s) produto(s) com maior preco e / sao:\n\n");

	for(contador = 0; contador < tamanho; contador++)
	{
		
		if(salvo[contador].preco == maior_preco)
		{
			printf("%s ",salvo[contador].produto);
		}
		
		else 
		{
			
			continue;
			
		}
		
		putchar('\n');
		
	}

}

// determinar e mostrar o produto com o maior preco

// funcao principal

int main()
{
	inicializar();
	
	cadastro();
    
}
// funcao principal
