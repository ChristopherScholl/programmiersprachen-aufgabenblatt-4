#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP
#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>
#include <type_traits>

#include <initializer_list>

template <typename T>
class List;

template <typename T>
struct ListNode {
  //ListNode(){}
  //ListNode (T v, ListNode* p, ListNode* n): value(v), prev(p), next(n){}
  T         value = T();
  ListNode* prev = nullptr;
  ListNode* next = nullptr;
};

template <typename T>
struct ListIterator {
  using Self              = ListIterator<T>;
  using value_type        = T;
  using pointer           = T*;
  using reference         = T&;
  using difference_type   = ptrdiff_t;
  using iterator_category = std::bidirectional_iterator_tag;


  /* DESCRIPTION  operator*() */
  T&  operator*()  const {
  	//not implemented yet
  	return {};
  } 

  /* DESCRIPTION  operator->() */
  T* operator->() const {
  	//not implemented yet
  	return nullptr;
  }

  /* ... */
  ListIterator<T>& operator++() {
  	//not implemented yet
  	return {};
  } //PREINCREMENT

  /* ... */
  ListIterator<T> operator++(int) {
  	//not implemented yet
  	return {};
  } //POSTINCREMENT (signature distinguishes)

  /* ... */
  bool operator==(ListIterator<T> const& x) const {
  	//not implemented yet
  }

  /* ... */
  bool operator!=(ListIterator<T> const& x) const {
  	//not implemented yet
  }

  /* ... */
  ListIterator<T> next() const {
    if (nullptr != node) {
      return ListIterator{node->next};
    } else {
      return ListIterator{nullptr};
    }
  }


  ListNode <T>* node = nullptr;
};



template <typename T>
class List {
  public:
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    // not implemented yet
    // do not forget about the initialiser list !
  	/* Default-Konstruktor f�r leere Liste */
    List(): first_(nullptr), last_(nullptr), size_(0) {}

    /* Copy-Konstruktor f�r neue Liste, die einer anderen Liste gleicht */
    //TODO: Copy-Konstruktor using Deep-Copy semantics (Aufgabe 4.8)

  	/* ... */
    //TODO: Move-Konstruktor (Aufgabe 4.13)

    //TODO: Initializer-List Konstruktor (4.14)
  	/* ... */
    List(std::initializer_list<T> ini_list) {
  		//not implemented yet
    }

  	/* ... */
    //TODO: Assignment operator (Aufgabe 4.12)

  	/* ... */
    //TODO: operator== (Aufgabe 4.7)

  	/* ... */
    //TODO: operator!= (Aufgabe 4.7)

  	/* ... */
    ~List() {
  		//TO IMPLEMENT PROPERLY
    }

  	/* diese Methode gibt den Iterator, der auf den Anfang der Liste zeigt, zur�ck */
    ListIterator<T> begin() {
  		////not implemented yet
    	return ListIterator<T>{};
    }

  	/* diese Methode gibt den Iterator, der auf das Ende (+1) der Liste zeigt, zur�ck */
    ListIterator<T> end() {
  		////not implemented yet
    	return ListIterator<T>{};
    }

    /* diese Methode l�scht alle Elemente der Liste */
    void clear() {
  		////not implemented yet
    }

    /* diese Methode f�gt ein Element an einer vorgesehenen Stelle ein */
    //TODO: member function insert

  	/* diese Methode dreht die Reihenfolge der Elemente in der Liste um */
    //TODO: member function reverse

    /* diese Methode f�gt ein Element an den Anfang der Liste an */
    void push_front(T const& element) {
      auto new_node = new ListNode<T>{ element,nullptr,first_ };
      if (!empty()) {
        first_->prev = new_node;
      }
      else {
        last_ = new_node;
      }
      first_ = new_node;
      size_++;
    }

    /* diese Methode f�gt ein Element an das Ende der Liste an */
    void push_back(T const& element) {
      auto new_node = new ListNode<T>{ element,last_,nullptr };
      if (!empty()) {
        last_->next = new_node;
      }
      else {
        first_ = new_node;
      }
      last_ = new_node;
      size_++;
    }

    /* diese Methode entfernt das erste Element der Liste */
    void pop_front() {
      if (!empty()) {
        if (size_ == 1) {
          first_ = nullptr;
          last_ = nullptr;
        }
        else {
          first_ = first_->next;
          first_->prev = nullptr;
        }
        size_--;
      }
    }

    /* diese Methode entfernt das letzte Element der Liste */
    void pop_back() {
      if (!empty()) {
        if (size_ == 1) {
          first_ = nullptr;
          last_ = nullptr;
        }
        else {
          last_ = last_->prev;
          last_->next = nullptr;
        }
        size_--;
      }
    }

    /* diese Methode gibt das erste Element zur�ck */
    T& front() {
      assert(!empty());
      return (*first_).value;
    }

    /* diese Methode gibt das letzte Element zur�ck */
    T& back() {
      assert(!empty());
      return (*last_).value;
    }

  	/* diese Methode gibt zur�ck ob die Liste leer ist */
    bool empty() const {
      if (size_ == 0) {
        return true;
      }
      else {
        return false;
      }
    };

    /* diese Methode gibt die Anzahl der in der Liste enthaltenen Objekte zur�ck */
    std::size_t size() const{
      return size_;
    };


  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
    ListNode<T>* node;
};

/* ... */
//TODO: Freie Funktion reverse

/* ... */
//TODO: Freie Funktion operator+ (4.14)

#endif // # define BUW_LIST_HPP
