#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


#define MAX_CLIENTES 100
#define MAX_ANIMAIS 100
#define MAX_TRATAMENTOS 100
#define MAX_CONSULTAS 100
#define MAX_VETERINARIOS 100
#define MAX_EXAMES 100



    typedef struct{
	char nomeClientes[100];
	char enderecoClientes[100];
	char cepClientes[15];
	char telefoneClientes[20];
	char emailClientes[100];
	}Cliente;
	
	Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;
    
    typedef struct{
	char nomeEspecie[50];
    }Especie;

    typedef struct{
	char nomeAnimal[100];
	int idadeAnimal;
	char sexoAnimal[15];
	Cliente proprietario; // Relacionamento com Cliente
	Especie especie; // Especie pertence a classe animais
   }Animal;

   Animal animais[MAX_ANIMAIS];
   int totalAnimais=0;
 
    typedef struct{
	char dataInicialTratamento[12];
    char dataFinalTratamento[12];
    char descricaoTratamento[500];
    Animal animal; // Relacionamento com Animal
   }Tratamento;

   Tratamento tratamentos[MAX_TRATAMENTOS];
   int totalTratamentos = 0;
   
    typedef struct{
	char nomeVeterinario[100];
	char enderecoVeterinario[100];
	char cepVeterinario[20];
	char telefoneVeterinario[20];
	char emailVeterinario[100];
   }Veterinario;

   Veterinario veterinarios[MAX_VETERINARIOS];
   int totalVeterinarios = 0;

    typedef struct{
	char dataConsulta[11];
    char relatoConsulta[500];
    Tratamento *tratamento; // Relacionamento com Tratamento
    Veterinario veterinario; // Relacionamento com Veterinario
    }Consulta;
    
    Consulta consultas[MAX_CONSULTAS];
    int totalConsultas = 0; 
    
    typedef struct {
	char descricaoExame[500];
	Consulta consulta; // Relacionamento com Consulta
	Animal animal; //Relacionamento com animal
    }Exame;

    Exame exames[MAX_EXAMES];
    int totalExames=0;
    
