#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::swap(CP::vector<T> &other)
{
  // your code here
  T *tempmData = other.mData;
  size_t tempmCap = other.mCap;
  size_t tempmSize = other.mSize;

  other.mData = this->mData;
  other.mCap = this->mCap;
  other.mSize = this->mSize;

  this->mData = tempmData;
  this->mCap = tempmCap;
  this->mSize = tempmSize;
}

#endif
