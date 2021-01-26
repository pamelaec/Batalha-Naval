//Filipe Soares Fernandes - 0022921
//Pâmela Evelyn Carvalho - 0015669

#include <iostream> // Biblioteca padrão
#include <stdlib.h> // Utilizado na rand e srand
#include <time.h> // Utilizado na função time

using namespace std;

void preencher_matriz_com_agua(char matriz[][10]) // Esta função preenche a matiz com água
{

    for(int i=0; i<10; i++) // for percorre a linha da matriz
    {
        for(int j=0; j<10; j++) // for percorre a coluna da matriz
        {
            matriz[i][j] = '~'; // as respectivas posições da matriz são preenchidas com água
        }
    }
}

void mostra_matriz( char matriz[][10]) // Esta função mostra a matriz
{
    cout << "  ";

    for(int i=0; i<10; i++) // Mostra as posições da coluna
    {
        cout << i ;
    }
    cout << "\n";
    cout << "\n";

    for(int i=0; i<10; i++) // Percorre a linha da matriz
    {
        cout << i << " "; // Mostra o número da linha

        for(int j=0; j<10; j++) // Percorre a coluna
        {
            cout << matriz[i][j]; // Mostra a água ~
        }
        cout << "\n";
        cout << "\n";
    }
}

int sorteio_das_embarcacoes() // Esta função sorteia as embarcações
{
    int recebe_a_embarcacao_sorteada = rand()% 5 + 1; // Aqui é sorteado uma entre as cinco embarcações

    return recebe_a_embarcacao_sorteada; // Retorna a embarcação sorteada
}

int sorteio_linha() // Esta função sorteia uma linha da matriz
{
    int linha = rand()% 10; // Aqui é sorteado uma entre as dez linhas da matriz

    return linha; // Retornar a linha sorteada
}
int sorteio_coluna() // Esta função sorteia uma coluna da matriz
{
    int coluna = rand()% 10; // Aqui é sorteada uma coluna entre as dez linhs da matriz

    return coluna; // Retornar a linha sorteada
}

bool cabe_a_embarcacao(char matriz[][10],int embarcacao,int linha,int coluna) // Esta função verifica se a embarcação cabe na matriz
{
    /*submarino = 1;
    cruzador = 2;
    destroyer =3;
    encouracado =4;
    porta_avioes = 5;*/

    bool test = false; // A função recebe falso

    if( embarcacao == 1  && matriz[linha][coluna+1]== '~' ) // Se a embarcação é um submarino e se na coluna a direita tem água
    {
        test = true; // Se as duas condições forem aceitas, a função recebe verdadeira, a embarcação cabe na matriz
    }

    if (embarcacao == 2 && coluna <9) // Se embarcação é um cruzador e delimita que ela não pode ser colocada em uma coluna maior que 8
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~') // Verifica se na linha e coluna inserida tem água, se na coluna +1 tem água e se na coluna +2 tem água
        {
            test = true; // Se essas condições acima forem respeitadas, a função retorna verdadeiro, a embarcação cabe na matriz
        }
    }

    if (embarcacao == 3 && coluna <8) // Se a embarcação é um  cruzador e delimita que a embarcação não pode ser inserida em uma coluna maior que 7
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~' && matriz[linha][coluna +3] == '~') // Verifica se todas as posições ocupadas pela embarcação são água, e se uma posição depois da embarcação é água
        {
            test = true; // Se essas condições acima forem respeitadas, a função retorna verdadeiro, e a embarcação cabe na matriz
        }
    }

    if (embarcacao == 4 && coluna <7) // Se a embarcação é um  encouraçado e delimita que ela não pode ser colocada em uma coluna maior que 6
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~' && matriz[linha][coluna +3] == '~' && matriz[linha][coluna +4]=='~') // Verifica se todas as posições da embarcação são água e se uma coluna a direita dessa embarcação é agua
        {
            test = true; // Se essas condições acima forem respeitadas, a função retorna verdadeiro, e a embarcação cabe na matriz
        }
    }

    if (embarcacao == 5 && coluna <6) // Se a embarcação é um  encouraçado e delimita que ela não pode ser colocada em uma coluna maior que 5
    {
        if(matriz[linha][coluna] == '~' && matriz [linha][coluna +1]== '~' && matriz[linha][coluna+2]== '~' && matriz[linha][coluna +3] == '~' && matriz[linha][coluna +4]=='~' && matriz[linha][coluna +5]=='~')
        {
            test = true; // Se essas condições acima forem respeitadas, a função retorna verdadeiro, e a embarcação cabe na matriz
        }
    }
    return test; // Retorna o valor do teste
}

