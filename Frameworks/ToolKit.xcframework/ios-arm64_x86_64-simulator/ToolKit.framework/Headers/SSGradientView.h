//
//  SSGradientView.h
//  Tools
//
//  Created by Simeon on 30/06/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PXPGradientColor;

@interface SSGradientView : UIView

@property (nonatomic, strong) PXPGradientColor *gradientColor;
@property (nonatomic, assign) CGFloat angle;

@end
