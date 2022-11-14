//============================================================================//
//========================//TODAS AS BIBLIOTECAS\\============================//
//============================================================================//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//============================================================================//
//=========================//TODAS AS ESTRUTURAS\\============================//
//============================================================================//

// Estrutura para o cliente
typedef struct{
	char nome[50];
	char sexo[10];
 	int telefone;
}cliente;

// Estrutura para a roupa
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
}roupa;

//Estrutura para o funcionario
typedef struct {
	float salario;
	char nome[50];
}funcionario;

//Estrutura para peca mais vendida
typedef struct {
	char nome[50];
	int cont;
}pecamaisvendida;

//Estrutura para cadastrar acessorio
typedef struct {
	char nome[50];
	float preco;
}acessorio;

//Estrutura para pesquisar dia caixa
typedef struct{
  int cod;
  char dia[50];
  float n1;
}caixapesquisar;

//============================================================================//

//ESTRUTURAS PARA PERFUME

//Estruturas para funcionar os cadastros dos perfumes
typedef struct {
  float vlr;
  char nome[100];
} perfumes;

struct No {
  perfumes dado;
  struct No * prox;
};

typedef struct No No;

typedef struct {
  No * inicio;
} Lista;
//Estruturas para funcionar os cadastros dos perfumes

//============================================================================//


//============================================================================//
//=========================//TODAS AS FUNÇÕES\\===============================//
//============================================================================//

//FUNÇÕES PARA PERFUME!

//Função para ler os dados dos perfumes
void ler(perfumes *ps) {
  scanf("%f %s", &ps->vlr, ps->nome);
}

//Função para inserir no inicio (perfume)
void inserir_inicio(Lista *plista, perfumes dado) {
  No * novo = (No*) malloc(sizeof(No));
  novo->dado = dado;
  novo->prox = plista->inicio;
  plista->inicio = novo;
}

//Função para inserir no final (perfume)
void inserir_fim(Lista *plista, perfumes dado) {
  No* novo = (No *) malloc(sizeof(No));
  novo->dado = dado;
  novo->prox = NULL;
  if (plista->inicio == NULL) {
    plista->inicio = novo;
  }
  else {
    No * pi;
    for (pi = plista->inicio; pi->prox != NULL; pi = pi->prox);
    pi->prox = novo;
  }
}

//Função para inserir apos (perfume)
struct No * inserir_apos (Lista *plista, perfumes dado, float vlr){
	struct No * pi;
	for(pi = plista->inicio; pi != NULL && pi->dado.vlr != vlr; pi = pi->prox);
	if(pi == NULL){
		return pi;
	}
	else {
		struct No *novo = (struct No *) malloc(sizeof(struct No));
		novo->dado = dado;
		novo->prox = pi->prox;
		pi->prox = novo;
		return pi;
	}
	
}

//Função para inserir antes (perfume)
struct No* inserir_antes (Lista *plista, perfumes dado, float vlr){
	if (plista->inicio == NULL){
		return NULL;
	}
	else if (plista->inicio->dado.vlr == vlr) {
		struct No* novo = (struct No*) malloc(sizeof(struct No));
		novo->dado = dado;
		novo->prox = plista->inicio;
		plista->inicio = novo;
	}
	else{
		struct No* pi;
		for(pi = plista->inicio; pi->prox != NULL && pi->prox->dado.vlr != vlr; pi = pi->prox);
		if(pi->prox == NULL){
			return NULL;
		}
		else{
			struct No *novo = (struct No *) malloc(sizeof(struct No));
			novo->dado = dado;
			novo->prox = pi->prox;
			pi->prox = novo;
			return pi;
		}
	}
}

//Função para deletar inico 
void deletar_inicio (Lista *plista){
	if (plista->inicio == NULL){
		printf("\n");
		printf("A Lista Esta Vazia\n");
		printf("\n");
	}
	else {
		struct No * pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
		
		printf("=================================================================\n");
	    printf("Inicio Deletado Com Sucesso !\n");
 	    printf("=================================================================\n");
	}	
}

