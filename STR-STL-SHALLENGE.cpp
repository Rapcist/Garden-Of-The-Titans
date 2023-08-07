//#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
//using namespace std;

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
