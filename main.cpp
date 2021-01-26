//Filipe Soares Fernandes - 0022921
//P�mela Evelyn Carvalho - 0015669

#include <iostream> // Biblioteca padr�o
#include <stdlib.h> // Utilizado na rand e srand
#include <time.h> // Utilizado na fun��o time

using namespace std;

void preencher_matriz_com_agua(char matriz[][10]) // Esta fun��o preenche a matiz com �gua
{

    for(int i=0; i<10; i++) // for percorre a linha da matriz
    {
        for(int j=0; j<10; j++) // for percorre a coluna da matriz
        {
            matriz[i][j] = '~'; // as respectivas posi��es da matriz s�o preenchidas com �gua
        }
    }
}

void mostra_matriz( char matriz[][10]) // Esta fun��o mostra a matriz
{
    cout << "  ";

    for(int i=0; i<10; i++) // Mostra as posi��es da coluna
    {
        cout << i ;
    }
    cout << "\n";
    cout << "\n";

    for(int i=0; i<10; i++) // Percorre a linha da matriz
    {
        cout << i << " "; // Mostra o n�mero da linha

        for(int j=0; j<10; j++) // Percorre a coluna
        {
            cout << matriz[i][j]; // Mostra a �gua ~
        }
        cout << "\n";
        cout << "\n";
    }
}

int sorteio_das_embarcacoes() // Esta fun��o sorteia as embarca��es
{
    int recebe_a_embarcacao_sorteada = rand()% 5 + 1; // Aqui � sorteado uma entre as cinco embarca��es

    return recebe_a_embarcacao_sorteada; // Retorna a embarca��o sorteada
}

int sorteio_linha() // Esta fun��o sorteia uma linha da matriz
{
    int linha = rand()% 10; // Aqui � sorteado uma entre as dez linhas da matriz

    return linha; // Retornar a linha sorteada
}
int sorteio_coluna() // Esta fun��o sorteia uma coluna da matriz
{
    int coluna = rand()% 10; // Aqui � sorteada uma coluna entre as dez linhs da matriz

    return coluna; // Retornar a linha sorteada
}

bool cabe_a_embarcacao(char matriz[][10],int embarcacao,int linha,int coluna) // Esta fun��o verifica se a embarca��o cabe na matriz
{
    /*submarino = 1;
    cruzador = 2;
    destroyer =3;
    encouracado =4;
    porta_avioes = 5;*/

    bool test = false; // A fun��o recebe falso

    if( embarcacao == 1  && matriz[linha][coluna+1]== '~' ) // Se a embarca��o � um submarino e se na coluna a direita tem �gua
    {
        test = true; // Se as duas condi��es forem aceitas, a fun��o recebe verdadeira, a embarca��o cabe na matriz
    }

    if (embarcacao == 2 && coluna <9) // Se embarca��o � um cruzador e delimita que ela n�o pode ser colocada em uma coluna maior que 8
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~') // Verifica se na linha e coluna inserida tem �gua, se na coluna +1 tem �gua e se na coluna +2 tem �gua
        {
            test = true; // Se essas condi��es acima forem respeitadas, a fun��o retorna verdadeiro, a embarca��o cabe na matriz
        }
    }

    if (embarcacao == 3 && coluna <8) // Se a embarca��o � um  cruzador e delimita que a embarca��o n�o pode ser inserida em uma coluna maior que 7
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~' && matriz[linha][coluna +3] == '~') // Verifica se todas as posi��es ocupadas pela embarca��o s�o �gua, e se uma posi��o depois da embarca��o � �gua
        {
            test = true; // Se essas condi��es acima forem respeitadas, a fun��o retorna verdadeiro, e a embarca��o cabe na matriz
        }
    }

    if (embarcacao == 4 && coluna <7) // Se a embarca��o � um  encoura�ado e delimita que ela n�o pode ser colocada em uma coluna maior que 6
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~' && matriz[linha][coluna +3] == '~' && matriz[linha][coluna +4]=='~') // Verifica se todas as posi��es da embarca��o s�o �gua e se uma coluna a direita dessa embarca��o � agua
        {
            test = true; // Se essas condi��es acima forem respeitadas, a fun��o retorna verdadeiro, e a embarca��o cabe na matriz
        }
    }

    if (embarcacao == 5 && coluna <6) // Se a embarca��o � um  encoura�ado e delimita que ela n�o pode ser colocada em uma coluna maior que 5
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~' && matriz[linha][coluna +3] == '~' && matriz[linha][coluna +4]=='~' && matriz[linha][coluna +5]=='~')
        {
            test = true; // Se essas condi��es acima forem respeitadas, a fun��o retorna verdadeiro, e a embarca��o cabe na matriz
        }
    }
    return test; // Retorna o valor do teste
}

