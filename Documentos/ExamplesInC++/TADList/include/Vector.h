#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef unsigned long long size_type;

template <typename T>
class Vector{

public:
  Vector();
  ~Vector(){ clear(); };
  size_type size() const;
  void clear();
  bool empty();
  void push_back( const T & x );
  void pop_back();
  const T & back() const;
  const T & front() const;
  void assign( const T & x );
  T & operator[]( size_type idx);
  T & at ( size_type idx );
  size_type capacity() const;
  void reserve( size_type new_capacity );

private:
  std::unique_ptr<T[]> myList; // Array dinâmico usado para armazenar os elementos
  size_type length; // Armazena a capacidade máxima do array
  size_type logic_size; // Armazena a quantidade atual de elementos
};

#include "Vector.inl"

#endif
