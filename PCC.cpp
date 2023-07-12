#define SIZE 30
class polynom{
  size_t size;
  int *arr;
public:
  polynom(size_t size_) : size(size_){
    arr = new int[size_];   
  }
  size_t length () const {
    return size;
  }
};
