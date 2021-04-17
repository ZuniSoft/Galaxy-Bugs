//
//  DelayedLoadViewController.h
//  Tools
//
//  Created by Simeon on 1/10/2014.
//  Copyright (c) 2014 Two Lives Left. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DelayedLoadViewController : UIViewController

@property (nonnull, nonatomic, readonly) UIViewController *controller;

- (nonnull instancetype) initWithViewController:(nonnull UIViewController*)controller;

@end
