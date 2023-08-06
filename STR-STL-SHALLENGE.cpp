#include <iostream>
#include <algorithm>

using namespace std;

class StrType{
  vector<char> s;
public:

  StrType();
  StrType(const StrType &ob);
  StrType(const char *cs);

  friend istream & operator>>(istream &stream, const StrType & in);
  friend ostream & operator<<(ostream &stream, const StrType & out);

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
  
}