//Função para deletar final
void deletar_fim (Lista *plista){
	if (plista->inicio == NULL){
		printf("\n");
		printf("A Lista Esta Vazia\n");
		printf("\n");
	}
	else if (plista->inicio->prox == NULL){
		struct No * pi = plista->inicio;
		plista->inicio = NULL;
		free(pi);
		
		printf("=================================================================\n");
	    printf("Fim Deletado Com Sucesso !\n");
 	    printf("=================================================================\n");				
	}
	else{
		struct No* pi;
		struct No* pa;
		for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
			pa = pi;
		}
		pa->prox = NULL;
		free(pi);

		printf("=================================================================\n");
	    printf("Fim Deletado Com Sucesso !\n");
 	    printf("=================================================================\n");
	}
}

//Função para deletar por valor
void deletar_por_valor(Lista *plista, float vlr){
	//quando inicio for igual a nulo
	if (plista->inicio == NULL){
	   	printf("\n");
		printf("A Lista Esta Vazia\n");
		printf("\n");
	}
	//quando o nó se encontra no inicio
	else if(plista->inicio->dado.vlr == vlr){
		struct No* pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
	}
	//quando a lista tem um unico nó (Perfume Não Existe)
	else if(plista->inicio->prox == NULL){
		if (plista->inicio->dado.vlr != vlr){
			printf("\n");
			printf("O Perfume Nao Pode Ser Removido\n");
			printf("\n");
		}
	}
	//quando a lista tem multiplos casos (Valor Existe)
	//quando a lista tem multiplos casos (Valor Não Existe)
	else {
		struct No* pi;
		struct No* pa;
		for(pi = plista->inicio; pi != NULL && pi->dado.vlr != vlr; pi = pi->prox){
			pa = pi;
		}	
		if (pi == NULL){
			printf("\n");
			printf("O Perfume Nao Pode Ser Removido\n");
			printf("\n");
		}
		else {
			pa->prox = pi->prox;
			free(pi);
		}
	}	
}

//Função para deletar apos um determinado valor
void deletar_apos (Lista *plista, float vlr){
	struct No* pa;
	struct No* pi;
	for(pa = plista->inicio; pa != NULL && pa->dado.vlr != vlr; pa = pa->prox);
	if (pa == NULL){
		printf("\n");
		printf("O Perfume Nao Pode Ser Removido\n");
		printf("\n");
	}
	else if(pa->prox == NULL){
		printf("\n");
		printf("O Perfume Nao Pode Ser Removido\n");
		printf("\n");			
	}
	else {
		pi = pa->prox;
		pa->prox = pi->prox;
		free(pi);
	}
}

//Função para deletar antes de um determinado valor
void deletar_antes (Lista *plista, float vlr){
	//lista vazia
	if (plista->inicio == NULL){
	   	printf("\n");
		printf("A Lista Esta Vazia\n");
		printf("\n");
	}
	else {
		struct No* paa = NULL;
		struct No* pa = NULL;
		struct No* pi;
		for (pi = plista->inicio; pi != NULL && pi->dado.vlr != vlr; pi = pi->prox){
			paa = pa;
			pa = pi;
		}
		//multiplos itens (nó existe)
		//multiplos itens (nó não existe)
		if (pi == NULL){
		   	printf("\n");
			printf("O Perfume Nao Pode Ser Removido\n");
			printf("\n");
		}
		//nó inicial igual ao pesquisado
		else if (pa == NULL){
			printf("\n");
			printf("O Perfume Nao Pode Ser Removido\n");
			printf("\n");
		}
		//o segundo nó eh igual ao valor pesquisado
		else if (paa == NULL){
			plista->inicio = pi;
			free(pa);
		}
		else {
			paa->prox = pi;
			free(pa);
		}
	}
}

//Função para deletar lista
void deletar_lista (Lista *plista){
	struct No* pi;
	while (plista->inicio != NULL){
		pi = plista->inicio;
		plista->inicio = pi->prox;
		free(pi);
	}
	printf("\n");
	printf("Lista Deletada Por Completo\n");
	printf("\n");
}

