#include "string_trim.hpp"
#include <assert.h>
#include <string>
#include <vector>

void trim_empty_string_does_nothing(){
    std::string s;
    trim(s);
    assert(s.empty());
}

void trim_non_space_string_does_nothing(){
    std::string const orig="hello";
    auto s=orig;
    trim(s);
    assert(s==orig);
}

void trim_all_space_string_removes_everything(){
    std::string s="     ";
    trim(s);
    assert(s.empty());
}

void trim_spaces_from_left(){
    std::string const hello="hello";
    std::string s="     "+hello;
    trim(s);
    assert(s==hello);
}

void trim_spaces_from_right(){
    std::string const hello="hello";
    std::string s=hello+"     ";
    trim(s);
    assert(s==hello);
}

void trim_spaces_from_both_ends(){
    std::string const hello="hello";
    std::string s="     "+hello+"   ";
    trim(s);
    assert(s==hello);
}

void trim_spaces_from_left_only(){
    std::string const hello="hello     ";
    std::string s="     "+hello;
    trim_left(s);
    assert(s==hello);
}

void trim_spaces_from_right_only(){
    std::string const hello="     hello";
    std::string s=hello+"     ";
    trim_right(s);
    assert(s==hello);
}

void trim_copy_empty_string_does_nothing(){
    std::string orig;
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s.empty());
    assert(s2.empty());
}

void trim_copy_non_space_string_does_nothing(){
    std::string const orig="hello";
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s==orig);
    assert(s2==orig);
}

void trim_copy_all_space_string_removes_everything(){
    std::string const orig="     ";
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2.empty());
    assert(s==orig);
}

