#define SIZE 30
class polynom{
  polynom(int size_) : size(size_){
    arr = new int[size_];   
  }
  size_t size;
  int *arr;
public:
  int length () const {
    return size;
  }
};
