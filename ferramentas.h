//Essa biblioteca contÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©m as funÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âµes que serÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o usadas como ferramentas ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âºteis ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â s outras


void text_color(int color){
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	
}

void print_mapa(){ 
	//funÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o que printa na tela o mapa
	//system("color 1F"); 
	//define as cores do mapa
	text_color(15);
	printf("========================================================================================================================================================================\n");
	int cont_tropas = 0, cont_linhas, cont_colunas, cont_pais = 0, mapa[40][75] = {
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,7,0,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,5,2,2,2,6,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
3,3,3,3,3,3,3,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,7,0,7,3,7,0,7,7,0,7,7,0,7,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,8,2,2,2,9,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,5,2,2,2,6,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,3,7,0,7,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,8,2,2,2,9,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,1,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,3,3,3,7,0,7,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,7,0,7,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,0,7,4,4,4,4,4,4,4,4,4,4,5,2,2,2,6,5,2,2,2,6,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,4,4,4,4,4,4,4,4,4,4,7,0,7,7,0,7,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,2,2,2,9,8,2,2,2,9,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
4,4,4,4,4,4,4,4,4,4,4,4,4,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
};
	//NOTA MENTAL PARA JOAO COLOCAR UM TEXT COLOR EM CADA QUE AI DA CERTO PORA;
	
	for(cont_linhas = 0; cont_linhas < 40; cont_linhas++ ){ 
		//percorre a matriz mapa toda e substitui seus valores por um caracter especial
		for(cont_colunas = 0 ; cont_colunas < 75; cont_colunas++ ){
			
			if(mapa[cont_linhas][cont_colunas] == NEVE){
				text_color(2);
				printf("%c%c",219,219);
					
			}else if(mapa[cont_linhas][cont_colunas] == AGUA){
				text_color(1);
				printf("%c%c",32,32);
										
			}else if(mapa[cont_linhas][cont_colunas] == HORIZONTAL){
				text_color(15);
				printf("%c%c",205,205);
										
			}else if(mapa[cont_linhas][cont_colunas] == VERTICAL){
				text_color(15);
				printf("%c%c",186,186);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTINFESQ){
				text_color(15);
				printf("%c%c",200,200);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTINFDIR){
				text_color(15);
				printf("%c%c",188,188);
										
			}else if(mapa[cont_linhas][cont_colunas] == CANTSUPESQ){
				text_color(15);
				printf("%c%c",201,201);	
									
			}else if(mapa[cont_linhas][cont_colunas] == CANTSUPDIR){
				text_color(15);
				printf("%c%c",187,187);
										
			}else if(mapa[cont_linhas][cont_colunas] == CAMINHOHOR){
				text_color(15);
				printf("%c%c",196,196);	
									
			}else if(mapa[cont_linhas][cont_colunas] == CAMINHOVER){
				text_color(15);
				printf("%c%c",124,124);	
									
			}else if(mapa[cont_linhas][cont_colunas] == PAIS){
				//condicionais que permitem printar a cor respectiva do player
				if(pais[cont_pais][0] == '1'){
					text_color(2);
					printf("%s%.3d", pais[cont_pais], tropas_pais[cont_tropas]);
					cont_pais++;
					cont_tropas++;
				}else if(pais[cont_pais][0] == '2'){
					text_color(1);	
					printf("%s%.3d", pais[cont_pais], tropas_pais[cont_tropas]);
					cont_pais++;
					cont_tropas++;
				}
			}
				
		}printf("\n");
				
	}text_color(15); 
	printf("========================================================================================================================================================================\n");
	
}

bool teste_dono_pais(char letra){ 
	//funcao que testa se o pais pertence ao player ou nao, retornando true ou false
	bool true_false = true; 
	//essa variavel fica armazenada como true, pois caso a letra digitada nao se refira a nenhum pais, o codigo ira continuar, ja que o erro do usuario nao foi selecionar uma pais que nao eh seu, mas sim um pais que nem existe
	int cont_matriz_pais; 
	//variavel contadora que percorrer a matriz pais[21][4]
	if(letra >= 97 && letra <= 116){ 
	//se a letra for minuscula de acordo com a tabela ascii, ela sera tranformada em maiuscula para poder ser comparada com a letra do pais na matriz pais[21][4]
		letra = letra - 32; 
		//transforma a letra minuscula em maiuscula
	}
	
	for(cont_matriz_pais = 0; cont_matriz_pais < 21; cont_matriz_pais++){ 
	//percorre os 20 paises da matriz pais[21][4]
		if(pais[cont_matriz_pais][1] == letra){ 
		//caso encontre a letra digitada, prosseguira a anÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¡lise
			if(strcmp(player[vez], player1) == 0){ 
			//a analise continua se a vez da rodada for do jogador 1
				if(pais[cont_matriz_pais][0] == '1'){ 
				//se o numero encontrado no pais tiver a numeracao 1, a funcao retornara true, senao retornara false
					true_false = true;
					
					break; 
					//para de percorrer a matriz caso a resposta seja obtida
				} else{
					
					true_false = false;
					
					break; 
					//para de percorrer a matriz caso a resposta seja obtida
				}
			
			} else if(strcmp(player[vez], player2) == 0){ 
			//a analise continua se a vez da rodada for do jogador 2 
				if(pais[cont_matriz_pais][0] == '2'){
				//se o numero encontrado no pais tiver a numeracao 2, a funcao retornara true, senao retornara false
					
					true_false = true;
					
					break; 
					//para de percorrer a matriz caso a resposta seja obtida
				} else{
					
					true_false = false;
					
					break;
					//para de percorrer a matriz caso a resposta seja obtida
				}
				
			}
			
		}
		
	}
	
	return true_false;
}

