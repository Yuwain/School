/******************************************************************************
    Written by:     Jeremy High
    Student ID:     103306452
    Written on:     February 25th, 2014

    This program defines an array of boolean values and some necessary
    operations to smoothly run.

    The class declaration should really be in a separate header file,
    but the assignment asks otherwise.
******************************************************************************/
#include <cstddef>
#include <cstring>
#include <limits>
#include <iostream>

/* Definitions outside bool_array class to improve readability */
template <std::size_t N>
class bool_array {
  public:
    using size_type = std::size_t;
    using value_type = bool;

    bool_array();

    bool_array(bool_array const& a);
    bool_array& operator =(bool_array const& a);
    
    ~bool_array() = default;

    constexpr size_type size() const;

  private:
    class bit_proxy {
      public:
        bit_proxy() = delete;

        bit_proxy(bit_proxy const&) = default;
        bit_proxy& operator =(bit_proxy const&) = default;

        bit_proxy(bit_proxy&&) = default;
        bit_proxy& operator =(bit_proxy&&) = default;

        ~bit_proxy() = default;

        bit_proxy(unsigned char& datum, size_type offset);
        
        bit_proxy& operator =(bool b);

        operator bool() const;

      private:
        unsigned char& datum_;
        size_type offset_;
    };

  public:
    bit_proxy operator [](size_type i);

  private:
    static constexpr auto MAX =
      N / std::numeric_limits<unsigned char>::digits 
      + (N % std::numeric_limits<unsigned char>::digits != 0)
    ;

    unsigned char bits_[MAX];
};

/* bool_array definitions */

/* Default constructor */
template <std::size_t N>
bool_array<N>::bool_array() {
  std::memset(bits_, 0, MAX);
}

/* Copy constructor */
template <std::size_t N>
bool_array<N>::bool_array(bool_array const& a) {
  std::memcpy(bits_, a.bits_, MAX);
}

/* Copy assignment operator */
template <std::size_t N>
bool_array<N>& bool_array<N>::operator =(bool_array const& a) {
  std::memcpy(bits_, a.bits_, MAX);
  
  return *this;
}


template <std::size_t N>
constexpr std::size_t bool_array<N>::size() const {
  return N; //bool_array's size
}

/*bit_proxy definitions */

/* Array operator */
template <std::size_t N>
typename bool_array<N>::bit_proxy bool_array<N>::operator [](size_type i) {
 return bit_proxy{bits_[i / std::numeric_limits<unsigned char>::digits],
    i % std::numeric_limits<unsigned char>::digits}
 ;
}

/* Custom constructor for bit_proxy */
template <std::size_t N>
bool_array<N>::bit_proxy::bit_proxy(unsigned char& datum, size_type offset) : 
  datum_(datum), offset_(offset) { }

/* Bool assignment operator */
template <std::size_t N>
typename bool_array<N>::bit_proxy& bool_array<N>::bit_proxy::operator =(bool b) {
  unsigned char value {1};

  b ? datum_ |= (value << offset_) 
    : datum_ &= ~(value << offset_);
  
  return *this;
}

/* Bool cast operator */
template <std::size_t N>
bool_array<N>::bit_proxy::operator bool() const {
  unsigned char value {1};

  return (datum_ & (value << offset_)) != 0;
}


/* Several tests to make sure code is valid */
int main() {
  using std::cout;
  using std::endl;

  bool_array<13> test;

  cout << endl << "Default constructor called. This should be " 
       << test.size() << " 0s" << endl;
  for (unsigned i = 0; i != 13; ++i) {
    cout << i << ": " << test[i] << endl;
  }

  cout << endl << "Set all bits from 0 to 1" << endl;
  for (unsigned i = 0; i != 13; ++i) {
    cout << i << ": " << test[i] << " -> ";
    test[i] = true;
    cout << test[i] << endl;
  }

  cout << endl << "Print all bits to ensure nothing changed unexpectedly. "
       << "This should be all 1s" << endl;
  for (unsigned i = 0; i != 13; ++i) {
    cout << i << ": " << test[i] << endl;
  }

  cout << endl << "Set every other bit to 0" << endl;
  for (unsigned i = 0; i != 13; ++i) {
    cout << i << ": " << test[i] << " -> ";
    test[i] = (i % 2) ? false : test[i];
    cout << test[i] << endl;
  }

  bool_array<13> test_2 = test;

  cout << endl << "Copy old array to a new one with copy constructor. "
       << "Nothing should change" << endl;
  for (unsigned i = 0; i != 13; ++i) {
    cout << i << ": " << test_2[i] << endl;
  }

  cout << endl << "Test bool cast operator by checking if bit n is set" << endl;
  for (unsigned i = 0; i != 13; ++i) {
    cout << i << ": ";
    test[i] ? cout << "Set \n" : cout << "Not set \n";
  }

  cout << endl;

  return 0;
}