//Função para mostrar dados dos perfumes
void mostrar(Lista lista) {
  No* pi;
  printf("\n");
	printf("=================================================================\n");
	for (pi = lista.inicio; pi != NULL; pi = pi->prox) {
  		printf("\n");
 		printf("%.2f %s\n", pi->dado.vlr, pi->dado.nome);
    }
    printf("\n");
	printf("=================================================================\n");
}

//Pesquisar perfume pelo valor
struct No* pesquisar(Lista lista, float vlr){
	struct No* pi;
	for(pi = lista.inicio; pi != NULL && pi->dado.vlr != vlr; pi = pi->prox);
	return pi;
}

//Função para alterar nome do perfume
void alterar(Lista *plista, float vlr, char nome[]){
	struct No* pi = pesquisar(*plista, vlr);
	if (pi == NULL){
		printf("\n");
		printf("=============================================================\n");
		printf("O Perfume Nao Pode Ser Removido\n");
		printf("=============================================================\n");
		printf("\n");		
	}
	else {
		strcpy(pi->dado.nome, nome);
	}
}

//Função para mostrar o tamanho da lista
int tamanho_da_lista (Lista lista){
	struct No* pi;
	int cont = 0;
	for (pi = lista.inicio; pi != NULL; pi = pi->prox){
		cont++;
	}
	return cont;
}

//Função para criar uma nova lista
Lista criar_lista(int n){
	Lista lista;
	lista.inicio = NULL;
	int i;
	for(i = 0; i < n; i++){
		printf("=============================================================\n");
		printf("Informe o %d Item Da Lista\n", i + 1);
		printf("\n");
		perfumes f;
		ler (&f);
		inserir_fim(&lista, f);
	}
		printf("=============================================================\n");
	return lista;
}

//Função para ordenar lista
void ordenar_lista (Lista *plista){
	struct No* pi;
	struct No* pj;
	struct No* pfim = NULL;
	if(plista->inicio == NULL){
		return;
	}
	for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
		for(pj = plista->inicio; pj->prox != pfim; pj = pj->prox){
			if(pj->dado.vlr > pj->prox->dado.vlr){
   			 	 perfumes temp = pj->dado;
   			 	 pj->dado = pj->prox->dado;
   			 	 pj->prox->dado = temp;
			}
		}
		pfim = pj;
	}
	printf("\n");
	printf("\n");
	printf("=================================================================\n");
	printf("Lista Ordenada Com Sucesso\n");
	printf("=================================================================\n");
	printf("\n");
	
}

//função para ler lista de um arquivo
Lista ler_arquivo(){
	Lista lista;
	lista.inicio = NULL;
	FILE *file = fopen("./perfumes.b", "rb"); 
	perfumes p;
	while(fread(&p, sizeof(perfumes), 1, file)){
		inserir_fim(&lista, p);
	}
	printf("\n");
	printf("=================================================================\n");
	printf("Lista Lida Com Sucesso\n");
	printf("=================================================================\n");
	printf("\n");
	fclose(file);
	return lista;
}

//Função para salvar lista para um arquivo
void salvar_arquivo (Lista lista){
	FILE *file = fopen("./perfumes.b", "wb");
	struct No* pi;
	for(pi = lista.inicio; pi != NULL; pi = pi->prox){
		fwrite(&pi->dado, sizeof(perfumes), 1, file);
	}
	printf("\n");
	printf("=================================================================\n");
	printf("Lista Escrita(SALVA) Com Sucesso\n");
	printf("=================================================================\n");
	printf("\n");
	fclose(file);
}

//============================================================================//

//FUNÇÕES DOS MENUS

