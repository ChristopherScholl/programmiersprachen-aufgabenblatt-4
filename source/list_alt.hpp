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
class ListNode {
  public:
    ListNode<T>(T value, ListNode* prev, ListNode* next): value_(value), prev_(prev), next_(next) {}
    T         value_ = T ();
    ListNode* prev_ = nullptr;
    ListNode* next_ = nullptr;
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
  	/* Default-Konstruktor für leere Liste */
    List(): first_(nullptr), last_(nullptr), size_(0) {}

    /* Copy-Konstruktor für neue Liste, die einer anderen Liste gleicht */
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

  	/* diese Methode gibt den Iterator, der auf den Anfang der Liste zeigt, zurück */
    ListIterator<T> begin() {
  		////not implemented yet
    	return ListIterator<T>{};
    }

  	/* diese Methode gibt den Iterator, der auf das Ende (+1) der Liste zeigt, zurück */
    ListIterator<T> end() {
  		////not implemented yet
    	return ListIterator<T>{};
    }

    /* diese Methode löscht alle Elemente der Liste */
    void clear() {
  		////not implemented yet
    }

    /* diese Methode fügt ein Element an einer vorgesehenen Stelle ein */
    //TODO: member function insert

  	/* diese Methode dreht die Reihenfolge der Elemente in der Liste um */
    //TODO: member function reverse

    /* diese Methode fügt ein Element an den Anfang der Liste an */
    void push_front(T const& element) {
     
      ListNode<T>* nn;
      ListNode<T> new_node = ListNode(element, nullptr, first_);
      nn = &new_node;
      first_ = nn;
      size_ ++;
      if (size_ == 1) {
 //       last_ = std::addressof(new_node);
        last_ = nn;
      }
    }

    /* diese Methode fügt ein Element an das Ende der Liste an */
    void push_back(T const& element) {
      ListNode<T> new_node{element, last_, nullptr};
      last_ = std::addressof(new_node);
      size_++;
      if (size_ == 1) {
        first_ = std::addressof(new_node);
      }
    }

    /* diese Methode entfernt das erste Element der Liste */
    void pop_front() {
      if (!empty()) {
        if (size_ == 1) {
          first_ = nullptr;
          last_ = nullptr;
        }
        else {
          first_ = first_->next_;
          (*first_).prev_ = nullptr;
        }
        size_--;
      }
      // there is no need to tell if list is empty - we wanted to erase it anyway
    }

    /* diese Methode entfernt das letzte Element der Liste */
    void pop_back() {
    	assert(!empty());
		//not implemented yet
    }

  	/* diese Methode gibt das erste Element zurück */
    T& front() {
    	assert(!empty());
  		//not implemented yet
    	
    	return first_->(*value); //<- obviously wrong because of 
    				// returned reference to tmp-Object
    }

  	/* diese Methode gibt das letzte Element zurück */
    T& back() {
    	assert(!empty());

    	//not implemented yet

      return last_->(*value); //<- obviously wrong because of
    				// returned reference to tmp-Object
    }

  	/* diese Methode gibt zurück ob die Liste leer ist */
    bool empty() const {
      if (size_ == 0) {
        return true;
      }
      else {
        return false;
      }
    };

    /* diese Methode gibt die Anzahl der in der Liste enthaltenen Objekte zurück */
    std::size_t size() const{
      return size_;
    };


  private:
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
    ListNode<T> newNode;
};

/* ... */
//TODO: Freie Funktion reverse

/* ... */
//TODO: Freie Funktion operator+ (4.14)

#endif // # define BUW_LIST_HPP
