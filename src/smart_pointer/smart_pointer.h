#pragma once
#include "../../inc/type.h"
// Copyright yht 2020 SegmentFaultCPP
namespace algor_yht {
namespace smart_pointer {
template <typename T>
class SmartPointer {
 public:
  SmartPointer() = default;
  // 构造函数 输入一个指向相应数据的有效指针
  explicit SmartPointer(T*(&p_src)) : m_ptr(p_src), count(new type::uint_t(0)) {
    if (m_ptr == nullptr) {
      *this->count = 0;
    } else {
      *this->count = 1;
    }
  }
  //  将一个指针托管给SmartPointer
  void operator=(T* ptr) {
    if (this->count == nullptr) {
      this->count = new int(1);
    } else if (*this->count == 0) {
      *this->count = 1;
    }
  }
  // 拷贝构造函数 若是输人这个对象的实例的话 则不做任何操作
  SmartPointer(const SmartPointer& sm) {
    if (this != &sm) {
      this->m_ptr = sm.m_ptr;
      this->count = sm.count;
      ++*count;
    }
  }
  // 提供右值构造函数， 转移数据所有权
  SmartPointer(const SmartPointer&& sm) {
    if (this != &sm) {
      this->m_ptr = sm.m_ptr;
      this->count = sm.count;
      sm.m_ptr = nullptr;
      sm.count = nullptr;
    }
  }
  // 重载拷贝赋值函数
  // 若输入一个 指向不同对象的指针那 那么 即使this对象中含有有效数据
  // 也会用sm中的数据覆盖 若输入的对象含有的有效数据
  // 指针指向的位值相同则返回*this
  SmartPointer& operator=(const SmartPointer& sm) {
    if (this != &(sm)) {
      reset();
      this->m_ptr = sm.m_ptr;
      this->count = sm.count;
      ++*count;
    }
    return *this;
  }
  SmartPointer& operator=(const SmartPointer&& sm) {
    if (this != &sm) {
      reset();
      this->m_ptr = sm.m_ptr;
      this->count = sm.count;
      sm.count = nullptr;
      sm.m_ptr = nullptr;
    }
  }
  T& operator*() const {
    if (this->m_ptr != nullptr) {
      return *(this->m_ptr);
    }
    throw "Error access nullptr";  // error handle 以后重写
  }
  T* operator->() const {
    if (this->m_ptr != nullptr) {
      return (this->m_ptr);
    }
    throw "access nullptr";
  }
  virtual ~SmartPointer() {
    if (this->count != nullptr && this->m_ptr != nullptr) {
      reset();
    }
  }

 protected:
  T* m_ptr = nullptr;
  algor_yht::type::uint_t* count = nullptr;
  // 重置当前对象
 private:
  inline void reset() {
    --*count;
    if (this->count == 0) {
      delete this->m_ptr;
      delete this->count;
    }
    this->m_ptr = nullptr;
    this->count = nullptr;
  }
};
}  // namespace smart_pointer
}  // namespace algor_yht