#include "Text.hpp"
#include "../../Utils/File.hpp"

Text::Text(INTN x, INTN y, UINTN scale, Color color, CHAR8* text, CHAR16* font_name) {
	SetPosX(x);
	SetPosY(y);
	SetColor(color);
	font_name_ = font_name;
	text_ = text;
	scale_ = scale;

	File f(font_name);
	UINTN size;
	const auto data = f.Read(&size);
	font_data_ = static_cast<unsigned char*>(data);

	if(size == 0){
		return;
	}
	height_ = font_data_[3];
	text_size_ = size;
}
VOID Text::Draw(Graphics& g){
	INTN x = pos_x_;
	INTN y = pos_y_;

	for(int i = 0; text_[i] != '\0'; i++) {
		if(text_[i+1] == '\n' && text_[i] == '\r') {
			x = pos_x_;
			y += height_ * scale_; 
		}
		else if(text_[i] == '\n'){
			x = pos_x_;
			y += height_ * scale_;
		}
		else if(text_[i] == '\r'){
			x = pos_x_;
		}
		else{
			const unsigned char width = DrawGlyph(g, text_[i], x, y, color_, scale_);
			x += width * scale_;
		}
		
	}
}

unsigned char Text::DrawGlyph(const Graphics& g, const char ch, UINTN x_pos, UINTN y_pos, const Color color, const UINTN scale) const{
	const unsigned char width = GetGlyphWidth(ch);
	const unsigned char* glyph = GetGlyphDataPtr(ch);

	for (int y = 0; y < height_; y++){
		for (int x = 0; x < width; x++){
			const int fontAlpha = 1 - glyph[width * y + x] / 255; // Normalize the alpha
			if (fontAlpha == 1) {
				g.DrawRectangle(x_pos + x * scale, y_pos + y * scale, scale, scale, Color::WHITE);
			}
		}
	}
	return width;
}
