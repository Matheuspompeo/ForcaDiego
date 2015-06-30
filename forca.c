#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Palavra{
	char palavra[20];
	struct Palavra * prox;
};

struct Palavra * cria(void){
	return NULL;
}

struct Palavra * insere (struct Palavra * p, char * valor){
	struct Palavra * nvPalavra = (struct Palavra*) malloc(sizeof(struct Palavra));
	
	strcpy(nvPalavra->palavra,valor);	
	nvPalavra->prox = p;
	return nvPalavra;
}

void imprime(struct Palavra * p){
	struct Palavra * plv;
	
	for(plv=p;plv!=NULL;plv=plv->prox){
		printf("Palavra = %s\n",p->palavra);
	}
}

int busca(struct Palavra * p,char * palavra){
	struct Palavra *plv;
	int i=1;
	for(p=plv;p!=NULL;p=p->prox){
		if(strcmp(palavra,p->palavra)){
			printf("Palavra %s \n",p->palavra);
			return i++;
		}
		return 0;
	}	
}



int main() {
	//Constante do nÃºmero de Ã­tens por tema. Usada para randomizar um tema.
	const NUM_ITENS = 20;

	//Vetores com as palavras possÃ­veis. A declaraÃ§Ã£o do tamanho deve ser manual, pois C nÃ£o permite que a constante seja declarada como dimensÃ£o do array.
	char animal[20][12] = { "AVESTRUZ", "BORBOLETA", "CARANGUEJO",
			"ORANGOTANGO", "CROCODILO", "DROMEDARIO", "ROUXINOL", "CENTOPEIA",
			"GAFANHOTO", "PINTASSILGO", "HIPOPOTAMO", "LEOPARDO", "GUAXINIM",
			"JAGUATIRICA", "OSTRA", "MICO", "CHIMPANZE", "CARNEIRO", "GOLFINHO",
			"MINHOCA" };
	char comida[20][12] = { "EMPADA", "FARINHA", "FEIJOADA", "COXINHA",
			"BRIGADEIRO", "CHURRASCO", "LASANHA", "MACARRONADA", "TORTA",
			"TORRADA", "PIZZA", "PANQUECA", "PIPOCA", "PAMONHA", "OVO",
			"ACARAJE", "CROISSANT", "HAMBURGUER", "BISCOITO", "BOLO" };
	char fruta[20][12] = { "ABACATE", "BANANA", "CARAMBOLA", "DAMASCO", "FIGO",
			"GOIABA", "JABUTICABA", "KIWI", "LARANJA", "MELANCIA", "MANGA",
			"MARACUJA", "PESSEGO", "PITOMBA", "ROMA", "TANGERINA", "TOMATE",
			"TAMARINDO", "UVA", "UMBU" };
	char profissao[20][12] = { "ADVOGADO", "BOMBEIRO", "CARPINTEIRO",
			"DESENHISTA", "ENGENHEIRO", "ESCRITOR", "FERREIRO", "GUARDA",
			"HISTORIADOR", "JORNALISTA", "LEILOEIRO", "MARINHEIRO", "OURIVES",
			"PROGRAMADOR", "PADEIRO", "RELOJOEIRO", "SILVICULTOR", "TRADUTOR",
			"VETERINARIO", "ZOOLOGO" };
	char informatica[20][12] = { "LINUX", "WINDOWS", "C", "PROCESSADOR",
			"TECLADO", "MOUSE", "PROGRAMA", "ALGORITMO", "HACKER", "TOUCHPAD",
			"ASCII", "JAVA", "JAVASCRIPT", "PROGRAMADOR", "PYTHON", "INTERNET",
			"ROTEADOR", "SERVIDOR", "GOOGLE", "APPLE" };

	//Iterador para uso geral.
	int i;

	//Char usado pra voltar ao menu
	char voltarMenu;

	//Dica da palavra para o jogador.
	char dica[20];
	//Palavra que o jogador deve acertar. Pode ser uma da lista acima ou personalizada.
	char palavra[12];
	//VariÃ¡vel usada para controle dos acertos do usuÃ¡rio. Cada letra acertada Ã© colocada em sua posiÃ§Ã£o nessa string. Quando <acertos> == <palavra>, o jogador acertou.
	char acertos[12];

	//Palpite do jogador.
	char palpite;

	//VariÃ¡vel de controle; 0 = nÃ£o contem o
	int contemPalpite = 0;

	//VariÃ¡veis de opÃ§Ã£o dos menus de jogo e de tema.
	int opc = 0;
	int tema = 0;

	//O programa Ã© executado enquanto opc != 3 (sair no menu);
	while (opc != 3) {

		//Letras usadas pelo usuÃ¡rio e contador de letras usadas para repetiÃ§Ãµes.
		char letrasUsadas[26];
		int numLetrasUsadas = 0;
		int usada;

		//Contador de erros. 6 erros = derrota;
		int erros = 0;

		struct Palavra *itPalavra = (struct Palavra*) malloc(sizeof(struct Palavra));
		do {

			system("clear");

			//Limpa as letras usadas
			for (i = 0; i < strlen(letrasUsadas); i++) {
				letrasUsadas[i] = '*';
			}

			printf(
					"#################################### Forca #####################################");
			printf("\n\n Escolha o modo de jogo: ");
			printf("\n\n 1 - Palavras prÃ©-definidas: ");
		//	printf("\n\n 2 - Palavra personalizada: ");
			printf("\n\n 2 - Sair: ");
		//	printf("\n\n OpÃ§Ã£o escolhida: ");
			scanf("%d", &opc);

			if (opc == 1) {
			
		
			cria();			
			char palavraJg[50] ;
			
				do {

					//system("clear");

					printf(
							"#################################### Forca #####################################");
					printf("\n\n Escolha o tema para jogar: ");
					printf("\n\n 1 - Animais: ");
					printf("\n\n 2 - Comida: ");
					printf("\n\n 3 - Frutas: ");
					printf("\n\n 4 - Profissao: ");
					printf("\n\n 5 - Informatica: ");
					printf("\n\n Tema escolhido: ");
					scanf(" %d", &tema);

				} while (tema < 1 || tema > 5);

				//Para gerar nÃºmeros aleatÃ³rios
				srand(time(NULL));

				switch (tema) {
				case 1:
					strcpy(dica, "Animal");
					//Seleciona uma palavra aleatÃ³ria
					strcpy(palavra, animal[rand() % NUM_ITENS]);
					strcpy(palavraJg, animal[rand() % NUM_ITENS]);
					insere(itPalavra,palavraJg);				
					break;
				case 2:
					strcpy(dica, "Comida");
					strcpy(palavra, comida[rand() % NUM_ITENS]);
					strcpy(palavraJg, animal[rand() % NUM_ITENS]);
					insere(itPalavra,palavraJg);
					break;
				case 3:
					strcpy(dica, "Fruta");
					strcpy(palavra, fruta[rand() % NUM_ITENS]);
					strcpy(palavraJg, animal[rand() % NUM_ITENS]);
					insere(itPalavra,palavraJg);
					break;
				case 4:
					strcpy(dica, "Profissao");
					strcpy(palavra, profissao[rand() % NUM_ITENS]);
					strcpy(palavraJg, animal[rand() % NUM_ITENS]);
					insere(itPalavra,palavraJg);
					break;
				case 5:
					strcpy(dica, "Informatica");
					strcpy(palavra, informatica[rand() % NUM_ITENS]);
					strcpy(palavraJg, animal[rand() % NUM_ITENS]);
					insere(itPalavra,palavraJg);
					break;
				default:
					break;
				}

			} 
			
			/*else if (opc == 2) {

				printf("\n Digite a dica: ");
				scanf(" %[^\n]", dica);
				printf("\n Digite a palavra a ser adivinhada: ");
				scanf(" %[^\n]", palavra);

				for (i = 0; i < strlen(palavra); i++) {
					palavra[i] = toupper(palavra[i]);
				}

			} */
			
			else if (opc == 3) {
				break;
			}

		} while (opc != 1 && opc != 3 && itPalavra->palavra!=NULL);

		if (opc != 3) {

			//Preenche a variÃ¡vel acertos com asteriscos, que representam caracteres desconhecidos
			for (i = 0; i < strlen(palavra); i++) {
				acertos[i] = '*';
			}

			acertos[strlen(palavra)] = '\0';

			while (strcmp(palavra, acertos) != 0 && erros != 6) {

				system("clear");

				printf(
						"#################################### Forca #####################################");
				printf("\n\n  Dica: %s   Letras usadas: ", dica);

				for (i = 0; i < numLetrasUsadas; i++) {
					printf("%c ", letrasUsadas[i]);

				}

				switch (erros) {
				case 0:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####            \n");
					printf("  ####            \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 1:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 2:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 3:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|    \n");
					printf("  ##       / |    \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 4:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\  \n");
					printf("  ##       / | \\ \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##              \n");
					printf("  ##              \n");
					break;
				case 5:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *o o*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\  \n");
					printf("  ##       / | \\ \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##        /     \n");
					printf("  ##       /      \n");
					break;
				case 6:
					printf("\n\n");
					printf("  ##########***##  \n");
					printf("  ####       *    \n");
					printf("  ####      ***   \n");
					printf("  ##       *X X*  \n");
					printf("  ##       * ^ *  \n");
					printf("  ##         *    \n");
					printf("  ##         |    \n");
					printf("  ##        /|\\   \n");
					printf("  ##       / | \\  \n");
					printf("  ##         |    \n");
					printf("  ##         |    \n");
					printf("  ##        / \\   \n");
					printf("  ##       /   \\  \n");
					break;
				}
				printf("  ##               \n");
				printf("  #######################\n\n  ");

				//Desenha os espaÃ§os para as letras
				for (i = 0; i < strlen(palavra); i++) {
					if (acertos[i] == '*') {
						printf("_ ");
					} else {
						printf("%c ", acertos[i]);
					}
				}

				if (strcmp(palavra, acertos) != 0 && erros != 6) {

					usada = 0;

					printf("\n\n  Digite seu palpite: ");
					scanf(" %c", &palpite);
					palpite = toupper(palpite);

					//checa se a letra jÃ¡ foi usada
					for (i = 0; i < 26; i++) {
						if (letrasUsadas[i] == palpite) {
							usada = 1;
						}
					}

					//Se nÃ£o foi usada
					if (usada == 0) {
						letrasUsadas[numLetrasUsadas] = palpite;
						numLetrasUsadas++;

						contemPalpite = 0;

						//Verifica se a palavra contÃ©m o palpite do usuÃ¡rio. A variÃ¡vel contemPalpite Ã© usada para o controle dos erros
						for (i = 0; i < strlen(palavra); i++) {
							if (palpite == palavra[i]) {
								acertos[i] = palpite;
								contemPalpite = 1;
							}
						}

						if (contemPalpite == 0) {
							erros++;
						}
					}

				}

			}

			if (erros == 6) {
				
				printf("\n  VocÃª perdeu! =(\n  A palavra era %s", itPalavra->palavra);				
				
			} else {
				printf("\n  VocÃª ganhou! :D A palavra era %s", itPalavra->palavra);
				
			}

			printf("\n\n  Digite alguma coisa para voltar ao menu!");
			scanf(" %c", &voltarMenu);
		}

	}

	return 0;
}




