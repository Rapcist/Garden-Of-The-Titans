
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
//upd you f*ing idiot, check the predicate definition
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

//-------------------
//hehehe
#include <iostream>
#include <iterator>

using namespace std;

int main() {
  istream_iterator<char> in_it(cin);
  do { 
    cout << *in_it++;
  } while (*in_it != '.');
  return 0;
}

//------------------
//Elements of Group A4
//(i.e. ,all even permutations)

//0es - delimiters for cycles

//Maybe replace returns with
//somewhat references
//in routines ?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> cycles_gen( vector<int> & arr){
    vector<int> new_one;
    auto p1=arr.begin();
    while(p1!=arr.end()){
        if(find(new_one.begin(),new_one.end(),
        *p1)!=new_one.end()) {
           // cout<<*p1;
            p1++;
            continue;
  
        }
        int tmp = *p1;
        do{
            new_one.push_back(tmp);
            tmp=arr[tmp-1];
        }while(tmp!=*p1);
        new_one.push_back(0);
        p1++;
    }
    
   return new_one ;
}

template <class T>
bool per_sign(T st,T en){
    size_t sum = 0;
    while(st!=en){
        auto ptr = st+1;
        while(ptr!=en){
            if(*st>*ptr++) sum++;
        }
        st++;
    }
    return sum%2;
}

int main()
{
    vector<int> a{1,2,3,4};
    size_t r {0};
    bool red {true};
    while(red){
        
        if(!per_sign(a.begin(),a.end())){
            ++r;
            for(auto el:a) cout<<el;
            cout<<' ';
            vector<int> tmp = cycles_gen(a);
            for(auto el:tmp)cout<<el;
            cout<<endl;
        }
        red = next_permutation(a.begin(),a.end());
    }
    cout<<r;
    return 0;
}
}
//-----------------
class cycle{
    int *a;
    int length;
    
    public:
    cycle(int n=0) : length(n){
        if(n>0){
            try{
                a = new int[length];
            }
            catch(bad_alloc xa){
                exit(1);
            }
        }
        for(int i=1;i<=n;++i){
            a[i-1]=i;
        }
    }
    ~cycle(){
        if(length>0){
            delete [] a;
        }
    }
    cycle & operator=(const cycle &s){
        
    }
    cycle operator*(const cycle &s);
};
//-------++-
#include<iostream>
#include<string>
using namespace std;
class code{
    size_t siz=0;
    int *arr=nullptr;
    public:
    code(const string& s):arr(new int[s.size()]),siz(s.size()){
      for(size_t i=0;i<s.size();++i) arr[i]=s[i]%2;
    }
    const int *get() const{
        return arr;
    }
    size_t size() const{
        return siz;
    }
    const int operator[](size_t i) const{
        try{
            if(i>=siz) throw 0;
            return arr[i];
        }
        catch(...){
            cout<<"Un-or-Ov-flow";
            exit(1);
        }
    }
    

};

size_t dist(const code& s1,const code& s2){
    size_t sum = 0;
    size_t len = s1.size()>s2.size()?s2.size():s1.size();
    for(int i=0;i<len;++i){
        if(s1[i]!=s2[i]) sum++;
    }
    return sum;
}

int main()
{
    string ex[] ={"00110", "10011","01101","11000"};
    int max = 0;
    for(int i=0;i<4;++i){
        for(int j=i+1;j<4;++j) {
            if(dist(ex[i],ex[j])>max) max = dist(ex[i],ex[j]);
        }
    }
    cout<<max;
    return 0;
}

//-------------------
#include <utility>
#include <iostream>
class A{
    public:
    static constexpr int i{5};
    static const int j;
} ;

const int A::j = 7;

template<class T, class P>
auto f(T a,P b){
  return a>b?a:b;
}
int main()
{
  cout<<A::i<<endl;
pair two {6,one};
  auto [x,y] {two};
  cout<<x*(*y);
return 0;
}


//-------------------

template <typename U, typename T>
std::shared_ptr<T> make_aliased(const std::shared_ptr<U>& owner, T* ptr) {
    if (owner.use_count() == 0) return {};
    return std::shared_ptr<T>(owner, ptr);
}

//-------------------
// u are funny guy, Sally
#include<iostream>

using namespace std;
class B{
    virtual void foo() const { cout<<"B foo ";}
    public:
    friend void bar(const B & rhs, const B & lhs);
    virtual ~B() = default;
   
};
class D : public B{
    void foo() const override{
        cout<<"D foo ";
    }
};
void bar(const B & rhs, const B & lhs){
    rhs.foo();
    lhs.foo();
}
int main()
{
    B one;
    D two;
    bar( two, one);
    return 0;
}
//--------------
//
class A{
    public:
    A(int a) : i{a} {}
    
    explicit operator int() const{
        return i;
    }
    int i{0};
};
A operator+(const A & rhs, const A & lhs){
    return A{rhs.i*lhs.i };
}
int main()
{
    A one {4};
    int two {static_cast<int>(one)+3};
    int three {one + 3};
    cout<<two<<endl<<three;
    //7
    //12
    return 0;
}
//-----+-----+-------
#include<array>
#include<initializer_list>

class BasisEl{
  std::array<int,4> m_arr {0};
  public:
  BasisEl(std::initializer_list<int>);
  
  BasisEl operator+(
  BasisEl operator-
  BasisEl operator*



};
