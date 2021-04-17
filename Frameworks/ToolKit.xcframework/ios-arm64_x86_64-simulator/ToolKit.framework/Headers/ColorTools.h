//
//  ColorTools.h
//  Tools
//
//  Created by Simeon Saint-Saens on 24/2/20.
//  Copyright © 2020 Two Lives Left. All rights reserved.
//

#ifndef ColorTools_h
#define ColorTools_h

struct CPColor;

typedef float CPColorValue;

struct CPColor HSLtoRGB( CPColorValue h, CPColorValue s, CPColorValue l );
void HSVtoHSL(CPColorValue h, CPColorValue s, CPColorValue v, CPColorValue *hh, CPColorValue *ss, CPColorValue *ll);

typedef struct CPColor
{
    CPColorValue red, green, blue, alpha;
} CPColor;

typedef struct CPColorHSL
{
    CPColorValue hue, saturation, lightness, alpha;
} CPColorHSL;

@interface CPColorConversion : NSObject

+ (CPColor) hslToRgb:(CPColorHSL)hsl;
+ (CPColorHSL) rgbToHsl:(CPColor)rgb;

@end

#endif /* ColorTools_h */
