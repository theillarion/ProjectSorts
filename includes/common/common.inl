#include "common.hpp"

template <typename T>
inline std::ostream& operator<<(std::ostream& out, std::vector<T>&	src)
{
	out << "{ ";
	for (const auto& elem: src)
		out << elem << " ";
	out << "}" << std::endl;
	return (out);
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, std::list<T>& src)
{
	out << "{ ";
	for (const auto& elem : src)
		out << elem << " ";
	out << "}" << std::endl;
	return (out);
}

template<typename ForwardIterator>
void	PrintRange(ForwardIterator begin, ForwardIterator end)
{
	static unsigned int count = 1;
	std::cout << count++ << " : { ";
	for (auto it = begin; it <= end; ++it)
		std::cout << *it << " ";
	std::cout << "}" << std::endl;
}
