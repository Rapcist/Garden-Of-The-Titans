#include <algorithm>
#include <vector>
#include <stdexcept>

namespace MyStr{ 

  const int myPos {255};
  
//simple analog unique_ptr<char> (smart pointer)
 class CharPtr{
	 
	char *m_ptr {nullptr};
	
public:
	//CONSTRUCTORS DESTRUCTORS COPYes 
	constexpr CharPtr() = default ;
	explicit CharPtr(char *ob}  : m_ptr{ob} {}
	CharPtr (const CharPtr & ob) = delete;
	CharPtr & operator=(CharPtr & ob}  {m_ptr = ob.m_ptr; ob.m_ptr = nullptr; return *this;}
	~CharPtr()  {if(!m_ptr) delete [] m_ptr;}
	
	//METHODS
	std::size_t length () const {std::size_t len{0}; while(m_ptr[len]) ++len; return len;}
	bool isEmpty() const {return m_ptr == nullptr;}
	char & operator*() {return *m_ptr;}
	char & operator[](std::size_t pos) noexcept {
		if(pos<=length()) return m_ptr[pos];
	}
	char * data() {return m_ptr;}
	
 };
 
 class StrType{ 
   //CONTAINER AND ITERATORS
   using cont_t = std::vector<char>; 
   using iter_t = cont_t::iterator; 
   using coiter_t = cont_t::const_iterator;
   
   cont_t m_str; 
   CharPtr m_ptr;
 public: 
  
   StrType() = default; 
   StrType(const StrType &ob) : m_str{ob.m_str} {}
   StrType(const char *cs); 
   ~StrType() = default;
   

  
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
   bool operator ==(const char * cs)const { 
     return equal(m_str.begin(),m_str.end(),StrType(cs).m_str.begin()); 
   } 
   bool operator <(const char * cs) const{ 
     std::size_t i=0; 
     for(;cs[i];++i); 
     return lexicographical_compare(m_str.begin(),m_str.end(),cs,cs+i); 
   } 
  
   bool operator !=(const char * cs) const {return !(*this==StrType(cs));} 
   bool operator >=(const char * cs) const {return !(*this<StrType(cs));} 
   bool operator >(const char * cs) const {return !(*this<StrType(cs) && *this!=StrType(cs));} 
   bool operator <=(const char * cs) const {return !(*this>StrType(cs));} 
  
   std::size_t strsize() const {return m_str.size();} 
   
   void makestr(char *str){
     iter_t p { m_str.begin()} ; 
     while(str && p!=m_str.end()){ 
      *str++ = *p++; 
     } 
   } 
  
   operator char *(){ 
     if(m_ptr.isEmpty()){ 
     std::size_t len { m_str.size()}; 
     m_ptr { new char[len+1]}; 
     iter_t p { m_str.begin()}; 
     for(std::size_t i{0};p != m_str.end();++i){ 
       m_ptr[i]=*p++; 
     } 
     m_ptr[len]='\0'; 
     } 
     return m_ptr.data(); 
  
   } 
 }; 
//|=============================|
//|END OF THE SCOPE OF THE CLASS|
//|=============================|
  
 StrType::StrType(const char *cs){ 
   for(std::size_t i{0};cs[i];++i){ 
     m_str.push_back(cs[i]); 
   } 
 } 
 std::istream & operator>>(std::istream &stream, StrType & ob){ 
   char c[myPos]; 
   cont_t tmp;
   stream.getline(c,myPos-1); 
   for(std::size_t i=0;c[i];++i){ 
     tmp.push_back(c[i]); 
   } 
   m_str = tmp;
   return stream; 
 } 
  
 std::ostream & operator<<(std::ostream &stream, const StrType & ob){ 
   coiter_t p {ob.m_str.begin()}; 
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
   std::size_t i{0}; 
   for(;cs[i];++i); 
   s.assign(cs,cs+i); 
   return *this; 
 } 
  
 StrType StrType::operator+(const StrType &ob) const{ 
   StrType tmp {*this};
   coiter_t p=ob.m_str.begin(); 
   while(p!=ob.m_str.end()){ 
     tmp.m_str.push_back(*p++); 
   } 
   return tmp; 
 } 
 StrType StrType::operator+(const char* cs) const{ 
   StrType tmp {*this}; 
   for(std::size_t i{0};cs[i];++i){ 
     tmp.m_str.push_back(cs[i]); 
   } 
   return tmp; 
 } 
  
 StrType operator+(const char* cs,const StrType &ob){    
    StrType tmp {cs}; 
    tmp.m_str.insert(tmp.m_str.end(),ob.m_str.begin(),ob.m_str.end()); 
    return tmp; 
 } 
  
  //SUBTRACTING ALL SUBSTINRGS
 StrType StrType::operator-(const StrType &ob) const{ 
   std::size_t i {0}; 
   StrType tmp; 
   iter_t p { m_str.begin()}; 
   while(p!=m_str.end()){ 
     if(ob.m_str[0]!=*p) tmp.m_str.push_back(*p++); 
     else{ 
       for( i{0};p+i!=m_str.end()&&p[i]==ob.m_str[i];++i); 
       if(i==ob.m_str.size()) p+=i; 
       else tmp.m_str.push_back(*p++); 
     } 
   } 
   return tmp; 
 } 
 StrType StrType::operator-(const char* cs) const{ 
   return (*this)-StrType(cs); 
 } 
  
 }
//|=========================================|
//|END OF THE SCOPE OF THE NAMESPACE "MyStr"|
//|=========================================|