bool insere_a_embarcacao_na_matriz( char matriz[][10],int embarcacao, int coluna, int linha) // Esta fun��o insere a embarca��o na matriz
{
    bool test= false; // Teste recebe falso
    if(embarcacao == 1) // Se a embarca��o � um sobmarino
    {
        matriz [linha][coluna] = 's'; // matriz[linha][coluna] selecionada recebem s
        test= true; // teste recebe verdadeiro
    }
    if (embarcacao == 2) // Se a embarca��o � um cruzador
    {
        for(int i=coluna; i<= coluna +1; i++ ) // este for percorrerar a coluna at� o tamanho da embarca��o
        {
            matriz[linha][i]= 'c'; // matriz [coluna][linha] selecionada recebe c e matriz[linha][coluna +1] recebe c
        }
        test = true; // teste recebe verdadeiro
    }
    if (embarcacao == 3) // Se a embarca��o destroyer
    {
        for(int i=coluna; i<=coluna +2; i++) // Este for percorre a coluna at� o tamanho da embarca��o
        {
            matriz [linha][i] = 'd'; // matriz[linha][coluna] recebe d e matriz [linha][coluna +1] recebe  d e [linha][coluna +2] recebe d
        }
        test = true; // teste recebe verdadeiro
    }
    if(embarcacao == 4) // Se a embarca��o encoura�ado
    {
        for(int i=coluna; i<=coluna+3; i++) // Este for percorre a coluna at� o tamanho da embarca��o
        {
            matriz[linha][i]='e'; // matriz[linha][coluna] recebe "e" e matriz [linha][coluna +1] recebe  "e" e [linha][coluna +2] recebe e
        }

        test = true; // teste recebe verdadeiro
    }
    if(embarcacao ==5) // Se a embarca��o port�o-avi�es
    {
        for (int i=coluna; i<=coluna+4; i++) // Este for percorre a coluna at� o tamanho da embarca��o
        {
            matriz[linha][i]='p'; // matriz[linha][coluna] recebe p e matriz [linha][coluna +1] recebe  p e [linha][coluna +2] recebe p
        }
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o valor do teste
}

bool verificar_se_pode_ser_inserido(char matriz[][10],int embarcacao) // Esta fun��o verifica se a embarca��o ode ser inserida na matriz
{
    int coluna = sorteio_coluna(); // sorteia uma coluna da matriz
    int linha = sorteio_linha(); // sorteia uma linha da matriz
    bool test = false; // teste recebe falso
    if(coluna == 0  && cabe_a_embarcacao(matriz,embarcacao,linha,coluna) == true) // Se a coluna for igual a zero, e a embarca��o cabe
    {
        if (insere_a_embarcacao_na_matriz(matriz,embarcacao,coluna,linha)==true) // Insere a embarca��o na matriz e recebe verdadeiro
            test = true; // teste recebe verdadeiro
    }
    if(coluna ==9 && matriz[linha][coluna -1 ] =='~'&& cabe_a_embarcacao(matriz,embarcacao,linha,coluna) == true) // Se a coluna for igual a 9 e matriz[linha][coluna -1] igual a �gua e cabe
    {
        matriz[linha][coluna] = 's'; // insere submarino
        test = true; // teste recebe verdadeiro
    }
    if(matriz[linha][coluna -1] == '~' && cabe_a_embarcacao(matriz,embarcacao,linha,coluna) == true) // Se a matriz [linha][coluna -1] � �gua e cabe
    {
        if (insere_a_embarcacao_na_matriz(matriz,embarcacao,coluna,linha)==true) //  embarca��o vai ser verdadeira
            test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}

void insere_uma_embarcacao_de_cada (char matriz[][10]) //Esta fun��o insere uma embarca��o de cada na matriz, pois, � neces�rio ter pelo menos uma embarca��o de cada
{
    int vetor[5]; // vetor com 5 posi��es

    for(int i =0; i<5 ; i++) // Este for percorre as cinco posi��es do vetor
    {
        vetor[i] = sorteio_das_embarcacoes(); // O vetor [i] recebe a embarca��o sorteada

        if(i==1) // Se a embarca��o � um submarino
        {
            while (vetor[i-1] == vetor[i]) // verifica se o modelo dessa embarca��o j� foi sorteado
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor [i] recebe a embarca��o
            }
        }

        if(i==2) // Se a embarca��o � um cruzador
        {
            while (vetor[i-1]==vetor[i]  || vetor[i-2] == vetor[i]) // verifica se o modelo dessa embarca��o j� foi sorteado, sen�o sorteia novamente
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor [i] recebe a embarca��o
            }
        }

        if(i==3) // Se a embarca��o � um destroyer
        {
            while (vetor[i-1]==vetor[i]  || vetor[i-2]==vetor[i] || vetor[i-3] == vetor[i]) // verifica se o modelo dessa embarca��o j� foi sorteado, sen�o sorteia novamente
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor [i] recebe a embarca��o
            }
        }
        if(i==4) // Se a embarca��o encoura�ado
        {
            while (vetor[i-1]==vetor[i]  || vetor[i-2]==vetor[i] || vetor[i-3]==vetor[i] || vetor [i-4]== vetor[i]) // verifica se o modelo j� foi sorteado, sen�o sorteia novamente
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor[i] recebe a embarca��o
            }
        }
    }
    for(int i=0; i<5; i++) // for percorre as  5 posi��es do vetor
    {
        bool  verificancando_se_pode_ser_inserido = verificar_se_pode_ser_inserido(matriz,vetor[i]); // A vari�vel boolleana recebe o retorno d fun��o verificar se pode ser inserido, passando com o parametro a matriz e a embarca��o que esta na posi��o "i" do vetor

        while(verificancando_se_pode_ser_inserido != true ) // Enquanto o retorno for falso
        {
            verificancando_se_pode_ser_inserido = verificar_se_pode_ser_inserido(matriz,vetor[i]); // � feito uma nova tentativa de inser��o
        }
    }
}

