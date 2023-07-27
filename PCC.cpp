
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

template <typename T>
class loc{
  public:
  T show();
};

template <class T>
inline T loc<T>::show() {return 0;}


//function member specialization 

template <>
inline int loc<int>::show() {return 0;}

// class specialization 

template <>
class loc<double>{
  public:
  double show();
};

//doesn't require template <>???
inline double loc<double>::show(){return 0;}

//-----------------


typedef void (*ABC)(int);

void f(int i){
    cout<<i;
}

int main()
{
    
    ABC r = f;
    //void (*r)(int) = f;
    void (*t)(int);
    t = f;
    (*t)(148);
    (*r)(8);

    return 0;
}


//-------------------
//How predicate determines a type of object
//(as function parameter)?

//this won't compile
template<class T>
bool foo(T r){
    return r;
}

template<class A,class F>
void bar(const A &tmp,F f){
    cout<<boolalpha<<(*f)(tmp);
}
int main()
{
    
    bar(3,foo);

    return 0;
}