//fun�ao para registrar clientes
    void registraClientes(){
	if(totalClientes >= MAX_CLIENTES){
	printf("Limite maximo de clientes atingido! \n");
	return;
	}
	 Cliente novoCliente;

    printf("Digite o nome do cliente: ");
    fgets(novoCliente.nomeClientes, 100, stdin);
    novoCliente.nomeClientes[strcspn(novoCliente.nomeClientes, "\n")] = '\0';  // Remove nova linha

    printf("Digite o endere�o do cliente: ");
    fgets(novoCliente.enderecoClientes, 100, stdin);
    novoCliente.enderecoClientes[strcspn(novoCliente.enderecoClientes, "\n")] = '\0';  // Remove nova linha

    printf("Digite o CEP do cliente: ");
    fgets(novoCliente.cepClientes, 15, stdin);
    novoCliente.cepClientes[strcspn(novoCliente.cepClientes, "\n")] = '\0';  // Remove nova linha

    printf("Digite o telefone do cliente: ");
    fgets(novoCliente.telefoneClientes, 20, stdin);
    novoCliente.telefoneClientes[strcspn(novoCliente.telefoneClientes, "\n")] = '\0';  // Remove nova linha

    printf("Digite o email do cliente: ");
    fgets(novoCliente.emailClientes, 100, stdin);
    novoCliente.emailClientes[strcspn(novoCliente.emailClientes, "\n")] = '\0';  /// Remove nova linha

    clientes[totalClientes] = novoCliente;
    totalClientes++;

    printf("Cliente registrado com sucesso.\n");
    
    system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
    }
    //Fun�ao para consultar o cliente pelo nome
    
    void consultarCliente(){
    char nomeBusca[100];
    printf("Digite o nome do Cliente que deseja consultar: ");
    fgets(nomeBusca, 100, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // remove nova linha
    
    int encontrado=0;
    for(int i=0; i<totalClientes; i++){
    if(strcmp(clientes[i].nomeClientes, nomeBusca)==0){      //strcmp para realizar uma compara��o ordinal de string1 e string2 e retorna um valor que indica a rela��o entre eles.
    printf("Cliente encontrado! \n");
    printf("Nome: %s \n", clientes[i].nomeClientes);
    printf("Endere�o: %s \n", clientes[i].enderecoClientes);
    printf("Cep: %s \n", clientes[i].cepClientes);
    printf("Telefone: %s \n", clientes[i].telefoneClientes);
    printf("E-mail: %s \n", clientes[i].emailClientes);
    encontrado=1;
    break;
		}
	}
	if(!encontrado){
	printf("Cliente n�o encontrado! \n");
	}
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
	}
    

 // Fun�a� para registrar animais
    void registrarAnimal(){
 	if(totalAnimais>=MAX_ANIMAIS){
 	printf("Limite m�ximo de animais atingido! \n");
 	return;
	 }
	Animal novoAnimal;
	printf("Insira o nome do animal: ");
	fgets(novoAnimal.nomeAnimal, 100, stdin);
	novoAnimal.nomeAnimal[strcspn(novoAnimal.nomeAnimal, "\n")] = '\0'; //Remove nova linha
	 
	printf("Insira a idade: ");
	scanf("%d", &novoAnimal.idadeAnimal);
	getchar(); //limpar o buffer
	 
	printf("Insira o Sexo: ");
	fgets(novoAnimal.sexoAnimal, 10, stdin);
	novoAnimal.sexoAnimal[strcspn(novoAnimal.sexoAnimal, "\n")] = '\0'; //Remove nova linha
	 
	printf("Insira a esp�cie: ");
	fgets(novoAnimal.especie.nomeEspecie, 50, stdin);
	novoAnimal.especie.nomeEspecie[strcspn(novoAnimal.especie.nomeEspecie, "\n")] = '\0'; //Remove nova linha
	 
	printf("Insira o nome do propriet�rio: ");
	char nomeProprietario[100];
	fgets(nomeProprietario, 100, stdin);
	nomeProprietario[strcspn(nomeProprietario, "\n")] = '\0'; //Remove nova linha
	 
	int encontrado=0;
	
	//la�o para verificar se existe proprietario cadastrado para concluir cadastro do animal 
	 
	for(int i=0; i<totalClientes; i++){          //strcmp para realizar uma compara��o ordinal de string1 e string2 e retorna um valor que indica a rela��o entre eles.
    if(strcmp(clientes[i].nomeClientes, nomeProprietario)==0){
    novoAnimal.proprietario = clientes[i];
    encontrado = 1;
    break;
	 }
	 	
	 }
	if(!encontrado){
	printf("Propriet�rio n�o encontrado! Registro do animal n�o conclu�do. \n");
	return;
	 }
	animais[totalAnimais] = novoAnimal;
	totalAnimais++;
	 
	printf("Animal registrado com sucesso! \n");
	 
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
 }
 //Fun��o para listar animais
 
    void listarAnimais(){
 	if(totalAnimais==0){
 	printf("Nenhum animal encontrado! \n");
 	return;
	 }
	for(int i = 0; i<totalAnimais; i++){
	printf("\nAnimal: %d \n", i+1);
	printf("Nome: %s \n", animais[i].nomeAnimal);
	printf("Idade %d: \n", animais[i].idadeAnimal);
	printf("Sexo %s: \n", animais[i].sexoAnimal);
	printf("Esp�cie: %s \n", animais[i].especie.nomeEspecie);
	printf("Propriet�rio: %s \n", animais[i].proprietario.nomeClientes);
	 }
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
 }
 //Fun��o para consultar animal pelo nome.
 
    void consultarAnimal(){
 	char nomeBusca[100];
 	printf("Digite o nome do animal que deseja consultar: ");
 	fgets(nomeBusca, 100, stdin);
 	nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; //Remove nova linha
 	int encontrado=0;
 	for(int i =0; i< totalAnimais; i++){
 	if(strcmp(animais[i].nomeAnimal, nomeBusca)==0){
 	printf("Animal encontrado!\n");
 	printf("Nome: %s \n", animais[i].nomeAnimal);
 	printf("Idade: %d \n", animais[i].idadeAnimal);
 	printf("Sexo: %s \n", animais[i].sexoAnimal);
 	printf("Esp�cie: %s \n", animais[i].especie.nomeEspecie);
 	printf("Propriet�rio: %s \n", animais[i].proprietario.nomeClientes);
 	encontrado=1;
	 }
	 }
	if(!encontrado){
	printf("Animal n�o encontrado!\n");
	 }
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
 }
 
    //Fun�ao para registrar tratamento
    
    void registrarTratamento(){
    	
    if(totalTratamentos >= MAX_TRATAMENTOS){
    printf("Limite m�ximo de tratamentos atingido!\n");
    return;
		}
	
	Tratamento novoTratamento;
    printf("Digite o nome do animal a ser tratado:\n");
    char nomeAnimal[100];
    fgets(nomeAnimal, 100, stdin);
    nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0'; //Remove nova linha
    
    int encontrado=0;
    for(int i=0; i<totalAnimais; i++){
    if(strcmp(animais[i].nomeAnimal, nomeAnimal)==0){
    novoTratamento.animal = animais[i];
    encontrado=1;
    break;
	}
	
	}
	if(!encontrado){
	printf("Animal n�o encontrado! O registro de tratamento n�o foi conclu�do. \n");
	}
	printf("Digite a descri��o do tratamento:");
	fgets(novoTratamento.descricaoTratamento, 500, stdin);
	novoTratamento.descricaoTratamento[strcspn(novoTratamento.descricaoTratamento, "\n")] = '\0'; //Remove nova linha
	
	
	printf("Digite a data inicial do tratamento (formato: dd/mm/yyyy): ");
    fgets(novoTratamento.dataInicialTratamento, 12, stdin);
    novoTratamento.dataInicialTratamento[strcspn(novoTratamento.dataInicialTratamento, "\n")] = '\0'; //Remove nova linha
	
	printf("Digite a data final do tratamento (formato: dd/mm/yyyy): ");
    fgets(novoTratamento.dataFinalTratamento, 12, stdin);
    novoTratamento.dataFinalTratamento[strcspn(novoTratamento.dataFinalTratamento, "\n")] = '\0'; // Remove nova linha
	
	tratamentos[totalTratamentos] = novoTratamento;
	totalTratamentos++; 
	
	printf("Tratamento registrado com sucesso! \n");
	
    system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o	
}
//Fun��o para listar tratamentos

    void listarTratamentos(){
	if(totalTratamentos == 0){
	printf("Nnenhum tratamento encontrado.\n");
	return;
	}
	for(int i=0; i<totalTratamentos; i++){
	printf("\nTratamento %d: \n", i+1);
	printf("Animal: %s \n", tratamentos[i].animal.nomeAnimal);
	printf("Propriet�rio: %s \n", tratamentos[i].animal.proprietario.nomeClientes);
	printf("Descri��o: %s \n", tratamentos[i].descricaoTratamento);
    printf("Data inicial: %s\n", tratamentos[i].dataInicialTratamento);
    printf("Data final: %s\n", tratamentos[i].dataFinalTratamento);
	}
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}
//Fun��o para consultar tratamento

    void consultarTratamento(){
	
	char nomeBusca[100];
	printf("Digite o nome do animal para consultar seus tratamentos.\n");
	fgets(nomeBusca, 100, stdin);
	nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; //Remove nova linha
	
	int encontrado=0;
	for(int i=0; i<totalTratamentos; i++){
	if(strcmp(tratamentos[i].animal.nomeAnimal, nomeBusca)==0){  //strcmp para fazer a compara��o ordinal  da string 1 e 2 e retornar um valor que indica a rela�ao entre as duas
	printf("\nTrataento encontrado para o animal %s: \n", nomeBusca);
	printf("Descri��o: %s \n", tratamentos[i].descricaoTratamento);
    printf("Data inicial: %s\n", tratamentos[i].dataInicialTratamento);
    printf("Data final: %s\n", tratamentos[i].dataFinalTratamento);
	encontrado=1;
		}
	}
	if(!encontrado){
	printf("Nenhum tratamento encontrado para o animal %s. \n", nomeBusca);
	}
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}

//Fun�o para registrar veterinario

    void registrarVeterinario() {
    if (totalVeterinarios >= MAX_VETERINARIOS) {
    printf("Limite m�ximo de veterin�rios atingido!\n");
    return;
    }

    Veterinario novoVeterinario;

    printf("Insira o nome do veterin�rio: ");
    fgets(novoVeterinario.nomeVeterinario, 100, stdin);
    novoVeterinario.nomeVeterinario[strcspn(novoVeterinario.nomeVeterinario, "\n")] = '\0'; //Remove nova linha

    printf("Endere�o: ");
    fgets(novoVeterinario.enderecoVeterinario, 100, stdin);
    novoVeterinario.enderecoVeterinario[strcspn(novoVeterinario.enderecoVeterinario, "\n")] = '\0'; //Remove nova linha

    printf("CEP: ");
    fgets(novoVeterinario.cepVeterinario, 15, stdin);
    novoVeterinario.cepVeterinario[strcspn(novoVeterinario.cepVeterinario, "\n")] = '\0'; //Remove nova linha

    printf("telefone: ");
    fgets(novoVeterinario.telefoneVeterinario, 20, stdin);
    novoVeterinario.telefoneVeterinario[strcspn(novoVeterinario.telefoneVeterinario, "\n")] = '\0'; //Remove nova linha

    printf("Email: ");
    fgets(novoVeterinario.emailVeterinario, 100, stdin);
    novoVeterinario.emailVeterinario[strcspn(novoVeterinario.emailVeterinario, "\n")] = '\0'; //Remove nova linha

    veterinarios[totalVeterinarios] = novoVeterinario;
    totalVeterinarios++;

    printf("Veterin�rio registrado com sucesso.\n");
    
    system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}
//Fun��o listar veterin�rios
void listarVeterinarios(){
 	if(totalVeterinarios==0){
 	printf("Nenhum Veterin�rio encontrado! \n");
 	return;
	 }
	for(int i = 0; i<totalVeterinarios; i++){
	printf("\nVeterin�rio: %d \n", i+1);
	printf("Nome: %s \n", veterinarios[i].nomeVeterinario);
	
	 }
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}
//Fun��o para registrar consulta

    void registrarConsulta() {
    if (totalConsultas >= MAX_CONSULTAS) {
    printf("Limite m�ximo de consultas atingido!\n");
    return;
    }

    Consulta novaConsulta;

    // Inserindo veteririanrio ja cadastrado para registro de consulta
    
    printf("Digite o nome do veterin�rio respons�vel pela consulta: ");
    char nomeVeterinario[100];
    fgets(nomeVeterinario, 100, stdin);
    nomeVeterinario[strcspn(nomeVeterinario, "\n")] = '\0'; //Remove nova linha

    int veterinarioEncontrado = 0;
    for (int i = 0; i < totalVeterinarios; i++) {
    if (strcmp(veterinarios[i].nomeVeterinario, nomeVeterinario) == 0) {
    novaConsulta.veterinario = veterinarios[i];
    veterinarioEncontrado = 1;
    break;
        }
    }

    if (!veterinarioEncontrado) {
    printf("Veterin�rio n�o encontrado! O registro da consulta n�o foi conclu�do.\n");
    return;
        
    }
    
    printf("Digite o nome do animal associado ao tratamento: ");
    char nomeAnimal[100];
    fgets(nomeAnimal, 100, stdin);
    nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0'; //Remove nova linha

    int tratamentoEncontrado = 0;
    for (int i = 0; i < totalTratamentos; i++) {
    if (strcmp(tratamentos[i].animal.nomeAnimal, nomeAnimal) == 0) {
    novaConsulta.tratamento = &tratamentos[i];
    tratamentoEncontrado = 1;
    break;
    }
    }

    if (!tratamentoEncontrado) {
    printf("Tratamento n�o encontrado! O registro da consulta n�o foi conclu�do.\n");
    return;
    }

    // Registrar dados da consulta
    
    printf("Digite o relato da consulta: ");
    fgets(novaConsulta.relatoConsulta, 500, stdin);
    novaConsulta.relatoConsulta[strcspn(novaConsulta.relatoConsulta, "\n")] = '\0'; //Remove nova linha

    printf("Digite a data da consulta (formato: dd/mm/yyyy): ");
    fgets(novaConsulta.dataConsulta, 11, stdin);
    novaConsulta.dataConsulta[strcspn(novaConsulta.dataConsulta, "\n")] = '\0'; // Remove nova linha

    consultas[totalConsultas] = novaConsulta;
    totalConsultas++;

    printf("Consulta registrada com sucesso.\n");
    
    system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}
//Fun��o para listar consulta

    void listarConsultas(){
	char nomeAnimal[100];
	printf("Digite o nome do animal para listar as consultas: ");
	fgets(nomeAnimal, 100, stdin);
	nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0'; //Remove nova linha
	
	int encontrado=0;
	for(int i=0; i<totalConsultas; i++){
	if (strcmp(consultas[i].tratamento->animal.nomeAnimal, nomeAnimal) == 0){
	printf("\nConsulta %d: \n", i+1);
	printf("Veterin�rio: %s\n", consultas[i].veterinario.nomeVeterinario);
	printf("Animal: %s\n", consultas[i].tratamento->animal.nomeAnimal);
	printf("Data: %s\n", consultas[i].dataConsulta);
	printf("Relato: %s \n", consultas[i].relatoConsulta);
	printf("Propriet�rio: %s\n", consultas[i].tratamento->animal.proprietario.nomeClientes);
		
	encontrado=1;
		}
	}
	if(!encontrado){
	printf("Nenhuma consulta encontrada para o %s\n", nomeAnimal);
	}
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}

//Fun��o para verificar consulta especifica

    void verificarConsulta(){
	char nomeAnimal[100];
	
	printf("Digite o nome do animal cuja consulta deseja verificar: ");
	fgets(nomeAnimal, 100, stdin);
	nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0'; //Remove nova linha
	
	int encontrado=0;
	for(int i=0; i<totalConsultas; i++){
	if(strcmp(consultas[i].tratamento->animal.nomeAnimal, nomeAnimal)==0){
	printf("\nConsulta %d\n", i+1);
	printf("Veterin�rio: %s\n", consultas[i].veterinario.nomeVeterinario);
	printf("Animal: %s\n", consultas[i].tratamento->animal.nomeAnimal);
	printf("Data: %s\n", consultas[i].dataConsulta);
	printf("Relato: %s \n", consultas[i].relatoConsulta);
	printf("Propriet�rio: %s\n", consultas[i].tratamento->animal.proprietario.nomeClientes);
		
	encontrado=1;
	break;
		}
	}
	if(!encontrado){
	printf("Nenhuma consulta encontrada para o animal %s\n", nomeAnimal);
	}
	
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}

//Fun�ao para registrar  exame

    void registrarExame(){
	if(totalExames>=MAX_EXAMES){
	printf("Limite m�ximo de exames atingido!\n");
	return;
	}
	Exame novoExame;
	
	printf("Insira o nome do animal associado a consulta para exame: ");
	char nomeAnimal[100];
	fgets(nomeAnimal, 100, stdin);
	nomeAnimal[strcspn(nomeAnimal, "\n")] = '\0'; //Remove nova linha
    
	int encontrado=0;
	for(int i =0; i<totalConsultas; i++){
	if(strcmp(consultas[i].tratamento->animal.nomeAnimal, nomeAnimal)==0){
	novoExame.consulta = consultas[i];
	encontrado = 1;
	break;
		}
		
	}
	if(!encontrado){
	printf("Consulta n�o encontrada! O registro do exame n�o foi conclu�do.\n");
	return;
	}
	printf("Insira a descri��o do exame: ");
	fgets(novoExame.descricaoExame, 500, stdin);
	novoExame.descricaoExame[strcspn(novoExame.descricaoExame, "\n")] = '\0'; //Remove nova linha
	
	exames[totalExames] = novoExame;
	totalExames++;
	
	printf("Exame registrado com sucesso! \n");
	
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
	
}
//Fun��o para listar exames

    void listarExames(){
	if(totalExames==0){
	printf("Nenhum exame registrado. \n");
	return;
	}
	for(int i=0; i<totalExames; i++){
	printf("\n Exame %d \n", i+1);
	printf("Animal: %s\n", exames[i].consulta.tratamento->animal.nomeAnimal);
	printf("Veterin�rio: %s", exames[i].consulta.veterinario.nomeVeterinario);
	printf("Descri��o: %s \n", exames[i].descricaoExame);
		
	}
	
	system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}

// Fun��o para consultar exame

    void consultarExame(){
    char nomeBusca[100];

    printf("Insira o nome do animal para consultar seus exames:\n");
    fgets(nomeBusca, 100, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Remove nova linha

    int exameEncontrado = 0;
    for(int i = 0; i < totalExames; i++){
    if(strcmp(exames[i].consulta.tratamento->animal.nomeAnimal, nomeBusca) == 0){
    printf("\nExame %d:\n", i + 1);
    printf("Animal: %s\n", exames[i].consulta.tratamento->animal.nomeAnimal);
    printf("Veterin�rio: %s\n", exames[i].consulta.veterinario.nomeVeterinario);
    printf("Descri��o: %s\n", exames[i].descricaoExame);
    printf("Data: %s\n", consultas[i].dataConsulta);
    exameEncontrado = 1;
        }
    }
    if(!exameEncontrado){
    printf("Nenhum exame encontrado para o animal %s.\n", nomeBusca);
    }
    
    system("pause");  // Pausa para o usu�rio visualizar a mensagem
    system("cls");    // Limpa a tela ap�s a opera��o
}
//Fun��o para Menu clientes

    void menuClientes(){
	int opcaoClientes;
	
	do{
	printf("\n-----Gerenciar Clientes----\n");
	printf("1.Registrar Clientes\n");
	printf("2.Consultar Clientes\n");
	printf("3.Voltar ao Menu Principal\n");
	printf("Escolha uma op�ao:\n");
	scanf("%d", &opcaoClientes);
	getchar(); //limpar o buffer
		
	switch(opcaoClientes){
	case 1:
	registraClientes();
	break;
	case 2:
	consultarCliente();
	break;
	case 3:
	break;
	default:
	printf("Op��o inv�lida!\n");		
		}
	}while (opcaoClientes!=3);
}

//Fun�ao menu animais

    void menuAnimais(){
	int opcaoAnimal;
	
	do{
	printf("\n----Gerenciar animais----\n");
	printf("1.Registrar Animais\n");
	printf("2.Listar Animais\n");
	printf("3.Consultar Animais\n");
	printf("4.Voltar ao Menu Principal\n");
	printf("Escolha uma op��o: ");
	scanf("%d", &opcaoAnimal);
	getchar();  // Limpar o buffer de entrada
		
	switch(opcaoAnimal){
	case 1:
	registrarAnimal();
	break;
	case 2:
	listarAnimais();
	break;
	case 3:
	consultarAnimal();
	break;
	case 4:
	break;
	default:
	printf("Op��o inv�lida!\n");
			
		}
	}while(opcaoAnimal!=4);
}
//Fun��o menu tratamento

    void menuTratamentos(){
	int opcaoTratamento;
	
	do{
	printf("\n----Gerenciar Tratamentos----\n");
	printf("1.Registrar Tratamento\n");
	printf("2.Listar Tratamento\n");
	printf("3.Consultar Tratamento\n");
	printf("4.Voltar ao Menu Principal\n");
	printf("Escolha a op��o: ");
	scanf("%d", &opcaoTratamento);
	getchar();  // Limpar o buffer de entrada
		
	switch(opcaoTratamento){
	case 1:
	registrarTratamento();
	break;
	case 2:
	listarTratamentos();
	break;
	case 3:
	consultarTratamento();
	break;
	case 4:
	break;
	default:
	printf("Op��o inv�lida!\n");	
		}
	}while(opcaoTratamento!=4);
}
//Fun��o menu Exames

    void menuExames(){
	int opcaoExame;
	
	do{
	printf("\n----Gerenciar Exames----\n");
	printf("1.Registrar Exame\n");
	printf("2.Listar Exames\n");
	printf("3.Consultar Exame\n");
	printf("4.Voltar ao Menu Principal\n");
	printf("Escola uma op��o\n");
	scanf("%d", &opcaoExame);
	getchar();  // Limpar o buffer de entrada
	
	switch(opcaoExame){
	case 1:
	registrarExame();
	break;
	case 2:
	listarExames();
	break;
	case 3:
	consultarExame();
	break;
	case 4:
	break;
	default:
	printf("Op��o inv�lida!\n");
	}	
	}while(opcaoExame!=4);
}
//Fun��o menu consultas

    void menuConsultas(){
	int opcaoConsulta;
	
	do{
	printf("\n----Gerenciar Consultas----\n");
	printf("1.Registrar Consulta\n");
	printf("2.Listar Consultas\n");
	printf("3.Voltar ao Menu Principal\n");
	printf("Escolha uma op��o: ");
	scanf("%d", &opcaoConsulta);
	getchar();  // Limpar o buffer de entrada
	
	switch(opcaoConsulta){
	case 1:
    listarVeterinarios();
	registrarConsulta();
	break;
	case 2:
	listarConsultas();
	break;
	case 3:
	break;
	default:
	printf("Op��o inv�lida!\n");	
	}
	}while(opcaoConsulta!=3);
}
//Fun��o menu veterinario

    void menuVeterinarios(){
	int opcaoVeterinario;
	
	do{
	printf("\n----Gerenciar Veterin�rio----\n");
	printf("1.Registrar Veterin�rio\n");
	printf("2.Voltar ao Menu Principal\n");
	printf("Escolha uma op��o: ");
	scanf("%d", &opcaoVeterinario);
	getchar();  // Limpar o buffer de entrada
	
	switch (opcaoVeterinario) {
    case 1:
    registrarVeterinario();
    break;
    case 2:
    break;
    default:
    printf("Op��o inv�lida!\n");
        }
    } while (opcaoVeterinario != 2);
}


int main() {
    setlocale(LC_ALL, "");  // Permite acentos conforme a localiza��o do sistema

    int opcao;

    do {
    printf("\n=== Sistema de Gerenciamento Veterin�rio ===\n");
    printf("1. Gerenciar Clientes\n");
    printf("2. Gerenciar Animais\n");
    printf("3. Gerenciar Tratamentos\n");
    printf("4. Gerenciar Veterin�rios\n");
    printf("5. Gerenciar Consultas \n");
    printf("6. Gerenciar Exames\n");
    printf("7. Sair\n");
    printf("Escolha uma op��o: ");
    scanf("%d", &opcao);
    getchar();  // Limpar o buffer de entrada

    switch (opcao) {
    case 1:
    menuClientes();
    break;
    case 2:
    menuAnimais();
    break;
    case 3:
    menuTratamentos();
    break;
    case 4:
    menuVeterinarios();
	break;
    case 5:
    menuConsultas();
    break;
    case 6:
    menuExames();
    break;
    case 7:
    printf("Saindo...\n");
    break;
    default:
    printf("Op��o inv�lida!\n");
        }
    } while (opcao != 7);

    return 0;
}



