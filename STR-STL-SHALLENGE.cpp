#include <algorithm>
#include <vector>

//IT'S ALIVE!!!im not:(
namespace MyStr{

class StrType{
  typedef std::size_t msize_t;
  typedef std::vector<char> cont_t;
  typedef cont_t::iterator iter_t;
  typedef cont_t::const_iterator coiter_t

  static const int myPos = 255;
  cont_t s;
  char *ptr = nullptr;
public:

  StrType() = default;
  StrType(const StrType &ob);
  StrType(const char *cs);

  ~StrType() {
// "if" because of the abundance of tmp-objects
    if(ptr) delete [] ptr; 
  }

  friend istream & operator>>(istream &stream, StrType & ob);
  friend ostream & operator<<(ostream &stream, const StrType & ob);

  StrType & operator=(const StrType &ob);
  StrType & operator=(const char * cs);

  StrType operator+(const StrType &ob);
  StrType operator+(const char* cs);
  friend StrType operator+(const char* cs,const StrType &ob);

  StrType operator-(const StrType &ob);
  StrType operator-(const char* cs);

  //relational with StrType
  bool operator ==(const StrType & ob) {
    return equal(s.begin(),s.end(),ob.s.begin());
  }
  bool operator <(const StrType & ob){
    return lexicographical_compare(s.begin(),s.end(),ob.s.begin(),ob.s.end());
  }

  bool operator !=(const StrType & ob) {return !(*this==ob);}
  bool operator >=(const StrType & ob) {return !(*this<ob);}
  bool operator >(const StrType & ob) {return !(*this<ob && *this!=ob);}
  bool operator <=(const StrType & ob) {return !(*this>ob);}

  //relational with Char *
  bool operator ==(const char * cs) {
    msize_t i=0;
    for(;cs[i];++i);
    return equal(s.begin(),s.end(),StrType(cs).s.begin());
  }
  bool operator <(const char * cs){
    msize_t i=0;
    for(;cs[i];++i);
    return lexicographical_compare(s.begin(),s.end(),cs,cs+i);
  }

  bool operator !=(const char * cs) {return !(*this==StrType(cs));}
  bool operator >=(const char * cs) {return !(*this<StrType(cs));}
  bool operator >(const char * cs) {return !(*this<StrType(cs) && *this!=StrType(cs));}
  bool operator <=(const char * cs) {return !(*this>StrType(cs));}

  msize_t strsize() const {return s.size();}
  void makestr(char *str){
    iter_t p = s.begin();
    while(p!=s.end()){
     *str++ = *p++;
    }
  }

  operator char *(){
    if(!ptr){
    msize_t len = s.size();
    ptr = new char[len+1];
    iter_t p = s.begin();
    for(msize_t i=0;p != s.end();++i){
      ptr[i]=*p++;
    }
    ptr[len]='\0';
    }
    return ptr;
    
  }
};

/*StrType::StrType(){
  //???
}*/

StrType::StrType(const StrType &ob){
  coiter_t p= ob.s.begin();
  while(p!=ob.s.end()){
    s.push_back(*p++);
  }
}

StrType::StrType(const char *cs){
  for(msize_t i=0;cs[i];++i){
    s.push_back(cs[i]);
  }
}
istream & operator>>(istream &stream, StrType & ob){
  char c[myPos];
  stream.getline(c,myPos-1);
  ob.s.erase(ob.s.begin(),ob.s.end());
  for(msize_t i=0;c[i];++i){
    ob.s.push_back(c[i]);
  }
  return stream;
}

ostream & operator<<(ostream &stream, const StrType & ob){
  coiter_t p=ob.s.begin();
  while(p!=ob.s.end()){
    stream<<*p++;
  }
  return stream;
}

StrType & StrType::operator=(const StrType &ob){
  s.assign(ob.s.begin(),ob.s.end());
  return *this;
}

StrType & StrType::operator=(const char * cs){
  msize_t i=0;
  for(;cs[i];++i);
  s.assign(cs,cs+i);
  return *this;
}

StrType StrType::operator+(const StrType &ob){
  auto tmp = StrType();
  tmp.s.assign(s.begin(),s.end());
  coiter_t p=ob.s.begin();
  while(p!=ob.s.end()){
    tmp.s.push_back(*p++);
  }
  return tmp;
}
StrType StrType::operator+(const char* cs){
  auto tmp = StrType();
  tmp.s.assign(s.begin(),s.end());
  for(msize_t i=0;cs[i];++i){
    tmp.s.push_back(cs[i]);
  }
  return tmp;
}

StrType operator+(const char* cs,const StrType &ob){   
  auto tmp = StrType();
  for(int i=0;cs[i];++i){
    tmp.s.push_back(cs[i]);
  }
      tmp.s.insert(tmp.s.end(),ob.s.begin(),ob.s.end());
    return tmp;
}

StrType StrType::operator-(const StrType &ob){
  msize_t i = 0;
  auto tmp = StrType();
  iter_t p = s.begin();
  while(p!=s.end()){
    if(ob.s[0]!=*p) tmp.s.push_back(*p++);
    else{
      for( i=0;p+i!=s.end()&&p[i]==ob.s[i];++i);
      if(i==ob.s.size()) p+=i;
      else tmp.s.push_back(*p++);
    }
  }
  return tmp;
}
StrType StrType::operator-(const char* cs){
  return (*this)-StrType(cs);
}


}
