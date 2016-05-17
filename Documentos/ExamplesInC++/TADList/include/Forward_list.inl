template < typename Object >
Forward_list<Object>::Forward_list (){
  this->m_size = 0;
  m_head = nullptr;
  m_tail = nullptr;
}

template < typename Object >
Forward_list<Object>::~Forward_list (){
  delete m_head;
  delete m_tail;
  m_size = 0;
}

template < typename Object >
Forward_list<Object>::Forward_list ( const Forward_list & list ){
  this->m_head = new Node(); // Aloca a cabeça e calda para cópia profunda
  this->m_tail = new Node();
  this->m_size = list.m_size;
  *(this->m_head) = *(list.m_head);
  *(this->m_tail) = *(list.m_tail);
}

template < typename Object >
Forward_list<Object>::Forward_list ( Forward_list && list){ // Construtor move do Forward_list
  this->m_size = list.m_size;
  this->m_head = list.m_head;
  this->m_tail = list.m_tail;
  list.m_size = 0;
  list.m_head = nullptr;
  list.m_tail = nullptr;
}

template < typename Object >
Forward_list & Forward_list<Object>::operator = ( const Forward_list & list){
  Forward_list * Forward_list_copy = new Forward_list(list); // Objeto que será retornado pela função
  this->m_size = list.m_size; // Cópia profunda dos elementos
  *(this->m_head) = *(list.m_head);
  *(this->m_tail) = *(list.m_tail);
  return Forward_list_copy;
}

template < typename Object >
Forward_list & Forward_list<Object>::operator = ( Forward_list && list){
  Forward_list * Forward_list_move = new Forward_list(list);
  this->m_size = Forward_list_move->m_size; // Cópia profunda dos elementos
  *(this->m_head) = *(Forward_list_move->m_head);
  *(this->m_tail) = *(Forward_list_move->m_tail);
  return Forward_list_move;
}

template < typename Object >
iterator Forward_list<Object>::before_begin (){
  Node * bef_begin = new Node(); // Elemento que aponta para o m_head
  bef_begin->next = m_head;
  iterator * it = new iterator(bef_begin);
  return it; // Retorna o iterator
}

template < typename Object >
const_iterator Forward_list<Object>::cbefore_begin() const{
  Node * bef_begin = new Node(); // Elemento que aponta para o m_head
  bef_begin->next = m_head;
  const_iterator * cit = new iterator(bef_begin);
  return cit; // Retorna o const_iterator
}
