//
//  TLLButton.h
//  Tools
//
//  Created by Simeon on 11/08/13.
//  Copyright (c) 2013 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum TLLButtonTitleStyle
{
    TLLButtonTitleStyleNormal,
    TLLButtonTitleStyleCenteredBelow,
} TLLButtonTitleStyle;

@interface TLLButton : UIButton

@property (nonatomic, strong) UIFont *titleFont UI_APPEARANCE_SELECTOR;

@property (nonatomic, assign) TLLButtonTitleStyle titleLayoutStyle;

@end