void trim_copy_spaces_from_left(){
    std::string const hello="hello";
    std::string const orig="     "+hello;
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_spaces_from_right(){
    std::string const hello="hello";
    std::string const orig=hello+"     ";
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_spaces_from_both_ends(){
    std::string const hello="hello";
    std::string const orig="     "+hello+"   ";
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_spaces_from_left_only(){
    std::string const hello="hello     ";
    std::string const orig="     "+hello;
    auto s=orig;
    auto s2=trim_copy_left(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_spaces_from_right_only(){
    std::string const hello="     hello";
    std::string const orig=hello+"     ";
    std::string s=orig;
    auto s2=trim_copy_right(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_spaces_and_tabs_from_both_ends(){
    std::string const hello="hello";
    std::string s="    \t \t \t   \t "+hello+"  \t \t\t\t\t ";
    trim(s);
    assert(s==hello);
}

void trim_empty_vector_does_nothing(){
    std::vector<char> s;
    trim(s);
    assert(s.empty());
}

void trim_non_space_vector_does_nothing(){
    std::vector<char> const orig{'h','e','l','l','o'};
    auto s=orig;
    trim(s);
    assert(s==orig);
}

void trim_all_space_vector_removes_everything(){
    std::vector<char> s(5,' ');
    trim(s);
    assert(s.empty());
}

void trim_vector_spaces_from_left(){
    std::vector<char> const hello{'h','e','l','l','o'};
    std::vector<char> s(5,' ');
    s.insert(s.end(),hello.begin(),hello.end());
    trim(s);
    assert(s==hello);
}

void trim_vector_spaces_from_right(){
    std::vector<char> const hello{'h','e','l','l','o'};
    std::vector<char> spaces(5,' ');
    std::vector<char> s=hello;
    s.insert(s.end(),spaces.begin(),spaces.end());
    trim(s);
    assert(s==hello);
}

void trim_vector_spaces_from_both_ends(){
    std::vector<char> const hello{'h','e','l','l','o'};
    std::vector<char> spaces(5,' ');
    std::vector<char> s=spaces;
    s.insert(s.end(),hello.begin(),hello.end());
    s.insert(s.end(),spaces.begin(),spaces.end());
    trim(s);
    assert(s==hello);
}

void trim_vector_spaces_from_left_only(){
    std::vector<char> const hello{'h','e','l','l','o',' ',' ',' '};
    std::vector<char> spaces(5,' ');
    std::vector<char> s=spaces;
    s.insert(s.end(),hello.begin(),hello.end());
    trim_left(s);
    assert(s==hello);
}

void trim_vector_spaces_from_right_only(){
    std::vector<char> const hello{' ',' ',' ',' ',' ','h','e','l','l','o'};
    std::vector<char> spaces(5,' ');
    std::vector<char> s;
    s.insert(s.end(),hello.begin(),hello.end());
    s.insert(s.end(),spaces.begin(),spaces.end());
    trim_right(s);
    assert(s==hello);
}

void trim_vector_copy_empty_string_does_nothing(){
    std::vector<char> orig;
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s.empty());
    assert(s2.empty());
}

void trim_vector_copy_non_space_string_does_nothing(){
    std::vector<char> const orig{'h','e','l','l','o'};
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s==orig);
    assert(s2==orig);
}

void trim_vector_copy_all_space_string_removes_everything(){
    std::vector<char> const orig(6,' ');
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2.empty());
    assert(s==orig);
}

void trim_vector_copy_spaces_from_left(){
    std::vector<char> const hello{'h','e','l','l','o'};
    std::vector<char> spaces(5,' ');
    std::vector<char> orig=spaces;
    orig.insert(orig.end(),hello.begin(),hello.end());
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_vector_copy_spaces_from_right(){
    std::vector<char> const hello{'h','e','l','l','o'};
    std::vector<char> spaces(5,' ');
    std::vector<char> orig;
    orig.insert(orig.end(),hello.begin(),hello.end());
    orig.insert(orig.end(),spaces.begin(),spaces.end());
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_vector_copy_spaces_from_both_ends(){
    std::vector<char> const hello{'h','e','l','l','o'};
    std::vector<char> spaces(5,' ');
    std::vector<char> orig=spaces;
    orig.insert(orig.end(),hello.begin(),hello.end());
    orig.insert(orig.end(),spaces.begin(),spaces.end());
    auto s=orig;
    auto s2=trim_copy(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_vector_copy_spaces_from_left_only(){
    std::vector<char> const hello{'h','e','l','l','o',' ',' ',' '};
    std::vector<char> spaces(5,' ');
    std::vector<char> orig=spaces;
    orig.insert(orig.end(),hello.begin(),hello.end());
    auto s=orig;
    auto s2=trim_copy_left(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_vector_copy_spaces_from_right_only(){
    std::vector<char> const hello{' ',' ',' ','h','e','l','l','o'};
    std::vector<char> spaces(5,' ');
    std::vector<char> orig;
    orig.insert(orig.end(),hello.begin(),hello.end());
    orig.insert(orig.end(),spaces.begin(),spaces.end());
    std::vector<char> s=orig;
    auto s2=trim_copy_right(s);
    assert(s2==hello);
    assert(s==orig);
}

void trim_left_with_specified_characters(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    trim_left(s,"ab");
    assert(s==hello);
}

void trim_left_with_specified_characters_via_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    char const* space_chars="ab";
    trim_left(s,space_chars);
    assert(s==hello);
}

void trim_left_with_specified_characters_via_non_const_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    char space_chars[]="ab";
    char* space_chars_ptr=space_chars;
    trim_left(s,space_chars_ptr);
    assert(s==hello);
}

void trim_spaces_and_tabs_from_both_ends_wide_chars(){
    std::wstring const hello=L"hello";
    std::wstring s=L"    \t \t \t   \t "+hello+L"  \t \t\t\t\t ";
    trim(s);
    assert(s==hello);
}

void trim_left_with_specified_characters_via_string(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    std::string const space_chars="ab";
    trim_left(s,space_chars);
    assert(s==hello);
}

void trim_right_with_specified_characters(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    trim_right(s,"ab");
    assert(s==hello);
}

void trim_right_with_specified_characters_via_char_pointer(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    char const* space_chars="ab";
    trim_right(s,space_chars);
    assert(s==hello);
}

void trim_right_with_specified_characters_via_non_const_char_pointer(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    char space_chars[]="ab";
    char* space_chars_ptr=space_chars;
    trim_right(s,space_chars_ptr);
    assert(s==hello);
}

void trim_right_with_specified_characters_via_string(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    std::string const space_chars="ab";
    trim_right(s,space_chars);
    assert(s==hello);
}

void trim_left_with_predicate(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    trim_left(s,[](char c){
            return c=='a' || c=='b';
        });
    assert(s==hello);
}

void trim_both_with_specified_characters(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    trim(s,"ab");
    assert(s==hello);
}

void trim_both_with_specified_characters_via_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    char const* space_chars="ab";
    trim(s,space_chars);
    assert(s==hello);
}

void trim_both_with_specified_characters_via_non_const_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    char space_chars[]="ab";
    char* space_chars_ptr=space_chars;
    trim(s,space_chars_ptr);
    assert(s==hello);
}

void trim_both_with_specified_characters_via_string(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    std::string const space_chars="ab";
    trim(s,space_chars);
    assert(s==hello);
}

void trim_right_with_predicate(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    trim_right(s,[](char c){
            return c=='a' || c=='b';
        });
    assert(s==hello);
}

void trim_both_with_predicate(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello+"aaabbabab";
    auto s=orig;
    trim(s,[](char c){
            return c=='a' || c=='b';
        });
    assert(s==hello);
}

void trim_copy_left_with_specified_characters(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    auto s2=trim_copy_left(s,"ab");
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_left_with_specified_characters_via_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    char const* space_chars="ab";
    auto s2=trim_copy_left(s,space_chars);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_left_with_specified_characters_via_non_const_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    char space_chars[]="ab";
    char* space_chars_ptr=space_chars;
    auto s2=trim_copy_left(s,space_chars_ptr);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_left_with_specified_characters_via_string(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    std::string const space_chars="ab";
    auto s2=trim_copy_left(s,space_chars);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_right_with_specified_characters(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    auto s2=trim_copy_right(s,"ab");
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_right_with_specified_characters_via_char_pointer(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    char const* space_chars="ab";
    auto s2=trim_copy_right(s,space_chars);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_right_with_specified_characters_via_non_const_char_pointer(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    char space_chars[]="ab";
    char* space_chars_ptr=space_chars;
    auto s2=trim_copy_right(s,space_chars_ptr);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_right_with_specified_characters_via_string(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    std::string const space_chars="ab";
    auto s2=trim_copy_right(s,space_chars);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_left_with_predicate(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    auto s2=trim_copy_left(s,[](char c){
            return c=='a' || c=='b';
        });
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_both_with_specified_characters(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    auto s2=trim_copy(s,"ab");
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_both_with_specified_characters_via_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    char const* space_chars="ab";
    auto s2=trim_copy(s,space_chars);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_both_with_specified_characters_via_non_const_char_pointer(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    char space_chars[]="ab";
    char* space_chars_ptr=space_chars;
    auto s2=trim_copy(s,space_chars_ptr);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_both_with_specified_characters_via_string(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    std::string const space_chars="ab";
    auto s2=trim_copy(s,space_chars);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_right_with_predicate(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    auto s2=trim_copy_right(s,[](char c){
            return c=='a' || c=='b';
        });
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_both_with_predicate(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello+"aaabbabab";
    auto s=orig;
    auto s2=trim_copy(s,[](char c){
            return c=='a' || c=='b';
        });
    assert(s2==hello);
    assert(s==orig);
}

class ab_whitespace_ctype:
    public std::ctype<char>{
    mask mask_table[std::ctype<char>::table_size];
public:
    ab_whitespace_ctype():
        std::ctype<char>(mask_table){
        auto const default_table=std::ctype<char>::classic_table();
        for(unsigned i=0;i<std::ctype<char>::table_size;++i){
            mask_table[i]=default_table[i];
            if((i=='a') || (i=='b'))
                mask_table[i]|=space;
        }
    }
};

class ab_whitespace_ctype_wchar:
    public std::ctype<wchar_t>{
public:
    bool do_is(mask m, wchar_t c) const{
        mask classification;
        do_is(&c,&c+1,&classification);
        return (classification&m)!=0;
    }
    const wchar_t* do_is(const wchar_t* low, const wchar_t* high,
                       mask* vec) const{
        std::ctype<wchar_t>::do_is(low,high,vec);
        for(;low!=high;++low,++vec){
            if((*low==L'a') || (*low==L'b'))
                *vec|=space;
        }
        return high;
    }
    const wchar_t* do_scan_is(mask m, const wchar_t* low, const wchar_t* high) const{
        for(;low!=high && !do_is(m,*low);++low);
        return low;
    }
    const wchar_t* do_scan_not(mask m, const wchar_t* low, const wchar_t* high) const{
        for(;low!=high && do_is(m,*low);++low);
        return low;
    }
    
};

void trim_left_with_locale(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype());
    trim_left(s,custom_locale);
    assert(s==hello);
}

void trim_left_wide_with_locale(){
    std::wstring const hello=L"hello";
    std::wstring const orig=L"aaabbabab"+hello;
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype_wchar());
    trim_left(s,custom_locale);
    assert(s==hello);
}

void trim_right_with_locale(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype());
    trim_right(s,custom_locale);
    assert(s==hello);
}

void trim_right_wide_with_locale(){
    std::wstring const hello=L"hello";
    std::wstring const orig=hello+L"aaabbabab";
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype_wchar());
    trim_right(s,custom_locale);
    assert(s==hello);
}

void trim_both_with_locale(){
    std::string const hello="hello";
    std::string const orig="aaabbbabab"+hello+"aaabbabab";
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype());
    trim(s,custom_locale);
    assert(s==hello);
}

void trim_copy_left_with_locale(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello;
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype());
    auto s2=trim_copy_left(s,custom_locale);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_right_with_locale(){
    std::string const hello="hello";
    std::string const orig=hello+"aaabbabab";
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype());
    auto s2=trim_copy_right(s,custom_locale);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_both_with_locale(){
    std::string const hello="hello";
    std::string const orig="aaabbabab"+hello+"aaabbabab";
    auto s=orig;
    std::locale custom_locale(std::locale(),new ab_whitespace_ctype());
    auto s2=trim_copy(s,custom_locale);
    assert(s2==hello);
    assert(s==orig);
}

void trim_copy_left_string_view(){
    std::string const hello="hello     ";
    std::string const orig="     "+hello;
    std::string_view s=orig;
    auto s2=trim_copy_left(s);
    assert(s2==hello);
    assert(s==orig);
    assert((std::is_same_v<decltype(s2),std::string>));
}

int main(){
    trim_empty_string_does_nothing();
    trim_non_space_string_does_nothing();
    trim_all_space_string_removes_everything();
    trim_spaces_from_left();
    trim_spaces_from_right();
    trim_spaces_from_both_ends();
    trim_spaces_from_left_only();
    trim_spaces_from_right_only();
    trim_copy_empty_string_does_nothing();
    trim_copy_non_space_string_does_nothing();
    trim_copy_all_space_string_removes_everything();
    trim_copy_spaces_from_left();
    trim_copy_spaces_from_right();
    trim_copy_spaces_from_both_ends();
    trim_copy_spaces_from_left_only();
    trim_copy_spaces_from_right_only();
    trim_spaces_and_tabs_from_both_ends();
    trim_empty_vector_does_nothing();
    trim_non_space_vector_does_nothing();
    trim_all_space_vector_removes_everything();
    trim_vector_spaces_from_left();
    trim_vector_spaces_from_right();
    trim_vector_spaces_from_both_ends();
    trim_vector_spaces_from_left_only();
    trim_vector_spaces_from_right_only();
    trim_vector_copy_empty_string_does_nothing();
    trim_vector_copy_non_space_string_does_nothing();
    trim_vector_copy_all_space_string_removes_everything();
    trim_vector_copy_spaces_from_left();
    trim_vector_copy_spaces_from_right();
    trim_vector_copy_spaces_from_both_ends();
    trim_vector_copy_spaces_from_left_only();
    trim_vector_copy_spaces_from_right_only();
    trim_spaces_and_tabs_from_both_ends_wide_chars();
    trim_left_with_specified_characters();
    trim_left_with_specified_characters_via_char_pointer();
    trim_left_with_specified_characters_via_non_const_char_pointer();
    trim_left_with_specified_characters_via_string();
    trim_right_with_specified_characters();
    trim_right_with_specified_characters_via_char_pointer();
    trim_right_with_specified_characters_via_non_const_char_pointer();
    trim_right_with_specified_characters_via_string();
    trim_both_with_specified_characters();
    trim_both_with_specified_characters_via_char_pointer();
    trim_both_with_specified_characters_via_non_const_char_pointer();
    trim_both_with_specified_characters_via_string();
    trim_left_with_predicate();
    trim_right_with_predicate();
    trim_both_with_predicate();
    trim_copy_left_with_specified_characters();
    trim_copy_left_with_specified_characters_via_char_pointer();
    trim_copy_left_with_specified_characters_via_non_const_char_pointer();
    trim_copy_left_with_specified_characters_via_string();
    trim_copy_right_with_specified_characters();
    trim_copy_right_with_specified_characters_via_char_pointer();
    trim_copy_right_with_specified_characters_via_non_const_char_pointer();
    trim_copy_right_with_specified_characters_via_string();
    trim_copy_both_with_specified_characters();
    trim_copy_both_with_specified_characters_via_char_pointer();
    trim_copy_both_with_specified_characters_via_non_const_char_pointer();
    trim_copy_both_with_specified_characters_via_string();
    trim_copy_left_with_predicate();
    trim_copy_right_with_predicate();
    trim_copy_both_with_predicate();
    trim_left_with_locale();
    trim_left_wide_with_locale();
    trim_right_with_locale();
    trim_right_wide_with_locale();
    trim_both_with_locale();
    trim_copy_left_with_locale();
    trim_copy_right_with_locale();
    trim_copy_both_with_locale();
    trim_copy_left_string_view();
}
