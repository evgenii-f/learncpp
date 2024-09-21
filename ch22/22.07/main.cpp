// Fix the program presented in the section “A reductive case” so that the Resource 
// is properly deallocated. Do not alter the code in main().
// Here is the program again for ease of reference:

// #include <iostream>
// #include <memory> // for std::shared_ptr

// class Resource
// {
// public:
// 	// std::shared_ptr<Resource> m_ptr {}; // initially created empty
// 	std::weak_ptr<Resource> m_ptr {}; // make it shared so the Resource can be deallocated

// 	Resource() { std::cout << "Resource acquired\n"; }
// 	~Resource() { std::cout << "Resource destroyed\n"; }
// };

// int main()
// {
// 	auto ptr1 { std::make_shared<Resource>() };

// 	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

// 	return 0;
// }

#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <unordered_set>
#include <string>


using list_t = std::vector<int>;
using seq_t = std::vector<list_t>;
using memo_t = std::unordered_set<std::string>;

std::string getListId(const list_t& l, char sep = '-') {
    std::string out{};
    for (const auto& el : l) out += std::to_string(el) + sep;
    return out.substr(0, out.length() - 1);
}

bool checkList(const list_t& l, const seq_t seq) {
    std::size_t n{ l.size() };
    std::size_t m{ seq[0].size() };
    for (const auto& s : seq) {
        std::size_t i{ 0 };
        while (l[i] != s[0]) {
            if (i == n)
                return false;
            i++;
        }

        if (n - i < m)
            return false;
        for (int j{0}; j < m; ++j) {
            if (s[j] != l[i])
                return false;
            i++;
        }

    }

    return true;
}

bool checkList(const list_t& target, const list_t checker) {
    std::size_t n{ target.size() };
    std::size_t m{ checker.size() };
    std::size_t i{ 0 };
    std::size_t j{ 0 };
    int found{ 0 };
    while (i < n && j < m) {
        if (target[i] == checker[j]) {
            ++found;
            ++i;
            ++j;
        } else {
            ++i;
        }
    }
    return found == m;

}

list_t getList(const list_t& s1, const list_t& s2) { 
    std::size_t m{ s1.size() };
    list_t res{};
    int i{ 0 };
    int j{ 0 };
    while (i < m) {
        if (s1[i] == s2[j]) {
            res.push_back(s1[i]);
            i++;
            j++;
        } else {
            res.push_back(s1[i]);
            i++;
        }
    }
    while (j < m) {
        // in case if it should be inserted in the beggining
        if (s2[j] == res[0])
            break;
        res.push_back(s2[j]);
        j++;
    }

    return res;
}



bool dfs(
    const list_t& orig, 
    const seq_t& seq
    ) {
    memo_t checked{};
    int nValid{ 0 };
    for (auto i{0}; i < seq.size(); i++) {
        list_t s1{ seq[i] };
        for (auto j{0}; j < seq.size(); j++) {
            if (i == j) continue;
            list_t s2{ seq[j] };
            list_t child{ getList(s1, s2) };
            std::string childId{ getListId(child) };

            if (checked.count(childId))
                continue;

            checked.emplace(childId);
            bool ifValid{ true };
            for (auto k{0}; k < seq.size(); k++) {
                if (k == i || k == j)
                    continue;

                if (checkList(child, seq[k])) {
                    ifValid = false;
                    break;
                }
            }
            if (!ifValid)
                continue;

            ++nValid;
            if (nValid > 1)
                return false;
        }
    }
    std::cout << "nValid = " << nValid << std::endl;

    return nValid == 1;
}

bool sequence_reconstruction(std::vector<int> original, std::vector<std::vector<int>> seqs) {
    // WRITE YOUR BRILLIANT CODE HERE
    return dfs(original, seqs);
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::ostream& operator<<(std::ostream& out, const list_t& s) {
    for (const auto el : s) out << el << " ";
    return out;
}


int main() {
    // std::vector<int> original = get_words<int>();
    // int seqs_length;
    // std::cin >> seqs_length;
    // ignore_line();
    // std::vector<std::vector<int>> seqs;
    // for (int i = 0; i < seqs_length; i++) {
    //     seqs.emplace_back(get_words<int>());
    // }
    // bool res = sequence_reconstruction(original, seqs);
    // std::cout << std::boolalpha << res << '\n';
    list_t orig{ 1, 2, 3 };
    list_t s1{ 1, 3};
    list_t s2{ 1, 2};
    list_t s3{ 2, 3 };
    seq_t seqs{ s1, s2, s3 };

    std::cout << std::boolalpha << dfs(orig, seqs) << std::endl;

    // list_t child12{ getList(s1, s2) };
    // std::cout << "child = " << child12 << std::endl;
    // std::cout << checkList(child12, s1) << std::endl;
    // std::cout << checkList(child12, s2) << std::endl;
    // std::cout << checkList(child12, s3) << std::endl;
    // std::cout << getListId(child12) << std::endl;
    // std::cout << getList(s1, s2) << std::endl;
    // std::cout << getList(s2, s1) << std::endl;

}