bool insere_a_embarcacao_na_matriz( char matriz[][10],int embarcacao, int coluna, int linha) // Esta função insere a embarcação na matriz
{
    bool test= false; // Teste recebe falso
    if(embarcacao == 1) // Se a embarcação é um sobmarino
    {
        matriz [linha][coluna] = 's'; // matriz[linha][coluna] selecionada recebem s
        test= true; // teste recebe verdadeiro
    }
    if (embarcacao == 2) // Se a embarcação é um cruzador
    {
        for(int i=coluna; i<= coluna +1; i++ ) // este for percorrerar a coluna até o tamanho da embarcação
        {
            matriz[linha][i]= 'c'; // matriz [coluna][linha] selecionada recebe c e matriz[linha][coluna +1] recebe c
        }
        test = true; // teste recebe verdadeiro
    }
    if (embarcacao == 3) // Se a embarcação destroyer
    {
        for(int i=coluna; i<=coluna +2; i++) // Este for percorre a coluna até o tamanho da embarcação
        {
            matriz [linha][i] = 'd'; // matriz[linha][coluna] recebe d e matriz [linha][coluna +1] recebe  d e [linha][coluna +2] recebe d
        }
        test = true; // teste recebe verdadeiro
    }
    if(embarcacao == 4) // Se a embarcação encouraçado
    {
        for(int i=coluna; i<=coluna+3; i++) // Este for percorre a coluna até o tamanho da embarcação
        {
            matriz[linha][i]='e'; // matriz[linha][coluna] recebe "e" e matriz [linha][coluna +1] recebe  "e" e [linha][coluna +2] recebe e
        }

        test = true; // teste recebe verdadeiro
    }
    if(embarcacao ==5) // Se a embarcação portão-aviões
    {
        for (int i=coluna; i<=coluna+4; i++) // Este for percorre a coluna até o tamanho da embarcação
        {
            matriz[linha][i]='p'; // matriz[linha][coluna] recebe p e matriz [linha][coluna +1] recebe  p e [linha][coluna +2] recebe p
        }
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o valor do teste
}

bool verificar_se_pode_ser_inserido(char matriz[][10],int embarcacao) // Esta função verifica se a embarcação ode ser inserida na matriz
{
    int coluna = sorteio_coluna(); // sorteia uma coluna da matriz
    int linha = sorteio_linha(); // sorteia uma linha da matriz
    bool test = false; // teste recebe falso
    if(coluna == 0  && cabe_a_embarcacao(matriz,embarcacao,linha,coluna) == true) // Se a coluna for igual a zero, e a embarcação cabe
    {
        if (insere_a_embarcacao_na_matriz(matriz,embarcacao,coluna,linha)==true) // Insere a embarcação na matriz e recebe verdadeiro
            test = true; // teste recebe verdadeiro
    }
    if(coluna ==9 && matriz[linha][coluna -1 ] =='~'&& cabe_a_embarcacao(matriz,embarcacao,linha,coluna) == true) // Se a coluna for igual a 9 e matriz[linha][coluna -1] igual a água e cabe
    {
        matriz[linha][coluna] = 's'; // insere submarino
        test = true; // teste recebe verdadeiro
    }
    if(matriz[linha][coluna -1] == '~' && cabe_a_embarcacao(matriz,embarcacao,linha,coluna) == true) // Se a matriz [linha][coluna -1] é água e cabe
    {
        if (insere_a_embarcacao_na_matriz(matriz,embarcacao,coluna,linha)==true) //  embarcação vai ser verdadeira
            test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}

void insere_uma_embarcacao_de_cada (char matriz[][10]) //Esta função insere uma embarcação de cada na matriz, pois, é necesário ter pelo menos uma embarcação de cada
{
    int vetor[5]; // vetor com 5 posições

    for(int i =0; i<5 ; i++) // Este for percorre as cinco posições do vetor
    {
        vetor[i] = sorteio_das_embarcacoes(); // O vetor [i] recebe a embarcação sorteada

        if(i==1) // Se a embarcação é um submarino
        {
            while (vetor[i-1] == vetor[i]) // verifica se o modelo dessa embarcação já foi sorteado
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor [i] recebe a embarcação
            }
        }

        if(i==2) // Se a embarcação é um cruzador
        {
            while (vetor[i-1]==vetor[i]  || vetor[i-2] == vetor[i]) // verifica se o modelo dessa embarcação já foi sorteado, senão sorteia novamente
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor [i] recebe a embarcação
            }
        }

        if(i==3) // Se a embarcação é um destroyer
        {
            while (vetor[i-1]==vetor[i]  || vetor[i-2]==vetor[i] || vetor[i-3] == vetor[i]) // verifica se o modelo dessa embarcação já foi sorteado, senão sorteia novamente
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor [i] recebe a embarcação
            }
        }
        if(i==4) // Se a embarcação encouraçado
        {
            while (vetor[i-1]==vetor[i]  || vetor[i-2]==vetor[i] || vetor[i-3]==vetor[i] || vetor [i-4]== vetor[i]) // verifica se o modelo já foi sorteado, senão sorteia novamente
            {
                vetor[i]= sorteio_das_embarcacoes(); // O vetor[i] recebe a embarcação
            }
        }
    }
    for(int i=0; i<5; i++) // for percorre as  5 posições do vetor
    {
        bool  verificancando_se_pode_ser_inserido = verificar_se_pode_ser_inserido(matriz,vetor[i]); // A variável boolleana recebe o retorno d função verificar se pode ser inserido, passando com o parametro a matriz e a embarcação que esta na posição "i" do vetor

        while(verificancando_se_pode_ser_inserido != true ) // Enquanto o retorno for falso
        {
            verificancando_se_pode_ser_inserido = verificar_se_pode_ser_inserido(matriz,vetor[i]); // É feito uma nova tentativa de inserção
        }
    }
}

