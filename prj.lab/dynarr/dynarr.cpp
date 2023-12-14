#include <dynarr/dynarr.hpp>

std::ostream& operator<<(std::ostream& out, DynArr a) {
  for (int i = 0; i < a.Size(); ++i)
    out << a[i] << " ";
  return out;
}