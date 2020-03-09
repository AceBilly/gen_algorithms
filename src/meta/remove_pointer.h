#pragma once
// copyright 2020 yht SegmentFault
// meta funciotn

namespace algor_yht {
namespace meta {
template <typename T>
struct remove_pointer {
  using type = T;
};
template <typename T>
struct remove_pointer<T*> {
  using type = T;
};
template <typename T>
struct remove_pointer<const T*> {
  using type = const T;
};
}  // namespace meta
}  // namespace algor_yht
