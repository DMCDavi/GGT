//dados de ataque e defesa (apos ter add as tropas aos seus devidos territorios)
void ataque_defesa (){
	int qtd_comparacao, qtd_dados_ataque, qtd_dados_defesa; //variaveis q calculam a qtd de dados de ataque X defesa e dps comparam
	int cont_sorteio_dados, posicao_pais_encontrado_ataque, posicao_pais_encontrado_defesa, dado_ataque[3], dado_defesa[3]; //contadores para o for 
	int maior_ataque[3] = {0, 0, 0}, maior_defesa[3] = {0, 0, 0}; //vetores que armazenarao valores sorteados em ordem crescente
	char pais_desejado_atacante, pais_desejado_atacado;  //variaveis que receberao os nomes dos paises de ataque e defesa selecionados pelo player
	char resposta_ataque[4]; //resposta do novo ataque
	printf("%s, chegou a sua vez de atacar! Para pular essa parte digite 0! Senao, prossiga normalmente o jogo!\n\n");
	
	while (pais_desejado_atacante != '0' || pais_desejado_atacado != '0' || strcmp(resposta_ataque, "sim") == 0 || strcmp(resposta_ataque, "SIM") == 0){ // LOOPING DO ATAQUE
				
		printf("%s, Digite a letra do pais com o qual deseja atacar:\n", player[vez]);
		scanf("%c", &pais_desejado_atacante); //variavel que recebe o pais de ataque // ñ funciona assim "%s"
		fflush(stdin);		
		
		//verificacao se o país existe ou n
		//parte de verificacao de pertencimento do pais ao jogador :
		if(teste_dono_pais(pais_desejado_atacante)){ //caso o pais pertenca ao player q ataca...
									
			//relacionando com as tropas do pais que ataca correspondente
			if(pais_desejado_atacante >= 65 && pais_desejado_atacante <= 84){ //se a letra for maiuscula
				
				posicao_pais_encontrado_ataque = pais_desejado_atacante - 65;
				
			} else if(pais_desejado_atacante >= 97 && pais_desejado_atacante <= 116){ //se a letra for minuscula
				
				posicao_pais_encontrado_ataque = pais_desejado_atacante - 97;
				
			}
		
			//se pertencer ao jogador:
			//fara a verificacao se o numero de tropas eh suficiente para atacar
			if(tropas_pais[posicao_pais_encontrado_ataque] > 1) { //caso a qtd de tropas seja suficiente...
				//determinando a quantidade de dados maximo do jogador
				if(tropas_pais[posicao_pais_encontrado_ataque] == 2) qtd_dados_ataque = 1; //para 1 dado
				else if(tropas_pais[posicao_pais_encontrado_ataque] == 3) qtd_dados_ataque = 2; // para 2 dados
				else if(tropas_pais[posicao_pais_encontrado_ataque] >=4) qtd_dados_ataque = 3; // para 3 dados
				
				//selecionando quem vai ser atacado
				printf("%s, digite a letra do pais adversario que voce deseja atacar:\n", player[vez]);
				scanf("%c", &pais_desejado_atacado);
				fflush(stdin);
				
				// verificando pertencimento de do pais a ser atacado (inimigo)
				if (!teste_dono_pais(pais_desejado_atacado) && teste_vizinhanca_pais(pais_desejado_atacante, pais_desejado_atacado)) { //se pertencer ao inimigo e for vizinho
					//caso o pais atacado pertenca ao player q defende...
					
					
					//relacionando com as tropas do pais correspondente
					if(pais_desejado_atacado >= 65 && pais_desejado_atacado <= 84){ //se a letra for maiuscula
				
						posicao_pais_encontrado_defesa = pais_desejado_atacado - 65;
				
					} 
					else if(pais_desejado_atacado >= 97 && pais_desejado_atacado <= 116){ //se a letra for minuscula
				
						posicao_pais_encontrado_defesa = pais_desejado_atacado - 97;
				
					}
					
				
					//determinando a quantidade de dados para defesa do inimigo
					if(tropas_pais[posicao_pais_encontrado_defesa] == 1) { //para 1 dado
						qtd_dados_defesa = 1;
					}
					else if (tropas_pais[posicao_pais_encontrado_defesa] == 2){ // para 2 dados
			 			qtd_dados_defesa = 2;
					}
					else if (tropas_pais[posicao_pais_encontrado_defesa] >= 3){ // para 3 dados
						qtd_dados_defesa = 3;
					}			
				
				
					//sorteando dados do ATAQUE
					for (cont_sorteio_dados=0; cont_sorteio_dados<qtd_dados_ataque; cont_sorteio_dados++){
						srand(time(NULL));
						dado_ataque[cont_sorteio_dados] = (rand() % 5) + 1;
						//printf("%d ", dado_ataque[cont_sorteio_dados]);
					}
	
					//colocando em ORDEM CRESCENTE os numeros sorteados pelos dados de ataque
					if (qtd_dados_ataque == 3){ //para 3 dados de ataque
						if (dado_ataque[0] < dado_ataque[1]) { //a<b 0<1
							if(dado_ataque[1] > dado_ataque[2]){ //a<b e c<b 0<1 e 2<1
								if (dado_ataque[0] > dado_ataque[2]){ //c<a<b 2<0<1
									maior_ataque[0] = dado_ataque[2];
									maior_ataque[1] = dado_ataque[0];			 
								}
								if(dado_ataque[0] < dado_ataque[2]){ //a<c<b 0<2<1
									maior_ataque[0] = dado_ataque[0];
									maior_ataque[1] = dado_ataque[2];
								}
								maior_ataque[2] = dado_ataque[1];
							}
						}
						else if(maior_ataque[1] < maior_ataque[0]){ //b<a 1<0
							if(maior_ataque[1] < maior_ataque[2] ) {//b<c 1<2
								if (maior_ataque[2] < maior_ataque[0]){ //b<c<a 1<2<0
									maior_ataque[1] = dado_ataque[2];
									maior_ataque[2] = dado_ataque[0];
								}
								else if (maior_ataque[2] > maior_ataque[0]){ //b<a<c 1<0<2
									maior_ataque[1] = dado_ataque[0];
									maior_ataque[2] = dado_ataque[2];
								}
								maior_ataque[0] = dado_ataque[1];
							}
							
							else if(dado_ataque[1] > dado_ataque[2]){ // c<b 2<1 ---> c<b<a 2<1<0
								maior_ataque[0] = dado_ataque[2];
								maior_ataque[1] = dado_ataque[1];
								maior_ataque[2] = dado_ataque[0];
							}
						}
						
						else{ //a<b<c 0<1<2
							maior_ataque[0] = dado_ataque[0];
							maior_ataque[1] = dado_ataque[1];
							maior_ataque[2] = dado_ataque[2];
						}					
					}
					
					
						if (qtd_dados_ataque == 2){ //para 2 dados de ataque
							if(dado_ataque[0] > dado_ataque[1]){ // b<a 1<0
								maior_ataque[1] = dado_ataque[1];
								maior_ataque[2] = dado_ataque[0];
							}
							else{ // a<b 0<1
								maior_ataque[1] = dado_ataque[0];
								maior_ataque[2] = dado_ataque[1];
							}		
						}
						
						if(qtd_dados_ataque == 1){ //para apenas 1 dado de ataque
							maior_ataque[2]= dado_ataque[0];
						}
								
			
			
					//sorteando dados da DEFESA
					for (cont_sorteio_dados = 0; cont_sorteio_dados < qtd_dados_defesa; cont_sorteio_dados++){
						srand(time(NULL));
						dado_defesa[cont_sorteio_dados] = (rand() % 5) + 1;
						//printf("%d ", dado_defesa[cont_sorteio_dados]);
					}
		
					//colocando em ordem crescente os numeros sorteados pelos dados de defesa
						if (qtd_dados_defesa == 3){ //para 3 dados de defesa
							if (dado_defesa[0] < dado_defesa[1]) { //a<b 0<1
								if(dado_ataque[1] > dado_ataque[2]){ //a<b e c<b 0<1 e 2<1
									if (dado_defesa[0] > dado_defesa[2]){ //c<a<b 2<0<1
										maior_defesa[0] = dado_defesa[2];
										maior_defesa[1] = dado_defesa[0];			 
									}
									else if(dado_defesa[0] < dado_defesa[2]){ //a<c<b 0<2<1
										maior_defesa[0] = dado_defesa[0];
										maior_defesa[1] = dado_defesa[2];
									}
									maior_defesa[2] = dado_defesa[1];
								}								
							}
							else if(maior_ataque[1] < maior_ataque[0]){ //b<a 1<0
								if(maior_defesa[1] < maior_defesa[2] ) {//b<c 1<2
									if (maior_defesa[2] < maior_defesa[0]){ //b<c<a 1<2<0
										maior_defesa[1] = dado_defesa[2];
										maior_defesa[2] = dado_defesa[0];
									}
									else if (maior_ataque[2] > maior_defesa[0]){ //b<a<c 1<0<2
									maior_defesa[1] = dado_defesa[0];
									maior_defesa[2] = dado_defesa[2];
									}
									maior_defesa[0] = dado_defesa[1];
								}
								else if(dado_defesa[1] > dado_defesa[2]){ // c<b 2<1 ---> c<b<a 2<1<0
									maior_defesa[0] = dado_defesa[2];
									maior_defesa[1] = dado_defesa[1];
									maior_defesa[2] = dado_defesa[0];
								}
							}
						
							else{ //a<b<c 0<1<2
								maior_defesa[0] = dado_defesa[0];
								maior_defesa[1] = dado_defesa[1];
								maior_defesa[2] = dado_defesa[2];
							}
						}
	
	
							if (qtd_dados_defesa == 2){ //para 2 dados de defesa
								if(dado_defesa[0] > dado_defesa[1]){ // b<a 1<0
									maior_defesa[1] = dado_defesa[1];
									maior_defesa[2] = dado_defesa[0];
								}
								else{ // a<b 0<1
									maior_defesa[1] = dado_defesa[0];
									maior_defesa[2] = dado_defesa[1];
								}						
							}
						
							if(qtd_dados_defesa == 1){ //para apenas 1 dado de defesa
								maior_defesa[2]= dado_defesa[0];
							}
								
	
					//comparando e imprimindo valores de ataque e defesa (quem ganha/perde territorio)
				
					if(qtd_dados_ataque>=qtd_dados_defesa){
						qtd_comparacao = qtd_dados_defesa;
					}
					else{
						qtd_comparacao = qtd_dados_ataque;
					}					
					if(strcmp(player[vez], player1) == 0){
						printf("\n\n\t%s\tx\t%s\n", player1, player2);
					}
					else if(strcmp(player[vez], player2) == 0){
						printf("\n\n\t%s\tx\t%s\n", player2, player1);
					}
					for(cont_sorteio_dados=2; cont_sorteio_dados > qtd_comparacao; cont_sorteio_dados--){
						printf("\t%d\tx\t%d\n", maior_ataque[cont_sorteio_dados], maior_defesa[cont_sorteio_dados]);
						if(maior_ataque[cont_sorteio_dados] <= maior_defesa[cont_sorteio_dados]){ //ganho defesa
							tropas_pais[posicao_pais_encontrado_ataque] = tropas_pais[posicao_pais_encontrado_ataque] -1;
						}
						else{ //ganho ataque
							tropas_pais[posicao_pais_encontrado_defesa] = tropas_pais[posicao_pais_encontrado_defesa] - 1;
							if(tropas_pais[posicao_pais_encontrado_defesa] == 0){ //se o a defesa nao tiver mais tropas...
								if(strcmp(player[vez], player1) == 0){ //se for a vez do player 1
									pais[posicao_pais_encontrado_defesa][0] = '1'; //player1 conquista o territorio do player2
								}
								else if(strcmp(player[vez], player2) == 0){ //se for player 2 
									pais[posicao_pais_encontrado_defesa][0] = '2'; //player2 conquista o territorio do player1
								}			
								
							}
						}						
					}
					//atualizando o mapa...
					system("cls"); //limpando a tela
					print_mapa(); //reimprime o mapa

										
				
					/*if(cont_vitoria_ataque <= cont_vitoria_defesa){
						printf("%s, vc nao obteve sucesso nesse ataque!\n", player[vez]);	
					}
					else{
						printf("%s, vc obteve sucesso nesse ataque!\n", player[vez]);	
					}*/
					
					//perguntando se deseja novo ataque
					printf("\nDeseja atacar novamente? [SIM][NAO]\n");
					scanf("%s", resposta_ataque);
		
						
				}//FIM IF PERTENCIMENTO AO INIMIGO
	
				else{ //caso o pais nao pertenca ao inimigo
					printf("[ERRO] NAO EH POSSIVEL SELECIONAR ESSE PAIS! Por favor, tente outro.\n");
				}
		
			} //FIM IF QTD DE TROPAS > 1
		
			else if(tropas_pais[posicao_pais_encontrado_ataque] == 1){//caso a quantidade de tropas seja insuficiente
				printf("[ERRO] NUMERO DE TROPAS INSUFICIENTE PARA ATAQUE! Por favor, tente outro.\n");
			}
		
		} //FIM IF PERTENCIMENTO  DO PAIS ATACANTE
		
		else //if(teste_dono_pais(pais_desejado_atacante) || teste_existencia_pais(pais_desejado_atacante)){ //caso o pais ÃƒÂ± pertenÃƒÂ§a ao jogador q estÃƒÂ¡ jogando
		{	printf("[ERRO] ESSE PAIS NAO TE PERTENCE! Por favor, tente outro.\n");
		}	
					
	} //fim do while do ataque
	//chamar funcao de remanejamento de tropas
	
}//fim da funcao (void)	