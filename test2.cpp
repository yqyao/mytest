#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;using std::cout;using std::endl;
using std::list;using std::cin;using std::fill_n;
using std::string;
template<typename Sequence>
inline std::ostream& println(Sequence const& seq)
{
	for (const auto& i : seq)
		cout << i << " ";
	cout << endl;
	return cout;
}
inline bool
is_shorter(std::string const& lhs, std::string const& rhs)
{
	return lhs.size() < rhs.size();
}
void elimdups(std::vector<std::string> &vs)
{
	std::sort(vs.begin(), vs.end());
	auto new_end = std::unique(vs.begin(), vs.end());
	vs.erase(new_end, vs.end());
}
void biggies(std::vector<std::string> &vs, std::size_t sz)
{
	elimdups(vs);
	println(vs);
	std::stable_sort(vs.begin(), vs.end(), [](string const& lhs, string const& rhs) {
		return lhs.size() < rhs.size();
	});
	auto wc = std::find_if(vs.begin(), vs.end(), [sz](string const& s){
		return s.size() >= sz ;
	});
	cout << *wc <<endl;
	std::for_each(wc, vs.end(), [](const string &s){
		std::cout << s << " ";
	});
}
int main()
{

	std::vector<std::string> v{"1234", "1234", "1234", "hi~", "alan", "alan", "cp"};
	biggies(v, 3);
	std::cout<< std::endl;
	std::cout <<"hello world" ;
	return 0;

}