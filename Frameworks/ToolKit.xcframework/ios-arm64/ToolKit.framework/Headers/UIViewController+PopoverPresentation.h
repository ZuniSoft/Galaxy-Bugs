//
//  UIViewController+PopoverPresentation.h
//  Tools
//
//  Created by Simeon on 19/03/2015.
//  Copyright (c) 2015 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (PopoverPresentation)

- (void)showAsPopoverFromRect:(CGRect)rect inController:(UIViewController *)controller animated:(BOOL)animated;
- (void)showAsPopoverFromRect:(CGRect)rect inController:(UIViewController *)controller animated:(BOOL)animated delegate:(id<UIPopoverPresentationControllerDelegate>)delegate;
- (void)showAsPopoverFromRect:(CGRect)rect inController:(UIViewController *)controller animated:(BOOL)animated delegate:(id<UIPopoverPresentationControllerDelegate>)delegate backgroundColor:(UIColor*)color;

@end
