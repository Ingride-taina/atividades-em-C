//Elabore um programa em C para liberação de empréstimos bancários, com os seguintes requisitos:

//1. O sistema deve calcular a Taxa de Endividamento do solicitante, que é a porcentagem de seu salário mensal comprometido com 
//as dívidas atuais.
//Se a taxa de endividamento (total de dívidas divididas pelo salário) for superior a 50%, o empréstimo será recusado,
// independente de outras condições.

//2. Limitação de Percentual do Empréstimo em Relação ao Salário. O valor da parcela do empréstimo não pode
// ultrapassar um determinado percentual do valor do salário do solicitante. O sistema deve fazer esse cálculo
// e recusar a solicitação caso ultrapasse o limite máximo.

//3. O sistema deve permitir que o número de parcelas seja condicionado ao tempo de estabilidade no emprego do solicitante:
 //se o solicitante tem um emprego estável por menos de 1 ano, o número máximo de parcelas será limitado a 12. 
 //Se o tempo de emprego for entre 1 e 3 anos, o número máximo de parcelas será 24. Se o tempo de emprego for superior a 3 anos,
 // o solicitante pode solicitar até 60 parcelas

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

float taxa_edividamento, salario, total_dividas, valor_parcela, limite_max;
float valor_do_emprestimo, percentual_do_valor_salario;
int quantidade_parcelas, tempo_estavel_emprego,max_parcelas;
char user [20];// variavel (local que armazena um nome com,no maximo,50 caracteres)


 int main() {
    
    printf(" Digite seu nome\n");
    scanf("%s",&user);// entrada padrão. captura oq é digitado pelo usuario no teclado
   
    printf ("ola,%s. Seja bem vindo (a) Informe seu salario \n", user);

    scanf("%f", &salario);
 
    printf ("Informe suas dividas: ");
    scanf ("%f", &total_dividas);

    printf ("informe a quantidade de anos de contratacao do seu emprego atual:");
    scanf ("%d", &tempo_estavel_emprego);

    printf("Qual valor do emprestimo que voce deseja fazer?");
    scanf("%f", &valor_do_emprestimo);

    printf ("Informe o numero de parcelas: ");
    scanf ("%d", &quantidade_parcelas);


    taxa_edividamento= ( total_dividas/salario)*100;

    if (taxa_edividamento>50);
    {
        printf ("emprestimo recusado\n");
        printf("Sua taxa de endividamento e superior a 50%%\n");

        printf("taxa: %2f\n",taxa_edividamento);
        }
        
    
    valor_parcela=valor_do_emprestimo/quantidade_parcelas;
    percentual_do_valor_salario=(valor_parcela/salario)*100;

    if (percentual_do_valor_salario>30)
    {
        printf("O Emprestimo foi recusado");
        printf("parcela superior a 30%% do seu salario.\n");
        return 0;
    }
    

 // parte para quantidade de parcelas sob a condição do tempo de emprego
        if (tempo_estavel_emprego <1)
        {
            max_parcelas=12;
        } 
        else if (tempo_estavel_emprego>1&& tempo_estavel_emprego <3)
        {
           max_parcelas=24 ;
        } else
        {
            max_parcelas=60;
        }

        if (quantidade_parcelas>max_parcelas)
        {
            printf("Seu emprestimo foi recusado\n");
            printf("O numero de parcelas ultrapassou a quantidade permitida\n");
            return 0;
        }
      //caso emprestimo aprovado  
        printf ("%s Seu emprestimo foi aprovado!\n"), user;
        printf("Valor do emprestimo: %.2f\n ", valor_do_emprestimo);
        printf("Valor da parcela: %.2f\n ", valor_parcela);
        printf("Quantidade de parcelas: %.2d \n", quantidade_parcelas);
        printf("Sua taxa de endividamneto é de: %f \n", taxa_edividamento );
        printf("Percentual da parcela: %.2f\n ", percentual_do_valor_salario);

        return 0;
    }     
        


 