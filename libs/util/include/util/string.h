#include <string>
#include <vector>

namespace util {

std::vector<std::string> split(std::string const& s, char delimeter)
{
    std::vector<std::string> result;

    std::size_t begin = 0;
    std::size_t end = s.find(delimeter);

    while (end != std::string::npos) {
        result.emplace_back(s, begin, end - begin);
        begin = end + 1;
        end = s.find(delimeter, begin);
    }

    result.emplace_back(s, begin, s.size() - begin);

    return result;
}

void strip(std::string& s, char toStrip)
{
    std::size_t pos = s.find(toStrip);
    while (pos != std::string::npos) {
        s.erase(pos, 1);
        pos = s.find(toStrip, pos);
    }
}

} // namespace util
