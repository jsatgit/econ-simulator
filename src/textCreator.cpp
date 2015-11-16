#include "textCreator.h"

using namespace sf;
using namespace std;

TextCreator::TextCreator()
{
    m_font.loadFromFile("/Library/Fonts/Arial.ttf");
}

TextCreator::~TextCreator()
{
}

TextCreator& TextCreator::instance()
{
    static TextCreator instance;
    return instance;
}

Text TextCreator::createDialog(const string& str)
{
    Text text(str, m_font);
    text.setColor(sf::Color::White);
    return text;
}