bool verifica_se_afundou_submarino(char matriz[][10],int linha ,int coluna) // Função que verifica se afundou um submarino
{
    bool test = false; // teste recebe falso
    if (matriz[linha][coluna] == 's') // Se a matriz[linha][coluna] for igual ao submarino
    {
        test = true; // teste reebe verdadeiro
    }
    return test; // retorna o teste
}

bool verifica_se_afundou_cruzador(char matriz[][10], int linha, int coluna) // Função que verifica se afundou um cruzador
{
    bool test = false; // teste recebe falso
    if((matriz[linha][coluna]== 'c'&& matriz[linha][coluna +1]== 'c') || (matriz [linha][coluna]=='c' && matriz [linha][coluna -1]=='c')) // Verifica se em todas as posições adjacentes a linha e a coluna possuem um pedaço do cruzador (respeitando o tamanho deste)
    {
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}

bool verifica_se_afundou_destroyer(char matriz[][10],int linha,int coluna) // Função que verifica se afundou um destroyer
{
    bool test = false; // teste recebe falso
    if((matriz [linha][coluna]== 'd'&& matriz [linha][coluna +1]== 'd' && matriz [linha][coluna +2]== 'd') || (matriz [linha][coluna]== 'd' && matriz[linha][coluna -1]== 'd' && matriz [linha][coluna -2]== 'd') ||
            (matriz [linha][coluna] == 'd' && matriz [linha][coluna -1]== 'd' && matriz[linha][coluna +1]== 'd')) //  // Verifica se em todas as posições adjacentes a linha e a coluna possuem um pedaço do destroyer (respeitando o tamanho deste)
    {
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}
bool verifica_se_afundou_encouracado (char matriz [][10],int linha,int coluna) // Função que verifica se afundou um encouraçado
{
    bool test = false; // teste recebe falso
    if ((matriz [linha][coluna] == 'e' && matriz [linha][coluna +1 ]== 'e' && matriz [linha][coluna +2]== 'e' && matriz [linha][coluna +3]== 'e') ||(matriz [linha][coluna]=='e' && matriz [linha][coluna -1]== 'e' && matriz[linha][coluna -2]== 'e' && matriz[linha][coluna -3]== 'e') ||
            (matriz [linha][coluna]=='e' && matriz[linha][coluna +1]=='e' && matriz [linha][coluna +2]=='e' && matriz[linha][coluna -1] == 'e') || (matriz[linha][coluna]=='e' && matriz [linha][coluna +1]=='e' && matriz[linha][coluna -1]=='e' && matriz[linha][coluna -2]== 'e'))  // Verifica se em todas as posições adjacentes a linha e a coluna possuem um pedaço do encouraçado (respeitando o tamanho deste
    {
        test = true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}
bool verifica_se_afundou_porta_avioes (char matriz[][10],int linha,int coluna) // Função que verifica se afundou um porta-aviões
{
    bool test = false;
    if((matriz[linha][coluna]=='p' && matriz[linha][coluna + 1]=='p'&& matriz[linha][coluna +2]=='p'&& matriz[linha][coluna +3]=='p' && matriz[linha][coluna +4]=='p') || (matriz[linha][coluna]=='p'&& matriz [linha][coluna -1]=='p' && matriz[linha][coluna -2]=='p' && matriz [linha][coluna -3] && matriz[linha][coluna -4]== 'p') ||
            (matriz[linha][coluna] == 'p' && matriz[linha][coluna +1]=='p' && matriz[linha][coluna +2] == 'p' && matriz[linha][coluna +3] =='p' && matriz[linha][coluna -1] == 'p') || (matriz[linha][coluna]=='p' && matriz[linha][coluna +1]=='p' && matriz[linha][coluna +2]== 'p' && matriz[linha][coluna -1]=='p' && matriz [linha][coluna -2]== 'p') ||
            (matriz[linha][coluna]=='p' && matriz[linha][coluna+1]=='p' && matriz[linha][coluna -1]=='p' && matriz[linha][coluna-2]=='p' && matriz[linha][coluna-3]=='p' && matriz[linha][coluna -4] =='p')) //  // Verifica se em todas as posições adjacentes a linha e a coluna possuem um pedaço do portão-avião (respeitando o tamanho deste

    {
        test=true; // teste recebe verdadeiro
    }
    return test; // retorna o teste
}

bool verifica_se_afundou (char matriz[][10],int linha,int coluna,int tiro) // A função verifica se com um tiro, o jogador conseguiu afundar um barco
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
    if(tiro == 3) // Com apenas três tiros, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true || verifica_se_afundou_cruzador(matriz,linha,coluna) == true || verifica_se_afundou_destroyer(matriz,linha,coluna) == true) // Verificar se o jogador conseguiu afundar um submarino ou um cruzador ou um destroyer
        {
            test = true; // teste recebe verdadeiro
        }
    }
    if(tiro == 4) // Com quatro tiros, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true || verifica_se_afundou_cruzador(matriz,linha,coluna) == true || verifica_se_afundou_destroyer(matriz,linha,coluna) == true || verifica_se_afundou_encouracado(matriz,linha,coluna) == true) // // Verificar se o jogador conseguiu afundar um submarino ou um cruzador ou um destroyer ou um encouraçado
        {
            test = true; // teste recebe verdadeiro
        }
    }
    if (tiro == 5) // Com cinco tiros, o jogador conseguiu afundar
    {
        if(verifica_se_afundou_submarino(matriz,linha,coluna) == true || verifica_se_afundou_cruzador(matriz,linha,coluna) == true || verifica_se_afundou_destroyer(matriz,linha,coluna) == true || verifica_se_afundou_encouracado(matriz,linha,coluna) == true || verifica_se_afundou_porta_avioes(matriz,linha,coluna) == true) // // Verificar se o jogador conseguiu afundar um submarino ou um cruzador ou um destroyer ou um encouraçado ou um porta-avião
        {
            test = true; // teste recebe verdadeiro
        }
    }

    return test; // retorna o teste
}

