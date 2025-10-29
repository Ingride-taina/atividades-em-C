#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    char aluno_name [30];
    int quantidade_notas;
    float *notas;

} ficha;

//ponteiro *atributo que aponta para -> os dados da ficha, que sao chamados nas funçôes

void cadastrar_aluno(ficha *atributo){
    
    printf("Digite o nome do aluno: ");
    scanf("%s", atributo->aluno_name);

    printf("Quantas notas o aluno possui? ");
    scanf("%d", &atributo-> quantidade_notas);



    atributo->notas=(float*) malloc(atributo->quantidade_notas * sizeof(float));

    if (atributo->notas==NULL)
    {

        printf("Sem memoria\n");

        return;

    } else {
        for (int i = 0; i < atributo->quantidade_notas; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &atributo->notas[i]);
         }

    }

    //Mostra o nome e todas as notas
    printf("\nAluno: %s\n", atributo->aluno_name);
    printf("Notas: ");
    for (int i = 0; i < atributo->quantidade_notas; i++) {
        printf("%.2f ", atributo->notas[i]);
    }
    printf("\n");
    


}


float calcular_media(ficha *atributo) {

    float soma = 0;
    for (int i = 0; i < atributo->quantidade_notas; i++) {
        soma += atributo->notas[i];
    }
    
    float media = soma / atributo->quantidade_notas;

    printf("Media:  %.2f\n", media);

    
//avalia desempenho
    if (media<=5)
    {
        printf("Desempenho insuficiente!\n ");
    } else
    {
        printf("O aluno teve um bom desempenho!\n");
    }
    

}

    

int main() {
    int opcao=0;
    int sair = 0;
    ficha aluno;

    do {
        printf("\n\n>>>> Ambiente do Professor <<<<");
        printf("\n\t1 - Cadastrar aluno");
        printf("\n\t2- Sair\n\t>>>> ");
        
        scanf("%d", &opcao);

        if (opcao == 1) {

          printf("\n----Cadastro do Aluno---\n");
          cadastrar_aluno(&aluno);
          calcular_media(&aluno);
      } 
      else if (opcao == 2) {
        sair=1;
        }
        else {
            printf("\nOpcao invalida!\n");
        }
    }
       while (sair != 1);


    // Libera memória

    free(aluno.notas);

    }

