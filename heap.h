#ifndef HEAP_H
#define HEAP_H
#include <vector>
//#include <functional>
#include <stdexcept>

//paing a compareter  the name is eventLess
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator())
  {
    comp = c;
  }

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap()
  {
    
  }

	  // get left child index
  int leftChild(int parent_index) const {
    return parent_index * 2 + 1;
  }

  // get right child index
  int rightChild(int parent_index) const {
    return parent_index * 2 + 2;
  }

  // get parent index
  int getParent(int child_index) const {
    return (child_index - 1) / 2;
  }


  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item){
    int index = size();
    array_.push_back(item);
    // heapify
    while(index > 0) {
      int parent_index = getParent(index);
      if (comp(array_[parent_index], array_[index])) {
        break;
      } else {
        std::swap(array_[parent_index], array_[index]);
        index = parent_index;
      }
    }
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const{
    return array_.empty();
  }
    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const
	{
  	return array_.size();
  }

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> array_;
	PComparator comp;



};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename P>
T const & Heap<T,P>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Top from empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return array_.front();

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		 throw std::underflow_error("Pop from empty heap");
  }
  std::swap(array_.front(), array_.back());
  array_.pop_back();
  // fix the heap
  int index = 0;
  while(index < size()) {
    int left_index = leftChild(index);
    int right_index = rightChild(index);
    if (left_index >= size()) {
      // No children
      break;
    }
    if (right_index >= size()) {
      if (comp(array_[index], array_[left_index])) {
        break;
      } else {
        std::swap(array_[index], array_[left_index]);
        index = left_index;
        continue;
      }
    }

    if(comp(array_[index], array_[left_index]) && comp(array_[index], array_[right_index])) {
      // parent has higher priority than both children
      break;
    }
    
    if (comp(array_[left_index], array_[right_index])) {
      if (comp(array_[index], array_[left_index])) {
        std::swap(array_[index], array_[right_index]);
        index = right_index;
      } else {
        std::swap(array_[index], array_[left_index]);
        index = left_index;
      }
    }
    else {
      if (comp(array_[index], array_[right_index])) {
        std::swap(array_[index], array_[left_index]);
        index = left_index;
      } else {
        std::swap(array_[index], array_[right_index]);
        index = right_index;
      }
    }
  }
}
#endif

