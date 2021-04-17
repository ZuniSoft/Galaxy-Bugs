//
//  ColorPicker.h
//  Codea
//
//  Created by Simeon Saint-Saëns on 24/05/11.
//  Copyright 2011 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ColorTools.h"

@class ColorPicker;

@protocol ColorPickerDelegate <NSObject>

- (void) colorPicker:(ColorPicker*)colorPicker didPickColorWithRed:(CPColorValue)red green:(CPColorValue)green blue:(CPColorValue)blue alpha:(CPColorValue)alpha;

@end

@interface ColorPicker : UIViewController
{
    IBOutlet UIImageView *pickerRing;
    IBOutlet UIView *pickerSquare;
    
    IBOutlet UIView *pickerStrokeSample;
    IBOutlet UIView *pickerSample;
    
    UISlider *opacitySlider;

@private
    float hue;
    float saturation;
    float lightness;
    float alpha;
    
    UIImageView *pickerRingSelector;
    UIImageView *pickerSquareSelector;    
}
@property (nonatomic, weak) id<ColorPickerDelegate> delegate;
@property (nonatomic, assign) CPColor color;
@property (nonatomic, assign) BOOL continuous;

@end

