#include <iostream>
#include <cstdlib>
using namespace std;

// ALUNA: Helen C. S. Brandão
// TDSI 04/06/24

void printInfo(int tamanhoArray, string nome[6]){

    for(int i = 0; i < tamanhoArray; i++){
        cout << nome[i] << "\t" << "\t";
    }
    cout << endl;
}

void printInfo(int tamanhoArray, int idade[6]){

    for(int i = 0; i < tamanhoArray; i++){
        cout << idade[i] << "\t" << "\t";
    }
    cout << endl;
}

void printGrupo(int tamanhoArray, string nome[6]){

    for(int i = 0; i < tamanhoArray; i++){
        cout << i+1 << "." << nome[i] << endl;
    }
    cout << endl;
}

void printchosenInfo(int escolha, string persona[6], int idade[6], 
string classe[6], string vertente[6]){
    cout << "1. Nome: " << persona[escolha] << endl;
    cout << "2. Idade: " << idade[escolha] << endl;
    cout << "3. Classe: " << classe[escolha] << endl;
    cout << "4. Vertente: " << vertente[escolha] << endl;
}

void personaEditor(int escolha, int personagem, string persona[6], int idade[6], 
string classe[6], string vertente[6]){

    switch(escolha){

        case 0: 
        cout << "Informe o novo nome do personagem: ";
        cin >> persona[personagem];
        break;

        case 1:
        cout << "Informe a nova idade do personagem: ";
        cin >> idade[personagem];
        break;

        case 2:
        cout << "Informe a nova classe do personagem: ";
        cin >> classe[personagem];
        break;

        case 3:
        cout << "Informe a nova vertente do personagem: ";
        cin >> vertente[personagem];

        default:
        cout << "Opção inválida";
        break;
    }
}

void history(int personagem){
    
    switch (personagem){

        case 0:
        cout << "É uma noite fria, você não possui nada mais que um manto fino. Suas mãos assim com todos seus outros memobros tremem a cada nova rajada de vento." << endl << "Ao longe, você avista fumaça sendo lançada aos céus, seria uma oportunidade para se salvar de uma morte lenta e dolorida? Sua intuição o manda seguir.";
        break;

        case 1:
        cout << "A glória já não lhe é presente. O ouro lhe falta no bolso. As missões já não lhe satisfazem. A honra já não é mais sinônimo de ser. Em tempos difícies, o desespero toma conta, e aceitar uma missão de vida ou morte já não te assusta mais.";
        break;

        case 2:
        cout << "Seu folego já não se faz presente. Ao longe os grunhidos de cachorros selvagens o persegue, o fim lhe parece próximo, mas uma luz lhe parece ascender ao fim do tunel... Ou será isso uma chama de dragão vindo em sua direção prestes a lhe tornar carvão?";
        break;

        case 3:
        cout << "Uma missão lhe foi dada! Proteger e zelar pelo mestre ancião que estar a vir. Será escoltada e apenas terá de tratar de seus anseios... Uma tarefa simples, se ninguém intervisse.";
        break;

        case 4:
        cout << "Uma missão lhe foi dada! Uma carruagem cheia de ouro e riquezas se esgueira ao calar da noite. Ajude o ladino a saquear esse achado, cuidando para que seu dragão não saia do controle.";
        break;
        
        case 5:
        cout << "Um elfo lhe pede um conjunto de ferramentes feitas de escama de dragão. O local da entrega é incerto mas a recompensa é boa. A ida fora tranquila, a entrega foi feita com agilidade, só não esperava que fosse requisistado para participar da missão e conquistar a lealdade do dra";
        break;

        default:
        cout << "O que era para ser um sono tranquilo acaba por se tornar em um pesadelo com direito a dragões, ouro, gritos e fogo... muito fogo... muito muito... FOGO?!";
        break;
    }
}

int main() {
    // CRUD - ESCOLHA DE PERSONAGEM RPG POR CLASSE

    // VARIAVEIS
    int tamanhoArray = 6;

    // NOME
    string persona[tamanhoArray] = {"Cléa", "Artore", "Lex", "Loyr", "Belle", "Jamir"};
    // CLASSE
    string classe[tamanhoArray] = {"Warlox", "Warrior", "Ladino", "Fairy", 
    "Domador", "Crafter"};
    // IDADE
    int idade[tamanhoArray] = {103, 28, 40, 78, 19, 53};
    // VERTENTE
    string vertente[tamanhoArray] = {"Trevas", "Terra", "Trevas", "Luz", 
    "Ar", "Terra"};

   printInfo(tamanhoArray, persona);
   printInfo(tamanhoArray, idade);
   printInfo(tamanhoArray, classe);
   printInfo(tamanhoArray, vertente);

   int escolha = 0;

   while(escolha <= 0 || escolha >= 7){
   cout << "Escolha seu personagem editável: ";
   cin >> escolha;
   }

   escolha = escolha -1;
   int personagem = escolha;

   system("cls");
   printchosenInfo(personagem, persona, idade, classe, vertente);

    bool edicao = true;
    char resposta;
    do{
    escolha = 0;
   cout << "Gostaria de editar seu personagem? S/N" << endl;
   cin >> resposta;

   if(resposta == 'S'){
       cout << "O que você gostaria de editar?" << endl;
       cin >> escolha;
       escolha = escolha -1;
    personaEditor(escolha, personagem, persona, idade, classe, vertente);

    system("cls");
    printchosenInfo(personagem, persona, idade, classe, vertente);
    edicao = true;
   }else if(resposta == 'N'){
       edicao = false;
   }else{
       cout << "Opção inválida, tente novamente." << endl;
       edicao = true;
   }
   }while(edicao);

    system("cls");
    cout << "Suas informações foram salvas!" << endl;
    printchosenInfo(personagem, persona, idade, classe, vertente);

    cout << "\nSeu grupo é formado por: " << endl;
    printGrupo(tamanhoArray, persona);

    do{
    cout << "Você gostaria de retirar alguém do seu grupo? S/N" << endl;
    cin >> resposta;
    escolha = 0;
        if(resposta == 'S'){
                while(escolha <= 0 || escolha >= 7){
            cout << "Quem?" << endl;
            cin >> escolha;
            }

            escolha = escolha -1;
                if(escolha == personagem){
                    cout << "Você não pode ser retirar!" << endl;
                }else{
                    persona[escolha] = "Personagem deixou o grupo.";
                }
    
        }
    }while(resposta == 'S');

    system("cls");
    cout << "\nSeu grupo é formado por: " << endl;
    printGrupo(tamanhoArray, persona);

    cout << "\n[BOM JOGO!]" << endl;
    system("pause");

    cout << endl;
    history(personagem);
  


    return 0;
}