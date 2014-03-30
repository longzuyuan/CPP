#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>

using namespace std;

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,
             std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream& is)
    : file(new vector<string>)
{


}


int main()
{

    return 0;
}