//Função para o menu dos perfume
void menu_perfume() {
    printf("\n");	
    printf("======== Escolha Uma Opcao ======================================\n");
    printf("\n");
    printf(" 1  -  Adicionar Perfume No Inicio Da Lista\n");
    printf(" 2  -  Adicionar Perfume No Final Da Lista\n");
    printf(" 3  -  Adicionar Perfume Apos\n");
    printf(" 4  -  Adicionar Perfume Antes\n");
    printf(" 5  -  Mostrar Lista\n");
    printf(" 6  -  Pesquisar Pelo Valor\n");
    printf(" 7  -  Deletar Perfume No Inicio Da Lista\n");
    printf(" 8  -  Deletar Perfume No Final Da Lista\n"); 
    printf(" 9  -  Deletar Perfume Por Valor\n");
    printf(" 10 -  Deletar Perfume Apos\n");
	printf(" 11 -  Deletar Perfume Antes\n");
	printf(" 12 -  Deletar Lista Completa\n");
	printf(" 13 -  Alterar Nome Do Perfume Ja Cadastrado\n");
	printf(" 14 -  Mostrar o Tamanho Da Lista\n");
	printf(" 15 -  Criar Lista\n");
	printf(" 16 -  Ordenar Lista\n");
	printf(" 17 -  Salvar Lista Em Arquivo\n");
	printf(" 18 -  Ler Lista De Um Arquivo\n");
    printf(" 19 -  Sair\n");
    printf("\n");
    printf("=================================================================\n");
}

//Função para mostrar o menu principal
void menu_principal(){
  printf("\n");
  printf("==========================ESCOLHA UMA OPCAO========================\n");
  printf("\n");
  printf(" 1 - Cadastrar Roupa\n");
  printf(" 2 - Cadastrar Funcionario(s) e Mostrar Salario Do Maior Pro Menor\n");
  printf(" 3 - Olhar Qual Peca Foi a Mais Vendida\n");
  printf(" 4 - Cadastrar Os Dados Do Cliente\n");
  printf(" 5 - Cadastrar Acesssorio e Comprar\n");
  printf(" 6 - Pesquisar Quanto No Dia Foi Recebido\n");
  printf(" 7 - Cadastrar Perfume(s) - Lista / Arquivo\n");
  printf(" 8 - Sair\n");
  printf("\n");
  printf("===================================================================\n");
}

//Função para menu de exemplo de uso para caixa dia
void menuexemplocaixadia(){
	printf("\n");
	printf("=================================================================\n");
	printf("==========================EXEMPLO================================\n");
	printf("===================(Codigo) (Dia) (Valor)========================\n");
	printf("====================== 1 SEGUNDA 780 ============================\n");
	printf("=================================================================\n");
	printf("\n");
}

//============================================================================//

//FUNÇÕES PARA DADOS DO CLIENTE

//Função para ler os dados do cliente
void lerdadosdoclientes (cliente *pc){
  printf("\n");
  printf("=========================INFORME OS DADOS==========================\n");
  printf("\n");
  printf("Informe O Nome Do Cliente:\n");
  scanf(" %[^\n]s", (*pc).nome);
  printf("\n");

  printf("Informe O Sexo:\n");
  scanf("%s", (*pc).sexo);
  printf("\n");

  printf("Informe O Telefone:\n");
  scanf("%d", &(*pc).telefone);
  printf("\n");
  printf("===================================================================\n");
  printf("\n");
}

//Função para mostrar os dados do cliente
void mostrardadosdocliente (cliente *pc){
  printf("======================DADOS SOBRE O CLIENTE========================\n");
  printf("\n");
  printf("Nome do cliente: %s\nSexo Do cliente: %s\nTelefone: %d\n"
  , (*pc).nome, pc->sexo, pc->telefone);
  printf("\n");
  printf("===================================================================\n");
}

//============================================================================//

//FUNÇÕES PARA APESENTAÇÃO E AGRADECIMENTO

//Função para a apresentação inicial
void apresentacaoinicial (){
  printf("\n");
  printf("===================================================================\n");
  printf("========================Seja Bem Vindo(a)!=========================\n");
  printf("===================================================================\n");
  printf("\n");
}

//Função para o agradecimento final
void agredecimentofinal (){
	printf("\n");
  printf("===================================================================\n");
  printf("=============Agradecemos Pela Preferencia, Volte Sempre============\n");
  printf("===================================================================\n");
  printf("\n");
}

//============================================================================//