bool teste_existencia_pais(char letra){ 
//funcao que testa se a letra digitada esta entre A e T maiusculo ou minusculo
	
	bool true_false;
	
	if((letra >= 65 && letra <= 84) || (letra >= 97 && letra <= 116)){
		
		true_false = true;
		
	} else{
		
		true_false = false;
		
	} return true_false;
		
}

bool teste_vizinhanca_pais(char pais_origem, char pais_destino){
	
	bool true_false;
	
	if(pais_origem >= 97 && pais_origem <= 116){ 
	//se a letra for minuscula de acordo com a tabela ascii, ela sera tranformada em maiuscula para poder ser comparada posteriormente
		pais_origem = pais_origem - 32; 
		//transforma a letra minuscula em maiuscula
	} if(pais_destino >= 97 && pais_destino <= 116){ 
	//se a letra for minuscula de acordo com a tabela ascii, ela sera tranformada em maiuscula para poder ser comparada posteriormente
		pais_destino = pais_destino - 32; 
		//transforma a letra minuscula em maiuscula
	} if(pais_origem == 'A'){
	//se o pais de origem for letra 'A', tera como vizinhos os paises 'C' e 'D'
		if(pais_destino == 'C' || pais_destino == 'D'){
		//caso o pais de destino seja um de seus vizinhos, true_false recebera true
			true_false = true;
			
		} else{
		//senao, recebera false	
			true_false = false;
			
		}
		
	} else if(pais_origem == 'B'){
	//a mesma verificacao eh feita para todos os outros paises para checar a vizinhanca
		if(pais_destino == 'H' || pais_destino == 'C' || pais_destino == 'I'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'C'){
		
		if(pais_destino == 'A' || pais_destino == 'B'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'D'){
		
		if(pais_destino == 'A' || pais_destino == 'E'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'E'){
		
		if(pais_destino == 'D' || pais_destino == 'F' || pais_destino == 'J'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}	
		
	} else if(pais_origem == 'F'){
		
		if(pais_destino == 'E' || pais_destino == 'G' || pais_destino == 'K'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'G'){
		
		if(pais_destino == 'F' || pais_destino == 'H' || pais_destino == 'L'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'H'){
		
		if(pais_destino == 'G' || pais_destino == 'B' || pais_destino == 'M'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'I'){
		
		if(pais_destino == 'B' || pais_destino == 'N'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'J'){
		
		if(pais_destino == 'E' || pais_destino == 'K' || pais_destino == 'P'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'K'){
		
		if(pais_destino == 'J' || pais_destino == 'F' || pais_destino == 'L'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'L'){
		
		if(pais_destino == 'K' || pais_destino == 'G' || pais_destino == 'M'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'M'){
		
		if(pais_destino == 'H' || pais_destino == 'L' || pais_destino == 'S'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'N'){
		
		if(pais_destino == 'I' || pais_destino == 'Q' || pais_destino == 'O'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'O'){
		
		if(pais_destino == 'N' || pais_destino == 'P'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'P'){
		
		if(pais_destino == 'O' || pais_destino == 'R' || pais_destino == 'J'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'Q'){
		
		if(pais_destino == 'N'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'R'){
		
		if(pais_destino == 'P'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'S'){
		
		if(pais_destino == 'T' || pais_destino == 'M'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} else if(pais_origem == 'T'){
		
		if(pais_destino == 'S'){
			
			true_false = true;
			
		} else{
			
			true_false = false;
			
		}
		
	} return true_false;

}

bool bonus_tropas_pais(){ 
	//funcao que adiciona a quantidade de tropas bonus de cada continente e retorna um bool para saber se existe bonus de tropas ou nao
	bool true_false = false;
	char continente[17];
	
	if(pais[0][0] == '1' && pais[1][0] == '1' && pais[2][0] == '1' && pais[8][0] == '1'){
	//caso os paises 'A', 'B', 'C' e 'I' estejam sob controle do player 1, este recebera 5 tropas de bonus por dominar a America do Norte
		qntd_tropas_bonus_player1 += 5;
		
		//continente = "America do Norte";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player1, continente);

		true_false = true;
		
		
		//caso exista bonus de tropas por continente, true_false recebera true. Isso serve para saber se ira existir bonus de tropas ou nao
	} else if(pais[0][0] == '2' && pais[1][0] == '2' && pais[2][0] == '2' && pais[8][0] == '2'){
		//a mesma verificacao ocorre para o player 2
		qntd_tropas_bonus_player2 += 5;
		
		//continente = "America do Norte";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player2, continente);

		true_false = true;
		
	} if(pais[3][0] == '1' && pais[4][0] == '1' && pais[9][0] == '1'){
		//a mesma verificacao ocorre para todos os outros continentes. Essa eh a Europa
		qntd_tropas_bonus_player1 += 5;
		
		//continente = "Europa";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player1, continente);

		
		true_false = true;
	
	} else if(pais[3][0] == '2' && pais[4][0] == '2' && pais[9][0] == '2'){
		
		qntd_tropas_bonus_player2 += 5;
		
		//continente = "Europa";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player2, continente);
		
		true_false = true;
		
	} if(pais[5][0] == '1' && pais[6][0] == '1' && pais[7][0] == '1' && pais[10][0] == '1' && pais[11][0] == '1' && pais[12][0] == '1'){
		//essa eh a Asia
		qntd_tropas_bonus_player1 = 7;
		
		//continente = "Asia";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player1, continente);

		
		true_false = true;
	
	} else if(pais[5][0] == '2' && pais[6][0] == '2' && pais[7][0] == '2' && pais[10][0] == '2' && pais[11][0] == '2' && pais[12][0] == '2'){
		
		qntd_tropas_bonus_player2 = 7;
		
		//continente = "Asia";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player2, continente);
		
		true_false = true;
		
	} if(pais[13][0] == '1' && pais[16][0] == '1'){
		//Essa eh a America do Sul
		qntd_tropas_bonus_player1 = 2;
		
		//continente = "America do Sul";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player1, continente);
		
		true_false = true;
	
	} else if(pais[13][0] == '2' && pais[16][0] == '2'){
		
		qntd_tropas_bonus_player2 = 2;
		
		//continente = "America do Sul";
		
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player2, continente);
		
		true_false = true;
		
	} if(pais[14][0] == '1' && pais[15][0] == '1' && pais[17][0] == '1'){
		//Essa eh a Africa
		qntd_tropas_bonus_player1 = 3;
		
		//continente = "Africa";
	
		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player1, continente);

		true_false = true;
	
	} else if(pais[14][0] == '2' && pais[15][0] == '2' && pais[17][0] == '2'){
		
		qntd_tropas_bonus_player2 = 3;
		
		//continente = "Africa";

		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player2, continente);

		true_false = true;
		
	} if(pais[18][0] == '1' && pais[19][0] == '1'){
		//Essa eh a Oceania
		qntd_tropas_bonus_player1 = 2;
		
		//continente = "Oceania";

		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player1, continente);

		true_false = true;
	
	} else if(pais[18][0] == '2' && pais[19][0] == '2'){
		
		qntd_tropas_bonus_player2 = 2;
		
		//continente = "Oceania";

		printf("\t\t\t\t\t %s, voce ainda possui %d tropas adicionais por conquistar %s! Mas so pode adiciona-las nesse continente! \n ", player[vez], qntd_tropas_bonus_player2, continente);

		true_false = true;
		
	} return true_false;
	
}
void contar_paises(){
		
	qntd_paises_player1 = 0;
	
	qntd_paises_player2 = 0	;
		
	int cont_num_pais;
	
	for(cont_num_pais = 0; cont_num_pais < 21; cont_num_pais++){ //percorre a matriz pais[21][4] em busca dos numeros 1 e 2 que definirÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â£o a que player cada pais pertence
		
		if(pais[cont_num_pais][0] == '1'){ //se o pais tiver o numero 1, a variavel qntd_paises_player1 vai aumentar em 1
			
			qntd_paises_player1++;
			
		} else if(pais[cont_num_pais][0] == '2'){ //se o pais tiver o numero 2, a variavel qntd_paises_player2 vai aumentar em 1
			
			qntd_paises_player2++;
			
		}
	
	}
	
}
