#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    int dia, mes;
}data;

typedef struct Contato{
    char* nome;
    char* email;
    int telefone, celular;
    data DataAniversario;
    struct Contato* prox;
} contato;

contato* cria_agenda(void);
contato* recebe_contato(void);
contato* cria_contato(char* nome, char* email, int telefone, int celular, data DataAniversario);
contato* alfabetico(contato* x, contato* y, char* nome);
void insere_contato(contato** head);
void lista_contatos(contato* head);
contato* busca_contato(contato* head);
void remove_contato(contato** head);
void atualiza_contato(contato* head);
void remove_duplicados(contato* head);
void libera_agenda(contato* head);


int main(){
    contato* head = cria_agenda();

    int x;

    printf("1 - Inserir Contato\n2 - Listar Contatos\n3 - Buscar contato\n4 - Editar Contato\n5 - Remover Contato\n6 - Remover Contatos Duplicados\n7 - Sair\n\n");
    scanf("%d", &x);
    printf("\n");
    getchar();

    while(x != 7){
        switch (x)
        {
        case 1:
            insere_contato(&head);
            break;
        case 2:
            lista_contatos(head);
            break;
        case 3:
            busca_contato(head);
            break;
        case 4:
            atualiza_contato(head);
            break;
        case 5:
            remove_contato(&head);
            break;
        case 6:
            remove_duplicados(head);
            break;
        default:
            break;
        }
        printf("1 - Inserir Contato\n2 - Listar Contatos\n3 - Buscar contato\n4 - Editar Contato\n5 - Remover Contato\n6 - Remover Contatos Duplicados\n7 - Sair\n\n");
        scanf("%d", &x);
        printf("\n");
        getchar();
    }
    

    return 0;
}

contato* cria_agenda(void){
    contato* head = NULL;
    return head;
}