//FUNÇÕES PARA AS PEÇAS

//Função para cadastrar as pecas
void cadastrarpecas(int n,roupa *roupas){
	int i;
    for(i=0;i<n;i++){
      printf("\n");
        printf("=============================================================\n");
        printf("===================INFORME A ROUPA NUMERO: %d================\n",i+1);
        printf("=============================================================\n");
        printf("\n");
        printf("Informe o Nome Da Peca:\n");
        scanf("%s",roupas[i].nome);
        printf("\n");
        printf("Informe a Quantidade De Pecas: \n");
        scanf("%d", &roupas[i].quantidade);
        printf("\n");
        printf("Informe o Preco Equivalente a Peca: \n");
        scanf("%f", &roupas[i].preco);
        printf("\n");
        printf("=============================================================\n");
      printf("\n");
    }
}

//Função para mostrar oas pecas cadastradas
void mostrarpecascadastradas(int n,roupa *roupas){
	int i;
  for(i=0;i<n;i++){
      printf("\n");
        printf("======================PECA NUMERO: %d =======================\n", i+1);
        printf("Nome Da Peca: %s\n",roupas[i].nome);
        printf("Quantidade: %d Unidade(s)\n",roupas[i].quantidade);
        printf("Preco: %.2f\n",roupas[i].preco);
        printf("=============================================================\n");
      printf("\n");
    }
}

//============================================================================//

//FUNÇÕES PARA OS DADOS DOS FUNCIONARIOS

//Função para ler funcionario
void lerfuncionario (int i, funcionario *pe){
	printf("\n");
	printf("=================================================================\n");
	printf("Informe o Nome e O salario Do %d Funcionario\n", i +1);
	printf("\n");
	scanf ("%s %f", pe->nome, &pe->salario);
	printf("=================================================================\n");
	printf("\n");
}

//Função particionar funcioanrio
int particiona(int e, int d, funcionario v[]){
	funcionario pivo =  v[d];
	int j = e - 1;
	int i;
	for(i = e; i<d; i++){
		if(v[i].salario <= pivo.salario){
			j++;
			funcionario temp = v[j];
			v[j] = v[i];
			v[i] = temp;
		}
	}
	funcionario temp = v[j + 1];
	v[j + 1] = v[d];
	v[d] = temp;
	return j + 1;    
}

//Função do quicksort para funcionario
void quicksort(int i, int f, funcionario v[]){ 
	if (i < f){
		int p = particiona(i, f, v);
		quicksort(i, p-1, v);
		quicksort(p + 1, f, v);
	}
}

//============================================================================//

//FUNÇÕES DOS DADOS DO CAIXA

//Função para ler dados do caixa
void ler(caixapesquisar *pe){
	printf("\n");
	printf("=================================================================\n");
    printf("Informe o Codigo, Dia (Digitado) e o Valor Recebido No Dia \n");
    printf("=================================================================\n");
    printf("\n");
    scanf("%d %s %f", &pe->cod, pe->dia, &pe->n1);
}

//Funcao para caixa pesquisar dia
int pesquisar(int cod, caixapesquisar v[], int i, int f){
	if (i >= f) return -1;
	int meio = (i + f)/2;
	if (v[meio].cod == cod){
		return meio;
	}
	if (v[meio].cod < cod){
		return pesquisar(cod, v, meio +1, f);
	}
	return pesquisar(cod, v, i, meio - 1);
}

//============================================================================//

//FUNÇÕES PARA OS CASOS DO WHILE PRINCIPAL

//Função para o caso um do while
void extra_para_caso_um(){
	printf("\n");
	printf("=====================================================\n");
	printf("Informe a Quantidade De Roupa(s) Que Deseja Cadastrar\n");
	printf("\n");
	int n;
	scanf("%d",&n);
	roupa *roupas = (roupa *) malloc(n*sizeof(roupa));
	printf("\n");
	printf("=====================================================\n");
   	         
	cadastrarpecas(n, roupas);
	mostrarpecascadastradas(n, roupas);
}

