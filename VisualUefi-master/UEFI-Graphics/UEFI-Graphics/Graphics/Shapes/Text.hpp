#pragma once
#include "../Graphics.hpp"
#include "../Drawable.hpp"
#include "../Transformable.hpp"
class Text : public Drawable, public Transformable{
public:
	Text(INTN x, INTN y, UINTN scale, Color color, CHAR8* text, CHAR16* font_name);
	VOID Draw(Graphics& g) override;

private:
	CHAR8* text_;
	CHAR16* font_name_;
	
	UINTN height_;
	UINTN text_size_;
	unsigned char* font_data_;

	unsigned char DrawGlyph(const Graphics& g, const char ch, UINTN x_pos, UINTN y_pos, const Color color, const UINTN scale) const;

	unsigned char GetGlyphWidth(const char ch) const{
		return font_data_[4 + 1024 * (ch - ' ')];
	}

	const unsigned char* GetGlyphDataPtr(const char ch) const{
		return &font_data_[4 + 1024 * (ch - ' ') + 1];
	}
};