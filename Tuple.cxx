#include <iostream>
#include <tuple>

template<class Tuple, size_t... Sequence>
void printer(const Tuple &t) 
{
    ((std::cout<<(Sequence ? "," : "") <<std::get<Sequence>(t)), ...);
    std::cout<<"\n";
}

//It  exapands
template<>
void printer<std::tuple<int, double, std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, 0, 1, 2>
      (const std::tuple<int, double, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > & t)
{
  (std::operator<<(std::cout, (static_cast<bool>(0UL) ? "," : "")).operator<<(std::get<0UL>(t))) , 
  ((std::operator<<(std::cout, (static_cast<bool>(1UL) ? "," : "")).operator<<(std::get<1UL>(t))) , 
  (std::operator<<(std::operator<<(std::cout, (static_cast<bool>(2UL) ? "," : "")), std::get<2UL>(t))));
  std::operator<<(std::cout, "\n");
}

template<class Tuple, size_t... Sequence>
void printer(const Tuple &t, std::index_sequence<Sequence...>) 
{
    ((std::cout<<(Sequence ? "," : "") <<std::get<Sequence>(t)), ...);
    std::cout<<"\n";
}

template <typename... Args>
void print(const std::tuple<Args...> &t)
{
     std::cout<<"Template Tuple\n";
    printer(t, std::index_sequence_for<Args...>{});
}

template <class Tuple>
void print( Tuple &t)
{
    std::cout<<"Template\n";
    printer(t, std::make_index_sequence<std::tuple_size_v<Tuple>>{});
}

int main()
{
    
    std::tuple<int, double, std::string> t(1, 2.3, "Ramaswamy");
    printer <decltype(t), 0,1,2> (t);
    print(t);
    return 0;
}