//Função para o segundo caso do while
void extra_para_caso_dois(){
	int n;
	printf("\n");
 	printf("=================================================================\n");
	printf("Informe a quantidade de funcionario(s)\n");
	printf("\n");
	scanf("%d", &n);
	funcionario v[n];
	int i;
	for (i = 0; i < n; i++){
		lerfuncionario(i, &v[i]);
	}
	quicksort(0, n-1, v);
	for (i = 0; i < n; i++){
 	   	printf("=============================================================\n");
		printf("%s Recebe Salario De %.2f\n", v[i].nome, v[i].salario);
		printf("=============================================================\n");	
	}
}

//Funçao para o caso treis do while 
void extra_para_caso_treis (){
	int n;
	printf("\n");
	printf("=================================================================\n");
	printf("=================Informe a Quantidade De Pecas===================\n");
	printf("\n");
	scanf("%d", &n);
	printf("=================================================================\n");
	pecamaisvendida v[n];
	int i;
	//Escrevendo para um arquivo 
	FILE *file = fopen ("./pecamaisvendida.txt", "w");
	
	for (i=0; i<n; i++){
		printf("\n");
		printf("=============================================================\n");
		printf("Informe o Nome Da Peca: %d\n", i+1);
		scanf("%s", v[i].nome);
		printf("\n");
		printf("Informe a Quantidade:\n");
		scanf("%d", &v[i].cont);
		printf("=============================================================\n");
		printf("\n");
	}
	pecamaisvendida maior = v[0];
	for (i = 1; i < n; i++){
		if (v[i].cont > maior.cont){
			maior = v[i];
		}
	}
	printf("\n");
	printf("=================================================================\n");
	printf("A peca: %s Foi a Mais Vendida Com: %d Unidade(s)\n", maior.nome, maior.cont);
	printf("=================================================================\n");
	printf("\n");
	fclose(file);
}

//Função para o quarto caso do while
void extra_para_caso_quatro(){
	cliente c;
   	cliente *pc = &c;
  	lerdadosdoclientes (pc);
  	mostrardadosdocliente (pc);
}

//Função para o quinto caso do while
void extra_para_caso_cinco(){
	//escrevendo para um arquivo binario
	FILE *file = fopen ("./acessorio.b", "wb");
	acessorio a;
	printf("\n");
	printf("=================================================================\n");
	printf("Informe O Nome Do Acessorio\n");
	scanf("%s", a.nome);
	printf("\n");
	printf("Informe o Preco\n");
	scanf("%f", &a.preco);
	fwrite(&a, sizeof(acessorio), 1, file);
	printf("\n");
	printf("=================================================================\n");
	printf("%s: Cadastrado(a) \n", a.nome);
	printf("=================================================================\n");
	printf("\n");
	fclose (file);

	//lendo de um arquivo binario
	file = fopen ("./acessorio.b", "rb");
	while (fread(&a, sizeof(acessorio), 1, file)){
		int qtd;
		printf("==================================================\n");
		printf("Informe a Quantidade De %s Que Deseja Comprar\n", a.nome);
		printf("\n");
		scanf("%d", &qtd);
		printf("\n");
		float valortotal = (a.preco * qtd);
		printf("=====================================\n");
		printf("Valor Total De %s(s): %.2f\n",a.nome ,valortotal);
		printf("=====================================\n");
	}
}

//Função para o sesto caso do while
void extra_para_caso_seis (){
	int n;
   	printf("\n");
  	printf("=================================================================\n");
    printf("Informe Quantos Dias Deseja Cadastrar\n");
    printf("\n");
    scanf("%d", &n);
    printf("=================================================================\n");
    printf("\n");
	caixapesquisar v[n];
    int i;
    menuexemplocaixadia();
	for(i=0;i<n;i++){
   	   	ler(&v[i]);
	}
    printf("\n");
	printf("=================================================================\n");
    printf("======================Valores Cadastrados========================\n");
    printf("=================================================================\n");
    printf("\n");
    int cod;
    printf("\n");
    printf("=================================================================\n");
	printf("=====Agora Informe O Codigo Referente Ao Dia Para Pesquisar======\n");
    printf("=================================================================\n");
    printf("\n");
    printf("=================================================================\n");
    printf("Digite o Codigo Referente Ao Dia\n");
	scanf(" %d", &cod);
	printf("\n");
	printf("=================================================================\n");
	int idx = pesquisar(cod, v, 0, n-1);
	if (idx != -1){
    	float aux = (v[idx].n1);
        printf("\n");
  	    printf("=============================================================\n");
        printf("Na %s Entrou %.2f No Caixa\n", v[idx].dia, aux);
        printf("=============================================================\n");
        printf("\n");
	}
}

