#include <array>
#include <utility>

template <int N, int I = 0, typename T = std::array<char, 1>>
constexpr auto int_to_string(T t = {}) {
    if constexpr (N == 0) {
        if constexpr (I == 0) {
            return std::array{'0', '\0'};
        } else {
            return t;
        }
    } else {
        constexpr auto new_t = std::array{char('0' + N % 10), t[I], '\0'};
        return int_to_string<N / 10, I + 1>(new_t);
    }
}

template <int N>
constexpr auto int_to_string_v = int_to_string<N>().data();

int main() {
    constexpr auto str = int_to_string_v<12345>;
    static_assert(str[0] == '1');
    static_assert(str[1] == '2');
    static_assert(str[2] == '3');
    static_assert(str[3] == '4');
    static_assert(str[4] == '5');
}