bool verifica_se_afundou_submarino(char matriz[][10],int linha ,int coluna) // Fun��o que verifica se afundou um submarino
{
    bool test = false; // teste recebe falso
    if (matriz[linha][coluna] == 's') // Se a matriz[linha][coluna] for igual ao submarino
    {
        test = true; // teste reebe verdadeiro
    }
    return test; // retorna o teste
}

bool verifica_se_afundou_cruzador(char matriz[][10], int linha, int coluna) // Fun��o que verifica se afundou um cruzador
{
    bool test = false; // teste recebe falso
    if((matriz[linha][coluna]== 'c'&& matriz[linha][coluna +1]== 'c') || (matriz [linha][coluna]=='c' && matriz [linha][coluna -1]=='c')) // Verifica se em todas as posi��es adjacentes a linha e a coluna possuem um peda�o do cruzador (respeitando o tamanho deste)
    {
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}

bool verifica_se_afundou_destroyer(char matriz[][10],int linha,int coluna) // Fun��o que verifica se afundou um destroyer
{
    bool test = false; // teste recebe falso
    if((matriz [linha][coluna]== 'd'&& matriz [linha][coluna +1]== 'd' && matriz [linha][coluna +2]== 'd') || (matriz [linha][coluna]== 'd' && matriz[linha][coluna -1]== 'd' && matriz [linha][coluna -2]== 'd') ||
            (matriz [linha][coluna] == 'd' && matriz [linha][coluna -1]== 'd' && matriz[linha][coluna +1]== 'd')) //  // Verifica se em todas as posi��es adjacentes a linha e a coluna possuem um peda�o do destroyer (respeitando o tamanho deste)
    {
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}
bool verifica_se_afundou_encouracado (char matriz [][10],int linha,int coluna) // Fun��o que verifica se afundou um encoura�ado
{
    bool test = false; // teste recebe falso
    if ((matriz [linha][coluna] == 'e' && matriz [linha][coluna +1 ]== 'e' && matriz [linha][coluna +2]== 'e' && matriz [linha][coluna +3]== 'e') ||(matriz [linha][coluna]=='e' && matriz [linha][coluna -1]== 'e' && matriz[linha][coluna -2]== 'e' && matriz[linha][coluna -3]== 'e') ||
            (matriz [linha][coluna]=='e' && matriz[linha][coluna +1]=='e' && matriz [linha][coluna +2]=='e' && matriz[linha][coluna -1] == 'e') || (matriz[linha][coluna]=='e' && matriz [linha][coluna +1]=='e' && matriz[linha][coluna -1]=='e' && matriz[linha][coluna -2]== 'e'))  // Verifica se em todas as posi��es adjacentes a linha e a coluna possuem um peda�o do encoura�ado (respeitando o tamanho deste
    {
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}
bool verifica_se_afundou_porta_avioes (char matriz[][10],int linha,int coluna) // Fun��o que verifica se afundou um porta-avi�es
{
    bool test = false;
    if((matriz[linha][coluna]=='p' && matriz[linha][coluna + 1]=='p'&& matriz[linha][coluna +2]=='p'&& matriz[linha][coluna +3]=='p' && matriz[linha][coluna +4]=='p') || (matriz[linha][coluna]=='p'&& matriz [linha][coluna -1]=='p' && matriz[linha][coluna -2]=='p' && matriz [linha][coluna -3] && matriz[linha][coluna -4]== 'p') ||
            (matriz[linha][coluna] == 'p' && matriz[linha][coluna +1]=='p' && matriz[linha][coluna +2] == 'p' && matriz[linha][coluna +3] =='p' && matriz[linha][coluna -1] == 'p') || (matriz[linha][coluna]=='p' && matriz[linha][coluna +1]=='p' && matriz[linha][coluna +2]== 'p' && matriz[linha][coluna -1]=='p' && matriz [linha][coluna -2]== 'p') ||
            (matriz[linha][coluna]=='p' && matriz[linha][coluna+1]=='p' && matriz[linha][coluna -1]=='p' && matriz[linha][coluna-2]=='p' && matriz[linha][coluna-3]=='p' && matriz[linha][coluna -4] =='p')) //  // Verifica se em todas as posi��es adjacentes a linha e a coluna possuem um peda�o do port�o-avi�o (respeitando o tamanho deste

    {
        test=true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}

bool verifica_se_afundou (char matriz[][10],int linha,int coluna,int tiro) // A fun��o verifica se com um tiro, o jogador conseguiu afundar um barco
{
    bool test =false; // teste recebe falso
    if (tiro == 1) // Com apenas um tiro, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true) // Verifica se o jogador afundou o submarino
        {
            test = true; // teste recebe verdadeiro
        }
    }
    if (tiro == 2) // Com apenas dois tiros, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true || verifica_se_afundou_cruzador(matriz,linha,coluna) == true) // Verifica se o jogador conseguiu afundar ou submarino ou um cruzador
        {
            test = true; // teste recebe verdadeiro
        }
    }
    if(tiro == 3) // Com apenas tr�s tiros, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true || verifica_se_afundou_cruzador(matriz,linha,coluna) == true || verifica_se_afundou_destroyer(matriz,linha,coluna) == true) // Verificar se o jogador conseguiu afundar um submarino ou um cruzador ou um destroyer
        {
            test = true; // teste recebe verdadeiro
        }
    }
    if(tiro == 4) // Com quatro tiros, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true || verifica_se_afundou_cruzador(matriz,linha,coluna) == true || verifica_se_afundou_destroyer(matriz,linha,coluna) == true || verifica_se_afundou_encouracado(matriz,linha,coluna) == true) // // Verificar se o jogador conseguiu afundar um submarino ou um cruzador ou um destroyer ou um encoura�ado
        {
            test = true; // teste recebe verdadeiro
        }
    }
    if (tiro == 5) // Com cinco tiros, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true || verifica_se_afundou_cruzador(matriz,linha,coluna) == true || verifica_se_afundou_destroyer(matriz,linha,coluna) == true || verifica_se_afundou_encouracado(matriz,linha,coluna) == true || verifica_se_afundou_porta_avioes(matriz,linha,coluna) == true) // // Verificar se o jogador conseguiu afundar um submarino ou um cruzador ou um destroyer ou um encoura�ado ou um porta-avi�o
        {
            test = true; // teste recebe verdadeiro
        }
    }

    return test; // retorna o teste
}