//Função para o caso 7 do while
void extra_para_caso_sete(){
  Lista lista;
  lista.inicio = NULL;
  int op;
  menu_perfume();
  scanf("%d", &op);
  while (op != 19) {
    switch(op) {
 	  //Opcao para inserir no inicio da lista
      case 1: {
        perfumes s;
        printf("\n");
        printf("=============================================================\n");
        printf("Informe o Valor e o Nome Do Perfume\n");
        printf("\n");
        ler(&s);
        inserir_inicio(&lista, s);
        printf("\n");
        printf("Perfume Adicionado\n");
        break;
      }
      //Opcao para inserir no fim da lista
      case 2: {
        perfumes s;
        printf("=============================================================\n");
        printf("Informe o Valor e o Nome Do Perfume\n");
        printf("\n");
        ler(&s);
        inserir_fim(&lista, s); 
    	printf("\n");
        printf("Perfume Adicionado\n");       
        break;
      }
      //opcao para inserir apos uma determinada posição na lista
      case 3: {
		perfumes f;
		printf("=============================================================\n");
		printf("Informe o Valor e o Nome Do Perfume\n");
		printf("\n");
		ler(&f);
		printf("\n");
		printf("Perfume Adicionado\n");
		float vlr;
		printf("\n");
		printf("=============================================================\n");
		printf("Informe o Valor Do Perfume Para Inserir Apos\n"); 
		printf("\n");
		scanf("%f", &vlr);
		struct No * pi = inserir_apos(&lista, f, vlr);
		if(pi == NULL){
			printf("=========================================================\n");
			printf("Nao Foi Possivel Inserir o Perfume\n");
			printf("=========================================================\n");
		}	  
		break;
	  }
	  //opcao para inserir antes de uma determinada posição na lista
	  case 4: {
		perfumes f;
		printf("=============================================================\n");
		printf("Informe o Valor e o Nome Do Perfume\n");
		printf("\n");
		ler(&f);
		printf("\n");
		printf("Perfume Adicionado\n");
		float vlr;
		printf("\n");
		printf("=============================================================\n");
		printf("Informe o Valor Do Perfume Para Inserir Antes\n"); 
		printf("\n");
		scanf("%f", &vlr);
		struct No * pi = inserir_antes(&lista, f, vlr);
		if(pi == NULL){
			printf("=========================================================\n");
			printf("Nao Foi Possivel Inserir o Perfume\n");
			printf("=========================================================\n");
		}			   
		break;
	  }
      //Opcao para mostrar a lista
      case 5: {
        mostrar(lista);
        break;
      }
      //Opcao para pesquisar pelo valor
      case 6: {
      	float vlr;
      	printf("\n");
       	printf("Informe o Valor\n");
        scanf("%f", &vlr);
	    struct No * pi = pesquisar (lista, vlr);
	    if (pi != NULL){
			printf("%.2f %s\n", pi->dado.vlr, pi->dado.nome);
		}
		else{
			printf("Perfume Nao Encontrado\n");
		}
		break;
	  }
	  //opcao para deletar inicio
	  case 7: {
		  deletar_inicio(&lista);
		break;
	  }
	  //opcao para deletar fim
	  case 8: {
		  deletar_fim(&lista);
		break;
	  }
	  //opcao para deletar por valor
	  case 9: {
		  float vlr;
		  printf("Informe O Valor\n");
		  scanf("%f", &vlr);
		  deletar_por_valor(&lista, vlr);
        break;
	  }
	  //opcao para deletar apos
	  case 10: {
		  float vlr;
		  printf("Informe O Valor\n");
		  scanf("%f", &vlr);
		  deletar_apos(&lista, vlr);		  
		break;
	  }
	  //opcao para deletar antes
	  case 11: {
		  float vlr;
		  printf("Informe O Valor\n");
		  scanf("%f", &vlr);
		  deletar_antes(&lista, vlr);
        break;
	  }
	  //opcao para deletar lista
	  case 12: {
		  deletar_lista(&lista);
		  break;
	  }
	  //opcao para alterar nome do perfume
	  case 13: {
		  float vlr;
		  printf("===========================================================\n");
		  printf("Informe O Valor Correspondente Ao Perfume\n");
		  printf("\n");
		  scanf("%f", &vlr);
		  printf("\n");
		  printf("Informe o Novo Nome Do Perfume\n");
		  printf("\n");
		  char nome[100];
		  scanf("%s", nome);
		  printf("\n");
		  
		  alterar(&lista, vlr, nome);
		  break;
	  }
	  //opcao para mostrar o tamanho da lista
	  case 14: {
	  	  int tam = tamanho_da_lista(lista);
		  printf("\n");
		  printf("===========================================================\n");
    	  printf("%d\n", tam);
    	  printf("===========================================================\n");
    	  printf("\n");
    	  break;
	  }
	  //opcao para criar uma lista nova
	  case 15: {
		  int n;
		  printf("\n");
		  printf("===========================================================\n");
		  printf("Informe o Tamanho Da Lista Que Deseja Criar\n");
		  printf("===========================================================\n");
		  printf("\n");
		  scanf("%d", &n);
		  printf("\n");
		  
		  lista = criar_lista(n);
		  break;
	  }
	  //opcao para ordenar lista
	  case 16: {
		  ordenar_lista(&lista);
		  break;
	  }
	  //opcao para salvar lista
	  case 17: {
		  salvar_arquivo(lista);
		  break;
	  }
	  //opcao para ler de um arquivo
	  case 18: {
		  lista = ler_arquivo();
		  break;
	  }
	  //opcao invalida
      default: {
        printf("Opcao invalida\n");
      }
    }
    menu_perfume();
    scanf("%d", &op);
  }
}

