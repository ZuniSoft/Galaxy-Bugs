//
//  NSString+Compatibility.h
//  Tools
//
//  Created by Simeon on 7/01/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface NSString (Compatibility)

- (CGSize) compatibleSizeWithFont:(UIFont *)font;
- (CGSize) compatibleSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)constrain;
- (CGSize) compatibleSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)constrain lineBreakMode:(NSLineBreakMode)lineBreakMode;

- (void) compatibleDrawInRect:(CGRect)rect withFont:(UIFont *)font lineBreakMode:(NSLineBreakMode)lineBreakMode alignment:(NSTextAlignment)alignment color:(UIColor *)color;

@end
