#ifndef _KENO_H_
#define _KENO_H_
#include <iostream>
#include <vector>

class KenoBet {
public:

  explicit KenoBet ( unsigned int _maxNumSpots = 15 );

  bool addNumber ( int _spot );

  bool setWage ( float _wage );

  void reset ( void );

  float getWage ( void ) const;

  size_t numChosen ( void ) const;

  std::vector < int > getHits ( std::vector < int > & _hits ) const;

  std::vector < int > getSpots ( void ) const;

private:
  std::vector < int > m_spots;

  float m_wage;

  unsigned int m_maxSpots;

};

#endif
