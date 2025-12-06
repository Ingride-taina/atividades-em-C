#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


#define TAM 200


//heap sort
//função para transformar o array em um heap
//n é o tamanho do heap
//i é o indice do nó raiz


void heapfy(float notas[], char nomes[][30],int n, int i){
    int largest= i;     //indice, assume que i é o maior ou seja a raiz
    int left= 2*i +1;   // calculo para o filho esquerdo
    int right= 2*i+2;   //calculo para o filho direito

// se o fiho esquerdo existir e for maior que a raiz, atualizar largest


    if (left< n && notas[left]> notas[largest]){
        largest= left;
    }

//se o filho direito existir e for maior que a raiz, atualizar largest


    if(right< n && notas[right]>notas[largest]){
        largest= right;
    }

/*Quando você troca a raiz com um dos filhos,
 o valor que estava na raiz pode desorganizar a subárvore onde foi colocado e tambem pode ser que
  o valor do filho que foi para a raiz desorganize a subárvore dele.

 Por isso, o heapfy precisa ser chamado recursivamente para corrigir o heap em níveis inferiores.*/


    if (largest != i){
        float Aux= notas[i];
        notas[i]= notas[largest];
        notas[largest]= Aux;

        char auxNome[30];
        strcpy (auxNome, nomes[i]);
        strcpy (nomes[i], nomes[largest]);
        strcpy(nomes[largest], auxNome);


         //reaplica heapfy na subárvore afetada
        heapfy(notas,nomes,n,largest);

    }

 }

//função principal do heap max, vai reorganizar o array de maneira crescente 

//n/2-1 é o índice do último nó que não- folha

void heap_Sort (float notas[], char nomes[][30], int n){
    //construindo max heap
    for ( int i = n/2 -1; i>=0; i--) {
        heapfy(notas,nomes,n,i);
    
    }
    
// extraindo elementos do heap um por um 
//revisar depois
    for (int i= n-1; i > 0; i--){
    // movendo a raiz atual para o final do array
        float Aux = notas[0];
        notas[0]=notas[i];
        notas[i]= Aux;


        char auxNome[30];
        strcpy(auxNome, nomes[0]);
        strcpy(nomes[0],nomes[i]);
        strcpy(nomes[i], auxNome);

 // reaplicando heapfy na raiz para manter a propriedade do heap
         heapfy (notas, nomes,i,0);
    }
   
 }




int main() {

float notas[TAM];
char nomes[TAM][30];
int tamanho;

    printf("\n>>>>>> BEM - VINDO <<<<<<");
    printf("\nQuantas notas deseja cadastrar?\n");
    scanf("%d", &tamanho);

    for (int i=0;i< tamanho; i++){
    
        do {

        printf("\nDigite o nome do Aluno %d: ", i+1);
         scanf("%s", nomes[i]);


        printf ("Digite a nota do aluno %d: ", i+1);
         scanf("%f", &notas[i] );
        
         if (notas[i]<0||notas[i]>10){
            printf("Nota invalida! Insira uma nota entre 0 e 10\n");
         }
        
         } while (notas[i]<0||notas[i]>10);
    }
    
    
     heap_Sort(notas,nomes, tamanho);

    printf("\nNotas em ordem crescente\n");

    for(int i = 0; i< tamanho; i++){

        printf("%s: %.2f\n", nomes[i],  notas[i]);
    }

    return 0;

}