void copiar_o_conteudo_da_linha_e_da_coluna_selecionada_pelo_usuario(char matriz[][10],char matriz_copiada[][10],int linha,int coluna) // Ela copia o conte�do da linha e da coluna digitada pelo usu�rio para a matriz copiada
{
    matriz_copiada[linha][coluna] = matriz[linha][coluna]; // a matriz copiada recebe o conte�do da linha e coluna digitada pelo usu�rio referente a matriz
}
void preencher_copiada_com_espaco(char matriz[][10]) // Preenche a matriz copiada, pois copiando o conte�do da linha e coluna selecionada direto para a matroz copiada ,ocorre lixo de mem�ria
{
    for(int i=0; i<10; i++) // percorre a linha
    {
        for(int j=0; j<10; j++) // percorre a coluna
        {

            matriz[i][j] = ' '; // posi��es da matriz recebe espa�o
        }
    }
}

int main()
{
    /* submarino = 1;
     cruzador = 2;
     destroyer = 3;
     encouracado = 4;
     porta_avioes = 5;*/

    int numero_de_embarcacoes; // delimita que as embarca��es devem possuir n�mero inteiro

    char matriz[10][10]; // Mostra que a matriz recebe caracteres

    preencher_matriz_com_agua(matriz); // Chama a fun��o que preenche a matriz com �gua "~"

    mostra_matriz(matriz); // Chama a fun��o que mostra a matriz

    srand(time(NULL)); // Evita que a rand sorteie valores iguais a cada chamada
    char opcao; // op��o recebe caracteres

    do // ir� rodar caso o usu�rio escolha a op��o jogar novamente
    {
        cout << "Digite um numero que representa a quantidade de embarcacoes desejadas entre 5 e 15:" << endl;
        cin >> numero_de_embarcacoes;

        if (numero_de_embarcacoes < 5 || numero_de_embarcacoes >15) // Ir� entrar nesse if apens quando o usu�rio digitar um valor fora desse intervalo

        {
            cout << "\n";
            numero_de_embarcacoes = rand() % 11 + 5; // Sorteia quantas embarca��es ter� no jogo
        }

        if(numero_de_embarcacoes == 5) // Essa fun��o ocorrer� caso o usu�rio insira 5 embarca��es ou o sorteio sorteie 5 embarca��es
        {
            insere_uma_embarcacao_de_cada(matriz); // Insere um embarca��o de cada
        }
        else // Caso o numero de embarca��es seja maior que 5
        {
            insere_uma_embarcacao_de_cada(matriz); // Insere uma embarca��o de cada

            bool resultado=false; // resultado recebe falso

            for(int i=6; i<=numero_de_embarcacoes; i++) // Sortear� as 5 primeiras embarca��es dferentes e o restante ser� aleat�rio
            {
                int embarcacao = sorteio_das_embarcacoes(); // embarca��o recebe sorteio

                resultado = verificar_se_pode_ser_inserido(matriz,embarcacao); // resultado recebe verificar se pode ser inserido

                while(resultado != true ) // Enquanto o resultado for diferente de falso
                {
                    resultado = verificar_se_pode_ser_inserido(matriz,embarcacao); // resultado recebe verificar se pode ser inserido
                }
            }
        }

        int linha,linha2;
        int coluna,coluna2;

        char matriz_copiada[10][10]; // a matriz copiada receber� caracteres
        bool ganhou = false; // ganhou recebe falso
        int tiro = 1; // tiro recebe um
        preencher_copiada_com_espaco(matriz_copiada); //  chama a fun��o preencher a matriz copiada

        while(ganhou != true && tiro <=5) // Enquanto ganhou for diferente de verdadeiro e tentativas menor igual a 5
        {
            do
            {
                do
                {
                    cout<< "Digite a linha na qual vc deseja atirar:" << endl;
                    cin >> linha;
                    if (linha >9 || linha < 0)//testa se linha est� entre o intervalo necess�rio
                        cout<<"Linha invalida, escolha uma linha entre 0 e 9: "<< endl;
                }
                while(linha >9 || linha < 0);//se n�o estiver for�a o usu�rio a digitar novamente

                do
                {
                    cout <<"Digite a coluna na qual deseja atirar:"<< endl;
                    cin >> coluna;
                    if (coluna >9 || coluna < 0)//testa se a coluna est� entre o intervalo necess�rio
                        cout<<"Coluna invalida, escolha uma coluna entre 0 e 9: "<< endl;
                }
                while(coluna >9 || coluna < 0); // se n�o estiver for�a o usuario a digitar novamente

                if(linha == linha2 && coluna == coluna2)//testa se as posi��es escolhidas s�o iguais a cada jogada
                {
                    cout<<"Ja atirou nesta posicao, escolha outra: "<<endl;
                    cout<<endl;
                }
            }
            while(tiro>1 && linha == linha2 && coluna==coluna2); // faz o jogador repetir a posi��o caso esta seja igual a posi��o anterior

            coluna2 = coluna;
            linha2 = linha;

            copiar_o_conteudo_da_linha_e_da_coluna_selecionada_pelo_usuario(matriz,matriz_copiada,linha,coluna);
            ganhou = verifica_se_afundou(matriz_copiada,linha,coluna,tiro);
            mostra_matriz(matriz_copiada);
            tiro ++; // Incrementando a quantidade de tiros
        }

        if(ganhou == true) // Se ganhou for igual a verdadeiro, mostrar a mensagem abaixo
        {
            cout <<" Voce Ganhou!!!" << " :)" << endl ;
        }
        else // Sen�o for verdadeiro, mostrar a mensagem abaixo
        {
            cout << "Voce Perdeu!!!" << " :("<< endl;
        }

        mostra_matriz(matriz);

        cout <<" Deseja jogar novamente? (s/n)" << endl;
        cin >> opcao;
        preencher_matriz_com_agua(matriz); // Ao final de cada partida, antes de iniciar uma nova, preenche a matriz com �gua

    }
    while(opcao != 'n'); // enquato a op��o for diferente de "n", o joagdor poder� jogar outra partida
    return 0;
}

