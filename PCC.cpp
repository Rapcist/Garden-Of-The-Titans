
const int SIZE = 30;
class polynom{
  unsigned size;
  int *arr;
public:
  polynom(unsigned size_) : size(size_), arr(new int[size_]) {}
  unsigned length () const {
    return size;
  }
};

//---------------------

template <typename T> class loc{
    public:
    T show();
};

template <class T>
T loc<T>::show() {return (T)0;}


//function member specialization 

template <>
int loc<int>::show() {return 0;}

// class specialization 
template <> class loc<double>{
    public:
    double show();
};
double loc<double>::show(){return 0;}


