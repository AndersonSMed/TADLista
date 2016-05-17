#include <iostream>
#include <algorithm>
#include <vector>
#include "Keno.h"

KenoBet::KenoBet( unsigned int _maxNumSpots ){
  m_maxSpots = _maxNumSpots;
}

bool KenoBet::addNumber( int _spot ){
  if(m_spots.size() <= m_maxSpots){// Verifica se é possível adicionar um novo número na aposta
    std::vector < int >::iterator it; // Cria um iterator it para chegar se o valor adicionado já existe no vector m_spot;
    for(it = m_spots.begin(); it != m_spots.end(); it++){
      if(_spot == *it){
        return false;
      }
    }
    m_spots.push_back(_spot);
    return true;
  }
  return false;
}

bool KenoBet::setWage( float _wage ){
  m_wage = _wage;
  return (m_wage > 0.0);
}

void KenoBet::reset( void ){
  m_spots.clear();
}

float KenoBet::getWage( void ) const{
  return m_wage;
}

size_t KenoBet::numChosen( void ) const{
  return m_spots.size();
}

std::vector < int > KenoBet::getHits ( std::vector < int > & _hits ) const{
  std::vector < int > matches;
  std::vector < int >:: iterator it; // Iterator usado para percorrer o vetor de hits
  for(it = _hits.begin(); it != _hits.end(); it++){
    if(std::binary_search (m_spots.begin(), m_spots.end(), *it)) // Busca binária dos hits nos spots do Cliente
    matches.push_back(*it); // Se a busca binária retornar true, então o vector matches recebe o valor de Hit
  }
  return matches;
}

std::vector < int > KenoBet::getSpots ( void ) const{
  return m_spots;
}
