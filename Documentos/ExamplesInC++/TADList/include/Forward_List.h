#ifndef _FORWARD_LIST_H_
#define _FORWARD_LIST_H_

template < typename Object >
class Forward_list {

private:
  struct Node {
    Object data; // <! Data field
    Node * next; // <! Pointer to the next node in the list .
    // <! Basic constructor .
    Node( const Object & d = Object ( ) , Node * p = nullptr , Node * n = nullptr )
      : data ( d ), next ( n ) { /* Empty */ }
   };

public:
  class const_iterator {
    public:
      const_iterator ();
      const Object & operator * ( ) const;
      const_iterator & operator ++ ( ); // ++ it;
      const_iterator operator ++ ( int ); // it ++;
      bool operator == ( const const_iterator & rhs ) const;
      bool operator != ( const const_iterator & rhs ) const;
    protected:
      Node * current;
      const_iterator ( Node * p ) : current ( p ){/* Empty */};
      friend class Forward_list < Object >;
  };

  class iterator : public const_iterator {
    public:
      iterator ( ) : const_iterator () { /* Empty */ }
      const Object & operator* ( ) const;
      Object & operator* ( );

      iterator & operator++ ( );
      iterator operator++ ( int );
      iterator & operator-- ( );
      iterator operator-- ( int );
    protected:
      iterator ( Node *p ) : const_iterator ( p ){/* Empty */};
      friend class Forward_list < Object >;
  };

  Forward_list ();
  ~Forward_list ();
  Forward_list ( const Forward_list & list);
  Forward_list ( Forward_list && list);
  Forward_list & operator = ( const Forward_list & list);
  Forward_list & operator = ( Forward_list && list);
  iterator before_begin ();
  const_iterator cbefore_begin () const;
  iterator begin ();
  const_iterator cbegin () const;
  iterator end ();
  const_iterator cend () const;
  int size () const;
  bool empty () const;
  void clear ();
  Object & front ();
  const Object & front () const;
  Object & back ();
  const Object & back () const;
  void push_front ( const Object & x );
  void push_back ( const Object & x );
  void pop_front ();
  void pop_back ();
  void assign ( const Object & value );

  template < class InItr >

  void assing ( InItr first , InItr last );
  void assign ( std::initializer_list <Object> ilist );
  iterator insert_after ( const_iterator itr , const Object & x );
  iterator insert_after ( const_iterator pos , std::initializer_list <Object> ilist );
  iterator erase_after ( const_iterator itr );
  iterator erase_after ( const_iterator first , const_iterator last );
  const_iterator find ( const Object & x ) const;

private:
  int m_size;
  Node * m_head;
  Node * m_tail;
};

#include "Forward_list.inl"

#endif