contato* recebe_contato(void){

    char nome[100], email[100];

    int telefone, celular;

    data aniversario;
 
    printf("Digite seu nome: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = 0; 

    printf("Digite seu email: ");
    fgets(email, 100, stdin);
    email[strcspn(email,"\n")] = 0;

    printf("Digite seu numero de telefone: ");
    scanf("%d", &telefone);
    
    printf("Digite seu numero de celular: ");
    scanf("%d", &celular);
    
    printf("Digite seu dia de nascimento: ");
    scanf("%d", &aniversario.dia);

    printf("Digite seu mes de nascimento: ");
    scanf("%d", &aniversario.mes);
    printf("\n");
    
    getchar();
   
    contato* novo = cria_contato(nome, email, telefone, celular, aniversario);
    
    return novo;
}

contato* cria_contato(char* nome, char* email, int telefone, int celular, data DataAniversario){

    contato* novo = (contato*)malloc(sizeof(contato));

    novo->nome = (char*)malloc(strlen(nome) + 1);
    strcpy(novo->nome, nome);

    novo->email = (char*)malloc(strlen(email) + 1);
    strcpy(novo->email, email);

    novo->telefone = telefone;

    novo->celular = celular;

    novo->DataAniversario = DataAniversario;

    novo->prox = NULL;

    return novo;
}

contato* alfabetico(contato* x, contato* y, char* nome){
    while(y != NULL){
        if(strcmp(nome, y->nome) <= 0) break;
        x = y;
        y = y->prox;
    }
    return x;
}

void insere_contato(contato** head){

    contato* novo = recebe_contato();

    contato* x = *head;

    if(*head == NULL){
        *head = novo;
        return;
    }
    
    if(strcmp(novo->nome, x->nome) <= 0){
        novo->prox = *head;
        *head = novo;
        return;
    }

    x = alfabetico(*head, x->prox, novo->nome);

    novo->prox = x->prox;
    x->prox = novo;

    return;
}

void lista_contatos(contato* head){
    int i = 1;
    printf("--------------------\n");
    while(head != NULL){
        printf("CONTATO %d\n\nNome = %s\nEmail = %s\nTelefone = %d\nCelular = %d\nData de aniversario = %d/%d\n\n", i , head->nome, head->email, head->telefone, head->celular, head->DataAniversario.dia, head->DataAniversario.mes);
        head = head->prox;
        i++;
    }
}

contato* busca_contato(contato* head){
    char nome[100];
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = 0;

    while(head != NULL){
        if(!strcmp(nome, head->nome)) return head;
        head = head->prox;
    }
    return NULL;
}

void remove_contato(contato** head){
    char nome[100];
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = 0;

    if(!strcmp(nome, (*head)->nome)){
        contato* temp = *head;
        *head = (*head)->prox;
        free(temp->nome);
        free(temp->email);
        free(temp);
        return;
    }

    contato* x = *head; contato* y = x->prox;

    while(y != NULL){
        if(!strcmp(nome, y->nome)){
            x->prox = y->prox;
            free(y->nome);
            free(y->email);
            free(y);
            return;
        }
        x = y;
        y = y->prox;
    }

    printf("\nContato nao encontrado\n");
}

void atualiza_contato(contato* head){
    contato* atualizar = busca_contato(head);

    if(atualizar == NULL){
        printf("\nContato nao encontrado\n");
        return;
    }
    char nome[100], email[100];

    int telefone, celular, x = 1;

    data aniversario;
    
    printf("Digite 0 para voltar ao menu\nDigite 1 para atualizar o nome\nDigite 2 para atualizar o email\nDigite 3 para atualizar o telefone\nDigite 4 para atualizar o celular\nDigite 5 para atualizar a data de aniversario\n\n");
    scanf("%d", &x);
    getchar();
    while(x){
        

        switch (x)
        {
        case 1:
            printf("Digite o novo nome: ");
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = 0;
            atualizar->nome = (char*)realloc(atualizar->nome, strlen(nome) + 1);
            strcpy(atualizar->nome, nome);
            break;
        case 2:
            printf("Digite o novo email: ");
            fgets(email, 100, stdin);
            email[strcspn(email, "\n")] = 0;
            atualizar->email = (char*)realloc(atualizar->email, strlen(email) + 1);
            strcpy(atualizar->email, email);
            break;
        case 3:
            printf("Digite o novo telefone: ");
            scanf("%d", &telefone);
            atualizar->telefone = telefone;
            break;
        case 4:
            printf("Digite o novo celular: ");
            scanf("%d", &celular);
            atualizar->celular = celular;
            break;
        case 5:
            printf("Digite o novo dia de aniversario: ");
            scanf("%d", &aniversario.dia);
            printf("Digite o novo mes de aniversario: ");
            scanf("%d", &aniversario.mes);
            atualizar->DataAniversario = aniversario;
            break;
        
        default:
            break;
        }
        printf("Digite 0 para voltar ao menu\nDigite 1 para atualizar o nome\nDigite 2 para atualizar o email\nDigite 3 para atualizar o telefone\nDigite 4 para atualizar o celular\nDigite 5 para atualizar a data de aniversario\n\n");
        scanf("%d", &x);
        getchar();
    }
   
}

void remove_duplicados(contato* head){
    if (head == NULL) return; // Verifica se a lista está vazia

    contato* temp;
    contato* temp2;

    while (head != NULL && head->prox != NULL) {
        temp2 = head;
        temp = head->prox;

        while (temp != NULL) {
            if (strcmp(head->nome, temp->nome) == 0) {
                // Encontrou duplicata
                temp2->prox = temp->prox;
                free(temp->nome);
                free(temp->email);
                free(temp);
                temp = temp2->prox;
            } else {
                temp2 = temp;
                temp = temp->prox;
            }
        }
        head = head->prox;
    }
}

void libera_agenda(contato *head) {
    contato* temp;
   
    while (head != NULL) {
        temp = head;
        head = head->prox;
        
        if (temp->nome != NULL) free(temp->nome);
        if (temp->email != NULL) free(temp->email);
       
        free(temp);
    }
}