void copiar_o_conteudo_da_linha_e_da_coluna_selecionada_pelo_usuario(char matriz[][10],char matriz_copiada[][10],int linha,int coluna) // Ela copia o conteúdo da linha e da coluna digitada pelo usuário para a matriz copiada
{
    matriz_copiada[linha][coluna] = matriz[linha][coluna]; // a matriz copiada recebe o conteúdo da linha e coluna digitada pelo usuário referente a matriz
}
void preencher_copiada_com_espaco(char matriz[][10]) // Preenche a matriz copiada, pois copiando o conteúdo da linha e coluna selecionada direto para a matroz copiada ,ocorre lixo de memória
{
    for(int i=0; i<10; i++) // percorre a linha
    {
        for(int j=0; j<10; j++) // percorre a coluna
        {

            matriz[i][j] = ' '; // posições da matriz recebe espaço
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

    int numero_de_embarcacoes; // delimita que as embarcações devem possuir número inteiro

    char matriz[10][10]; // Mostra que a matriz recebe caracteres

    preencher_matriz_com_agua(matriz); // Chama a função que preenche a matriz com água "~"

    mostra_matriz(matriz); // Chama a função que mostra a matriz

    srand(time(NULL)); // Evita que a rand sorteie valores iguais a cada chamada
    char opcao; // opção recebe caracteres

    do // irá rodar caso o usuário escolha a opção jogar novamente
    {
        cout << "Digite um numero que representa a quantidade de embarcacoes desejadas entre 5 e 15:" << endl;
        cin >> numero_de_embarcacoes;

        if (numero_de_embarcacoes < 5 || numero_de_embarcacoes >15) // Irá entrar nesse if apens quando o usuário digitar um valor fora desse intervalo

        {
            cout << "\n";
            numero_de_embarcacoes = rand() % 11 + 5; // Sorteia quantas embarcações terá no jogo
        }

        if(numero_de_embarcacoes == 5) // Essa função ocorrerá caso o usuário insira 5 embarcações ou o sorteio sorteie 5 embarcações
        {
            insere_uma_embarcacao_de_cada(matriz); // Insere um embarcação de cada
        }
        else // Caso o numero de embarcações seja maior que 5
        {
            insere_uma_embarcacao_de_cada(matriz); // Insere uma embarcação de cada

            bool resultado=false; // resultado recebe falso

            for(int i=6; i<=numero_de_embarcacoes; i++) // Sorteará as 5 primeiras embarcações dferentes e o restante será aleatório
            {
                int embarcacao = sorteio_das_embarcacoes(); // embarcação recebe sorteio

                resultado = verificar_se_pode_ser_inserido(matriz,embarcacao); // resultado recebe verificar se pode ser inserido

                while(resultado != true ) // Enquanto o resultado for diferente de falso
                {
                    resultado = verificar_se_pode_ser_inserido(matriz,embarcacao); // resultado recebe verificar se pode ser inserido
                }
            }
        }

        int linha,linha2;
        int coluna,coluna2;

        char matriz_copiada[10][10]; // a matriz copiada receberá caracteres
        bool ganhou = false; // ganhou recebe falso
        int tiro = 1; // tiro recebe um
        preencher_copiada_com_espaco(matriz_copiada); //  chama a função preencher a matriz copiada

        while(ganhou != true && tiro <=5) // Enquanto ganhou for diferente de verdadeiro e tentativas menor igual a 5
        {
            do
            {
                do
                {
                    cout<< "Digite a linha na qual vc deseja atirar:" << endl;
                    cin >> linha;
                    if (linha >9 || linha < 0)//testa se linha está entre o intervalo necessário
                        cout<<"Linha invalida, escolha uma linha entre 0 e 9: "<< endl;
                }
                while(linha >9 || linha < 0);//se não estiver força o usuário a digitar novamente

                do
                {
                    cout <<"Digite a coluna na qual deseja atirar:"<< endl;
                    cin >> coluna;
                    if (coluna >9 || coluna < 0)//testa se a coluna está entre o intervalo necessário
                        cout<<"Coluna invalida, escolha uma coluna entre 0 e 9: "<< endl;
                }
                while(coluna >9 || coluna < 0); // se não estiver força o usuario a digitar novamente

                if(linha == linha2 && coluna == coluna2)//testa se as posições escolhidas são iguais a cada jogada
                {
                    cout<<"Ja atirou nesta posicao, escolha outra: "<<endl;
                    cout<<endl;
                }
            }
            while(tiro>1 && linha == linha2 && coluna==coluna2); // faz o jogador repetir a posição caso esta seja igual a posição anterior

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
        else // Senão for verdadeiro, mostrar a mensagem abaixo
        {
            cout << "Voce Perdeu!!!" << " :("<< endl;
        }

        mostra_matriz(matriz);

        cout <<" Deseja jogar novamente? (s/n)" << endl;
        cin >> opcao;
        preencher_matriz_com_agua(matriz); // Ao final de cada partida, antes de iniciar uma nova, preenche a matriz com água

    }
    while(opcao != 'n'); // enquato a opção for diferente de "n", o joagdor poderá jogar outra partida
    return 0;
}