//Função para codigo errado  
void codigoerrado (){
	printf("\n");
	printf("=================================================================\n");
	printf("========================Codigo Invalido==========================\n");
	printf("==========================Digite Outro===========================\n");
	printf("=================================================================\n");
	printf("\n");
}

//============================================================================//

//FUNÇÃO DO WHILE COMPLETO

//Função para o while completo
void whileprincipal(){
	int opcao;
	scanf("%d", &opcao);
	while (opcao != 8){
		switch (opcao){
		   	//opcao de cadastrar as roupas
			case 1:{
 			   extra_para_caso_um();
			break;		
			}
			//opcao para calcular qual funcionario tem maior salario
			case 2:{ 
				extra_para_caso_dois();
		   	break;
		   	}
		   	//opcao para mostrar peca mais vendida
		   	case 3:{
				extra_para_caso_treis();	   
    		break;
			}
			//opcao para ler os dados do cliente
			case 4:{
				extra_para_caso_quatro();
 			break;
			}
			//opcao para cadastrar acesssorio e comprar
			case 5:{
				extra_para_caso_cinco();
			break;
			}
			//opcao para pesquisar dia caixa
			case 6:{
				extra_para_caso_seis();
			break;
			}
			//opcao para cadastrar perfume(s)
			case 7: {
				extra_para_caso_sete();
			break;
			}
			//opcao para codigo invalido
			default:{
				codigoerrado ();
			break;
			}
		}
		menu_principal();
		scanf("%i",&opcao);
	}
}

//============================================================================//

//============================================================================//
//===========================//FUNÇÃO PRINCIPAL\\=============================//
//============================================================================//

//Função Principal
int main (){
	apresentacaoinicial ();
	menu_principal();
	whileprincipal();
   	agredecimentofinal ();
}