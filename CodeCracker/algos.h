#ifndef ALGOS_H
#define ALGOS_H

#include <string>

// 1.1
bool has_unique_chars(const std::string&);
// 1.2
bool check_permutation_of_strings(const std::string&, const std::string&);
// 1.3
std::string insert_in_spaces(const std::string&, const std::string&);
// 1.4
bool palindrom_permutation(const std::string&);
// 1.5
bool can_be_same_one_oper(const std::string&, const std::string&); 
// 1.6
std::string compressor(const std::string&);
// 1.7
int** rotated_matrix(int**, int);
// 1.8
void set_to_zero_rows_and_columns(int** , int, int);
// 1.9
bool is_string_rotation(const std::string&, const std::string&);

#endif