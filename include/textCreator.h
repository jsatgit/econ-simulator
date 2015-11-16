#ifndef TEXT_CREATOR_H
#define TEXT_CREATOR_H

#include <SFML/Graphics/Text.hpp>
#include <string>

class TextCreator 
{
private:
    sf::Font m_font;
    TextCreator();
    ~TextCreator();

public:
    static TextCreator& instance();
    sf::Text createDialog(const std::string& str);
};

#endif /* TEXT_CREATOR_H */
