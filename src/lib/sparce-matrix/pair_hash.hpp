#include <cstdint>
#include <utility>

struct pair_fast_hash {
  std::size_t operator()(const std::pair<int32_t, int32_t>& p) const {
    uint32_t x_bits = static_cast<uint32_t>(p.first);
    uint32_t y_bits = static_cast<uint32_t>(p.second);

    uint64_t packed = (static_cast<uint64_t>(x_bits) << 32) | y_bits;

    return static_cast<std::size_t>(
        packed);  // in case of 64-bit size_t, this will be a no-op, but in case of 32-bit size_t,
                  // it will truncate the value.
  }
};