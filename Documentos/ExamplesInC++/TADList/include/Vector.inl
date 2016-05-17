// Implementação da classe Vector
template <typename T>
Vector<T>::Vector(){
  this->length = 2; // Seta o tamanho inicial do array para 20
  this->logic_size = 0; // O array começa com 0 elementos
  this->myList.reset( new T[this->length] ); // Armazena dinamicamente o array
}

template <typename T>
size_type Vector<T>::size() const{
  return this->logic_size;
}

template <typename T>
void Vector<T>::clear(){
  for(int i = 0; i < this->logic_size; i ++){ // Apaga todos os elementos do array
    (&this->myList[i])->~T(); // Apaga o elemento na posição i
  }
  this->logic_size = 0;
}

template <typename T>
bool Vector<T>::empty(){
  return(this->logic_size == 0); // Retorna true se não existe nenhum elemento no array
}

template <typename T>
void Vector<T>::push_back(const T & x){
  if(size() == capacity()){ // Se o array estiver cheio
    reserve(capacity() * 2);
  }
  this->myList[this->logic_size ++] = x; // Insere o elemento no final do array
}

template <typename T>
void Vector<T>::pop_back(){
  (&this->myList[ -- logic_size])->~T(); // Apaga o último elemento do array
}

template <typename T>
const T & Vector<T>::back() const{
  return this->myList[logic_size - 1]; // Retorna o último elemento da lista
}

template <typename T>
const T & Vector<T>::front() const{
  return this->myList[0]; // Retorna o objeto no início da lista
}

template <typename T>
void Vector<T>::assign( const T & x ){
  for(int i = 0; i < logic_size; i++){
    myList[i] = x; // Copia o valor de x para os elementos da lista
  }
}

template <typename T>
T & Vector<T>::operator[]( size_type idx){
  return this->myList[idx];
}

template <typename T>
T & Vector<T>::at ( size_type idx ){
  if(idx < logic_size - 1){ // Testa se o elemento existe
    return this->myList[idx];
  }else{
    std::cerr << ">>>ERROR: Out of range in Vector::at()" << std::endl;
  }
}

template <typename T>
size_type Vector<T>::capacity( ) const{
  return this->length;
}

template <typename T>
void Vector<T>::reserve( size_type new_capacity ){
  if(new_capacity > this->length){
    std::unique_ptr<T[]> newArray( new T[new_capacity] ); // Armazena dinamicamente o array para guardar um backup do original
    for(int i = 0; i < size(); i++){
      newArray[i] = this->myList[i];
    }
    for(int i = 0; i < this->logic_size; i ++){ // Apaga todos os elementos do array
      (&this->myList[i])->~T(); // Apaga o elemento na posição i
    }
    this->myList = std::move(newArray); // Guarda os elementos
    this->length = new_capacity; // Modifica o tamanho da lista
  }
}
