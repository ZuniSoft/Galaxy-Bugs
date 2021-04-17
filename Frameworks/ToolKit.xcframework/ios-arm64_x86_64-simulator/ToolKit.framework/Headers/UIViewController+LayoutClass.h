//
//  UIViewController+LayoutClass.h
//  Tools
//
//  Created by Simeon on 9/04/2015.
//  Copyright (c) 2015 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, SSLayoutClass) {
    SSLayoutClassPadRegular,                //iPad Regular
    SSLayoutClassPadCompact,                //iPad Compact
    
    SSLayoutClassPhoneCompact,              //iPhone
};

@interface UIViewController (LayoutClass)

+ (SSLayoutClass) layoutClassForTraits:(UITraitCollection *)traits size:(CGSize)size;
+ (BOOL) layoutClassSupportsSidebar:(SSLayoutClass)lc;

- (BOOL) layoutClassSupportsSidebar;

@end
