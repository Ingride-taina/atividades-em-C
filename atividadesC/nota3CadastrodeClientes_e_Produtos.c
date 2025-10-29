#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMCli 3
#define TAMProd 3

typedef struct {
    int id;
    char nome[20];
    int quantidade;
    float valor;
} Produto;

typedef struct {
    int id;
    char nome[20];
} Cliente;

typedef struct {
    int idCliente;
    int idProduto;
    int quantProduto;
    float valorTotal;
} Venda;

void cadastrarCliente(Cliente c[]) {
    for (int i = 0; i < TAMCli; i++) 
    
        {
        printf("Cliente %d, Primeiro Nome: ", i + 1);
        scanf("%s", c[i].nome);
        c[i].id = i + 1;
    }
}

void cadastrarProduto(Produto p[]) {
    for (int i = 0; i < TAMProd; i++) {
        printf("\nNome do Produto %d: ", i + 1);
        scanf("%s", p[i].nome);
        printf("Quantidade: ");
        scanf("%d", &p[i].quantidade);
        printf("Valor: ");
        scanf("%f", &p[i].valor);
        p[i].id = i + 1;
    }
}

void consultarCliente(Cliente c[]) {
    for (int i = 0; i < TAMCli; i++) {
        printf("\nId Cliente: %d", c[i].id);
        printf("\nPrimeiro Nome: %s\n", c[i].nome);
    }
    printf("\n");
}

void consultarProduto(Produto p[]) {
    for (int i = 0; i < TAMProd; i++) {
        printf("\nId Produto: %d", p[i].id);
        printf("\nNome Produto: %s", p[i].nome);
        printf("\nQuantidade: %d", p[i].quantidade);
        printf("\nValor: R$ %.2f", p[i].valor);
        printf("\n----------------------------------\n");
    }
    printf("\n");
}
void consultarVendas(Venda vendas[], int totalVendas, Cliente clientes[], Produto produtos[]);

void realizarVenda(Venda vendas[], int *totalVendas, Produto produtos[], Cliente clientes[]) {
     
    int idCli, idProd, quantidade;
 
     printf("\nDigite o ID do cliente (1 a %d): ", TAMCli);
     scanf("%d", &idCli);
 
     printf("Digite o ID do produto (1 a %d): ", TAMProd);
     scanf("%d", &idProd);
 
     printf("Quantidade desejada: ");
     scanf("%d", &quantidade);
 
     if (produtos[idProd - 1].quantidade >= quantidade) {
         vendas[*totalVendas].idCliente = idCli;
         vendas[*totalVendas].idProduto = idProd;
         vendas[*totalVendas].quantProduto = quantidade;
         vendas[*totalVendas].valorTotal = quantidade * produtos[idProd - 1].valor;
 
         produtos[idProd - 1].quantidade -= quantidade;
 
         (*totalVendas)++;
 
         printf("\nVenda realizada com sucesso!\n");
     } else {
         printf("\nQuantidade em estoque insuficiente!\n");
     }
 }
 
 void consultarVendas(Venda vendas[], int totalVendas, Cliente clientes[], Produto produtos[]) {
     if (totalVendas == 0) {
         printf("\nNenhuma venda realizada ainda.\n");
         return;
     }
 
     for (int i = 0; i < totalVendas; i++) {
         int idCli = vendas[i].idCliente - 1;
         int idProd = vendas[i].idProduto - 1;
 
         printf("\nVenda %d:", i + 1);
         printf("\nCliente: %s", clientes[idCli].nome);
         printf("\nProduto: %s", produtos[idProd].nome);
         printf("\nQuantidade: %d", vendas[i].quantProduto);
         printf("\nValor Total: R$ %.2f", vendas[i].valorTotal);
         printf("\n-----------------------------");
     }

     float somaTotal = 0;

    for (int i = 0; i < totalVendas; i++) {
        somaTotal += vendas[i].valorTotal;
    }

    printf("\nVALOR TOTAL DE TODAS AS VENDAS: R$ %.2f\n", somaTotal);

     printf("\n");
 }

int main() {
    int opcao, sair = 0;

    Cliente clientes[TAMCli];
    Produto produtos[TAMProd];
    Venda vendas[30];
    int totalVendas = 0;
    

    do {
        printf("\n\n>>>> Sistema de Vendas <<<<");
        printf("\n\t1 - Cadastrar Clientes");
        printf("\n\t2 - Cadastrar Produtos");
        printf("\n\t3 - Consultar Clientes");
        printf("\n\t4 - Consultar Produtos");
        printf("\n\t5 - Realizar Venda");
        printf("\n\t6 - Consultar Vendas");
        printf("\n\t7 - Sair\n\t>>>> ");
        scanf("%d", &opcao);

        if (opcao == 1) {
          cadastrarCliente(clientes);
      } else if (opcao == 2) {
          cadastrarProduto(produtos);
      } else if (opcao == 3) {
          consultarCliente(clientes);
      } else if (opcao == 4) {
          consultarProduto(produtos);
      } else if (opcao == 5) {
          realizarVenda(vendas, &totalVendas, produtos, clientes);
      } else if (opcao == 6) {
          consultarVendas(vendas, totalVendas, clientes, produtos);
      } else if (opcao == 7) {
          sair = 1;
      } else {
          printf("\n\nOpção inválida!");
      }
    } while (sair != 1);

    return 0;
}


