//it work, but not so perfect

#include <iostream>
#include <string>
#include <cctype>

namespace AdamR {

    using StringIt = std::string::iterator;

    StringIt My_strstr(std::string &needle, StringIt& haystack_beg, StringIt& haystack_end)
    {
        int needle_size = needle.size();

        StringIt needle_it;
        int j = 0;

        for (; haystack_beg != haystack_end; ++haystack_beg)
        {
            for (j = 0, needle_it = needle.begin(); toupper(*(haystack_beg + j)) == toupper(*needle_it); ++j, ++needle_it)
            {
                if (j + 1 == needle_size)
                {
                    return haystack_beg;
                }
            }
        }

        return haystack_end;
    }
}


int main() {
    std::string needle, haystack;
    int cnter = 0;

    std::cout << "Input your string:\n";
    std::getline(std::cin, haystack);

    std::cout << "Input substring\n";
    std::getline(std::cin, needle);

    AdamR::StringIt haystack_cur = haystack.begin();
    AdamR::StringIt haystack_end = haystack.end();

    while (true)
    {
        haystack_cur = AdamR::My_strstr(needle, haystack_cur, haystack_end);

        if (haystack_cur != haystack_end)
            cnter++;

        else break;

        haystack_cur = haystack_cur + needle.size();
    }

    std::cout << cnter;
    return 0;
}
