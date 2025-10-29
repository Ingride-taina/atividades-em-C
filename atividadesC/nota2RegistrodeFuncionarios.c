#include <stdio.h>

float salario[10],somasalario, maiorsalario=0;
int idade[10],genero[10],estcivil[10],qntfilhos[10];
int pais_idosos_solteiros=0, qntpais_adolescentes=0, total_idosos;

int main()
{
    for (int i= 0; i <10; i++)
    {
        printf("REGISTRO FUNCIONARIO %d\n", i +1);
        
        printf("Ola bem vindo ao sistema de registro de funcionarios\n");
        printf("Vamos comecar. Informe o genero do funcionario sendo 1 para F ou  2 para M: \n");
        scanf ("%d", &genero[i]);

        printf("Qual a idade do funcionario? \n");
        scanf("%d",&idade[i]);
    
        printf ("Informe o salario: \n");
        scanf  ("%f", &salario[i]);
    
        printf (" Nos informe o estado civil do funcionario\n(Sendo 1 para Casado (a) e 2 para Solteiro (a)): \n");
        scanf ("%d", &estcivil[i]);
    
        printf ("Caso o funcionario tenha filhos digite a quantidade, caso contrario, digite ""0"": \n");
        scanf ("%d", &qntfilhos[i]);
    }
    for (int i = 0; i <10 ; i++)
    {
        if (genero[i]==2 && estcivil[i]==2 && idade[i]>60)
        {
            somasalario+= salario[i];
            pais_idosos_solteiros++;
            total_idosos++;
        }

        if (genero[i]==1 && qntfilhos[i]==0)
        {
            if (salario[i]> maiorsalario)
            {
                maiorsalario=salario [i];
            }       
        }
        
        if (genero[i]==2 && idade[i]<18 && estcivil[i]==1 && salario[i]>3000)
        {
            qntpais_adolescentes++;
        }
    }

    printf("\n--- Dados sobre Funcionarios ---\n");
    if (total_idosos>0)
    {
      printf ("A media salarial dos pais idosos solteiros e de: %.2f\n",somasalario/total_idosos);
    } else {
        printf("Nao ha registro de pais idosos solteiros\n");
    }
    if (maiorsalario>0)
    {
      printf("A mulher que ganha o maior salario e que noo tem filhos recebe o valor de: R$ %.2f\n", maiorsalario);
    } else {
       printf ("Nao ha registro de mulheres com maior salario e que nao tem filhos\n");
    }
    if (qntpais_adolescentes>0)
    {
      printf("A quantidade de pais adolescentes que nao sao solteiros e ganham acima de R$ 3000 e de: %d\n", qntpais_adolescentes);   
    } else {
       printf ("Nao ha registro de pais adolescentes que nao sao solteiros e ganham acima de R$ 3000\n");
    }

    return 0;
}
