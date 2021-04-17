//
//  SSGradientOverlayView.h
//  Tools
//
//  Created by Simeon on 6/11/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import "SSGradientView.h"

#import <QuartzCore/QuartzCore.h>

@interface SSGradientOverlayView : SSGradientView

@property (nonatomic, strong) UIImage *overlayImage;

@property (nonatomic, assign) CGFloat overlayImageOpacity;

@property (nonatomic, assign) CGBlendMode blendMode;

@end
