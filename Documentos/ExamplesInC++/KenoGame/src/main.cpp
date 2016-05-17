#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Keno.h"

void playKeno(int wage, int rounds, int nspots, KenoBet & Keno);

void RandomHits(std::vector < int > & hits);

float Bet_Table[15][15];

int main(int argc, char * argv[]){
  // Configuração da tabela de apostas
  Bet_Table[1][0] = 0;
  Bet_Table[1][1] = 3;

  Bet_Table[2][0] = 0;
  Bet_Table[2][1] = 1;
  Bet_Table[2][2] = 9;

  Bet_Table[3][0] = 0;
  Bet_Table[3][1] = 1;
  Bet_Table[3][2] = 2;
  Bet_Table[3][3] = 16;

  Bet_Table[4][0] = 0;
  Bet_Table[4][1] = 0.5;
  Bet_Table[4][2] = 2;
  Bet_Table[4][3] = 6;
  Bet_Table[4][4] = 12;

  Bet_Table[5][0] = 0;
  Bet_Table[5][1] = 0.5;
  Bet_Table[5][2] = 1;
  Bet_Table[5][3] = 3;
  Bet_Table[5][4] = 15;
  Bet_Table[5][5] = 50;

  Bet_Table[6][0] = 0;
  Bet_Table[6][1] = 0.5;
  Bet_Table[6][2] = 1;
  Bet_Table[6][3] = 2;
  Bet_Table[6][4] = 3;
  Bet_Table[6][5] = 30;
  Bet_Table[6][6] = 75;

  Bet_Table[7][0] = 0;
  Bet_Table[7][1] = 0.5;
  Bet_Table[7][2] = 0.5;
  Bet_Table[7][3] = 1;
  Bet_Table[7][4] = 6;
  Bet_Table[7][5] = 12;
  Bet_Table[7][6] = 36;
  Bet_Table[7][7] = 100;

  Bet_Table[8][0] = 0;
  Bet_Table[8][1] = 0.5;
  Bet_Table[8][2] = 0.5;
  Bet_Table[8][3] = 1;
  Bet_Table[8][4] = 3;
  Bet_Table[8][5] = 6;
  Bet_Table[8][6] = 19;
  Bet_Table[8][7] = 90;
  Bet_Table[8][8] = 720;

  Bet_Table[9][0] = 0;
  Bet_Table[9][1] = 0.5;
  Bet_Table[9][2] = 0.5;
  Bet_Table[9][3] = 1;
  Bet_Table[9][4] = 2;
  Bet_Table[9][5] = 4;
  Bet_Table[9][6] = 8;
  Bet_Table[9][7] = 20;
  Bet_Table[9][8] = 80;
  Bet_Table[9][9] = 1200;

  Bet_Table[10][0] = 0;
  Bet_Table[10][1] = 0;
  Bet_Table[10][2] = 0.5;
  Bet_Table[10][3] = 1;
  Bet_Table[10][4] = 2;
  Bet_Table[10][5] = 3;
  Bet_Table[10][6] = 5;
  Bet_Table[10][7] = 10;
  Bet_Table[10][8] = 30;
  Bet_Table[10][9] = 600;
  Bet_Table[10][10] = 1800;

  Bet_Table[11][0] = 0;
  Bet_Table[11][1] = 0;
  Bet_Table[11][2] = 0.5;
  Bet_Table[11][3] = 1;
  Bet_Table[11][4] = 1;
  Bet_Table[11][5] = 2;
  Bet_Table[11][6] = 6;
  Bet_Table[11][7] = 15;
  Bet_Table[11][8] = 25;
  Bet_Table[11][9] = 180;
  Bet_Table[11][10] = 1000;
  Bet_Table[11][11] = 3000;

  Bet_Table[12][0] = 0;
  Bet_Table[12][1] = 0;
  Bet_Table[12][2] = 0;
  Bet_Table[12][3] = 0.5;
  Bet_Table[12][4] = 1;
  Bet_Table[12][5] = 2;
  Bet_Table[12][6] = 4;
  Bet_Table[12][7] = 24;
  Bet_Table[12][8] = 72;
  Bet_Table[12][9] = 250;
  Bet_Table[12][10] = 500;
  Bet_Table[12][11] = 2000;
  Bet_Table[12][12] = 4000;

  Bet_Table[13][0] = 0;
  Bet_Table[13][1] = 0;
  Bet_Table[13][2] = 0;
  Bet_Table[13][3] = 0.5;
  Bet_Table[13][4] = 0.5;
  Bet_Table[13][5] = 3;
  Bet_Table[13][6] = 4;
  Bet_Table[13][7] = 5;
  Bet_Table[13][8] = 20;
  Bet_Table[13][9] = 80;
  Bet_Table[13][10] = 240;
  Bet_Table[13][11] = 500;
  Bet_Table[13][12] = 3000;
  Bet_Table[13][13] = 6000;

  Bet_Table[14][0] = 0;
  Bet_Table[14][1] = 0;
  Bet_Table[14][2] = 0;
  Bet_Table[14][3] = 0.5;
  Bet_Table[14][4] = 0.5;
  Bet_Table[14][5] = 2;
  Bet_Table[14][6] = 3;
  Bet_Table[14][7] = 5;
  Bet_Table[14][8] = 12;
  Bet_Table[14][9] = 50;
  Bet_Table[14][10] = 150;
  Bet_Table[14][11] = 500;
  Bet_Table[14][12] = 1000;
  Bet_Table[14][13] = 2000;
  Bet_Table[14][14] = 7500;

  Bet_Table[15][0] = 0;
  Bet_Table[15][1] = 0;
  Bet_Table[15][2] = 0;
  Bet_Table[15][3] = 0.5;
  Bet_Table[15][4] = 0.5;
  Bet_Table[15][5] = 1;
  Bet_Table[15][6] = 2;
  Bet_Table[15][7] = 5;
  Bet_Table[15][8] = 15;
  Bet_Table[15][9] = 50;
  Bet_Table[15][10] = 150;
  Bet_Table[15][11] = 300;
  Bet_Table[15][12] = 600;
  Bet_Table[15][13] = 1200;
  Bet_Table[15][14] = 2500;
  Bet_Table[15][15] = 10000;

  std::string file_name; // Nome do arquivo passado pelo terminal
  float wage; // Quantidade de crédito inicial do usuário
  int rounds; // Quantidade de rodadas a serem jogadas
  int spots; // Números a serem adicionados na aposta
  int nspots = 0; // A quantidade de números apostados
  if(argc > 1){
    file_name = argv[1];
  }else{
    std::cout << ">>> ERROR >>> Missing name or directory of the file";
    return false;
  }

  KenoBet Keno;

  std::fstream file;

  std::cout << ">>> Preparing to read bet file ["<< file_name <<"], please wait...\n";
  std::cout << "--------------------------------------------------\n";

  file.open(file_name);

  std::cout << "Bet successfully read!\n";

  file >> wage;

  file >> rounds;

  while(!file.eof()){
    file >> spots;
    if(Keno.addNumber(spots)){
      nspots++;
    }
  }

  playKeno(wage, rounds, nspots, Keno); // Função responsável pelo desfecho do jogo

}

