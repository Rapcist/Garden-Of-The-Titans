#include <algorithm>
#include <vector>
#include <iterator>

namespace MyStr{

class StrType{
  vector<char> s;
public:

  StrType();
  StrType(const StrType &ob);
  StrType(const char *cs);

  friend istream & operator>>(istream &stream, const StrType & ob);
  friend ostream & operator<<(ostream &stream, const StrType & ob);

  StrType operator=(const StrType &ob);
  StrType operator=(const char * cs);

  StrType operator+(const StrType &ob);
  StrType operator+(const char* cs);
  friend StrType operator+(const char* cs,const StrType &ob);

  StrType operator-(const StrType &ob);
  StrType operator-(const char* cs);

  //relational with StrType
  bool operator ==(const StrType & ob) {
    return equal(s.begin(),s.end(),ob.s.begin(),ob.s.end());
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
    int i{};
    for(;cs[i];++i);
    return equal(s.begin(),s.end(),cs,cs+i);
  }
  bool operator <(const char * cs){
    int i{};
    for(;cs[i];++i);
    return lexicographical_compare(s.begin(),s.end(),cs,cs+i);
  }

  bool operator !=(const char * cs) {return !(*this==ob);}
  bool operator >=(const char * cs) {return !(*this<ob);}
  bool operator >(const char * cs) {return !(*this<ob && *this!=ob);}
  bool operator <=(const char * cs) {return !(*this>ob);}

  int strsize() const {return s.size();}
  void makestr(char *str){
    vector<char>::iterator p = s.begin();
    while(p!=s.end()){
     *s++ = *p++;
    }
  }

  operator char *(){
    int len = s.size();
    char *tmp=new(nothrow) char[len+1];
    if(tmp) exit(3);
    for(int i=0;i<len;++i){
      tmp[i]=s[i];
    }
    tmp[s.size]='\0';
    return tmp;
  }
};

StrType::StrType(){
  //????
}

StrType::StrType(const StrType &ob){
  vector<char>::iterator p=ob.s.begin();
  while(p!=ob.end()){
    s.push_back(*p);
    p++;
  }
}

StrType::StrType(const char *cs){
  for(int i=0;cs[i];++i){
    s.push_back(cs[i]);
  }
}
istream & operator>>(istream &stream, const StrType & ob){
  char c[255];
  stream>>c;
  for(int i=0;c[i];++i){
    s.push_back(c[i]);
  }
  return stream;
}

ostream & operator<<(ostream &stream, const StrType & ob){
  vector<char>::iterator p=s.begin();
  while(p!=s.end()){
    stream>>*p++;
  }
  return stream;
}

StrType::StrType operator=(const StrType &ob){
  s.assign(ob.s.begin(),ob.s.end());
}

StrType::StrType operator=(const char * cs){
  int i{};
  for(;cs[i];++i);
  s.assign(cs,cs+i);
}

StrType::StrType operator+(const StrType &ob){
  StrType tmp;
  tmps.s.assign(s.begin(),s.end());
  vector<char>::iterator p=ob.s.begin();
  while(p!=ob.s.end()){
    tmp.s.push_back(*p++);
  }
  return tmp;
}
StrType::StrType operator+(const char* cs){
  StrType tmp;
  tmp.s.assign(s.begin(),s.end());
  for(int i=0;cs[i];++i){
    tmp.s.push_back(cs[i]);
  }
  return tmp;
}

StrType operator-(const StrType &ob){
  
}
StrType operator-(const char* cs){
  
}

}
