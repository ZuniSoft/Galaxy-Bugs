//
//  ArrowView.h
//  Tools
//
//  Created by Simeon on 3/01/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum ArrowViewDirection
{
    ArrowViewDirectionUp,
    ArrowViewDirectionDown,
    ArrowViewDirectionLeft,
    ArrowViewDirectionRight,
} ArrowViewDirection;

typedef enum ArrowViewStyle
{
    ArrowViewStyleSolid,
    ArrowViewStyleChevron,
} ArrowViewStyle;

@interface ArrowView : UIView

@property (nonatomic, assign) ArrowViewDirection direction;
@property (nonatomic, assign) ArrowViewStyle style;
@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) CGLineCap lineCap;
@property (nonatomic, assign) CGSize size;
@property (nonnull, nonatomic, strong) UIColor *color;

+ (nonnull instancetype) arrowViewWithFrame:(CGRect)frame direction:(ArrowViewDirection)dir color:(UIColor*_Nonnull)color;
+ (nonnull instancetype) chevronViewWithFrame:(CGRect)frame direction:(ArrowViewDirection)dir lineWidth:(CGFloat)width color:(UIColor*_Nonnull)color;

+ (nonnull instancetype) arrowWithDirection:(ArrowViewDirection)dir color:(UIColor*_Nonnull)color;
+ (nonnull instancetype) chevronWithDirection:(ArrowViewDirection)dir lineWidth:(CGFloat)width color:(UIColor*_Nonnull)color;

@end