void playKeno(int wage, int rounds, int nspots, KenoBet & Keno){
  Keno.setWage(wage); // Adiciona o dinheiro inicial do Usuário
  float WagePerRound = wage / rounds;
  std::cout << "You are going to wage a total of $" << wage << " dollars.\n";
  std::cout << "Going for a total of "<< rounds <<" rounds, waging $"<< wage / rounds <<" per round.\n\n";

  std::cout << "Your bet has " << nspots << " numbers. They are: [";

  std::vector < int > spots = Keno.getSpots(); // Vector usado para ter uma cópia dos números da aposta
  std::vector < int > hits; // Vector usado para armazenar os hits aleatórios e os acertos
  std::vector < int >::iterator it; // Iterator para pegar os números apostados e para percorrer os acertos

  for(it = spots.begin(); it < spots.end(); it++){
    std::cout << " " << *it << " ";
  }
  std::cout << "]\n";

  std::cout << "-------+---------\n";
  std::cout << "Hits   | Payout\n";
  std::cout << "-------+---------\n";
  for(int i = 0; i <= nspots; i++){
    std::cout << i << "      | "<< Bet_Table[nspots][i] << std::endl;
  }

  for(int i = 1; i <= rounds; i++){
    std::cout << "--------------------------------------------------\n";
    std::cout << "This is round #"<<i<<" of " << rounds <<" and your wage is $" << WagePerRound <<". Good luck!\n";

    Keno.setWage(Keno.getWage() - WagePerRound); // A quantidade de dinheiro diminui a cada rodada

    std::cout << "The hits are: [ ";
    RandomHits(hits); // Sorteia números aleatórios
    //hits = Keno.getHits(hits);
    for(it = hits.begin(); it != hits.end(); it++){
      std::cout << *it << " ";
    }

    std::cout << "]\n\n";
    hits = Keno.getHits(hits);
    std::cout << "You hit the following number(s) [ ";

    for(it = hits.begin(); it != hits.end(); it++){
      std::cout << *it << " ";
    }

    int GainWage = WagePerRound * Bet_Table[nspots][hits.size()]; // Guarda a quantidade ganha de dinheiro na aposta
    std::cout << "], a total of " << hits.size() << " hits out of " << nspots << std::endl;
    std::cout << "Payout rate is " << Bet_Table[nspots][hits.size()] << ", thus you came out with: $" << GainWage << std::endl;

    Keno.setWage(Keno.getWage() + GainWage); // O dinheiro é aumentado pelo o ganho de cada rodada

    std::cout << "Your net balance so far is: $" << Keno.getWage() << " dollars\n";
  }

  std::cout << ">>> End of rounds!\n";
  std::cout << "--------------------------------------------------\n\n";
  std::cout << "===== SUMMARY =====\n";
  std::cout << ">>> You spent in this game a total of $" << wage << " dollars.\n";
  if((Keno.getWage() - wage) > 0.0)
  std::cout << ">>> Hooray, you won $" << (Keno.getWage() - wage) << " dollars. See you next time! ;-)\n";
  std::cout << ">>> You are leaving the Keno table with $" << Keno.getWage() << " dollars.\n";
}

void RandomHits( std::vector < int > & hits){
  hits.clear(); // O vector é limpo para previnir que não armazene mais de 20 elementos
  int RandomNum;
  std::random_device r;
  std::default_random_engine eng(r());
  std::uniform_real_distribution<double> distr(1, 80); // Gerando números dentro da faixa de hits possíveis do Keno

  for(int i = 0; i < 20;){
    RandomNum = distr(eng);
    if(std::binary_search(hits.begin(), hits.end(), RandomNum)){
      continue;
    }else{
      hits.push_back(RandomNum);
      i++;
    }
  }
}
