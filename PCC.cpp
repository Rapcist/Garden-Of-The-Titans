
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
    vector<int>::iterator p1;
    p1=arr.begin();
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
        T ptr = st++;
        while(ptr!=en){
            if(*st>*ptr++) sum++;
        }
    }
    return sum%2;
}

int main()
{
    vector<int> a={1,2,3,4};
    for(auto el:a)cout<<el;
    cout<<endl;
    while(next_permutation(a.begin(),a.end())){
        
        if(!per_sign(a.begin(),a.end())){
            for(auto el:a) cout<<el;
            cout<<' ';
            vector<int> tmp = cycles_gen(a);
            for(auto el:tmp)cout<<el;
            cout<<endl;
        }
    }

    return 0;
}
