#include <algorithm>
#include <vector>

//IT'S ALIVE!!!im not:(
namespace MyStr{ 
  constexpr int myPos {255};
  using cont_t = std::vector<char>; 
  using iter_t = cont_t::iterator; 
  using coiter_t = cont_t::const_iterator;

 class StrType{ 
   cont_t m_str; 
   char *m_ptr = nullptr; 
 public: 
  
   constexpr StrType() = default; 
   constexpr StrType(const StrType &ob); 
   constexpr StrType(const char *cs); 
  
   ~StrType() { 
 // "if" because of the abundance of tmp-objects 
     if(m_ptr) delete [] m_m_ptr;  
   } 
  
   friend std::istream & operator>>(std::istream &stream, StrType & ob); 
   friend std::ostream & operator<<(std::ostream &stream, const StrType & ob); 
  
   StrType & operator=(const StrType &ob); 
   StrType & operator=(const char * cs); 
  
   StrType operator+(const StrType &ob) const; 
   StrType operator+(const char* cs) const; 
   friend StrType operator+(const char* cs,const StrType &ob); 
  
   StrType operator-(const StrType &ob) const; 
   StrType operator-(const char* cs) const; 
  
   //relational with StrType 
   bool operator ==(const StrType & ob) const{ 
     return equal(m_str.begin(),m_str.end(),ob.m_str.begin()); 
   } 
   bool operator <(const StrType & ob) const{ 
     return lexicographical_compare(m_str.begin(),m_str.end(),ob.m_str.begin(),ob.m_str.end()); 
   } 
   
   bool operator !=(const StrType & ob) const {return !(*this==ob);} 
   bool operator >=(const StrType & ob) const {return !(*this<ob);} 
   bool operator >(const StrType & ob) const {return !(*this<ob && *this!=ob);} 
   bool operator <=(const StrType & ob) const {return !(*this>ob);} 
  
   //relational with Char * 
   bool operator ==(const char * cs) { 
     std::size_t i=0; 
     for(;cs[i];++i); 
     return equal(m_str.begin(),m_str.end(),StrType(cs).m_str.begin()); 
   } 
   bool operator <(const char * cs){ 
     std::size_t i=0; 
     for(;cs[i];++i); 
     return lexicographical_compare(m_str.begin(),m_str.end(),cs,cs+i); 
   } 
  
   bool operator !=(const char * cs) {return !(*this==StrType(cs));} 
   bool operator >=(const char * cs) {return !(*this<StrType(cs));} 
   bool operator >(const char * cs) {return !(*this<StrType(cs) && *this!=StrType(cs));} 
   bool operator <=(const char * cs) {return !(*this>StrType(cs));} 
  
   std::size_t strsize() const {return m_str.size();} 
   void makestr(char *str){ 
     iter_t p = m_str.begin(); 
     while(p!=m_str.end()){ 
      *str++ = *p++; 
     } 
   } 
  
   operator char *(){ 
     if(!m_ptr){ 
     std::size_t len = m_str.size(); 
     m_ptr = new char[len+1]; 
     iter_t p = m_str.begin(); 
     for(std::size_t i=0;p != m_str.end();++i){ 
       m_ptr[i]=*p++; 
     } 
     m_ptr[len]='\0'; 
     } 
     return m_ptr; 
  
   } 
 }; 
  
  
 StrType::StrType(const StrType &ob): m_str(ob.m_str){ 

 } 
  
 StrType::StrType(const char *cs){ 
   for(std::size_t i=0;cs[i];++i){ 
     m_str.push_back(cs[i]); 
   } 
 } 
 std::istream & operator>>(std::istream &stream, StrType & ob){ 
   char c[myPos]; 
   stream.getline(c,myPos-1); 
   ob.m_str.erase(ob.s.begin(),ob.s.end()); 
   for(std::size_t i=0;c[i];++i){ 
     ob.m_str.push_back(c[i]); 
   } 
   return stream; 
 } 
  
 std::ostream & operator<<(std::ostream &stream, const StrType & ob){ 
   coiter_t p=ob.m_str.begin(); 
   while(p!=ob.m_str.end()){ 
     stream<<*p++; 
   } 
   return stream; 
 } 
  
 StrType & StrType::operator=(const StrType &ob){ 
   m_str.assign(ob.m_str.begin(),ob.m_str.end()); 
   return *this; 
 } 
  
 StrType & StrType::operator=(const char * cs){ 
   std::size_t i=0; 
   for(;cs[i];++i); 
   s.assign(cs,cs+i); 
   return *this; 
 } 
  
 StrType StrType::operator+(const StrType &ob){ 
   auto tmp = StrType(); 
   tmp.s.assign(m_str.begin(),m_str.end()); 
   coiter_t p=ob.m_str.begin(); 
   while(p!=ob.m_str.end()){ 
     tmp.m_str.push_back(*p++); 
   } 
   return tmp; 
 } 
 StrType StrType::operator+(const char* cs){ 
   auto tmp = StrType(); 
   tmp.m_str.assign(s.begin(),s.end()); 
   for(std::size_t i=0;cs[i];++i){ 
     tmp.m_str.push_back(cs[i]); 
   } 
   return tmp; 
 } 
  
 StrType operator+(const char* cs,const StrType &ob){    
   auto tmp = StrType(); 
   for(int i=0;cs[i];++i){ 
     tmp.m_str.push_back(cs[i]); 
   } 
       tmp.m_str.insert(tmp.m_str.end(),ob.m_str.begin(),ob.m_str.end()); 
     return tmp; 
 } 
  
 StrType StrType::operator-(const StrType &ob){ 
   std::size_t i = 0; 
   auto tmp = StrType(); 
   iter_t p = m_str.begin(); 
   while(p!=m_str.end()){ 
     if(ob.m_str[0]!=*p) tmp.m_str.push_back(*p++); 
     else{ 
       for( i=0;p+i!=m_str.end()&&p[i]==ob.m_str[i];++i); 
       if(i==ob.m_str.size()) p+=i; 
       else tmp.m_str.push_back(*p++); 
     } 
   } 
   return tmp; 
 } 
 StrType StrType::operator-(const char* cs){ 
   return (*this)-StrType(cs); 
 } 
  
 }
