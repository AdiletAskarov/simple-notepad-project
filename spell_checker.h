#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <string>
#include <set>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

class spell_checker {
public:
    spell_checker() = default;

    bool load_dictionary(const std::string& path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            return false;
        }
        std::string word;
        while (file >> word) {
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
                return std::tolower(c);
            });
            dictionary.insert(word);
        }
        return true;
    }

    bool is_correct(const std::string& word) const {
        std::string clean_word = word;

        std::erase_if(clean_word, [](const unsigned char c) {
            return !std::isalpha(c);
        });

        if (clean_word.empty()) {
            return true;
        }

        std::transform(clean_word.begin(), clean_word.end(), clean_word.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        return dictionary.find(clean_word) != dictionary.end();
    }

    std::vector<std::string> get_suggestions(const std::string& word) const {
        std::vector<std::string> suggestions;
        std::string clean_word = word;

        std::erase_if(clean_word, [](const unsigned char c) { return !std::isalpha(c); });
        std::transform(clean_word.begin(), clean_word.end(), clean_word.begin(), [](unsigned char c) { return std::tolower(c); });

        if (clean_word.empty()) {
            return suggestions;
        }

        for (const auto& dict_word : dictionary) {
            if (dict_word[0] == clean_word[0] && dict_word.length() == clean_word.length()) {
                suggestions.push_back(dict_word);
                if (suggestions.size() >= 5) {
                    break;
                }
            }
        }
        return suggestions;
    }

private:
    std::set<std::string> dictionary;
};

#endif // SPELL_CHECKER_H